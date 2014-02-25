//
//  DotAndAd MRAID SDK
//
//  Version 3.1
//
//  Created on 9/21/12.
//
//  DotAndAdSDK.h
//
//

#import "DotAndAdRequest.h"
#import "MASTAdView.h"
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

#pragma mark Constants
extern const NSString *_baseUrl;        // Requested URL
extern const NSString *_configFileName; // JSON config filename
extern const NSString *_htmlPath;

#pragma mark - Defines
#define     kUpdateParametersDelay          .5

#pragma mark Notifications defines
#define     kDotAndAdWillHideNotification               @"kDotAndAdWillHideNotification"
#define     kDotAndAdDidHideNotification                @"kDotAndAdDidHideNotification"
#define     kDotAndAdLockedByFreqNotification           @"kADotAnddLockedByFreqNotification"
#define     kDotAndAdDidFailToReceiveADNotification     @"kDotAndAdDidFailToReceiveADNotification"
#define     kDotAndAdDidFailToInitNotification          @"kDotAndAdDidFailToInitNotification"
#define     kDotAndAdClosedByNoAdvNotification          @"kDotAndAdClosedByNoAdvNotification"

#pragma mark User info dictionary keys
//#define     kDotAndAdViewUserInfoKey                  @"DotAndAdView"
#define     kDotAndAdParentViewUserInfoKey              @"DotAndParentView"
#define     kDotAndAdCurrentMptUserInfoKey              @"DotAndCurrentMpt"
#define     kDotAndAdErrorInfoKey                       @"DotAndError"

/**
 DotAndAdSDK class that contains base functions to manage SDK features
 */
@class DotAndAdAPI;
@class DotAndAdConfig;

@protocol DotAndAdSDKDelegate
- (BOOL)supportViewRotationForBanner:(UIView *)bannerView;
@end

#pragma mark - Class interface
@interface DotAndAdSDK : NSObject <DotAndAdRequestDelegate, MASTAdViewDelegate, CLLocationManagerDelegate> {
        
    NSString *_mpo;                             // Application identifier
    NSString *_cid;                             // Customer identifier
    NSMutableDictionary *_numberOfRequests;     // Number of requests (dictionary: section -> counter)
    NSDictionary *_configMpts;
    NSMutableArray *_pendingBanners;
    BOOL _isConnected;
    BOOL _DotAndAdSDKIsInit;
    BOOL _DotAndAdSDKConfigIsLoaded;
    BOOL _isWifi, _isGPSEnabled, _locationFound;
    DotAndAdAPI *_api;    
    DotAndAdConfig *_config;
    
    CLLocationManager* _locationManager;
    CLLocation *_lastAvailableLocation;
//    NSMutableArray *_locationsArray;
    double _latitude, _longitude;
    NSString *_gpscn, *_gpsrg, *_gpspr, *_gpscm, *_gpszip, *_gpsla, *_gpsln, *_carrier, *_plistPath, *_plistFile;
}

#pragma mark Properties
//@property(nonatomic, assign) id<DotAndAdSDKDelegate> sdkDelegate;
@property(nonatomic, strong) NSString *mpo;
@property(nonatomic, strong) NSString *cid;
@property(nonatomic, assign) BOOL isWifi, isGPSEnabled;
@property (strong, nonatomic) IBOutlet CLLocationManager *locationManager;
@property (strong, nonatomic) IBOutlet CLGeocoder *geoCoder;

@property (assign, nonatomic) id<DotAndAdSDKDelegate>delegate;

#pragma mark Methods
/**
 Returns shared instance of DotAndAdSDK object
 @param application identifie string
 @param custumer identifier string
 @return newly initialized DotAndAdSDK object
 */
+ (DotAndAdSDK *)initWithAppId:(NSString *)mpo AndCid:(NSString *)cid IsGPSEnabled: (BOOL) isGPSEnabled;

/**
 Returns shared instance of DotAndAdSDK object
 @return DotAndAdSDK object
 */
+ (DotAndAdSDK *)sharedInstance;

/**

 */

//TODO mancano parametri window e features (per connessione)
- (void) addBannerMpt: (NSString*) mpt customParams: (NSDictionary*) params relativeToView:(UIView*)parentView;
- (void) pauseBannerTimers: (UIViewController*) controller;
- (void) removeBanner:(MASTAdView*)view;
- (void) removeAllBannersFromController: (UIViewController*) controller;
- (void) removeAllBannersFromView: (UIView*) view;
- (BOOL) checkNetworkStatus;
- (BOOL) isDebug;
@end

