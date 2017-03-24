//
//  OPGTheme.h
//  OnePointSDK
//
//  Created by OnePoint Global on 04/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGTheme : NSObject
/*!
 * @brief themeID : themeID
 */
@property(nonatomic,strong) NSString *themeID;
/*!
 * @brief themeTemplateID : themeTemplateID
 */
@property(nonatomic,strong) NSString *themeTemplateID;
/*!
 * @brief themeElementTypeID : themeElementTypeID
 */
@property(nonatomic,strong) NSString *themeElementTypeID;
/*!
 * @brief name : name
 */
@property(nonatomic,strong) NSString *name;
/*!
 * @brief value : Hexadecimal color code
 */
@property(nonatomic,strong) NSString *value;
/*!
 * @brief isDeleted : bool value of 1 indicates success and 0 indicates failure.
 */
@property(nonatomic,retain) NSNumber *isDeleted;
/*!
 * @brief createdDate : created date
 */
@property(readwrite,strong) NSDate *createdDate;
/*!
 * @brief lastUpdatedDate : last updated date
 */
@property(readwrite,strong) NSDate *lastUpdatedDate;
@end
