//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@interface ADMUserAccountUtilities : NSObject
{
}

+ (void)killProcessesForUserID:(unsigned int)arg1;
+ (id)listOfProcessOwners;
+ (id)humanSizeForSize:(unsigned long long)arg1;
+ (long long)numberForKey:(struct __CFString *)arg1 fromCFDict:(struct __CFDictionary *)arg2;
+ (id)passwordErrorStringForODError:(long long)arg1;
+ (id)changePasswordForUser:(id)arg1 oldPassword:(id)arg2 newPassword:(id)arg3 cdpCompletionHandler:(id)arg4;
+ (id)changePasswordForUser:(id)arg1 oldPassword:(id)arg2 newPassword:(id)arg3;
+ (int)changeKeychainPassword:(id)arg1 oldPassword:(id)arg2;

@end

