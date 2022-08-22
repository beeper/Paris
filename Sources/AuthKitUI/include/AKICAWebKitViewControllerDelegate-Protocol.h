#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

@protocol NSObject;

@class AKICAWebKitViewController, NSError, NSHTTPURLResponse, NSMutableURLRequest, NSString;

@protocol AKICAWebKitViewControllerDelegate <NSObject>
- (void)icaWebKitViewControllerSheetDidEnd:(AKICAWebKitViewController *)arg1 withData:(id)arg2;
- (void)icaWebKitViewControllerDidSucceed:(AKICAWebKitViewController *)arg1;
- (void)icaWebKitViewControllerDidCancel:(AKICAWebKitViewController *)arg1;

@optional
- (void)didChangePassword:(NSString *)arg1 toNewPassword:(NSString *)arg2 accountID:(NSString *)arg3;
- (void)icaWebKitViewControllerDidReceiveResponse:(NSHTTPURLResponse *)arg1;
- (void)icaWebKitViewControllerSignRequest:(NSMutableURLRequest *)arg1;
- (void)icaWebKitViewControllerDidFail:(AKICAWebKitViewController *)arg1 error:(NSError *)arg2;
- (void)icaWebKitViewControllerDidFinishLoading:(AKICAWebKitViewController *)arg1;
@end

