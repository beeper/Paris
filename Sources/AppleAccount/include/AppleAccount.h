#ifndef AppleAccount_H
#define AppleAccount_H

#import <Foundation/Foundation.h>
#import <Accounts/Accounts.h>

typedef void(^ACAccountStoreCredentialRenewalHandler)(ACAccountCredentialRenewResult renewResult, NSError *error);

typedef void(^AADataclassManagerCallback)(ACAccount* account, BOOL success, NSError* error);

NS_ASSUME_NONNULL_BEGIN
@interface AADataclassManager : NSObject
@property (class, readonly, strong) AADataclassManager *sharedManager;
-(void)enableDataclassesWithoutLocalDataDataclassActionsForAccount:(ACAccount*)account callback:(AADataclassManagerCallback)callback;
@end
NS_ASSUME_NONNULL_END

@class AAAuthenticationResponse;
typedef void (^ACAccountStoreAccountFetchHandler)(NSArray<ACAccount *> *accounts, NSError *error);
typedef void (^AAAccountAuthenticationCallback)(BOOL authenticated, NSError *error);
typedef void (^AAAccountHSAAuthenticationCallback)(BOOL authenticated, AAAuthenticationResponse *response, NSError *error);
typedef void (^AAAccountEmailLookupCallback)(NSDictionary *lookupResults, NSError *error);
typedef void (^ACAccountStoreAccountObjectFetchHandler)(ACAccount *account, NSError *error);
@interface ACAccountStore (AppleAccount)
- (ACAccountType *)aa_appleAccountType;
- (NSArray<ACAccount *> *)aa_appleAccounts;
- (ACAccount *)aa_primaryAppleAccount;
- (ACAccount *)aa_primaryAppleAccountWithPreloadedDataclasses;
- (void)renewCredentialsForAccount:(ACAccount *)account force:(BOOL)shouldForce reason:(NSString *)reason completion:(ACAccountStoreCredentialRenewalHandler)completion;
- (void)aa_appleAccountsWithCompletion:(ACAccountStoreAccountFetchHandler)completion;
- (void)aa_primaryAppleAccountWithCompletion:(ACAccountStoreAccountObjectFetchHandler)completion;
- (ACAccount *)aa_appleAccountWithUsername:(NSString *)username;
- (ACAccount *)aa_appleAccountWithPersonID:(NSString *)personID;
- (ACAccount *)aa_appleAccountWithAltDSID:(NSString *)altDSID;
- (NSArray<ACAccount *> *)aa_accountsEnabledForDataclass:(NSString *)dataclass;
- (void)aa_updatePropertiesForAppleAccount:(ACAccount *)account completion:(AAAccountAuthenticationCallback)completion;
- (void)aa_updatePropertiesForAppleAccount:(ACAccount *)account options:(NSDictionary *)options completion:(AAAccountAuthenticationCallback)completion;
- (void)aa_registerAppleAccount:(ACAccount *)account withCompletion:(AAAccountAuthenticationCallback)completion;
- (void)aa_registerAppleAccountWithHSA:(ACAccount *)account completion:(AAAccountHSAAuthenticationCallback)completion;
- (void)aa_registerAppleAccountWithHSA:(ACAccount *)account usingCookieHeaders:(NSDictionary *)cookieHeaders completion:(AAAccountHSAAuthenticationCallback)completion;
- (NSString *)aa_recommendedAppleIDForAccountSignInWithTypeIdentifier:(NSString *)accountTypeID;
- (ACAccount *)aa_grandSlamAccountForiCloudAccount:(ACAccount *)iCloudAccount;
- (ACAccount *)aa_grandSlamAccountForAltDSID:(NSString *)altDSID;
- (ACAccount *)aa_authKitAccountForAltDSID:(NSString *)altDSID;
- (BOOL)aa_isUsingiCloud;
@end

#endif /* #ifndef AppleAccount_H */
