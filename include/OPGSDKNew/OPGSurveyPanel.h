//
//  OPGSurveyPanel.h
//  OnePointSDK
//
//  Created by OnePoint Global on 04/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGSurveyPanel : NSObject
/*!
 * @brief surveyPanelID : surveyPanelID
 */
@property(nonatomic,strong) NSString *surveyPanelID;
/*!
 * @brief surveyID : surveyID
 */
@property(nonatomic,strong) NSString *surveyID;
/*!
 * @brief panelID : panelID
 */
@property(nonatomic,strong) NSString *panelID;
/*!
 * @brief isDeleted : bool value of 1 indicates success and 0 indicates failure.
 */
@property(nonatomic,retain) NSNumber *isDeleted;
/*!
 * @brief createdDate : created date
 */
@property(nonatomic,strong) NSDate *createdDate;
/*!
 * @brief lastUpdatedDate : last updated date
 */
@property(nonatomic,strong) NSDate *lastUpdatedDate;
@end
