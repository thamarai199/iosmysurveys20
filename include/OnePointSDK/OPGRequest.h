//
//  OPGRequest.h
//  OnePointSDK
//
//  Created by OnePoint Global on 30/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OPGPanellistProfile.h"

@interface OPGRequest : NSObject
-(NSMutableDictionary*) getAuthEntity : (NSString*)UserName password:(NSString*) password AppVersion:(NSString*) AppVersion;
-(NSMutableDictionary*) getGoogleAuthEntity : (NSString*)tokenID AppVersion:(NSString*) appVersion;
-(NSMutableDictionary*) getFacebookAuthEntity : (NSString*)tokenID AppVersion:(NSString*) appVersion;
-(NSMutableDictionary*) getSurveyEntity : (NSString*)uniqueId panelId:(NSString*)panelId;
-(NSMutableDictionary*) getScriptEntity : (NSString*)uniqueId surveyRef:(NSString*)surveyRef;
-(NSMutableDictionary*) getForgotPasswordEntity : (NSString*)mailId AppVersion:(NSString*) AppVersion;
-(NSMutableDictionary*) getChangePasswordEntity : (NSString*)uniqueId currentPassword:(NSString*)currentPassword newPassword:(NSString*)newPassword;
-(NSMutableDictionary*) getPanelistProfileEntity : (NSString*)uniqueId;
-(NSMutableDictionary*) getPanelistPanelEntity : (NSString*)uniqueId;
-(NSMutableDictionary*) getUpdatePanelistProfileEntity : (NSString*)uniqueId panelistProfile : (OPGPanellistProfile*) panelistProfile;
-(NSMutableDictionary*) getNotificationEntity : (NSString*)uniqueId deviceToken:(NSString*)deviceToken appVersion:(NSString*)appVersion;
-(NSMutableDictionary*) getGeoFencingEntity:(NSString*)uniqueID withSurveyIDs:(NSMutableString*)surveyIDs withLatitude:(NSString*)Latitude withLongitude:(NSString*)Longitude;
-(NSMutableDictionary*) getCountryEntity : (NSString*)uniqueId;
@end
