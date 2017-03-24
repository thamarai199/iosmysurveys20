//
//  OPGDownloadMedia.h
//  OnePointSDK
//
//  Created by OnePoint Global on 02/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGDownloadMedia : NSObject
/*!
 * @brief isDownloadSuccessful : bool value of 1 indicates success and 0 indicates failure.
 */
@property (nonatomic,assign) NSNumber *isDownloadSuccessful;
/*!
 * @brief mediaFilePath : Path to the downloaded media file.
 */
@property (nonatomic,strong) NSString *mediaFilePath;

/*!
 * @brief statusMessage : Download status message.
 */
@property (nonatomic,strong) NSString *statusMessage;
@end
