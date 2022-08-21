//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSLock;
@protocol OS_dispatch_source;

__attribute__((visibility("hidden")))
@interface AmbientLightSensorStats : NSObject
{
    id _activityFilteredStats;
    id _unfilteredStats;
    NSObject<OS_dispatch_source> *_reportTimer;
    unsigned long long _alsIdleEventStartTime;
    NSObject<OS_dispatch_source> *_alsIdleTimer;
    NSObject<OS_dispatch_source> *_userBrightnessTimer;
    unsigned long long _activityNotification;
    unsigned int _clamshellNotification;
    struct IONotificationPort *_port;
    unsigned int _clamshellStateIterator;
    NSLock *_alsEventLock;
    _Bool _clamshellOpened;
    _Bool _userIsActive;
    struct __IOHIDEventSystemClient *_hidEventSystemClient;
}

- (void)updateALSEnabled:(_Bool)arg1;
- (void)logALSEnabled:(_Bool)arg1 userChanged:(_Bool)arg2;
- (void)logUserBrightnessChanged;
- (void)logALSIdleEvent:(_Bool)arg1;
- (void)cancelALSIdleTimer;
- (void)startALSIdleTimer;
- (void)logALSEventLocked:(float)arg1 forStats:(id)arg2;
- (void)logALSEvent:(float)arg1;
- (void)reportUnfilteredLux:(int)arg1 range:(int)arg2 changes:(int)arg3 enabled:(int)arg4;
- (void)reportActivityFilteredLux:(int)arg1 range:(int)arg2;
- (unsigned int)floorTo2SigFig:(unsigned int)arg1;
- (void)dealloc;
- (id)init;

@end

