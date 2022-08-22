#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableDictionary;
@protocol OS_dispatch_queue;

@interface AKConfiguration : NSObject
{
    NSMutableDictionary *_cachedSettings;
    int _notificationToken;
    NSObject<OS_dispatch_queue> *_settingsQueue;
}

+ (instancetype _Nonnull)sharedConfiguration;

@property(nonatomic) unsigned long long lastKnownIDMSEnvironment;
@property(nonatomic) long long shouldAutocycleAppsInWebTakeover;
@property(nonatomic) long long shouldAlwaysShowWelcome;
@property(nonatomic) long long shouldAutocycleAppsInTiburon;
@property(nonatomic) long long shouldSuppressModalSheetsInMacBuddy;
@property(nonatomic) long long shouldEnableTestAccountMode;
@property(nonatomic) long long shouldAllowTestApplication;
@property(nonatomic) long long shouldAllowDemoMode;
@property(nonatomic) long long shouldAllowExperimentalMode;
@property(nonatomic) long long shouldAllowPhoneNumberAccounts;
@property(nonatomic) long long shouldAddHSA2CreateHeader;
@property(nonatomic) long long shouldSuppressHSA2Suggestions;
@property(nonatomic) long long shouldDisablePiggybacking;
@property(nonatomic) long long shouldFakeAuthSuccess;
@property(nonatomic) long long shouldDisablePETs;
- (void)setConfigurationValue:(id)arg1 forKey:(id)arg2;
- (id)configurationValueForKey:(id)arg1;
- (void)dealloc;
- (id)init;

@end

