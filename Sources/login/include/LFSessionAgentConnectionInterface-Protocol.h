//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

@protocol NSObject;

@class NSDictionary;

@protocol LFSessionAgentConnectionInterface <NSObject>
- (void)SACMessageLogoutStatusClientLogoutSuccess:(NSDictionary *)arg1 reply:(void (^)(int))arg2;
- (void)SACMessageLogoutStatusClientLogoutFailed:(NSDictionary *)arg1 reply:(void (^)(int))arg2;
- (void)SACMessageMiniBuddyUIShowing:(void (^)(int))arg1;
- (void)SACMessageFaceTimeCancelCall:(void (^)(int))arg1;
- (void)SACMessageFaceTimeMuteCall:(void (^)(int))arg1;
@end

