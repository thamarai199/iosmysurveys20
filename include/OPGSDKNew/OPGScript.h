//
//  OPGScript.h
//  OnePointSDK
//
//  Created by OnePoint Global on 01/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGScript : NSObject
/*!
 * @brief scriptFilePath : Path to the downloaded script.
 */
@property (nonatomic,strong) NSString *scriptFilePath;
/*!
 * @brief isDownloadSuccessful : bool value of 1 indicates success and 0 indicates failure.
 */
@property (nonatomic,assign) NSNumber *isDownloadSuccessful;
/*!
 * @brief statusMessage : Download status message.
 */
@property (nonatomic,strong) NSString *statusMessage;
@end
