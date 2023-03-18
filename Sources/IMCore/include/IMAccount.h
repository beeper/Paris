//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "IMSystemMonitorListener-Protocol.h"
#import <Contacts/Contacts.h>
#import "Presentity.h"

@class IMHandle, IMPeople, IMServiceImpl, NSArray, NSAttributedString, NSData, NSDate, NSDictionary, NSMapTable, NSMutableDictionary, NSRecursiveLock, NSString;

@interface CNContact ()
+(NSPredicate*)predicateForContactsMatchingHandleStrings:(NSArray*)strings;
@end

/**
 IMAccount.loginStatus corresponds to IMAccount.loginStatusMessage, where
 .loggedOut == "Offline",
 .disconnected == "Disconnected",
 .disconnecting == "Disconnecting",
 .loggingIn == "Connecting",
 .loggedIn == "Connected"
 */
typedef NS_ENUM(NSUInteger, IMAccountLoginStatus) {
    IMAccountStatusLoggedOut,
    IMAccountStatusDisconnected,
    IMAccountStatusLoggingOut,
    IMAccountStatusLoggingIn,
    IMAccountStatusLoggedIn
};

typedef NS_ENUM(NSInteger, IMAccountRegistrationStatus) {
    IMAccountRegistrationStatusFailed       = -1,
    IMAccountRegistrationStatusUnknown      =  0,
    IMAccountRegistrationStatusUnregistered,
    IMAccountRegistrationStatusAuthenticating,
    IMAccountRegistrationStatusAuthenticated,
    IMAccountRegistrationStatusRegistering,
    IMAccountRegistrationStatusRegistered,
};

NSString* const IMAccountRegistrationFailedAlertMessageKey;

typedef NS_ENUM(NSInteger, IMAccountRegistrationFailureReason) {
    IMAccountRegistrationFailureNoError            = -1,
    IMAccountRegistrationFailureUnknownError        = 0,
    IMAccountRegistrationFailureInvalidLogin,
    IMAccountRegistrationFailureInvalidPassword,
    IMAccountRegistrationFailureLoginFailed,
    IMAccountRegistrationFailureCannotConnect,
    IMAccountRegistrationFailureBadDeviceID,
    IMAccountRegistrationFailureBadPushToken,
    IMAccountRegistrationFailureServerDenied,
    IMAccountRegistrationFailureTooManyAttempts,

    IMAccountRegistrationFailureAccountUpdateNeeded,
    IMAccountRegistrationFailureAccountNotAuthorized,
    IMAccountRegistrationFailureNewPasswordNeeded,
    IMAccountRegistrationFailurePermanentlyBlocked,
    IMAccountRegistrationFailureTemporarilyBlocked,

    IMAccountRegistrationFailureCancelled,
    IMAccountRegistrationFailureNotSupported,
    IMAccountRegistrationFailureBadDeviceCredentials,
    IMAccountRegistrationFailureExpiredDeviceCredentials,
    IMAccountRegistrationFailureServerError,

    IMAccountRegistrationFailureUnconfirmedAlias,

    IMAccountRegistrationFailureRegistrationUnsupported,
    IMAccountRegistrationFailureRegistrationNoAliasesSpecified,
    
    IMAccountRegistrationFailureUnsupportedManagedID,
    IMAccountRegistrationFailureDisabledSMSAuthentication,
    
    IMAccountRegistrationFailureDeniedByServer,
    IMAccountRegistrationFailureBadCredentials,
    
    IMAccountRegistrationFailureIrreparableFailure,
};

@interface IMAccount : NSObject
{
    IMServiceImpl *_service;
    IMPeople *_buddyList;
    NSRecursiveLock *_lock;
    NSMapTable *_imHandles;
    IMHandle *_loginIMHandle;
    NSArray *_cachedAllowList;
    NSArray *_cachedBlockList;
    NSString *_loginID;
    NSString *_displayName;
    NSString *_uniqueID;
    long long _accountType;
    NSString *_strippedLogin;
    NSDictionary *_data;
    NSMutableDictionary *_dataChanges;
    NSMutableDictionary *_localCache;
    NSDictionary *_profile;
    NSMutableDictionary *_profileChanges;
    NSString *_countryCode;
    long long _profileStatus;
    NSDictionary *_accountPreferences;
    NSMutableDictionary *_accountPreferencesChanges;
    NSDictionary *_accountPersistentProperties;
    NSMutableDictionary *_accountPersistentPropertiesChanges;
    NSArray *_groups;
    NSMutableDictionary *_sortOrders;
    NSDictionary *_members;
    NSMutableDictionary *_coalescedChanges;
    NSArray *_targetGroupState;
    NSArray *_lastReceivedGroupState;
    NSDictionary *_subtypeInfo;
    NSArray *_vettedAliases;
    NSArray *_aliases;
    unsigned long long _myStatus;
    NSMutableDictionary *_currentAccountStatus;
    NSString *_myStatusMessage;
    NSDictionary *_myNowPlaying;
    NSDate *_myIdleSince;
    NSData *_myPictureData;
    NSData *_accountImageData;
    unsigned long long _capabilities;
    unsigned long long _defaultHandleCapabilities;
    BOOL _hasCheckedDefaultHandleCapabilities;
    NSAttributedString *_myProfile;
    long long _registrationStatus;
    IMAccountRegistrationFailureReason _registrationFailureReason;
    NSDictionary *_registrationAlertInfo;
    unsigned long long _loginStatus;
    BOOL _isActive;
    BOOL _hasPostedOfflineNotification;
    BOOL _justLoggedIn;
    BOOL _useMeCardName;
    unsigned int _cachedBlockingMode;
    BOOL _blockIdleStatus;
    BOOL _syncedWithRemoteBuddyList;
    BOOL _hasReceivedSync;
    int _numHolding;
    int _coalesceCount;
    BOOL _needToCheckForWatchedIMHandles;
    BOOL _iconChecked;
    BOOL _hasBeenRemoved;
    id _smallImage;
    id _accountImage;
    BOOL _asleep;
}

+ (id)allBuddyListIMHandles;
+ (id)arrayOfAllIMHandles;
+ (id)nameOfLoginStatus:(unsigned long long)arg1;
+ (id)_groupSummaryFromGroupList:(id)arg1;
+ (void)removeTemporaryPasswordForAccount:(id)arg1 forServiceName:(id)arg2;
+ (void)setTemporaryPassword:(id)arg1 forAccount:(id)arg2 forAuthID:(id)arg3 forServiceName:(id)arg4;
+ (id)temporaryPasswordForAccount:(id)arg1 forAuthID:(id)arg2 forServiceName:(id)arg3;
+ (void)removePasswordForAccount:(id)arg1 forServiceName:(id)arg2;
+ (void)setPassword:(id)arg1 forAccount:(id)arg2 forAuthID:(id)arg3 forServiceName:(id)arg4;
+ (id)passwordForAccount:(id)arg1 forServiceName:(id)arg2;
@property(readonly, nonatomic) BOOL justLoggedIn; // @synthesize justLoggedIn=_justLoggedIn;
@property(readonly, nonatomic) IMPeople *buddyList; // @synthesize buddyList=_buddyList;
@property(readonly, nonatomic, nullable) IMHandle *loginIMHandle; // @synthesize loginIMHandle=_loginIMHandle;
@property(readonly, nonatomic) NSDictionary *accountSubtypeInfo; // @synthesize accountSubtypeInfo=_subtypeInfo;
@property(readonly, nonatomic) BOOL isActive; // @synthesize isActive=_isActive;
@property(nonatomic) unsigned int blockingMode; // @synthesize blockingMode=_cachedBlockingMode;
@property(nonatomic) BOOL blockIdleStatus; // @synthesize blockIdleStatus=_blockIdleStatus;
@property(readonly, nonatomic) IMAccountLoginStatus loginStatus; // @synthesize loginStatus=_loginStatus;
@property(readonly, nonatomic) unsigned long long capabilities; // @synthesize capabilities=_capabilities;
@property(readonly, nonatomic) NSDate *myIdleSince; // @synthesize myIdleSince=_myIdleSince;
@property(readonly, nonatomic) NSData *myPictureData; // @synthesize myPictureData=_myPictureData;
@property(readonly, nonatomic) NSString *myStatusMessage; // @synthesize myStatusMessage=_myStatusMessage;
@property(readonly, nonatomic) unsigned long long myStatus; // @synthesize myStatus=_myStatus;
@property(readonly, nonatomic) NSAttributedString *myProfile; // @synthesize myProfile=_myProfile;
@property(readonly, nonatomic) NSDictionary *myStatusDictionary; // @synthesize myStatusDictionary=_currentAccountStatus;
@property(readonly, nonatomic, nullable) __weak IMServiceImpl *service; // @synthesize service=_service;
@property(readonly, nonatomic) NSString *strippedLogin; // @synthesize strippedLogin=_strippedLogin;
@property(retain, nonatomic) NSString *login; // @synthesize login=_loginID;
- (void)_handleIncomingCommand:(id)arg1 withProperties:(id)arg2 fromBuddyInfo:(id)arg3;
- (void)_handleDeliveredCommand:(id)arg1 withProperties:(id)arg2 fromBuddyInfo:(id)arg3;
- (BOOL)_updateDisplayName:(id)arg1;
@property(copy, nonatomic) NSString *displayName;
- (void)setInteger:(int)arg1 forPreferenceKey:(id)arg2;
- (int)integerForPreferenceKey:(id)arg1;
- (void)setBool:(BOOL)arg1 forPreferenceKey:(id)arg2;
- (BOOL)boolForPreferenceKey:(id)arg1;
- (void)setString:(id)arg1 forPreferenceKey:(id)arg2;
- (id)stringForPreferenceKey:(id)arg1;
- (id)dictionaryDataForPreferenceKey:(id)arg1;
- (void)setDictionaryData:(id)arg1 forPreferenceKey:(id)arg2;
- (void)removeObjectForPreferenceKey:(id)arg1;
- (void)setObject:(id)arg1 forPreferenceKey:(id)arg2;
- (id)objectForPreferenceKey:(id)arg1;
@property(readonly, nonatomic) NSDictionary *accountPreferences;
- (void)_removePersistentPropertyForKey:(id)arg1;
- (void)_setPersistentPropertyObject:(id)arg1 forKey:(id)arg2;
- (id)_persistentPropertyForKey:(id)arg1;
@property(readonly, nonatomic) NSDictionary *_persistentProperties;
@property(readonly, nonatomic) BOOL isAsleep;
- (void)systemWillSleep;
- (void)systemDidWake;
- (void)_setInteger:(long long)arg1 forKey:(id)arg2;
- (void)setInteger:(long long)arg1 forKey:(id)arg2;
- (long long)integerForKey:(id)arg1;
- (void)_setBool:(BOOL)arg1 forKey:(id)arg2;
- (void)setBool:(BOOL)arg1 forKey:(id)arg2;
- (BOOL)boolForKey:(id)arg1;
- (void)_setString:(id)arg1 forKey:(id)arg2;
- (void)setString:(id)arg1 forKey:(id)arg2;
- (id)stringForKey:(id)arg1;
- (id)dictionaryDataForKey:(id)arg1;
- (void)_setDictionaryData:(id)arg1 forKey:(id)arg2;
- (void)setDictionaryData:(id)arg1 forKey:(id)arg2;
- (void)_removeObjectForKey:(id)arg1;
- (void)removeObjectForKey:(id)arg1;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (void)_setLocalCachedObject:(id)arg1 forKey:(id)arg2;
- (void)_setObject:(id)arg1 forKey:(id)arg2;
- (id)objectForKey:(id)arg1;
- (long long)validationErrorReasonForAlias:(id)arg1 type:(long long)arg2;
- (long long)validationErrorReasonForAlias:(id)arg1;
- (long long)validationStatusForAlias:(id)arg1 type:(long long)arg2;
- (long long)validationStatusForAlias:(id)arg1;
- (BOOL)validateAlias:(id)arg1 type:(long long)arg2;
- (BOOL)validateAliases:(id)arg1;
- (BOOL)validateAlias:(id)arg1;
- (BOOL)unvalidateAliases:(id)arg1;
- (BOOL)unvalidateAlias:(id)arg1;
- (long long)typeForAlias:(id)arg1;
- (BOOL)removeAlias:(id)arg1 type:(long long)arg2;
- (BOOL)removeAliases:(id)arg1;
- (BOOL)removeAlias:(NSString*)arg1;
- (BOOL)addAlias:(id)arg1 type:(long long)arg2;
- (BOOL)addAliases:(id)arg1;
- (BOOL)addAlias:(NSString*)arg1;
- (id)aliasesForType:(long long)arg1;
- (BOOL)hasAlias:(id)arg1 type:(long long)arg2;
- (BOOL)hasAlias:(id)arg1;
- (void)_invalidateCachedAliases;
@property(readonly, nonatomic, nonnull) NSArray<NSString*> *aliases;
@property(readonly, nonatomic, getter=isMakoAccount) BOOL makoAccount;
- (id)_statuses;
- (NSDictionary<NSString *, id> * _Nullable)_aliasInfoForAlias:(NSString * _Nonnull)arg1;
- (BOOL)_aliasIsVisible:(id _Nonnull)arg1;
- (id)_aliases;
@property(readonly, nonatomic) NSArray *aliasesToRegister;
@property(readonly, nonatomic) NSArray<NSString*> *vettedAliases;
- (void)_updateProfileInfo:(id)arg1;
- (long long)profileValidationErrorReason;
- (long long)profileValidationStatus;
- (BOOL)validateProfile;
- (BOOL)setProfileString:(id)arg1 forKey:(id)arg2;
- (BOOL)setProfileValue:(id)arg1 forKey:(id)arg2;
- (BOOL)removeProfileValueForKey:(id)arg1;
- (id)profileStringForKey:(id)arg1;
- (id)profileValueForKey:(id)arg1;
@property(readonly, nonatomic) NSDictionary *profileInfo;
@property(readonly, nonatomic) NSString *countryCode;
- (BOOL)updateAuthorizationCredentials:(id)arg1 token:(id)arg2;
- (void)enrollSelfDeviceInSMSRelay;
- (void)unEnrollDeviceInSMSRelay:(id)arg1;
- (void)enrollDeviceInSMSRelay:(id)arg1;
- (BOOL)authenticateAccount;
- (BOOL)requestNewAuthorizationCredentials;
@property(readonly, nonatomic) NSString *authorizationToken;
@property(readonly, nonatomic) NSString *authorizationID;
@property(readonly, nonatomic) BOOL supportsAuthorization;
- (struct _FZChatRoomValidity)validityOfChatRoomName:(id)arg1;
- (id)defaultChatSuffix;
- (id)chatIDForRoomName:(id)arg1;
- (void)nowLoggedOut;
- (void)nowLoggedIn;
- (void)handleSubscriptionRequestFrom:(id)arg1 withMessage:(id)arg2;
- (void)imHandle:(id)arg1 buddyStatusChanged:(BOOL)arg2;
- (void)disconnectAllIMHandles;
- (void)unregisterIMHandleWithID:(id)arg1;
- (void)registerIMHandle:(id)arg1;
- (void)_refreshLoginIMHandle;
- (void)forgetAllWatches;
- (void)stopWatchingIMHandle:(id)arg1;
- (void)startWatchingIMHandle:(id)arg1;
- (void)watchBuddiesIfNecessary;
- (void)_watchBuddiesIfNecessary;
- (BOOL)removeIMHandle:(id)arg1 fromIMPerson:(id)arg2;
- (BOOL)addIMHandle:(id)arg1 toIMPerson:(id)arg2;
- (NSArray<IMHandle*>* _Nonnull)imHandlesForIMPerson:(IMPerson*)arg1;
- (void)requestBuddyListAuthorizationFromIMHandle:(id)arg1;
- (void)setBuddyListAuthorization:(BOOL)arg1 forIMHandle:(id)arg2;
- (unsigned long long)sortOrderForIMHandle:(id)arg1 inGroup:(id)arg2;
- (id)personSibsForIMHandle:(id)arg1;
- (id)personForIMHandle:(id)arg1 identifier:(int *)arg2;
- (id)personForIMHandle:(id)arg1;
- (IMHandle* _Nonnull)imHandleWithID:(NSString*)arg1;
- (id)existingIMHandleWithID:(id)arg1 countryCode:(id)arg2;
- (id)imHandleWithID:(id)arg1 countryCode:(id)arg2;
- (id)_imHandleWithID:(id)arg1 alreadyCanonical:(BOOL)arg2 originalID:(id)arg3 countryCode:(id)arg4;
- (IMHandle * _Nullable)imHandleWithID:(NSString * _Nonnull)arg1 alreadyCanonical:(BOOL)arg2;
- (unsigned long long)defaultHandleCapabilities;
- (IMHandle*)existingIMHandleWithID:(id)arg1;
- (id)existingIMHandleWithID:(id)arg1 alreadyCanonical:(BOOL)arg2;
- (id)existingIMHandleWithInfo:(id)arg1 alreadyCanonical:(BOOL)arg2;
- (id)imHandleWithInfo:(id)arg1 alreadyCanonical:(BOOL)arg2;
- (id)existingIMHandleWithInfo:(id)arg1;
- (id)imHandleWithInfo:(id)arg1;
- (Class)imHandleClass;
@property(readonly, nonatomic) NSArray<IMHandle*>* arrayOfAllIMHandles;
- (void)recalculateSubtypeInfo;
- (void)_clearImageCache;
- (id)recalculatedSubtypeInfo;
- (long long)compareNames:(id)arg1;
- (void)groupsChanged:(id)arg1 error:(id)arg2;
- (void)_syncWithRemoteBuddies;
- (void)setIMAccountLoginStatus:(unsigned long long)arg1 errorMessage:(id)arg2 reason:(int)arg3;
- (void)setIMAccountLoginStatus:(unsigned long long)arg1 errorMessage:(id)arg2;
- (void)setIMAccountLoginStatus:(unsigned long long)arg1;
- (void)setIsActive:(BOOL)arg1;
@property(readonly, nonatomic) BOOL isConnected;
@property(readonly, nonatomic) BOOL isConnecting;
@property(readonly, nonatomic) NSString *loginStatusMessage;
- (void)_notJustLoggedIn;
- (BOOL)unregisterAccount;
- (BOOL)registerAccount;
@property(readonly, nonatomic) IMAccountRegistrationFailureReason registrationFailureReason;
@property(readonly, nonatomic) IMAccountRegistrationStatus registrationStatus;
- (void)_updateRegistrationStatus:(int)arg1 error:(int)arg2 info:(id)arg3;
@property(readonly, nonatomic) BOOL supportsRegistration;
@property(readonly, nonatomic) NSDictionary *registrationFailureAlertInfo;
@property(readonly, nonatomic) BOOL canSendMessages;
@property(readonly, nonatomic) BOOL isOperational;
@property(readonly, nonatomic) BOOL isRegistered;
@property(readonly, nonatomic) BOOL _isUsableForSending;
- (void)accountDidDeactivate;
- (void)accountDidBecomeActive;
- (void)accountWillBeRemoved;
- (void)_serviceDidDisconnect:(id)arg1;
- (void)_serviceDidReconnect:(id)arg1;
- (void)_serviceDidConnect:(id)arg1;
- (void)_registrationStatusChanged:(id)arg1;
- (void)setBuddyProperties:(id)arg1 buddyPictures:(id)arg2;
- (void)buddyPictureChanged:(id)arg1 imageData:(id)arg2 imageHash:(id)arg3;
- (void)buddyPropertiesChanged:(id)arg1;
- (void)resumeBuddyUpdates;
- (void)_resumeBuddyUpdatesNow;
- (void)holdBuddyUpdates;
@property(readonly, nonatomic) BOOL makingChanges;
- (void)endChanges;
- (id)memberGroups:(id)arg1;
@property(readonly, nonatomic) NSArray *groupList;
- (id)groupMembers:(id)arg1;
- (id)propertiesForGroup:(id)arg1;
- (void)reorderGroups:(id)arg1;
- (void)reorderGroup:(id)arg1 order:(id)arg2;
- (void)renameGroup:(id)arg1 to:(id)arg2;
- (void)changeBuddyList:(id)arg1 add:(BOOL)arg2 groups:(id)arg3 atLocation:(long long)arg4;
- (void)addBuddyToBuddyList:(id)arg1;
- (BOOL)removeIMHandle:(id)arg1 fromGroups:(id)arg2;
- (BOOL)addIMHandle:(id)arg1 toGroups:(id)arg2 atLocation:(long long)arg3;
- (BOOL)removePeople:(id)arg1 fromGroups:(id)arg2;
- (BOOL)addPeople:(id)arg1 toGroups:(id)arg2 atLocation:(long long)arg3;
- (void)_ensureGroupsExists:(id)arg1;
- (void)syncWithRemoteBuddies;
- (void)_markHasSyncedWithRemoteBuddies;
@property(readonly, nonatomic) BOOL hasSyncedWithRemoteBuddies;
- (void)requestGroups;
- (void)hookupToDaemon;
- (void)beginChanges;
- (void)_applyChangesToTemporaryCache:(id)arg1;
- (void)setTargetGroupsState:(id)arg1;
- (void)updateWithTargetGroups;
- (void)setWaitForTargetState;
- (void)targetGroupStateTimeout;
@property(readonly, nonatomic) BOOL hasTargetGroupStateBeenMet;
@property(readonly, nonatomic) BOOL isAwaitingTargetGroupState;
- (void)clearTargetState;
@property(nonatomic) BOOL blockOtherAddresses;
@property(retain, nonatomic) NSArray *allowList;
@property(retain, nonatomic) NSArray *blockList;
- (void)blockMessages:(BOOL)arg1 fromID:(id)arg2;
- (void)setCachedBlockIdleStatus:(BOOL)arg1;
- (void)setCachedBlockingMode:(unsigned int)arg1;
- (void)setCachedBlockList:(id)arg1;
- (void)setCachedAllowList:(id)arg1;
@property(readonly, nonatomic) NSArray *emailDomains;
@property(readonly, nonatomic) NSString *addressBookProperty;
@property(readonly, nonatomic) NSArray *addressBookProperties;
@property(readonly, nonatomic) NSDictionary *dictionary;
- (void)loadFromDictionary:(id)arg1;
- (void)_loadFromDictionary:(id)arg1 force:(BOOL)arg2;
- (void)setValue:(id)arg1 ofExtraProperty:(id)arg2 ofIMHandle:(id)arg3;
- (void)requestProperty:(id)arg1 ofIMHandle:(id)arg2;
@property(readonly, nonatomic) long long invalidSettings;
@property(readonly, nonatomic) BOOL isManaged;
@property(readonly, nonatomic) BOOL validServer;
@property(readonly, nonatomic) BOOL validPort;
@property(readonly, nonatomic) BOOL validLogin;
@property(readonly, nonatomic) BOOL canActivate;
@property(readonly, nonatomic) BOOL isSMSRelayCapable;
@property(readonly, nonatomic) BOOL allowsMMSRelay;
@property(readonly, nonatomic) BOOL allowsSMSRelay;
@property(nonatomic) BOOL allowsVCRelay;
@property(nonatomic) BOOL goIdle;
@property(readonly, nonatomic) long long port;
@property(readonly, nonatomic) NSString *server;
- (id)_serverWithSSL:(BOOL)arg1;
- (id)description;
@property(readonly, nonatomic) BOOL useSSL;
@property(nonatomic) BOOL autoLogin;
@property(readonly, nonatomic) BOOL hasCustomDescription;
@property(retain, nonatomic) NSString *accountDescription;
@property(nonatomic, getter=isInvisible) BOOL invisible;
- (void)removeTemporaryPassword;
- (void)setTemporaryPassword:(id)arg1;
@property(readonly, nonatomic) NSString *temporaryPassword;
- (void)removePassword;
- (void)setPassword:(id)arg1;
@property(readonly, nonatomic) NSString *password;
@property(readonly, nonatomic) BOOL handlesChatInvites;
- (void)updateCapabilities:(unsigned long long)arg1;
- (BOOL)hasCapability:(unsigned long long)arg1;
- (long long)compareServices:(id)arg1;
- (long long)compareIDs:(id)arg1;
- (long long)compareStatus:(id)arg1;
- (long long)compareAccountNames:(id)arg1;
- (long long)compareLoginStatus:(id)arg1;
- (BOOL)emailAddressIsID:(id)arg1;
- (void)resetToDefaults;
- (void)writeSettings;
- (BOOL)equalID:(id)arg1 andID:(id)arg2;
- (id)canonicalFormOfID:(id)arg1 countryCode:(id)arg2;
- (id)canonicalFormOfID:(id)arg1;
@property(readonly, nonatomic) NSData *accountImageData;
@property(readonly, nonatomic) NSString *serviceName;
@property(readonly, nonatomic) NSString *name;
@property(readonly, nonatomic) NSString *internalName;
@property(readonly, nonatomic) NSString *shortName;
- (void)setUniqueID:(id)arg1;
@property(readonly, nonatomic, nullable) NSString *uniqueID;
@property(readonly, nonatomic) NSString *myNowPlayingString;
- (void)setCurrentAccountStatus:(id)arg1;
- (void)_updateMyStatus:(unsigned long long)arg1 message:(id)arg2;
@property(readonly, nonatomic) long long accountType;
- (void)_updateLogin:(id)arg1;
- (void)loginStatusChanged:(unsigned int)arg1 message:(id)arg2 reason:(int)arg3 properties:(id)arg4;
- (void)logoutAccount;
- (void)loginAccount;
- (void)autoLoginAccount;
- (void)_loginWithAutoLogin:(BOOL)arg1;
- (id)initWithUniqueID:(id)arg1 service:(id)arg2;
- (id)initWithService:(id)arg1;
- (void)clearServiceCaches;
- (void)dealloc;

@end

