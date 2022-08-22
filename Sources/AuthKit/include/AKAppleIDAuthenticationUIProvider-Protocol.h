#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AKAppleIDAuthenticationLimitedUIProvider-Protocol.h>
#import <AKAppleIDServerAuthenticationUIProvider-Protocol.h>

@class AKAccountRecoveryContext, NSString, NSError;

@protocol AKAppleIDAuthenticationUIProvider <AKAppleIDAuthenticationLimitedUIProvider, AKAppleIDServerAuthenticationUIProvider>
+(void) launchOutOfProcessAuthenticationWithContext:(AKAppleIDAuthenticationContext*)arg0 surrogateID:(NSUUID*)arg1 andErrorHandler:(void (^)(NSError*))arg2;
-(void) launchOutOfProcessAuthenticationWithContext:(AKAppleIDAuthenticationContext*)arg0 surrogateID:(NSUUID*)arg1 andErrorHandler:(void (^)(NSError*))arg2;

- (void)dismissNativeRecoveryUIWithCompletion:(void (^)(BOOL, NSError *))arg1;
- (void)presentNativeRecoveryUIWithContext:(AKAccountRecoveryContext *)arg1 completion:(void (^)(NSDictionary *, NSError *))arg2;

@optional
- (void)dismissKeepUsingUIWithCompletion:(void (^)(BOOL, NSError *))arg1;
- (void)presentKeepUsingUIForAppleID:(NSString *)arg1 completion:(void (^)(BOOL, NSError *))arg2;
@end

