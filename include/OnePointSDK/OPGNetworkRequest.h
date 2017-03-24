//
//  OPGNetworkRequest.h
//  OnePointSDK
//
//  Created by OnePoint Global on 30/08/16.
//  Copyright © 2016 OnePointGlobal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OPGNetworkRequest : NSObject

-(NSMutableURLRequest *)createRequest:(NSMutableDictionary*)values forApi:(NSString*)apiName;

-(NSMutableURLRequest *)createRequestForMediaForApi:(NSString*)apiName;

-(id) performRequest:(NSMutableURLRequest *)request withError:(NSError **)errorDomain;
-(BOOL) performUploadFile:(NSMutableURLRequest *)request  filePath:(NSString*)filePath  fileName:(NSString*)fileName withError:(NSError **)errorDomain;

@end
