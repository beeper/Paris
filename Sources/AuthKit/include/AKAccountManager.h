#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>
#import <os/lock.h>
#import <Accounts/ACAccount.h>

@class ACAccountStore, ACAccountType;
@protocol OS_dispatch_queue;

@interface AKAccountManager : NSObject
{
    ACAccountStore *_accountStore;
    NSObject<OS_dispatch_queue> *_accountQueue;
    ACAccountType *_authKitAccountType;
    struct os_unfair_lock_s _authKitAccountTypeLock;
    ACAccountType *_appleIDAccountType;
    struct os_unfair_lock_s _appleIDAccountTypeLock;
    ACAccountType *_iCloudAccountType;
    struct os_unfair_lock_s _iCloudAccountTypeLock;
}

+ (void)performWithinPersonaForAccount:(id)arg1 withBlock:(id)arg2;
+ (id)personaIDIfCurrentPersonaIsEnterprise;
+ (id)stringRepresentationForService:(long long)arg1;
+ (BOOL)isAccountsFrameworkAvailable;
+ (instancetype _Nonnull)sharedInstance;

@property(retain, nonatomic) ACAccountStore *store; // @synthesize store=_accountStore;
- (void)setAdditionalInfo:(id)arg1 forAccount:(id)arg2;
- (id)additionalInfoForAccount:(id)arg1;
@property(readonly, nonatomic) ACAccountType *appleIDAccountType;
@property(readonly, nonatomic) ACAccountType *iCloudAccountType;
- (id)_altDSIDForiCloudAccount:(id)arg1;
- (id)_aliasesForiCloudAccount:(id)arg1;
- (id)transportableAuthKitAccount:(id)arg1;
- (id)altDSIDforPrimaryiCloudAccount;
- (ACAccount*)primaryiCloudAccount;
- (BOOL)isPrimaryiCloudAccountEmailVerified:(id)arg1;
- (BOOL)isPrimaryiCloudAccount:(id)arg1;
- (id)iCloudAccountForAltDSID:(id)arg1;
- (id)iCloudAccountForAppleID:(id)arg1;
- (BOOL)hasPrimaryiCloudAccountForAltDSID:(id)arg1;
- (BOOL)hasPrimaryiCloudAccountForAppleID:(id)arg1;
- (void)removeUnusedAndDuplicateAuthKitAccountsWithCompletion:(id)arg1;
- (id)activeServiceNamesForAccount:(id)arg1;
- (id)servicesUsingAccount:(id)arg1;
- (void)setAccount:(id)arg1 inUse:(BOOL)arg2 byService:(long long)arg3;
- (void)_removeTokenForKeys:(id)arg1 forAccount:(id)arg2;
- (void)_removeTokenKey:(id)arg1 forAccount:(id)arg2;
- (void)removeContinuationTokenForAccount:(id)arg1;
- (void)removeAllPasswordResetTokens;
- (id)mostRecentlyUsedAuthKitAccount;
- (id)primaryAuthKitAccount;
- (id)appleIDAccountWithAppleID:(id)arg1;
- (id)appleIDAccountWithAltDSID:(id)arg1;
- (NSArray<ACAccount*>*)allAuthKitAccounts;
@property(readonly, nonatomic) ACAccountType *authKitAccountType;
- (id)authKitAccountWithAppleID:(id)arg1;
- (id)authKitAccountWithDSID:(id)arg1;
- (id)authKitAccountWithAltDSID:(id)arg1;
- (id)_tokenWithName:(id)arg1 forAccount:(id)arg2 error:(id *)arg3;
- (void)removeMasterTokenForAccount:(id)arg1;
- (id)masterTokenForAccount:(id)arg1;
- (id)passwordResetTokenBackupForAccount:(id)arg1 error:(id *)arg2;
- (id)passwordResetTokenForAccount:(id)arg1 error:(id *)arg2;
- (id)continuationTokenForAccount:(id)arg1 error:(id *)arg2;
- (id)hearbeatTokenForAccount:(id)arg1 error:(id *)arg2;
- (id)passwordResetTokenBackupForAccount:(id)arg1;
- (id)passwordResetTokenForAccount:(id)arg1;
- (id)continuationTokenForAccount:(id)arg1;
- (id)hearbeatTokenForAccount:(id)arg1;
- (void)setRepairState:(unsigned long long)arg1 forAccount:(id)arg2;
- (unsigned long long)repairStateForAccount:(id)arg1;
- (BOOL)needsRepairForAccount:(id)arg1;
- (void)updateSatoriWarmUpTimestampForAccount:(id)arg1;
- (BOOL)shouldPerformSatoriWarmupVerificationForAccount:(id)arg1;
- (void)setDeviceTrustRevoked:(BOOL)arg1 forAccount:(id)arg2;
- (BOOL)deviceTrustRevokedForAccount:(id)arg1;
- (void)setAuthenticationMode:(unsigned long long)arg1 forAccount:(id)arg2;
- (unsigned long long)authenticationModeForAccount:(id)arg1;
- (void)setSecurityLevel:(unsigned long long)arg1 forAccount:(id)arg2;
- (unsigned long long)securityLevelForAccount:(id)arg1;
- (BOOL)saveAccount:(id)arg1 error:(id *)arg2;
- (void)setApplicationListVersion:(id)arg1 forAccount:(id)arg2;
- (id)applicationListVersionForAccount:(id)arg1;
- (void)setSelectedAuthorizationEmail:(id)arg1 forAccount:(id)arg2;
- (id)selectedAuthorizationEmailForAccount:(id)arg1;
- (void)setSelectedPrivateEmail:(BOOL)arg1 forAccount:(id)arg2;
- (BOOL)selectedPrivateEmailForAccount:(id)arg1;
- (void)setForwardingEmail:(id)arg1 forAccount:(id)arg2;
- (id)forwardingEmailForAccount:(id)arg1;
- (void)setFamilyName:(id)arg1 forAccount:(id)arg2;
- (id)familyNameForAccount:(id)arg1;
- (void)setGivenName:(id)arg1 forAccount:(id)arg2;
- (id)givenNameForAccount:(id)arg1;
- (void)setReachableEmailAddresses:(id)arg1 forAccount:(id)arg2;
- (id)reachableEmailAddressesForAccount:(id)arg1;
- (void)setAuthorizationUsed:(BOOL)arg1 forAccount:(id)arg2;
- (BOOL)authorizationUsedForAccount:(id)arg1;
- (void)setAgeOfMajority:(id)arg1 forAccount:(id)arg2;
- (id)ageOfMajorityForAccount:(id)arg1;
- (void)setDemoAccount:(BOOL)arg1 forAccount:(id)arg2;
- (BOOL)demoAccountForAccount:(id)arg1;
- (void)setUserUnderage:(BOOL)arg1 forAccount:(id)arg2;
- (BOOL)userUnderAgeForAccount:(id)arg1;
- (void)setPhoneAsAppleID:(BOOL)arg1 forAccount:(id)arg2;
- (BOOL)phoneAsAppleIDForAccount:(id)arg1;
- (void)setVerifiedPrimaryEmail:(BOOL)arg1 forAccount:(id)arg2;
- (BOOL)verifiedPrimaryEmailForAccount:(id)arg1;
- (BOOL)_setUsername:(id)arg1 forAccount:(id)arg2;
- (void)updateUsername:(id)arg1 forAccountsWithAltDSID:(id)arg2;
- (void)updateVerifiedEmail:(BOOL)arg1 forAccountWithAltDSID:(id)arg2;
- (id)formattedUsernameForAccount:(id)arg1;
- (void)setAliases:(id)arg1 forAccount:(id)arg2;
- (id)aliasesForAccount:(id)arg1;
- (void)setDSID:(id)arg1 forAccount:(id)arg2;
- (id)DSIDForAccount:(id)arg1;
- (void)setAltDSID:(id)arg1 forAccount:(id)arg2;
- (id)altDSIDForAccount:(id)arg1;
- (id)init;

@end

