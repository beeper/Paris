#ifndef AOSAccounts_H
#define AOSAccounts_H

#import <Foundation/Foundation.h>
#import <Accounts/Accounts.h>

@interface ACAccountStore (iCloudAccount_Private)
+ (ACAccountStore *)sharedStore;
- (ACAccount *)icaAppleAccountWithPersonID:(NSString *)personID;
- (instancetype)initWithEffectiveBundleID:(NSString *)bundleID;
@end

@interface ACAccountCredential ()
@property (copy) NSString *token;
@property (copy) NSString *password;
@end

NS_ASSUME_NONNULL_BEGIN

CFStringRef const kMMServiceIDBookMarks;
CFStringRef const kMMServiceIDContacts;
CFStringRef const kMMServiceIDCalendars;
CFStringRef const kMMServiceIDPhotos;
CFStringRef const kMMServiceIDSharedStreams;
CFStringRef const kMMServiceMobileDocuments;
CFStringRef const kMMServiceIDMail;
CFStringRef const kMMServiceIDFMM;
CFStringRef const kMMServiceIDNotes;
CFStringRef const kMMServiceIDKeychainSync;
CFStringRef const kMMServiceIDCloudDesktop;
CFStringRef const kMMServiceIDReminders;
CFStringRef const kMMServiceIDFamily;
CFStringRef const kMMServiceIDSiri;
CFStringRef const kMMServiceIDMessages;
CFStringRef const kMMServiceIDPhotoServiceMediaStream;
CFStringRef const kMMServiceIDPhotoServiceCloudPhotos;
CFStringRef const kMMServiceIDPhotoServiceSharedStream;
CFStringRef const kMMServiceIDNews;
CFStringRef const kMMServiceIDHome;
CFStringRef const kMMServiceIDStocks;

CFStringRef const kMMPropertyAccountError;
CFStringRef const kMMPropertyAccountErrorInfo;

// Accounts
NSString * const ACAccountTypeIdentifierIdentityServices;
NSString * const ACAccountTypeIdentifieriTunesStore;
NSString * const ACAccountTypeIdentifierAppleAccount;
NSString * const ACAccountTypeIdentifierIDMS;

NSString * const kACRenewCredentialsShouldForceKey;
NSString * const kACRenewCredentialsShouldAvoidUIKey;

typedef void(^ACAccountStoreCredentialRenewalHandler)(ACAccountCredentialRenewResult renewResult, NSError *error);

@interface ACAccountStore ()
- (void)renewCredentialsForAccount:(ACAccount *)account options:(NSDictionary *)options completion:(ACAccountStoreCredentialRenewalHandler)completion;
@end

Boolean AuthenticateAccount(CFStringRef accountID, CFStringRef password, CFDictionaryRef context);

typedef enum {
    kMMNoOption = 0,
    kMMKeepLocal,
    kMMRemoveLocal,
    kMMMergeLocal,
    kMMForceEnable,
    kMMLogout,
    kMMKeychainRestore,
    kMMEnableForcedMask = 32,
    kMMEnableClassicPhotoStreamMask = 64,
    kMMEnableSharedPhotoStreamMask = 128,
    kMMEnableCloudPhotoStreamMask = 256,
    kMMCloudHomeMask = 64,
    kMMCloudHomeDesktopMask = 128,
    kMMCloudHomeDocumentsMask = 256
} MMSetEnableOptions;

typedef enum {
    kMMStatusNoError = 0,
    kMMStatusUnexpectedError,
    kMMStatusInvalidCredential,
    kMMStatusTOSNotAccepted,
    kMMStatusInvalidURL,
    kMMStatusMissingAccountInfo,
    kMMStatusBadParameterValue,
    kMMStatusCSAppleIDInvalid
} MMAccountErrorCode;

Boolean MMAccountLoginReAuthWithContext( CFStringRef accountID, CFStringRef password, Boolean isReAuth, CFDictionaryRef context);
Boolean MMAccountLogout( CFStringRef accountID);
CFArrayRef MMCopyAccountIDs( void );

typedef void (^MMCompletion)(Boolean , CFErrorRef _Nullable);

void MMServiceSetEnabledWithCompletion( CFStringRef accountID, CFStringRef serviceID, Boolean enable , MMSetEnableOptions option , MMCompletion completion);

CFStringRef kMMProperty;
CFStringRef const kMMPropertyAccountID;
CFStringRef const kMMPropertyServiceID;
CFStringRef const kMMPropertyAccountDSID;
CFStringRef const kMMPropertyAccountAlternateDSID;
CFStringRef const kMMPropertyAccountUUID;
CFStringRef const kMMPropertyAccountAuthToken;
CFStringRef const kMMPropertyAccountPrimaryEmailVerified;
CFStringRef const kMMPropertyAccountIsManagedAppleID;
CFStringRef const kMMPropertyAccountIsNotesMigrated;
CFStringRef const kMMPropertyAccountBeta;
CFStringRef const kMMPropertyAccountDisplayNameKey;
CFStringRef const kMMPropertyAccountFirstNameKey;
CFStringRef const kMMPropertyAccountLastNameKey;

CFStringRef const kMMAccountLoggedInNotification;
CFStringRef const kMMAccountRefreshCompletedNotification;
CFStringRef const kMMAccountLoggedOutNotification;
CFStringRef const kMMAccountLoginFailedNotification;
CFStringRef const kMMAccountLoginWithNonMigratedNotification;
CFStringRef const kVettingEmailNotification;
CFStringRef const kMMAccountLogoutFailedNotification;
CFStringRef const kMMAccountDeactivateCompleteNotification;
CFStringRef const kMMAccountDeactivateFailedNotification;
CFStringRef const kMMAccountVerificationCompletedNotification;
CFStringRef const kMMAccountVerificationFailedNotification;
CFStringRef const kMMAccountPasswordChangedNotification;

CFStringRef const kMMPropertyAccountStatus;
CFStringRef const kMMPropertyAccountError;
CFStringRef const kMMPropertyAccountErrorInfo;

Boolean MMAccountIsLoggedIn( CFStringRef accountID );

void MMRelayCookie( CFURLRef url, CFStringRef name );

NS_ASSUME_NONNULL_END

CFArrayRef MMAccountCopyServiceIDs( CFStringRef accountID );
CFDictionaryRef MMServiceCopyProperties( CFStringRef accountID, CFStringRef serviceID );
void MMServiceSetEnabledWithOption( CFStringRef accountID, CFStringRef serviceID, Boolean enable, MMSetEnableOptions );
void MMServiceSetEnabled( CFStringRef accountID, CFStringRef serviceID, Boolean enable );
Boolean MMServiceIsEnabled( CFStringRef accountID, CFStringRef serviceID );
Boolean MMServiceIsAvailable( CFStringRef accountID, CFStringRef serviceID );
Boolean MMAccountIsVetted( CFStringRef accountID );
Boolean MMAccountLogoutWithOptions( CFStringRef accountID,  CFDictionaryRef logoutOptions);
void MMAccountDeactivate( CFStringRef accountID );
void MMAccountRefreshLoggedIn( CFStringRef accountID );
Boolean MMAccountLogin( CFStringRef accountID, CFStringRef password );
Boolean MMAccountLoginReAuth( CFStringRef accountID, CFStringRef password, Boolean isReAuth );
CFStringRef MMAccountCopyDisplayName( CFStringRef accountID );
CFStringRef MMAccountCopyFormattedUsername(CFStringRef accountID);
CFStringRef MMCopyLoggedInAccountFromAccounts( void );
CFDictionaryRef MMAccountCopyProperties( CFStringRef accountID );
Boolean MMServiceIsAvailable( CFStringRef accountID, CFStringRef serviceID );
Boolean MMAccountLogoutWithOptions( CFStringRef accountID,  CFDictionaryRef logoutOptions);

#endif /* #ifndef AOSAccounts_H */
