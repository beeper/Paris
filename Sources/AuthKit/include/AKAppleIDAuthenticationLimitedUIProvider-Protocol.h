#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

@protocol NSObject;

@class NSError, NSString;

@protocol AKAppleIDAuthenticationLimitedUIProvider <NSObject>
- (void)presentSecondFactorAlertWithError:(NSError *)arg1 title:(NSString *)arg2 message:(NSString *)arg3 completion:(void (^)(NSNumber *, NSError *))arg4;
- (void)dismissSecondFactorUIWithCompletion:(void (^)(BOOL, NSError *))arg1;
- (void)presentSecondFactorUIWithCompletion:(void (^)(NSNumber *, NSError *))arg1;
- (void)presentLoginAlertWithError:(NSError *)arg1 title:(NSString *)arg2 message:(NSString *)arg3 completion:(void (^)(NSString *, NSString *, NSDictionary *, NSError *))arg4;
- (void)dismissBasicLoginUIWithCompletion:(void (^)(BOOL, NSError *))arg1;
- (void)presentBasicLoginUIWithCompletion:(void (^)(NSString *, NSString *, NSDictionary *, NSError *))arg1;

@optional
- (void)presentBiometricOrPasscodeValidationForAppleID:(NSString *)arg1 completion:(void (^)(unsigned long long, NSError *))arg2;
@end

