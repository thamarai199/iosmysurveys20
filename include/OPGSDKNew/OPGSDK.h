//
// Copyright (c) 2016 OnePoint Global Ltd. All rights reserved.
//
// This code is licensed under the OnePoint Global License.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#import <Foundation/Foundation.h>
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


@interface OPGSDK : NSObject

/*!
 @brief It initializes the OnePoint SDK with Username and SDK Key.
 @discussion This method is to intialize the SDK .
 This has to be initialised in AppDelegate didFinishLaunchingWithOptions method, As it is a static method just call OnePointSDK and initialize
 @param  sdk_UserName The input value is the admin username.
 @param  sdk_KEY The input value is the admin sdk key.
 @code
 [OnePointSDK initializeWithUserName:@"YOUR_ADMIN_NAME" withSDKKey:@"YOUR_ADMIN_KEY"];
 @endcode
 @return void.
 */
+(void)initializeWithUserName:(NSString *)sdk_UserName withSDKKey:(NSString *)sdk_KEY;

/*!
 @brief This method returns an OPGAuthenticate object.
 @discussion This method is used to authenticate the user.
 This has to be invoked with the SDK object.
 @param  username panel username
 @param  password panel password
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.authObj = [sdk authenticate:@"USERNAME" password:@"PASSWORD" error:&error];
 @endcode
 @return OPGAuthenticate.
 */
-(OPGAuthenticate*)authenticate:(NSString*)username password:(NSString*)password error:(NSError **)error;

/*!
 @brief This method returns an array of surveys.
 @discussion This method is to get the list of surveys for a particular panel ID.
 This has to be invoked with the SDK object.
 @param  panelId Panel ID
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.surveyList = [sdk getUserSurveyList:@"PANEL_ID" error:&error];
 @endcode
 @return NSArray.
 */
-(NSArray *)getUserSurveyListWithPanelID:(NSString*)panelId error:(NSError **)error;

/*!
 @brief This method returns an array of surveys.
 @discussion This method is to get the list of surveys.
 This has to be invoked with the SDK object.
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.surveyList = [sdk getUserSurveyList:&error];
 @endcode
 @return NSArray.
 */
-(NSArray *)getUserSurveyList:(NSError **)error;

/*!
 @brief This method downloads the survey script file.
 @discussion This method is to download the survey script file..
 This has to be invoked with the SDK object.
 @param  surveyReference Survey Reference
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.scriptResult = [sdk getScript:@"SURVEY_ID" error:&error];
 @endcode
 @return OPGScript.
 */
-(OPGScript*)getScript:(NSString*)surveyReference error:(NSError **)error;

/*!
 @brief This method uploads the media file.
 @discussion This method is to upload the media file and it returns the media ID of the uploaded file.
 This has to be invoked with the SDK object.
 @param  mediaPath Path of the media file
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.mediaId = [sdk uploadMediaFile:@"MEDIA_PATH" error:&error];
 @endcode
 @return NSString.
 */
-(NSString*)uploadMediaFile:(NSString*) mediaPath error:(NSError **)error;

/*!
 @brief This method downloads the media file.
 @discussion This method is to download the media file and it returns the status.
 This has to be invoked with the SDK object.
 @param  mediaId ID of the media file
 @param  mediaType Type of the media file
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.downloadMediaResult = [sdk downloadMediaFile:@"MEDIA_ID" mediaType:@"MEDIA_TYPE" error:&error];
 @endcode
 @return OPGDownloadMedia.
 */
-(OPGDownloadMedia*)downloadMediaFile:(NSString*)mediaId mediaType:(NSString*)mediaType error:(NSError **)error;

/*!
 @brief This method sends the password reset link to your registered email.
 @discussion This method is to send the password reset link to your registered email..
 This has to be invoked with the SDK object.
 @param  mailId registered email
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.forgotPassword = [sdk forgotPassword:@"YOUR_EMAILID" error:&error];
 @endcode
 @return OPGForgotPassword.
 */
-(OPGForgotPassword*)forgotPassword:(NSString*)mailId error:(NSError **)error;

/*!
 @brief This method resets the password.
 @discussion This method is used to reset the password.
 This has to be invoked with the SDK object.
 @param  currentPassword Existing password
 @param  newPassword new password
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.changePassResult = [sdk changePassword:@"CURRENT_PASSWORD" newPassword:@"NEW_PASSWORD" error:&error];
 @endcode
 @return OPGChangePassword.
 */
-(OPGChangePassword*)changePassword:(NSString*)currentPassword newPassword:(NSString*)newPassword error:(NSError **)error;

/*!
 @brief This method returns the panelist profile.
 @discussion This method is used to get the panelist profile.
 This has to be invoked with the SDK object.
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.panelistProfile = [sdk getPanelistProfile:&error];
 @endcode
 @return OPGPanelistProfile
 */
-(OPGPanelistProfile*)getPanelistProfile:(NSError **)error;

/*!
 @brief This method updates the panelist profile.
 @discussion This method updates the panelist profile
 This has to be invoked with the SDK object.
 @param  panelistProfile panelist profile that is to be updated
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.updatePanelistProfile = [sdk updatePanelistProfile:panelistProfile error:&error];
 @endcode
 @return BOOL
 */
-(BOOL)updatePanelistProfile:(OPGPanelistProfile*)panelistProfile error:(NSError **)error;

/*!
 @brief This method returns the array of Panelpanelist object.
 @discussion This method is used to get the panelpanelist.
 This has to be invoked with the SDK object.
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.panelPanelist = [sdk getPanelPanelist:&error];
 @endcode
 @return NSArray
 */
-(NSArray*)getPanelPanelist:(NSError **)error;

/*!
 @brief This method returns the array of panel object.
 @discussion This method is used to get the panels.
 This has to be invoked with the SDK object.
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.panels = [sdk getPanels:&error];
 @endcode
 @return NSArray
 */
-(NSArray*)getPanels:(NSError **)error;

/*!
 @brief This method returns the array of Theme object.
 @discussion This method is used to get the themes.
 This has to be invoked with the SDK object.
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.themes = [sdk getThemes:&error];
 @endcode
 @return NSArray
 */
-(NSArray*)getThemes:(NSError **)error;

/*!
 @brief This method returns the array of surveypanel object.
 @discussion This method is used to get the surveypanels.
 This has to be invoked with the SDK object.
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 self.surveyPanels = [sdk getSurveyPanels:&error];
 @endcode
 @return NSArray
 */
-(NSArray*)getSurveyPanels:(NSError **)error;

/*!
 @brief This method uploads the offline survey results.
 @discussion This method is used to upload the offline survey.
 This has to be invoked with the SDK object.
 @param  surveyReference survey Reference
 @param  panelistId Panelist ID
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 [sdk uploadResults:@"SURVEY_ID" panelistId:@"PANELIST_ID" error:&error]; 
 @endcode
 @return void.
 */
-(void)uploadResults :(NSString*)surveyReference panelistId:(NSString*)panelistId error:(NSError **)error;


/*!
 @brief This method registers your app for the push notification service.
 @discussion This method registers your app for the push notification service
 This has to be invoked with the SDK object.
 @param  deviceTokenID device token ID
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 BOOL status = [sdk registerNotifications:@"device_token" error:&error];
 @endcode
 @return BOOL
 */
-(BOOL) registerNotifications :(NSString*)deviceTokenID error:(NSError **)error;

/*!
 @brief This method unregisters your app for the push notification service.
 @discussion This method unregisters your app for the push notification service and the user will not recieve anymore notifications.
 This has to be invoked with the SDK object.
 @param  deviceTokenID device token ID
 @param  error An NSError object encapsulates information about an error condition in an extendable, object-oriented manner..
 @code
 BOOL status = [sdk unregisterNotifications:@"device_token" error:&error];
 @endcode
 @return BOOL
 */
-(BOOL) unregisterNotifications :(NSString*)deviceTokenID error:(NSError **)error;


/*!
 @brief It checks for internet connectivity.
 @discussion This synchronous method check for internet connectivity.
 This method can be written in an Utility class.
 @code
 - (IBAction)MemberSubmitAction:(id)sender
 {
 if([Utils isOnline] == YES)
 {
 NSlog(@"Network Connection available");
 }
 }
 @endcode
 @return Boolean.
 */
-(BOOL)isOnline;

/*!
 @brief It logs out of the application.
 @discussion This method terminates the session.
 This method can be written in an Utility class.
 @code
 [sdk logout];
 @endcode
 @return void.
 */
+(void)logout;

/*!
 @brief It sets the Unique ID.
 @discussion This method is a setter for Unique ID.
 @code
 [sdk setUniqueId:@"UNIQUE_ID"];
 @endcode
 @return void.
 */
+(void)setUniqueId:(NSString*)uniqueID;

/*!
 @brief It sets the app version.
 @discussion This method is a setter for the app version.
 @code
 [sdk setAppVersion:@"APP_VERSION"];
 @endcode
 @return void.
 */
+(void)setAppVersion:(NSString*)appVersion;

@end
