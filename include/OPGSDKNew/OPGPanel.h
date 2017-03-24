//
//  OPGPanel.h
//  OnePointSDK
//
//  Created by OnePoint Global on 04/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGPanel : NSObject
/*!
 * @brief panelID : panel ID
 */
@property(nonatomic,strong) NSString *panelID;
/*!
 * @brief themeTemplateID : theme template ID
 */
@property(nonatomic,strong) NSString *themeTemplateID;
/*!
 * @brief name : name
 */
@property(nonatomic,strong) NSString *name;
/*!
 * @brief description : description
 */
@property(nonatomic,strong) NSString *description;
/*!
 * @brief panelType : 1 indicates Normal and 2 indicates
 */
@property(nonatomic,retain) NSNumber *panelType;
/*!
 * @brief searchTag : search tag
 */
@property(nonatomic,strong) NSString *searchTag;
/*!
 * @brief remark : remark
 */
@property(nonatomic,strong) NSString *remark;
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
/*!
 * @brief userID : user ID
 */
@property(nonatomic,strong) NSString *userID;
@end
