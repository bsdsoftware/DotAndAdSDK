//
//  DotAndAdAPI.h
//  ORMMA
//
//  Created by Michele Broggi on 11/14/12.
//
//

#import <Foundation/Foundation.h>
#import "DotAndAdSDK.h"
#import "DotAndAdRequest.h"

/**
 DotAndAdAPI class that contains base API functions to manage SDK requests
 */
@interface DotAndAdAPI : NSObject <DotAndAdCacheDelegate> {
    
    id<DotAndAdRequestDelegate> _requestDelegate;
    DotAndAdRequest *_request;
}

@property(nonatomic,strong) id<DotAndAdRequestDelegate> requestDelegate;

/**
 Returns DotAndAdRequest object to initialize DotAndAdConfig
 @return DotAndAdRequest object
 */
- (DotAndAdRequest *)GetConfig;

@end
