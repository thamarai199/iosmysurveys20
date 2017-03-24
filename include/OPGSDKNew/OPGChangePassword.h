//
//  OPGChangePassword.h
//  OnePointSDK
//
//  Created by OnePoint Global on 01/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGChangePassword : NSObject
/*!
 * @brief isPasswordChangeSuccessfull : bool value of 1 indicates success and 0 indicates failure.
 */
@property (nonatomic,assign) NSNumber *isPasswordChangeSuccessfull;
/*!
 * @brief statusMessage : Status message.
 */
@property (nonatomic,strong) NSString *statusMessage;
@end
