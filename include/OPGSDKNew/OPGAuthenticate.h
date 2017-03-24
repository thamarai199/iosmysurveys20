//
//  OPGAuthentication.h
//  OnePointSDK
//
//  Created by OnePoint Global on 01/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGAuthenticate : NSObject

/*! @brief statusMessage : Authentication Status. */
@property (nonatomic,strong) NSString *statusMessage;
/*! @brief isSuccessful : bool value of 1 indicates success and 0 indicates failure. */
@property (nonatomic,assign) NSNumber *isSuccessful;
@end
