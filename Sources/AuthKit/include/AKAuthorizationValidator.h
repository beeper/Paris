#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@interface AKAuthorizationValidator : NSObject
{
}

+ (BOOL)_requirePasscodeSet;
+ (BOOL)shouldContinueWithResponse:(id)arg1 error:(id *)arg2;
+ (BOOL)canPerformPasswordRequest:(id)arg1 error:(id *)arg2;
+ (BOOL)canPerformAuthorizationRequest:(id)arg1 error:(id *)arg2;
+ (BOOL)canPerformCredentialRequest:(id)arg1 error:(id *)arg2;

@end

