//
//  AboutUsViewController.swift
//  MySurveys2.0
//
//  Created by Chinthan on 13/06/16.
//  Copyright © 2016 Chinthan. All rights reserved.
//

import UIKit

class AboutUsViewController: RootViewController, UIWebViewDelegate
{
    @IBOutlet weak var webView: UIWebView!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    
    var urlString : String?
    var pageTitle : String?
    
    // MARK: - View Delegate Methods
    override func viewDidLoad()
    {
        super.viewDidLoad()
        self.webView.delegate=self
        self.title = pageTitle
        self.activityIndicator.color = AppTheme.appBackgroundColor()
        if super.isOnline()
        {
            self.activityIndicator.startAnimating()
            let url = NSURL(string:urlString!)
            webView.loadRequest(NSURLRequest(url:url as! URL) as URLRequest)
        }
        else
        {
            super.showNoInternetConnectionAlert()
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    // MARK: - Webview Delegates
    func webViewDidStartLoad(_ webView: UIWebView)
    {
        
    }
    
    func webViewDidFinishLoad(_ webView: UIWebView)
    {
        self.activityIndicator.stopAnimating()
    }
}
