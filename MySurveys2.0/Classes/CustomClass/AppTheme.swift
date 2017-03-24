//
//  AppTheme.swift
//  MySurveys2.0
//
//  Created by Manjunath on 15/02/17.
//  Copyright © 2017 Chinthan. All rights reserved.
//

import UIKit

let EMPTY_STRING = ""

class AppTheme: NSObject
{
    static var theme : ThemeModel?

    static func initThemeModel(theme : NSDictionary) -> ThemeModel
    {
        let actionBtn: String? = theme.value(forKey: "Actionbtn") as! String?
        let headerLogo: String? =  theme.value(forKey: "Headerlogo") as! String?
        let linksColor: String? =  theme.value(forKey: "Linkscolor") as! String?
        let loginBackground: String? =  theme.value(forKey: "Loginbackground") as! String?
        let logoText: String? =  theme.value(forKey: "Logotext") as! String?
        let newTheme = ThemeModel(actionBtn: actionBtn,headerLogo: headerLogo,linksColor: linksColor, loginBackground: loginBackground,logoText: logoText)
        return newTheme
    }

    static func downloadThemeImage(mediaId : String, isLoginBGImage:Bool, fileName:String)
    {
        DispatchQueue.global(qos: .default).async
            {
                let sdk = OPGSDK()
                var mediaObj : OPGDownloadMedia?
                do {
                    print("downloaded login screen mediaId: \(mediaId)")

                    mediaObj  = try sdk.downloadMediaFile(mediaId, mediaType: "jpg", fileName:fileName) as OPGDownloadMedia
                    DispatchQueue.main.async
                        {
                            if (mediaObj?.isSuccess == 1)
                            {
                                if mediaObj!.mediaFilePath != nil
                                {
                                     if (isLoginBGImage)
                                     {
                                           self.setLoginBGImagePath(path: (mediaObj?.mediaFilePath)!)
                                     }
                                    else
                                    {
                                            self.setHeaderLogoImagePath(path: (mediaObj?.mediaFilePath)!)
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

    static func setCurrentTheme(theme : NSDictionary)
    {
        if ((theme.count)>0)
        {
            let keys = theme.allKeys
            if (keys.count==5)
            {
                //Construct theme object
                self.theme = self.initThemeModel(theme: theme)
                let panelName = UserDefaults.standard.value(forKey: "SelectedPanelName") as? String
                if (Int((self.theme?.headerLogo)!)!>0)
                {
                    self.downloadThemeImage(mediaId: (self.theme?.headerLogo)!, isLoginBGImage:false, fileName:(panelName?.appending("ThemeHeaderLogo"))!)
                }
                if (Int((self.theme?.loginBackground)!)!>0)
                {
                    self.downloadThemeImage(mediaId: (self.theme?.loginBackground)!, isLoginBGImage: true, fileName:(panelName?.appending("ThemeLoginBG"))!)
                }
            }
            else if (keys.count==15)                            //Not a new adminsuite theme
            {
                self.setLoginBGImagePath(path: EMPTY_STRING)                //defaultBG image
                self.setHeaderLogoImagePath(path: EMPTY_STRING)        //default header logo image
                self.theme = nil                                        //no theme
            }
        }
    }

    // Creates a UIColor from a Hex string.
    static func colorWithHexString (hex:String) -> UIColor {
        var cString:String = hex.trimmingCharacters(in: CharacterSet.whitespacesAndNewlines).uppercased()

        if cString.hasPrefix("#") {
            cString = (cString as NSString).substring(from: 1)
        }
        if cString.characters.count != 6 {
            return UIColor.gray
        }
        var rgbValue : UInt32 = 0
        Scanner(string: cString).scanHexInt32(&rgbValue)

        return UIColor(
            red: CGFloat((rgbValue & 0xFF0000) >> 16) / 255.0,
            green: CGFloat((rgbValue & 0x00FF00) >> 8) / 255.0,
            blue: CGFloat(rgbValue & 0x0000FF) / 255.0,
            alpha: CGFloat(1.0)
        )
    }

    static func appBackgroundColor() -> UIColor
    {
        if (self.theme==nil)
        {
            return UIColor.appBGColor()                 //default color
        }
        else
        {
            return self.colorWithHexString(hex: (self.theme?.actionBtn)!)
        }
    }

    static func getLoginBGImagePath() -> String
    {
        let bgImagePath:String? = UserDefaults.standard.value(forKey: "LoginBGImagePath") as? String
        if bgImagePath==nil || (bgImagePath?.isEmpty)!
        {
            return EMPTY_STRING
        }
        else
        {
             //UDID of the device tmp folder path changes on every re-run
            let filePath:String? = UserDefaults.standard.value(forKey: "LoginBGImagePath") as? String
            let filename =  NSURL(string: filePath!)?.lastPathComponent
            let tempDirURL = NSURL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(filename!)        //get image name, construct path and return
            return (tempDirURL?.path)!
        }
    }

    static func setLoginBGImagePath(path : String)
    {
        UserDefaults.standard.set(path, forKey: "LoginBGImagePath")
    }

    static func getHeaderLogoImagePath() -> String
    {
        let headerImgPath:String? = UserDefaults.standard.value(forKey: "HeaderLogoImagePath") as? String
        if headerImgPath==nil || (headerImgPath?.isEmpty)!
        {
            return EMPTY_STRING
        }
        else
        {
            //UDID of the device tmp folder path changes on every re-run
            let filePath = (UserDefaults.standard.object(forKey: "HeaderLogoImagePath") as? String)!
            let filename =  NSURL(string: filePath)?.lastPathComponent
            let tempDirURL = NSURL(fileURLWithPath: NSTemporaryDirectory()).appendingPathComponent(filename!)        //get image name, construct path and return
            return (tempDirURL?.path)!

        }
        
    }


    static func setHeaderLogoImagePath(path : String)
    {
        UserDefaults.standard.set(path, forKey: "HeaderLogoImagePath")
    }

    static func getLoginBtnTextColor() -> UIColor
    {
        return UserDefaults.standard.colorForKey("LoginBtnTextColor")!
    }

    static func setLoginBtnTextColor(color : UIColor)
    {
        UserDefaults.standard.setColor(color, forKey: "LoginBtnTextColor")
    }
    
    
}
