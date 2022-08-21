//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <CBModule.h>

#import <CBContainerModuleProtocol-Protocol.h>
#import <CBHIDServiceProtocol-Protocol.h>

@class CBABCurve, CBABRamp, CBDisplayModule, NSMutableArray, NSString;

__attribute__((visibility("hidden")))
@interface CBABModuleExternal : CBModule <CBContainerModuleProtocol, CBHIDServiceProtocol>
{
    NSMutableArray *_ALSServices;
    NSString *_containerID;
    BOOL _enabled;
    BOOL _available;
    BOOL _presetDisableAB;
    CBABCurve *_curve;
    CBABRamp *_ramp;
    BOOL _updatesFrozen;
    BOOL _suspendAutoBrightness;
    BOOL _fastRamp;
    CBDisplayModule *_displayModule;
}

@property(readonly) CBDisplayModule *displayModule; // @synthesize displayModule=_displayModule;
- (void)endFastRamp;
- (BOOL)getAggregatedLux:(float *)arg1;
- (void)handleNotificationForKey:(id)arg1 withProperty:(id)arg2;
- (void)sendNotificationForKey:(id)arg1 withValue:(id)arg2;
- (void)storeCurveToPreferences;
- (id)copyPropertyForKey:(id)arg1 withParameter:(id)arg2;
- (void)userBrightnessCommitHandler;
- (void)userBrightnessChangingHandler;
- (_Bool)handleHIDEvent:(struct __IOHIDEvent *)arg1 from:(struct __IOHIDServiceClient *)arg2;
- (void)updateAvailability;
- (_Bool)removeHIDServiceClient:(struct __IOHIDServiceClient *)arg1;
- (_Bool)addHIDServiceClient:(struct __IOHIDServiceClient *)arg1;
- (_Bool)newALSService:(struct __IOHIDServiceClient *)arg1;
- (void)updateBrightnessForce:(BOOL)arg1 periodOverride:(BOOL)arg2 period:(float)arg3;
- (void)updateBrightness;
- (void)updateAutoBrightnessState:(BOOL)arg1;
- (_Bool)setPropertyInternal:(id)arg1 forKey:(id)arg2;
- (_Bool)setProperty:(id)arg1 forKey:(id)arg2;
- (id)copyPropertyForKey:(id)arg1;
- (void)stop;
- (void)start;
- (void)dealloc;
- (id)initWithDisplayModule:(id)arg1 andQueue:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

