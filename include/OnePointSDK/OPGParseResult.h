//
//  OPGParseResult.h
//  OnePointSDK
//
//  Created by OnePoint Global on 30/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OPGSurvey.h"
#import "OPGAuthenticate.h"
#import "OPGScript.h"
#import "OPGForgotPassword.h"
#import "OPGChangePassword.h"
#import "OPGDownloadMedia.h"
#import "OPGPanellistProfile.h"
#import "OPGPanelPanellist.h"
#import "OPGPanel.h"
#import "OPGTheme.h"
#import "OPGSurveyPanel.h"
#import "OPGGeoFencingModel.h"
#import "OPGMSGeoFencingModel.h"
#import "OPGPanellistPanel.h"
#import "OPGCountry.h"

@interface OPGParseResult : NSObject
-(NSMutableArray*)parseSurveys:(NSArray*)responseList error:(NSError **)error;
-(OPGAuthenticate*) parseAuthenticationResult : (NSDictionary*) values;
-(OPGScript*) parseAndDownloadScript : (NSDictionary*) scriptData forSurvey : (OPGSurvey*)survey error:(NSError **)error;
-(OPGForgotPassword*) parseForgotPassword : (NSDictionary*) responseData;
-(OPGChangePassword*) parseChangePassword : (NSDictionary*) responseData;
-(OPGPanellistProfile*)parsePanelistProfile : (NSDictionary*)panelistProfile;
-(OPGCountry*) parseCountry : (NSDictionary*) countryJson;
-(BOOL) parseUpdatePanelistProfile : (NSDictionary*)panelistProfile;
-(NSMutableArray*) parsePanelPanelist : (NSArray*) panelistPanels;
-(NSMutableArray*)parsePanels:(NSArray*)panelArray;
-(NSMutableArray*) parseThemes : (NSArray*)themeArray;
-(NSMutableArray*) parseSurveyPanels : (NSArray*) surveyPanelArray;
-(OPGPanellistPanel*) parsePanellistPanel : (NSDictionary*) panellistPanel;
-(NSMutableArray*)parseGeoFencingSurvey:(NSArray*)responseList error:(NSError **)error;
-(NSMutableArray*)parseMSGeoFencing:(NSArray*)responseList error:(NSError **)error;
-(BOOL) parseNotificationResponse : (NSDictionary*) responseResult;
-(NSMutableArray*)parseListOfCountries:(NSArray*)responseList error:(NSError **)error;
@end
