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

@interface OPGSurvey : NSObject
/*!
 * @brief IsGeoFencing : bool value 0 indicates GeoFenced and 1 indicates it is not.
 */
@property(nonatomic,strong) NSNumber *IsGeoFencing;
/*!
 * @brief Name : Survey name.
 */
@property(nonatomic,strong) NSString *Name;
/*!
 * @brief Description : Survey description.
 */
@property(nonatomic,strong) NSString *Description;
/*!
 * @brief ScriptID : Script id.
 */
@property(nonatomic,strong) NSString *ScriptID;
/*!
 * @brief IsOffline : The property indicates bool value 0 as offline and 1 as Online
 */
@property(nonatomic,strong) NSNumber *IsOffline;
/*!
 * @brief LastUpdatedDate : Last updated date of the survey.
 */
@property(nonatomic,strong) NSString *LastUpdatedDate;
/*!
 * @brief SurveyReference : This survey reference is passed to OPGViewController to load Survey.
 */
@property(nonatomic,strong) NSString *SurveyReference;

@end
