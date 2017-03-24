/*
 Licensed to the Apache Software Foundation (ASF) under one
 or more contributor license agreements.  See the NOTICE file
 distributed with this work for additional information
 regarding copyright ownership.  The ASF licenses this file
 to you under the Apache License, Version 2.0 (the
 "License"); you may not use this file except in compliance
 with the License.  You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing,
 software distributed under the License is distributed on an
 "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied.  See the License for the
 specific language governing permissions and limitations
 under the License.
 */

#import <UIKit/UIKit.h>
#import <Foundation/NSJSONSerialization.h>
#import "OPGAvailability.h"
#import "OPGInvokedUrlCommand.h"
#import "OPGCommandDelegate.h"
#import "OPGCommandQueue.h"
#import "OPGWhitelist.h"
#import "OPGScreenOrientationDelegate.h"
#import "OPGPlugin.h"
#import "OPGSurvey.h"
#import <OnePoint.Runtime/IosRuntimeInteractor.h>
#import <OnePoint.Runtime/WebPlayer.h>
#import <OnePoint.Runtime/Controller.h>
#import <OnePoint.Runtime/WebSession.h>
#import <OnePoint.Runtime/InterviewSession.h>


@interface OPGBaseController : UIViewController <UIWebViewDelegate, OPGScreenOrientationDelegate, IosRuntimeInteractor>
{
    @protected
    id <OPGCommandDelegate> _commandDelegate;
    @protected
    OPGCommandQueue* _commandQueue;
    NSString* _userAgent;
    NSString* surveyReference;

}

@property (nonatomic, strong) IBOutlet UIWebView* webView;

@property (nonatomic, readonly, strong) NSMutableDictionary* pluginObjects;
@property (nonatomic, readonly, strong) NSDictionary* pluginsMap;
@property (nonatomic, readonly, strong) NSMutableDictionary* settings;
@property (nonatomic, readonly, strong) NSXMLParser* configParser;
@property (nonatomic, readonly, strong) OPGWhitelist* whitelist; // readonly for public
@property (nonatomic, readonly, assign) BOOL loadFromString;

@property (nonatomic, readwrite, copy) NSString* wwwFolderName;
@property (nonatomic, readwrite, copy) NSString* startPage;
@property (nonatomic, readonly, strong) OPGCommandQueue* commandQueue;
@property (nonatomic, readonly, strong) id <OPGCommandDelegate> commandDelegate;



/**
 The complete user agent that Cordova will use when sending web requests.
 */
@property (nonatomic, readonly) NSString* userAgent;

/**
 The base user agent data that Cordova will use to build its user agent.  If this
 property isn't set, Cordova will use the standard web view user agent as its
 base.
 */
@property (nonatomic, readwrite, copy) NSString* baseUserAgent;

+ (NSDictionary*)getBundlePlist:(NSString*)plistName;
+ (NSString*)applicationDocumentsDirectory;

- (void)printMultitaskingInfo;
- (void)createGapView;
- (UIWebView*)newCordovaViewWithFrame:(CGRect)bounds;

- (void)javascriptAlert:(NSString*)text;
- (NSString*)appURLScheme;

- (NSArray*)parseInterfaceOrientations:(NSArray*)orientations;
- (BOOL)supportsOrientation:(UIInterfaceOrientation)orientation;

- (id)getCommandInstance:(NSString*)pluginName;
- (void)registerPlugin:(OPGPlugin*)plugin withClassName:(NSString*)className;
- (void)registerPlugin:(OPGPlugin*)plugin withPluginName:(NSString*)pluginName;

- (BOOL)URLisAllowed:(NSURL*)url;
- (void)processOpenUrl:(NSURL*)url;

-(void)loadSurvey:(NSString *)surveyRef;
-(void)loadSurvey:(NSString *)surveyRef withDictionary:(NSDictionary *)values;

-(void)loadOfflineSurvey:(NSString*)scriptPath surveyName:(NSString*)surveyName surveyID:(NSNumber*)surveyID panelID:(NSNumber*)panelID panellistID:(NSNumber*)panellistID;


@end
