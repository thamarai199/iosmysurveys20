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
#import "OPGPanelistProfile.h"
#import "OPGPanelPanelist.h"
#import "OPGPanel.h"
#import "OPGTheme.h"
#import "OPGSurveyPanel.h"
#import "OPGGeoFencingModel.h"

@interface OPGParseResult : NSObject
- (NSMutableArray*)parseSurveys:(NSArray*)responseList error:(NSError **)error;
- (OPGAuthenticate*) parseAuthenticationResult : (NSDictionary*) values;
-(OPGScript*) parseAndDownloadScript : (NSDictionary*) scriptData forSurveyId : (NSString*)surveyId error:(NSError **)error;
-(OPGForgotPassword*) parseForgotPassword : (NSDictionary*) responseData;
-(OPGChangePassword*) parseChangePassword : (NSDictionary*) responseData;
-(OPGPanelistProfile*)parsePanelistProfile : (NSDictionary*)panelistProfile;
-(BOOL) parseUpdatePanelistProfile : (NSDictionary*)panelistProfile;
-(NSMutableArray*) parsePanelPanelist : (NSArray*) panelistPanels;
-(NSMutableArray*)parsePanels:(NSArray*)panelArray;
-(NSMutableArray*) parseThemes : (NSArray*)themeArray;
-(NSMutableArray*) parseSurveyPanels : (NSArray*) surveyPanelArray;
-(NSMutableArray*)parseGeoFencingSurvey:(NSArray*)responseList error:(NSError **)error;
-(BOOL) parseNotificationResponse : (NSDictionary*) responseResult;
@end
