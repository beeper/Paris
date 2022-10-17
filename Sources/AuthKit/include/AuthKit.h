#import "AKAbsintheSigner.h"
#import "AKAccountManager.h"
#import "AKAccountRecoveryContext.h"
#import "AKAdaptiveService.h"
#import "AKAdaptiveServiceInterface-Protocol.h"
#import "AKAlertHandler.h"
#import "AKAnisetteData.h"
#import "AKAnisetteProvisioningAndSigningDeamonInterface-Protocol.h"
#import "AKAnisetteProvisioningClientInterface.h"
#import "AKAnisetteProvisioningClientProtocol-Protocol.h"
#import "AKAnisetteProvisioningController.h"
#import "AKAnisetteProvisioningDaemonInterface.h"
#import "AKAnisetteProvisioningDaemonProtocol-Protocol.h"
#import "AKAppleIDAuthenticationClientInterface.h"
#import "AKAppleIDAuthenticationClientProtocol-Protocol.h"
#import "AKAppleIDAuthenticationCommandLineContext.h"
#import "AKAppleIDAuthenticationContext.h"
#import "AKAppleIDAuthenticationContextManager.h"
#import "AKAppleIDAuthenticationController.h"
#import "AKAppleIDAuthenticationDaemonInterface.h"
#import "AKAppleIDAuthenticationDaemonProtocol-Protocol.h"
#import "AKAppleIDAuthenticationLimitedUIProvider-Protocol.h"
#import "AKAppleIDAuthenticationSurrogateUIProvider-Protocol.h"
#import "AKAppleIDAuthenticationUIProvider-Protocol.h"
#import "AKAppleIDServerAuthenticationUIProvider-Protocol.h"
#import "AKAppleIDServerResourceLoadDelegate.h"
#import "AKAppleIDSession.h"
#import "AKAppleIDSigningController.h"
#import "AKAppleIDSigningDaemonInterface.h"
#import "AKAppleIDSigningDaemonProtocol-Protocol.h"
#import "AKApplicationMetadataInfo.h"
#import "AKAttestationData.h"
#import "AKAttestationSigner.h"
#import "AKAuthenticationContext-Protocol.h"
#import "AKAuthorization.h"
#import "AKAuthorizationAppSignInDiscovery.h"
#import "AKAuthorizationClientImpl.h"
#import "AKAuthorizationClientInterface.h"
#import "AKAuthorizationClientProtocol-Protocol.h"
#import "AKAuthorizationContext.h"
#import "AKAuthorizationController.h"
#import "AKAuthorizationCredential.h"
#import "AKAuthorizationCredentialStateRequest.h"
#import "AKAuthorizationDaemonConnection.h"
#import "AKAuthorizationDaemonInterface.h"
#import "AKAuthorizationDaemonProtocol-Protocol.h"
#import "AKAuthorizationLoginChoice.h"
#import "AKAuthorizationNotificationHandler-Protocol.h"
#import "AKAuthorizationNotificationHandlerInterface.h"
#import "AKAuthorizationNotificationService.h"
#import "AKAuthorizationPresentationContext.h"
#import "AKAuthorizationPresenterHostInterface.h"
#import "AKAuthorizationPresenterHostProtocol-Protocol.h"
#import "AKAuthorizationRequest.h"
#import "AKAuthorizationScopesUserSelection.h"
#import "AKAuthorizationTVServicePresenter.h"
#import "AKAuthorizationUserResponse.h"
#import "AKAuthorizationValidator.h"
#import "AKAutoBugCapture.h"
#import "AKCDPFactory.h"
#import "AKCarrierBundlePhoneCertificate.h"
#import "AKCarrierBundleUtilities.h"
#import "AKCertificatePinning.h"
#import "AKCircleRequestContext.h"
#import "AKCircleRequestPayload.h"
#import "AKConfiguration.h"
#import "AKConsentedApplication.h"
#import "AKCoordinatedDataBlock.h"
#import "AKCredential-Protocol.h"
#import "AKCredentialRequest.h"
#import "AKCredentialRequestContext.h"
#import "AKCredentialRequestProtocol-Protocol.h"
#import "AKDeveloperTeam.h"
#import "AKDevice.h"
#import "AKDeviceListDeltaMessagePayload.h"
#import "AKDeviceListRequestContext.h"
#import "AKFollowUpFactoryImpl.h"
#import "AKFollowUpItemFactory-Protocol.h"
#import "AKFollowUpProvider-Protocol.h"
#import "AKFollowUpProviderImpl.h"
#import "AKFollowUpServerPayloadFormatter.h"
#import "AKFollowUpTearDownContext.h"
#import "AKIconContext.h"
#import "AKMasterToken.h"
#import "AKMediaServicesController.h"
#import "AKNativeAccountRecoveryController.h"
#import "AKNetworkObserver.h"
#import "AKPasswordCredential.h"
#import "AKPasswordRequest.h"
#import "AKRemoteDevice.h"
#import "AKServerRequestConfiguration.h"
#import "AKToken.h"
#import "AKTrustedPhoneNumber.h"
#import "AKURLBag.h"
#import "AKURLDataTask.h"
#import "AKURLSession.h"
#import "AKUserInformation.h"
#import "AKUsernameFormatter.h"
#import "AKUtilities.h"
#import "_AKAnisetteProviderProxy.h"
#import "_AKMessageForwarder.h"

NSString* const AKAuthenticationUsernameKey;
NSString* const AKAuthenticationPasswordKey;

NSString* const AKAuthenticationCircleContinuationContextKey;
NSString* const AKAuthenticationDuplexSessionKey;

#import <Accounts/Accounts.h>

@interface ACAccount (Internal)
@property (readonly) BOOL cnIsEnabledForContacts;
- (id)accountPropertyForKey:(NSString *)key;
@property (strong) NSMutableSet<NSString *> *enabledDataclasses;
@property (strong) NSMutableSet<NSString *> *provisionedDataclasses;

@property (nonatomic, readonly) NSDictionary *icaTokens;
@property (nonatomic, readonly) NSString *icaAuthToken;
@property (nonatomic, assign)   BOOL icaNeedsToVerifyTerms; // Account may need to accept new terms
@property (strong) NSDate *lastCredentialRenewalRejectionDate;
@end

NSString * const AKAppleIDAuthenticationErrorDomain;
NSString * const AKServiceNameiMessage;
NSString * const AKServiceNameiCloud;

typedef NS_ENUM(NSInteger, AKAppleIDAuthenticationError) {
    AKAppleIDAuthenticationErrorUnknown = -7001,
    AKAppleIDAuthenticationErrorLegacyAuthRequired = -7002,
    AKAppleIDAuthenticationErrorUserCanceled = -7003,
    AKAppleIDAuthenticationErrorNoSRPContext = -7004,
    AKAppleIDAuthenticationErrorCannotFindServer = -7005,
    AKAppleIDAuthenticationErrorWrongPassword = -7006,
    AKAppleIDAuthenticationErrorSilentAuthFailed = -7007,
    AKAppleIDAuthenticationErrorNoMasterToken = -7008,
    AKAppleIDAuthenticationErrorNoServiceID = -7009,
    AKAppleIDAuthenticationErrorBadServerResponse = -7010,
    AKAppleIDAuthenticationErrorUnknownContext = -7011,
    AKAppleIDAuthenticationErrorMissingUserInput = -7012,
    AKAppleIDAuthenticationErrorUnableToPrompt = -7013,
    AKAppleIDAuthenticationErrorUINotSupported = -7014,
    AKAppleIDAuthenticationErrorSettingsLaunchFailed = -7015,
    AKAppleIDAuthenticationErrorUserRequestsAccountCreation = -7016,
    AKAppleIDAuthenticationErrorUserForgotCredentials = -7017,
    AKAppleIDAuthenticationErrorSupportAPIFailed = -7018,
    AKAppleIDAuthenticationErrorServerUIFailed = -7019,
    AKAppleIDAuthenticationErrorTooManyAttempts = -7020,
    AKAppleIDAuthenticationErrorInvalidServerToken = -7021,
    AKAppleIDAuthenticationErrorMissingAppleID = -7022,
    AKAppleIDAuthenticationErrorUnknownAppleID = -7023,
    AKAppleIDAuthenticationErrorMissingMasterToken = -7024,
    AKAppleIDAuthenticationErrorMissingAltDSID = -7025,
    AKAppleIDAuthenticationErrorNotPermitted = -7026,
    AKAppleIDAuthenticationErrorNotSupported = -7027,
    AKAppleIDAuthenticationErrorMaxAttemptsReached = -7028,
    AKAppleIDAuthenticationErrorServerRequestFailed = -7029,
    AKAppleIDAuthenticationErrorCodeValidationFailed = -7030,
    AKAppleIDAuthenticationErrorForcedSuccess = -7033,
    AKAppleIDAuthenticationErrorForcedFailure = -7034,
    AKAppleIDAuthenticationErrorNoCodeReceived = -7035,
    AKAppleIDAuthenticationErrorIncorrectLoginCode = -7036,
    AKAppleIDAuthenticationErrorCorruptMasterToken = -7037,
    AKAppleIDAuthenticationErrorUserSkipped = -7038,
    AKAppleIDAuthenticationErrorInvalidResponseSignal = -7039,
    AKAppleIDAuthenticationErrorUserBackedOut = -7040,
    AKAppleIDAuthenticationErrorNoAPSToken = -7041,
    AKAppleIDAuthenticationErrorMissingHeartbeatToken = -7042,
    AKAppleIDAuthenticationErrorNewAppleIDRequiresAdditionalSetup = -7043,
    AKAppleIDAuthenticationErrorInvalidContext = -7044,
    AKAppleIDAuthenticationErrorMaxBackgroundAuthReached = -7045,
    AKAppleIDAuthenticationErrorUserRequestsLegacyAccountCreation = -7046,
    AKAppleIDAuthenticationErrorUserRequestsLegacyForgotCredentials = -7047,
    AKAppleIDAuthenticationErrorUserRequestsClientAlternateAction = -7048,
    AKAppleIDAuthenticationErrorInvalidServiceType = -7049,
    AKAppleIDAuthenticationErrorMissingDSID = -7050,
    AKAppleIDAuthenticationErrorSecondaryActionRequired = -7052,
    AKAppleIDAuthenticationErrorMissingConfigurationInfoIdentifier = -7053,
    AKAppleIDAuthenticationErrorMalformedConfigurationData = -7054,
    AKAppleIDAuthenticationErrorUnknownAltDSID = -7055,
    AKAppleIDAuthenticationErrorMissingInputParameter = -7056,
    AKAppleIDAuthenticationErrorTokenValidationFailed = -7057,
    AKAppleIDAuthenticationErrorExpiredMasterToken = -7058,
    AKAppleIDAuthenticationErrorInvalidRecoveryResponseInformation = -7059,
    AKAppleIDAuthenticationErrorMissingAnisetteDataProvider = -7060,
    AKAppleIDAuthenticationErrorInvalidClientProxy = -7061,
    AKAppleIDAuthenticationErrorUserTryAgain = -7062,
    AKAppleIDAuthenticationErrorPiggybackingHandshakeFailure = -7063,
    AKAppleIDAuthenticationErrorOperationCanceled = -7064,
    AKAppleIDAuthenticationErrorAccessDeniedByProtectionPolicy = -7065,
};

extern NSString * const AKAltDSID;
