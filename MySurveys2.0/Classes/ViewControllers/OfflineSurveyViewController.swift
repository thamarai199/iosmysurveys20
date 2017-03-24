//
//  OfflineSurveyViewController.swift
//  MySurveys2.0
//
//  Created by ThamaraiD on 07/11/16.
//  Copyright © 2016 Chinthan. All rights reserved.
//

import Foundation

class OfflineSurveyViewController : RootViewController
{

    @IBOutlet weak var lblSurveyName: UILabel?
    @IBOutlet weak var lblSurveyStatus : UILabel?
    @IBOutlet weak var lblSurveyDate: UILabel?
    @IBOutlet weak var lblSurveyETA: UILabel?
    @IBOutlet weak var lblNumberOfTimes: UILabel!
    @IBOutlet weak var btnTakeSurvey : UIButton!
    @IBOutlet weak var btnTakeTrail : UIButton!
    @IBOutlet weak var btnUploadResults : UIButton!
    @IBOutlet weak var lblCounter: UILabel?
    @IBOutlet weak var dateView : UIView?
    @IBOutlet weak var approxTimeView : UIView?
    @IBOutlet weak var numberOfTimesView : UIView?
    @IBOutlet weak var progressView: UIProgressView!
    
    var surveyID : NSNumber?
    var surveySelected : OPGSurvey?
    var selectedSurveyIndex : Int?
    var surveyCounter : NSNumber?
    var totalNumberOfFiles = 0
    var numberOfFilesPending  = 0
    var numberOfFilesUploaded = 0

    // MARK: - View Delegate Methods
    override func viewDidLoad()
    {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        self.navigationController?.hidesBarsOnSwipe = false
        NotificationCenter.default.addObserver(self, selector: #selector(self.updateProgressBar(_:)), name: NSNotification.Name(rawValue: "NotificationIdentifier"), object: nil)
    }
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewWillAppear(_ animated: Bool)
    {
        super.viewWillAppear(animated)
        self.navigationController?.navigationBar.topItem?.title = NSLocalizedString("Back", comment: "Back")
        self.navigationItem.title = NSLocalizedString("Survey", comment: "Survey")
        self.progressView.progressTintColor = AppTheme.appBackgroundColor()
        self.btnUploadResults.isUserInteractionEnabled = true
        //self.navigationController?.navigationBar.topItem?.title = self.back
        
        let array : Array<Any>? = UserDefaults.standard.value(forKey: "downloadSurveysArray") as? Array<Any>
        if ((array?.count)! > 0) {
            // show from passed content
            setUpViews()
            
        } else {
            // take from dB
            self.surveySelected = CollabrateDB.sharedInstance().getSurvey(surveyID)
            setUpViews()
            
        }

    /**    if surveyID != nil {                     thamarai changes
            self.surveySelected = CollabrateDB.sharedInstance().getSurvey(surveyID)
            setUpViews()
        }**/
        self.setOfflineCounter()
    }

    // MARK: - Generic Private Methods
     func updateSurveyPendingInDB() {
      //  CollabrateDB.sharedInstance().updateSurvey(surveySelected?.surveyID, withStatus: "Pending")      Thamarai dB
        CollabrateDB.sharedInstance().updateSurvey(surveySelected?.surveyID, withStatus: "Pending", withDownloadStatus: 99)
        
    }

    func setBorder(view : UIView)
    {
        view.layer.borderWidth = 1
        let borderColor = UIColor(red:215/255.0, green:216/255.0, blue:217/255.0, alpha: 1.0)

        view.layer.borderColor = borderColor.cgColor
    }
    
    func setUpViews() {
        btnUploadResults.setTitleColor(AppTheme.appBackgroundColor(), for: .normal)
        btnTakeTrail.setTitleColor(AppTheme.appBackgroundColor(), for: .normal)
        self.view.layoutIfNeeded()
        btnTakeSurvey.backgroundColor = AppTheme.appBackgroundColor()
        btnTakeSurvey.layer.cornerRadius = 0.5 * btnTakeSurvey.bounds.size.width
        
        lblSurveyName?.text = surveySelected?.surveyName
        lblSurveyStatus?.text = surveySelected?.surveyDescription
        
        if ((self.surveySelected?.startDate == nil) || (self.surveySelected?.endDate == nil))
        {
            lblSurveyDate?.text = "Unscheduled"                 //temporary for unscheduled surveys
        }
        else
        {
            let dateRange = self.formatDate(dateString: (self.surveySelected?.startDate)!) + " - " + self.formatDate(dateString: (self.surveySelected?.endDate)!)
            lblSurveyDate?.text = dateRange
        }
        
        
        let approxString = NSLocalizedString("Approximately", comment: "") + " " + (self.surveySelected?.estimatedTime.stringValue)! + " " +  NSLocalizedString("min", comment: "")
        lblSurveyETA?.text = approxString
        lblNumberOfTimes?.text = NSLocalizedString("Number of times taken", comment: "")
        
        
        
        self.setBorder(view: self.dateView!)
        self.setBorder(view: self.approxTimeView!)
        self.setBorder(view: self.numberOfTimesView!)
        
        self.view.layoutIfNeeded()
    }

    func setOfflineCounter()
    {
        var count : NSNumber = 0
        DispatchQueue.global(qos: .default).async
            {
                let sdk = OPGSDK()

                count = sdk.getOfflineSurveyCount(self.surveySelected?.surveyID)
                DispatchQueue.main.async
                    {
                        self.surveyCounter = count
                        self.lblCounter?.text = self.surveyCounter?.stringValue               //set counter
                        if (self.surveyCounter?.intValue)! > 0
                        {
                           // CollabrateDB.sharedInstance().updateSurvey(self.surveySelected?.surveyID, withStatus: "Upload Results")  thamarai dB
                            CollabrateDB.sharedInstance().updateSurvey(self.surveySelected?.surveyID, withStatus: "Upload Results", withDownloadStatus: 99)
                        }
                }
        }
    }

    func formatDate(dateString : String) -> String
    {
        // create dateFormatter with UTC time format
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "yyyy-MM-dd HH:mm:ss"
        let date = dateFormatter.date(from: dateString)                   // create   date from string
        dateFormatter.dateFormat = "d MMM yyyy"
        let timeStamp = dateFormatter.string(from: date!)
        return timeStamp
    }

    func updateProgressBar(_ notification: NSNotification)
    {
        print("methodOfReceivedNotification\(notification.userInfo)")
        guard let userInfo = notification.userInfo,
            let percentage  = userInfo["percentage"] as? Float,
            let _ = userInfo["numberOfFilesPending"] as? Int else {
                print("No userInfo found in notification")
                return
        }

        DispatchQueue.main.async
            {
                self.progressView.progress = percentage
                if percentage == 1.0
                {
                    self.progressView.progress = 0.0
                    //change survey status in the present screen
                    self.lblSurveyStatus?.text = NSLocalizedString("Completed", comment: "")
                    self.setOfflineCounter()
                    self.btnUploadResults.isUserInteractionEnabled = true
                }
        }
    }


    // MARK: - IBAction Methods
     @IBAction func takeSurveyAction(_ sender: UIButton)
    {
        let survey:OPGSurvey = CollabrateDB.sharedInstance().getSurvey(surveySelected?.surveyID)
        print("Downloaded\(survey)")
        if(survey.isOfflineDownloaded == 2){
            self.updateSurveyPendingInDB()
            self.performSegue(withIdentifier: "takeOfflineSurvey", sender: self)
        }
        else{
            super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: ""), alertMessage:NSLocalizedString("Downloading. Please wait!", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))

        }
    }

    @IBAction func uploadResults(_ sender: Any)
    {
        if super.isOnline()
        {
            if (self.surveyCounter == 0 || self.surveyCounter==nil)             //check if survey is taken at least once
            {
                super.showAlert(alertTitle: NSLocalizedString("MySurveys", comment: ""), alertMessage: NSLocalizedString("Please take the survey before uploading results.", comment: ""), alertAction: NSLocalizedString("OK", comment: "OK"))
                return
            }
            DispatchQueue.main.async
            {
                self.progressView.progress = 0.05             //show some inital progress to make the progress bar visible
            }
            self.btnUploadResults.isUserInteractionEnabled = false              //disable upload button until upload is over to avoid double tap.
            DispatchQueue.global(qos: .default).async
            {
                    let upload = UploadSurvey.sharedInstance
                    let panellistID : String = UserDefaults.standard.value(forKey: "PanelListID") as! String
                    upload.uploadOfflineSurvey(self.surveySelected!.surveyID, panelistID:panellistID,index:self.selectedSurveyIndex!)
            }
        }
        else
        {
            super.showNoInternetConnectionAlert()
        }
    }
    
    // MARK: - Navigation
    
    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if(segue.identifier == "takeOfflineSurvey")
        {
            let viewController : SurveyViewController = segue.destination as! SurveyViewController
            viewController.surveyReference = surveySelected?.surveyReference
            viewController.surveySelected = self.surveySelected
            //viewController.delegate=self
        }
    }
}
