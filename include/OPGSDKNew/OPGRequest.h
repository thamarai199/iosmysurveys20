//
//  OPGRequest.h
//  OnePointSDK
//
//  Created by OnePoint Global on 30/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OPGPanelistProfile.h"

@interface OPGRequest : NSObject
- (NSMutableDictionary*) getAuthEntity : (NSString*)UserName password:(NSString*) password AppVersion:(NSString*) AppVersion;
- (NSMutableDictionary*) getSurveyEntity : (NSString*)uniqueId panelId:(NSString*)panelId;
- (NSMutableDictionary*) getScriptEntity : (NSString*)uniqueId surveyId:(NSString*)surveyId;
- (NSMutableDictionary*) getForgotPasswordEntity : (NSString*)mailId AppVersion:(NSString*) AppVersion;
- (NSMutableDictionary*) getChangePasswordEntity : (NSString*)uniqueId currentPassword:(NSString*)currentPassword newPassword:(NSString*)newPassword;
- (NSMutableDictionary*) getPanelistProfileEntity : (NSString*)uniqueId;
-(NSMutableDictionary*) getPanelistPanelEntity : (NSString*)uniqueId;
-(NSMutableDictionary*) getUpdatePanelistProfileEntity : (NSString*)uniqueId panelistProfile : (OPGPanelistProfile*) panelistProfile;
-(NSMutableDictionary*) getNotificationEntity : (NSString*)uniqueId deviceToken:(NSString*)deviceToken appVersion:(NSString*)appVersion;
-(NSMutableDictionary*) getGeoFencingEntity:(NSString*)uniqueID withSurveyIDs:(NSMutableString*)surveyIDs withLatitude:(NSString*)Latitude withLongitude:(NSString*)Longitude;
@end
