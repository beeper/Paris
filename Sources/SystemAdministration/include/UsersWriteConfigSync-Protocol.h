//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

@class NSData, NSString;

@protocol UsersWriteConfigSync

@optional
- (oneway void)notifyCFPreferencesOfImpendingUserDeletion:(NSString *)arg1 authorization:(NSData *)arg2 result:(void (^)(BOOL))arg3;
@end

