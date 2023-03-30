//
//  IMDMessageServicesCenter.h
//  
//
//  Created by June Welker on 3/28/23.
//

#ifndef IMDMessageServicesCenter_h
#define IMDMessageServicesCenter_h

#import <Foundation/Foundation.h>

@interface IMDMessageServicesCenter: NSObject
+ (instancetype _Nonnull)sharedInstance;
- (void)_disconnected;
- (void)_disconnect;
- (void)_connect;

- (void)_requestRoutingWithGUID:(NSString* _Nullable)guid chatGUID:(NSString* _Nullable)chatGUID error:(NSError* _Nullable * _Nullable)error handler:(void (^_Nonnull)(id _Nullable))handler;
- (void)requestRoutingWithCompletion:(void (^_Nonnull)(id _Nullable))completion;
// Basically just an alias for _requestRoutingWithGUID
- (void)requestRoutingForMessageGuid:(NSString* _Nonnull)guid inChat:(NSString* _Nonnull)chatGUID error:(NSError* _Nullable * _Nullable)error completionBlock:(void (^_Nonnull)(id _Nullable))completion;

- (void)_requestExpireStateWithGUID:(NSString* _Nullable)guid handler:(void (^_Nonnull)(id _Nullable))handler;
- (void)requestExpireStateWithCompletion:(void (^_Nonnull)(id _Nullable))completion;
// Basically just an alias _requestExpireStateWithGUID:
- (void)requestExpireStateForMessageGuid:(NSString* _Nullable)guid completionBlock:(void (^_Nonnull)(id _Nullable))completion;

- (void)_requestWatchdogWithGUID:(NSString* _Nullable)guid handler:(void (^_Nonnull)(id _Nullable))handler;
- (void)requestWatchdogWithCompletion:(void (^_Nonnull)(id _Nullable))completion;
// Basically just an alias for _requestWatchdogWithGUID:
- (void)requestWatchdogForMessageGuid:(NSString* _Nullable)guid completionBlock:(void (^_Nonnull)(id _Nullable))completion;
@end

#endif /* IMDMessageServicesCenter_h */
