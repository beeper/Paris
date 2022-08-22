#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

@protocol NSObject;

@class AKAppleIDAuthenticationContext, NSData, NSString, NSError;

@protocol AKAnisetteProvisioningClientProtocol <NSObject>
- (void)legacyAnisetteDataForContext:(AKAppleIDAuthenticationContext *)arg1 DSID:(NSString *)arg2 withCompletion:(void (^)(AKAnisetteData *, NSError *))arg3;
- (void)fetchAnisetteDataForContext:(AKAppleIDAuthenticationContext *)arg1 provisionIfNecessary:(BOOL)arg2 withCompletion:(void (^)(AKAnisetteData *, NSError *))arg3;
- (void)eraseAnisetteForContext:(AKAppleIDAuthenticationContext *)arg1 withCompletion:(void (^)(BOOL, NSError *))arg2;
- (void)syncAnisetteForContext:(AKAppleIDAuthenticationContext *)arg1 withSIMData:(NSData *)arg2 completion:(void (^)(BOOL, NSError *))arg3;
- (void)provisionAnisetteForContext:(AKAppleIDAuthenticationContext *)arg1 withCompletion:(void (^)(BOOL, NSError *))arg2;
@end

