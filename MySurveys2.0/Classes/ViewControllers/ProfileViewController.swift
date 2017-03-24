//
//  ProfileViewController.swift
//  MySurveys2.0
//
//  Created by Chinthan on 20/06/16.
//  Copyright © 2016 Chinthan. All rights reserved.
//

import UIKit

class ProfileViewController: RootViewController, UITableViewDelegate, UITableViewDataSource, UIImagePickerControllerDelegate, UINavigationControllerDelegate, CountryChangedDelegate
{
   // MARK: - IBOutlets for view
    @IBOutlet weak var imageView: UIImageView?
    @IBOutlet weak var lblUsername: UILabel?
    @IBOutlet weak var lblCountry: UILabel?
    @IBOutlet weak var lblEmail: UILabel?
    @IBOutlet weak var tableview: UITableView!
    @IBOutlet weak var btnEdit: UIBarButtonItem!
    @IBOutlet weak var bgImage: UIImageView?
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var viewHeight: NSLayoutConstraint!
    @IBOutlet weak var btnCameraIcon : UIButton!
    
    // MARK: - Properties for viewcontroller
    var titleArray:[String] = []
    var panelist:OPGPanellistProfile?
    var profileImgMediaID : String?
    var isEditable : Bool?
    var profileImgPath : String?

    
    // MARK: - Getter Setter Methods
    func setProfileImagePath(path : String)
    {
        let url = NSURL(string: path)
        let filename : String = url!.lastPathComponent!                                                 //set only imageName to defaults to fetch path when needed from tmp folder
        let defaults = UserDefaults.standard
        defaults.set(filename, forKey: "profileImagePath")
        defaults.synchronize()
    }
    
    func getProfileImagePath() -> String
    {
        let filename = (UserDefaults.standard.object(forKey: "profileImagePath") as? String)!
        let tempDirURL = NSURL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(filename)        //get image name, construct path and return
        return (tempDirURL?.path)!
    }

    func getDateString() -> String
    {
        let date = NSDate()
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "HH_mm_ss"
        return dateFormatter.string(from: date as Date)
    }
    
     // MARK: - View delegate methods
    override func viewDidLoad()
    {
        super.viewDidLoad()
        self.titleArray += [NSLocalizedString("Name", comment: ""), NSLocalizedString("Country", comment: ""), NSLocalizedString("E-mail Id", comment: "")]
        self.tableview.delegate=self
        self.tableview.dataSource=self
        self.tableview.allowsSelection = false                  //Disable table view selection
        self.tableview.separatorStyle = UITableViewCellSeparatorStyle.none
        //self.title = NSLocalizedString("Profile", comment: "")
        self.activityIndicator.color = AppTheme.appBackgroundColor()

        let bounds = UIScreen.main.bounds
        let height = bounds.size.height
        if height == 480                                    //Enable scroll only for 4S
        {
            self.tableview.isScrollEnabled=true
        }

        self.getPanellistProfileFromDB()
        if self.panelist != nil
        {
            print(self.panelist as Any)
        }
        self.isEditable=false
        self.view.layoutIfNeeded()
        circularImage(imageView)
        let width =  btnCameraIcon.bounds.size.width
        btnCameraIcon.layer.cornerRadius = 0.5 * width
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewWillAppear(_ animated: Bool)
    {
        super.viewWillAppear(animated)
        
        let isOperating : Int? = UserDefaults.standard.value(forKey: "isOperating") as? Int
        let array : Array<Any>? = UserDefaults.standard.value(forKey: "downloadSurveysArray") as? Array<Any>
        if (isOperating == 2) && (array?.count == 0){
            if self.panelist?.firstName==nil || self.panelist?.countryName==nil
            {
                self.getPanellistProfileFromDB()                        //get from DB again if profile was not loaded due to internet disconnetivity.
            }
        }  // thamarai changes
        
        if isEditable!
        {
            let btnEdit =  UIBarButtonItem(title: NSLocalizedString("Save", comment: "") , style: UIBarButtonItemStyle.plain, target: self, action: #selector(editProfile))
            self.tabBarController?.navigationItem.rightBarButtonItem = btnEdit
        }
        else
        {
            let btnEdit =  UIBarButtonItem(title: NSLocalizedString("Edit", comment: "") , style: UIBarButtonItemStyle.plain, target: self, action: #selector(editProfile))
            self.tabBarController?.navigationItem.rightBarButtonItem = btnEdit
            self.tableview.separatorStyle = UITableViewCellSeparatorStyle.none
            self.tableview.allowsSelection = false
            self.tableview.reloadData()                 //to disable editing after coming back to profile screen which was left in edit mode
        }
        
        let path : String? = UserDefaults.standard.object(forKey: "profileImagePath") as? String
        if path==nil || (path?.isEmpty)!
        {
            //Set default image
            self.imageView?.image = UIImage(named:"profile_default.png")
            //download again if profile pic was not loaded due to internet disconnetivity.
            if ( self.panelist?.mediaID != nil && self.panelist?.mediaID != "0" && self.panelist?.mediaID != "")
            {
                self.activityIndicator.startAnimating()
                self.downloadProfileImage(mediaId: self.panelist!.mediaID.description, didChangeProfilePic: false)              //media ID coming from DB is Int so need explicit cast(description).
            }
        }
        else
        {
            let imgPath = self.getProfileImagePath()
            let fileExists = FileManager().fileExists(atPath: (imgPath))
            if fileExists
            {
                self.imageView?.image = UIImage(contentsOfFile:(imgPath))
            }
        }
       
    }

    override func viewWillDisappear(_ animated: Bool)
    {
        self.isEditable = false
    }
    
    // MARK: - DB methods
    func getPanellistProfileFromDB()
    {
       self.panelist = CollabrateDB.sharedInstance().getPanellistProfile()
        let country : OPGCountry = CollabrateDB.sharedInstance().getCountry()                //country details stored in Country table, not in Panellist Profile table.
        self.panelist?.std = country.std
        self.panelist?.countryName = country.name
    }


    // MARK: - Generic Private methods
    func openGallery()
    {
        let imagePicker = UIImagePickerController()
        imagePicker.allowsEditing = false
        imagePicker.delegate=self
        imagePicker.sourceType =  .photoLibrary
        present(imagePicker, animated: true, completion: nil)
    }
    
    func openCamera()
    {
        let imagePicker = UIImagePickerController()
        imagePicker.allowsEditing = false
        imagePicker.delegate=self
        imagePicker.sourceType =  .camera
        present(imagePicker, animated: true, completion: nil)
    }
    
    func circularImage(_ photoImageView: UIImageView?)
    {
        //photoImageView!.layer.frame = photoImageView!.layer.frame.insetBy(dx: 0, dy: 0)
        photoImageView!.layer.borderColor = UIColor.gray.cgColor
        photoImageView!.layer.cornerRadius = photoImageView!.frame.width/2
        photoImageView!.layer.masksToBounds = false
        photoImageView!.clipsToBounds = true
        photoImageView!.layer.borderWidth = 0.5
        photoImageView!.contentMode = UIViewContentMode.scaleAspectFill
    }

    func updateProfile()
    {
        if super.isOnline()==false
        {
            super.showNoInternetConnectionAlert()
            self.tableview.reloadData()
            return
        }
        DispatchQueue.global(qos: .default).async
        {
                let sdk = OPGSDK()
                do
                {
                    let nameCell = self.tableview.cellForRow(at: IndexPath(row: 0, section: 0)) as! ProfileTableViewCell
                    self.panelist?.firstName = nameCell.txtValue.text!
                    try sdk.update(self.panelist)                               //update profile to server
                    DispatchQueue.main.async
                    {
                            self.getPanellistProfileFromServer()                //get profile from server and update DB
                            self.tableview.reloadData()
                    }
                }
                catch let err as NSError
                {
                    print("Error: \(err)")
                }
        }
    }

    func getPanellistProfileFromServer()
    {
        DispatchQueue.global(qos: .default).async
        {
            let sdk = OPGSDK()
            do
            {
                self.panelist = try sdk.getPanellistProfile() as OPGPanellistProfile
                DispatchQueue.main.async
                {
                    if (self.panelist != nil)
                    {
                         DispatchQueue.global(qos: .default).async
                        {
                            CollabrateDB.sharedInstance().update(self.panelist!)                     //Update DB only after successfully updating the server.
                            DispatchQueue.main.async
                            {
                                CollabrateDB.sharedInstance().updateCountry(self.panelist?.countryName, withStd: self.panelist?.std)
                            }

                        }
                    }
                }
                    
            }
            catch let err as NSError
            {
                print("Error: \(err)")
            }
        }
    }

    

    
    func logout()
    {

        let deviceToken : String? = UserDefaults.standard.value(forKey: "DeviceTokenID") as? String
        let bgImagePath:String? = AppTheme.getLoginBGImagePath()
        self.unRegisterForAPNS(deviceToken)
        let appDomain = Bundle.main.bundleIdentifier
        UserDefaults.standard.removePersistentDomain(forName: appDomain!)
        if geoFence?.fencingDelegate != nil
        {
            geoFence?.stop()
        }
        self.deleteTempDBFolders()
        GIDSignIn.sharedInstance().signOut()                    //Sign Out when the authentication fails

        let loginManager : FBSDKLoginManager = FBSDKLoginManager()
        loginManager.logOut()

        UserDefaults.standard.set(deviceToken, forKey: "DeviceTokenID")             // Before Logout, Re-assign DeviceTokenID as we get that only for one time
        AppTheme.setLoginBGImagePath(path: bgImagePath!)         // Before Logout, Re-assign login BG image path as it is to be shown after logout
        AppTheme.setLoginBtnTextColor(color: AppTheme.appBackgroundColor())
        UserDefaults.standard.synchronize()

        OPGSDK.logout()
        _ = self.navigationController?.popViewController(animated: true)
    }

    func unRegisterForAPNS(_ deviceToken:String?) {
        let sdk = OPGSDK()
        if  deviceToken != nil {
            do {
                try sdk.unregisterNotifications(deviceToken)
                print("APNs successfully unregistered")
            } catch let error as NSError {
                print("APNs unregistration failed due to \(error.localizedDescription)")
            }
        }
    }
    
    func deleteTempDBFolders() {
        let filemanager = FileManager.default
        let documentsPath : String = NSSearchPathForDirectoriesInDomains(.documentDirectory,.userDomainMask,true)[0]
        
        let filepath = documentsPath.appending("/Framework.db")
        let filepath1 = documentsPath.appending("/Framework.db-shm")
        let filepath2 = documentsPath.appending("/Framework.db-wal")
        let panelImagePath = documentsPath.appending("/PanelImages")
        
        if filemanager.fileExists(atPath: panelImagePath) {
            do {
                try filemanager.removeItem(atPath: panelImagePath)
            } catch let err as NSError {
                print("Error occured while copying and the error is \(err.description)")
            }
            
        }
        
        if filemanager.fileExists(atPath: filepath) {
            do {
                try filemanager.removeItem(atPath: filepath)
            } catch let err as NSError {
                print("Error occured while copying and the error is \(err.description)")
            }
            
        }
        if filemanager.fileExists(atPath: filepath1) {
            do {
                try filemanager.removeItem(atPath: filepath1)
            } catch let err as NSError {
                print("Error occured while copying and the error is \(err.description)")
            }
            
        }
        if filemanager.fileExists(atPath: filepath2) {
            do {
                try filemanager.removeItem(atPath: filepath2)
            } catch let err as NSError {
                print("Error occured while copying and the error is \(err.description)")
            }
            
        }
        
        OPGSDK.setAppVersion("iOSSDK-IOS-1.0.0-O")
        OPGSDK.initialize(withUserName: "mysurveys2.0", withSDKKey:"com.onepointsurveys.mysurveys2")
    }

    func deletePreviousProfileImg(path : String?)
    {
        if(path != nil)
        {
            let filemanager = FileManager.default
            if filemanager.fileExists(atPath: path!)
            {
                do
                {
                    try filemanager.removeItem(atPath: path!)
                    print("Deleted the old profile image from temp folder")
                }
                catch let err as NSError
                {
                    print("Error occured while deleting profile pic and the error is \(err.description)")
                }
            }
        }
    }
    
    func updatePanellistProfileWithMedia(mediaID : String)
    {
        if super.isOnline()==false
        {
            self.activityIndicator.stopAnimating()
            super.showNoInternetConnectionAlert()
            return
        }
        self.panelist?.mediaID = mediaID

        DispatchQueue.global(qos: .default).async
        {
                let sdk = OPGSDK()
                do
                {
                    try sdk.update(self.panelist)                             //Updating the profile with new media ID
                    DispatchQueue.main.async
                    {
                        print("Profile with Media updated to server")
                        self.getPanellistProfileFromServer()                  //After server update is done, update DB
                    }
                }
                catch let err as NSError
                {
                    print("Error: \(err)")
                    DispatchQueue.main.async
                    {
                        self.activityIndicator.stopAnimating()
                        super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: "App Name"), alertMessage: NSLocalizedString("Oops! Unknown error. Please try again.", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))
                    }
                }
        }
    }


    
    func downloadProfileImage(mediaId : String, didChangeProfilePic :  Bool)
    {
        var previousProfileImgPath : String?
        if super.isOnline()==false
        {
            self.activityIndicator.stopAnimating()
            super.showNoInternetConnectionAlert()
            return
        }
        if(didChangeProfilePic)
        {
            previousProfileImgPath = self.getProfileImagePath()
        }


        DispatchQueue.global(qos: .default).async
            {
                let sdk = OPGSDK()
                var mediaObj : OPGDownloadMedia?
                do {
                    print("downloaded mediaId: \(mediaId)")
                    mediaObj = try sdk.downloadMediaFile(mediaId, mediaType: "jpg", fileName: "ProfileImg"+self.getDateString())
                   // mediaObj  = try sdk.downloadMediaFile(mediaId, mediaType: "jpg") as OPGDownloadMedia
                    DispatchQueue.main.async
                        {
                            if super.isOnline()==false
                            {
                                self.activityIndicator.stopAnimating()
                                super.showNoInternetConnectionAlert()
                                return
                            }
                            if (mediaObj?.isSuccess == 1)
                            {
                                self.activityIndicator.stopAnimating()
                                self.profileImgPath = mediaObj!.mediaFilePath
                                if mediaObj!.mediaFilePath != nil
                                {
                                    self.setProfileImagePath(path: mediaObj!.mediaFilePath)
                                }
                                self.imageView?.image = UIImage(contentsOfFile: self.getProfileImagePath())           //Update profile image view
                                if(didChangeProfilePic)
                                {
                                    self.deletePreviousProfileImg(path: previousProfileImgPath)                     //delete old profile pic once new one is updated
                                    self.updatePanellistProfileWithMedia(mediaID: mediaId)                          //Update Panellist Profile with new media id using sdk api
                                }
                            }
                            else
                            {
                                self.activityIndicator.stopAnimating()
                                super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: "App Name"), alertMessage: NSLocalizedString("Oops! Unknown error. Please try again.", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))
                            }
                    }
                }
                catch let err as NSError
                {
                    print("Error: \(err)")
                    DispatchQueue.main.async
                        {
                            super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: "App Name"), alertMessage: NSLocalizedString("Oops! Unknown error. Please try again.", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))
                            self.activityIndicator.stopAnimating()
                    }
                }
        }
    }
    
    func uploadProfileImage(path : String)
    {
        if super.isOnline()==false
        {
            super.showNoInternetConnectionAlert()
            return
        }
        DispatchQueue.global(qos: .default).async
        {
            let sdk = OPGSDK()
            do
            {
                self.profileImgMediaID = try sdk.uploadMediaFile(path) as String?                //Upload the new profile pic
            }
            catch let err as NSError
            {
                DispatchQueue.main.async
                {
                    print("Error: \(err)")
                    self.activityIndicator.stopAnimating()
                    super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: "App Name"), alertMessage: NSLocalizedString("Oops! Unknown error. Please try again.", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))
                }
            }
            DispatchQueue.main.async
            {
                if (self.profileImgMediaID != nil)
                {
                    self.deleteImgFromDocsDirectory()                   //delete image after upload which was written into documents directory from albums
                    print(self.profileImgMediaID!)
                    self.downloadProfileImage(mediaId: self.profileImgMediaID!, didChangeProfilePic: true)
                }
                else
                {
                    self.activityIndicator.stopAnimating()
                    super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: "App Name"), alertMessage: NSLocalizedString("Oops! Unknown error. Please try again.", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))
                }
            }
        }
    }

    func deleteImgFromDocsDirectory()
    {
        let fileManager = FileManager.default
        let documentsPath : String = NSSearchPathForDirectoriesInDomains(.documentDirectory,.userDomainMask,true)[0]
        let filepath = documentsPath.appending("/profileimage")
        if fileManager.fileExists(atPath: filepath)
        {
            do
            {
                try fileManager.removeItem(atPath: filepath)
            }
            catch let error as NSError
            {
                print("Ooops! Something went wrong in deleting Image from Documents directory: \(error)")
            }
        }
    }
    
    
    
    // MARK: - Image Picker Delegates
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any])
    {
        let documentsPath = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true)[0]
        print("documentsPath: \(documentsPath)")

        let image:UIImage = (info[UIImagePickerControllerOriginalImage] as? UIImage)!
        let documentDirectory = NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true).first!
        let photoURL          = NSURL(fileURLWithPath: documentDirectory)
        let localPath         = photoURL.appendingPathComponent("profileimage")
        let data              = UIImageJPEGRepresentation(image, 0.9)

        do
        {
            try data?.write(to: localPath!, options: Data.WritingOptions.atomic)
        }
        catch
        {
            // Catch exception here and act accordingly
        }
        if !((localPath?.absoluteString.isEmpty)!)
        {
            self.activityIndicator.startAnimating()
            self.uploadProfileImage(path: (localPath?.absoluteString)!)
        }
        self.dismiss(animated: true, completion: nil)
    }

    // MARK: - IBOutlet Action methods
    @IBAction func cameraAction(_ sender: UIButton)
    {
        if super.isOnline()
        {
            let alert = UIAlertController(title: NSLocalizedString("MySurveys", comment: "App Name"), message: NSLocalizedString("Profile image", comment: "Profile image") , preferredStyle: UIAlertControllerStyle.alert)
            alert.addAction(UIAlertAction(title: NSLocalizedString("Take Photo", comment: ""), style: UIAlertActionStyle.default, handler:{
                action in self.openCamera()
            }))
            alert.addAction(UIAlertAction(title: NSLocalizedString("Choose From Gallery", comment: "gallery"), style: UIAlertActionStyle.default, handler:{
                action in self.openGallery()
            }))
            alert.addAction(UIAlertAction(title: NSLocalizedString("Cancel", comment: ""), style: UIAlertActionStyle.destructive, handler:nil))
            self.present(alert, animated: true, completion: nil)

        }
        else
        {
            super.showNoInternetConnectionAlert()
        }
        
    }

    func isUploadResultPending() -> Bool
    {
        var surveyList:Array<Any> = []
        let panelID : String? = UserDefaults.standard.value(forKey: selectedPanelID) as? String
        if (panelID != nil)
        {
            surveyList = CollabrateDB.sharedInstance().getAllSurveys(panelID)
        }
        if surveyList.count>0
        {
            for survey in surveyList
            {
                let surveyObj = survey as! OPGSurvey
                if (surveyObj.isOffline == 1 && surveyObj.surveyDescription == "Upload Results")
                {
                    return true
                }
            }
            return false
        }
        return false
    }



    func showAlert(sender:UIButton!)
    {
        let uploadPending = self.isUploadResultPending()
        if (uploadPending)
        {
            super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: "App Name"), alertMessage: NSLocalizedString("Please upload offline survey results before logout.", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))
        }
        else
        {
            if super.isOnline()
            {
                let alert = UIAlertController(title: NSLocalizedString("MySurveys", comment: "App Name"), message: NSLocalizedString("Are you sure you want to logout?", comment: "") , preferredStyle: UIAlertControllerStyle.alert)
                alert.addAction(UIAlertAction(title: NSLocalizedString("OK", comment: "OK"), style: UIAlertActionStyle.default, handler:{
                    action in self.logout()
                }))
                alert.addAction(UIAlertAction(title: NSLocalizedString("Cancel", comment: ""), style: UIAlertActionStyle.default, handler:nil))
                self.present(alert, animated: true, completion: nil)
            }
            else
            {
                super.showNoInternetConnectionAlert()
            }
        }
    }
    
    func editProfile()
    {
        if super.isOnline()
        {
            if self.isEditable!
            {
                self.isEditable = false
                self.tabBarController?.navigationItem.rightBarButtonItem?.title=NSLocalizedString("Edit", comment: "")
                self.tableview.allowsSelection = false
                self.tableview.separatorStyle = UITableViewCellSeparatorStyle.none
                self.updateProfile()
            }
            else
            {
                self.isEditable = true
                self.tabBarController?.navigationItem.rightBarButtonItem?.title=NSLocalizedString("Save", comment: "")
                self.tableview.allowsSelection = true
                self.tableview.isScrollEnabled=true
                self.tableview.separatorStyle = UITableViewCellSeparatorStyle.singleLine
                self.tableview.reloadData()                 //to enable country btn and name txtfld after hitting edit
            }
        }
        else
        {
            if self.isEditable!                                                 //calls when internet turned off during saving
            {
                self.isEditable = false
                self.tabBarController?.navigationItem.rightBarButtonItem?.title=NSLocalizedString("Edit", comment: "")
                self.tableview.allowsSelection = false
                self.tableview.separatorStyle = UITableViewCellSeparatorStyle.none
                self.getPanellistProfileFromDB()                    //get from DB again because profile object is edited locally in the class
                self.tableview.reloadData()
            }
            super.showNoInternetConnectionAlert()
        }
    }
    

    // MARK: - Custom Delegate Method
    func userDidChangeCountry(newCountry: OPGCountry)
    {
         if (newCountry.name.characters.count>0)
        {
            self.panelist?.countryName = newCountry.name
            self.panelist?.std = newCountry.std
            
            let nameCell = self.tableview.cellForRow(at: IndexPath(row: 0, section: 0)) as! ProfileTableViewCell
            self.panelist?.firstName = nameCell.txtValue.text!
            self.tableview.reloadData()
        }
    }

    func restoreEditMode()
    {
        self.isEditable = true
        self.tableview.reloadData()
    }
    
    
    // MARK: - Tableview Delegates
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 4
    }
    
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(_ tableView: UITableView, heightForFooterInSection section: Int) -> CGFloat {
        return 0.01
    }


    
    public func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        
        switch indexPath.row {
        case 0:
            let tableViewCell = tableView.dequeueReusableCell(withIdentifier: "Profile") as! ProfileTableViewCell
            if self.panelist?.firstName==nil
            {
                tableViewCell.fillCell(title: titleArray[indexPath.row], value : "", tagIdentifier: 1)
            }
            else
            {
                tableViewCell.fillCell(title: titleArray[indexPath.row], value : (panelist?.firstName)!, tagIdentifier: 1)
            }
            if isEditable! {
                tableViewCell.txtValue.isEnabled=true
                tableViewCell.txtValue.perform(#selector(becomeFirstResponder), with: nil , afterDelay: 0)
            }
            else{
                tableViewCell.txtValue.isEnabled=false
                tableViewCell.txtValue.resignFirstResponder()
                //self.view.endEditing(true)
            }
            tableViewCell.selectionStyle = UITableViewCellSelectionStyle.none
            return tableViewCell

        case 1:
            let tableViewCell = tableView.dequeueReusableCell(withIdentifier: "Country") as! ProfileTableViewCountryCell
            if self.panelist?.countryName==nil
            {
                tableViewCell.fillCell(title: titleArray[indexPath.row], value: "")
            }
            else
            {
                tableViewCell.fillCell(title: titleArray[indexPath.row], value: (self.panelist?.countryName)!)
            }
            tableViewCell.selectionStyle = UITableViewCellSelectionStyle.none
            return tableViewCell

        case 2:
            let tableViewCell = tableView.dequeueReusableCell(withIdentifier: "Profile") as! ProfileTableViewCell
            tableViewCell.separatorInset = UIEdgeInsetsMake(0, 0, 0, 1000)
            if self.panelist?.email==nil
            {
                tableViewCell.fillCell(title: titleArray[indexPath.row], value : "", tagIdentifier: 1)
            }
            else
            {
                tableViewCell.fillCell(title: titleArray[indexPath.row], value : (panelist?.email)!, tagIdentifier: 1)
            }
            tableViewCell.txtValue.isEnabled=false
            tableViewCell.selectionStyle = UITableViewCellSelectionStyle.none
            return tableViewCell

        case 3:
            let tableViewCell = tableView.dequeueReusableCell(withIdentifier: "Logout") as! ProfileLogoutTableViewCell
            tableViewCell.btnLogout.addTarget(self, action: #selector(showAlert(sender:)), for:UIControlEvents.touchUpInside)
            tableViewCell.btnLogout.setTitle(NSLocalizedString("Log out", comment: ""), for: .normal)
            tableViewCell.selectionStyle = UITableViewCellSelectionStyle.none
            return tableViewCell
            
        default:
            let tableViewCell = tableView.dequeueReusableCell(withIdentifier: "Profile") as! ProfileTableViewCell
            return tableViewCell
        }

    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath)
    {
        if indexPath.row==1
        {
            self.performSegue(withIdentifier: "ShowCountries", sender: nil)
        }
    }

    // MARK: - Segue Operations
    override func prepare(for segue: UIStoryboardSegue, sender: Any?)
    {
        if segue.identifier == "ShowCountries"
        {
            let viewController : CountriesListViewController = segue.destination as! CountriesListViewController
            viewController.delegate=self
        }
    }

}
