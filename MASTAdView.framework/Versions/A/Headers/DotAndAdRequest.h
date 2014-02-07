//
//  DotAndAdRequest.h
//  ORMMA
//
//  Created by Lorenzo Canese on 11/14/12.
//
//

#import <Foundation/Foundation.h>

@protocol DotAndAdRequestDelegate;
@protocol DotAndAdCacheDelegate;
/**
 DotAndAdRequest class that contains base function to manage request and deserialize data
 */
@interface DotAndAdRequest : NSObject{
    id<DotAndAdRequestDelegate> _delegate;
    NSString*             _url;
    NSString*             _httpMethod;
    NSMutableDictionary*  _params;
    NSURLConnection*      _connection;
    NSMutableData*        _responseText;
}

@property(nonatomic,strong) id<DotAndAdRequestDelegate> delegate;
/**
 * The URL which will be contacted to execute the request.
 */
@property(nonatomic,strong) NSString* url;
/**
 * The API method which will be called.
 */
@property(nonatomic,strong) NSString* httpMethod;

/**
 * The dictionary of parameters to pass to the method.
 */
@property(nonatomic,strong) NSMutableDictionary* params;
@property(nonatomic,strong) NSURLConnection*  connection;
@property(nonatomic,strong) NSMutableData* responseText;
@property(nonatomic,strong) id<DotAndAdCacheDelegate> cacheDelegate;

+ (DotAndAdRequest*) getRequestWithParams:(NSMutableDictionary *) params
                               httpMethod:(NSString *) httpMethod
                                 delegate:(id<DotAndAdRequestDelegate>) delegate
                               requestURL:(NSString *) url;
+ (DotAndAdRequest*) getRequestWithParams:(NSMutableDictionary *) params
                               httpMethod:(NSString *) httpMethod
                                 delegate:(id<DotAndAdRequestDelegate>) delegate
                               requestURL:(NSString *) url
                         cacheDataWithKey:(NSString*)key;
+(DotAndAdRequest*)cachedObjectForKey:(NSString*)key forDelegate:(id<DotAndAdRequestDelegate>) delegate;
-(BOOL) loading;
-(void)connect;
+ (NSString*)serializeURL:(NSString *)baseUrl
                   params:(NSDictionary *)params
               httpMethod:(NSString *)httpMethod;
@end

/**
 DotAndAdRequestDelegate class that represents request delegate protocol
*/
@protocol DotAndAdRequestDelegate <NSObject>

@optional

- (void)requestFailed:(DotAndAdRequest *)request ;
- (void)requestSuccessed:(DotAndAdRequest *)request AndData:(id) data;

@end

/**
 DotAndAdRequestDelegate class that represents cache delegate protocol
 */
@protocol DotAndAdCacheDelegate <NSObject>
@optional
-(void)request:(DotAndAdRequest*)request didRetrieveData:(NSData*)data;
@end