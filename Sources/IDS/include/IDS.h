#import <ENGroupContextCacheMiddleware.h>
#import <ENGroupContextDataSource.h>
#import <ENGroupContextMiddleware.h>
#import <IDSAccount.h>
#import <IDSAccountController.h>
#import <IDSAccountControllerDelegate.h>
#import <IDSAccountDelegate.h>
#import <IDSAccountRegistrationDelegate.h>
#import <IDSAppleCareDaemonResponseListener.h>
#import <IDSAuthenticationCertificateSignature.h>
#import <IDSAuthenticationSigningResult.h>
#import <IDSAutoCleanup.h>
#import <IDSBaseSocketPairConnectionDelegate.h>
#import <IDSBatchIDQueryController.h>
#import <IDSCarrierToken.h>
#import <IDSCarrierTokenRequestParameters.h>
#import <IDSConnection.h>
#import <IDSConnectionDelegate.h>
#import <IDSConnectionDelegatePrivate.h>
#import <IDSContinuity.h>
#import <IDSDaemonController.h>
#import <IDSDaemonControllerForwarder.h>
#import <IDSDaemonListener.h>
#import <IDSDaemonListenerProtocol.h>
#import <IDSDaemonProtocol.h>
#import <IDSDaemonProtocolController.h>
#import <IDSDaemonRequestContext.h>
#import <IDSDaemonRequestTimer.h>
#import <IDSDaemonResponseHandler.h>
#import <IDSDataChannelLinkContext.h>
#import <IDSDatagramChannel.h>
#import <IDSDestination-Additions.h>
#import <IDSDevice.h>
#import <IDSDeviceConnection.h>
#import <IDSGroupContextCacheMiddlewareDaemonProtocol.h>
#import <IDSGroupContextController.h>
#import <IDSGroupContextControllerContent.h>
#import <IDSGroupContextControllerDelegate.h>
#import <IDSGroupContextDaemonProtocol.h>
#import <IDSGroupContextDataSource.h>
#import <IDSGroupContextDataSourceDaemonProtocol.h>
#import <IDSGroupContextNotifyingObserver.h>
#import <IDSGroupContextNotifyingObserverDelegate.h>
#import <IDSGroupContextObserverDaemonProtocol.h>
#import <IDSGroupSession.h>
#import <IDSGroupSessionUnicastParameter.h>
#import <IDSHomeKitManager.h>
#import <IDSIDQueryController.h>
#import <IDSIDQueryControllerDelegate.h>
#import <IDSInternalQueueController.h>
#import <IDSLocalPairingAddPairedDeviceInfo.h>
#import <IDSLocalPairingIdentityDataErrorPair.h>
#import <IDSLocalPairingLocalDeviceRecord.h>
#import <IDSLocalPairingPairedDeviceRecord.h>
#import <IDSLocalPairingRecord.h>
#import <IDSLogging.h>
#import <IDSPairedDeviceManager.h>
#import <IDSPhoneCertificateVendor.h>
#import <IDSPhoneSubscription.h>
#import <IDSPhoneSubscriptionSelector.h>
#import <IDSQuickRelayFixedTokenAllocator.h>
#import <IDSQuickSwitchAcknowledgementTracker.h>
#import <IDSRealTimeEncryptionProxy.h>
#import <IDSRegistrationControlDaemonResponseListener.h>
#import <IDSReportiMessageSpamDaemonResponseListener.h>
#import <IDSService.h>
#import <IDSServiceAvailabilityController.h>
#import <IDSServiceContainer.h>
#import <IDSServiceMonitor.h>
#import <IDSSession.h>
#import <IDSSignInController.h>
#import <IDSSignInControllerAccountDescription.h>
#import <IDSSignInServiceUserInfo.h>
#import <IDSSignInServiceUserStatus.h>
#import <IDSTransactionLogBaseTaskHandler.h>
#import <IDSTransactionLogDataMessage.h>
#import <IDSTransactionLogDictionaryMessage.h>
#import <IDSTransactionLogMessage.h>
#import <IDSTransactionLogSyncTask.h>
#import <IDSTransactionLogSyncTaskHandler.h>
#import <IDSTransactionLogTask.h>
#import <IDSTransactionLogTaskHandler.h>
#import <IDSTransactionLogTaskHandlerAccountInfo.h>
#import <IDSTransactionLogTaskHandlerDelegate.h>
#import <IDSTransportLog.h>
#import <IDSXPCConnection.h>
#import <IDSXPCConnectionRemoteObjectPromise.h>
#import <IDSXPCConnectionTimeoutProxy.h>
#import <IDSXPCDaemon.h>
#import <IDSXPCDaemonClient.h>
#import <IDSXPCDaemonClientInterface.h>
#import <IDSXPCDaemonController.h>
#import <IDSXPCDaemonInterface.h>
#import <IDSXPCInternalTesting.h>
#import <IDSXPCInternalTestingInterface.h>
#import <IDSXPCOpportunistic.h>
#import <IDSXPCOpportunisticInterface.h>
#import <IDSXPCPairedDeviceManager.h>
#import <IDSXPCPairedDeviceManagerInterface.h>
#import <IDSXPCPairing.h>
#import <IDSXPCPairingInterface.h>
#import <IDSXPCRegistration.h>
#import <IDSXPCRegistrationInterface.h>
#import <IDSXPCReunionSync.h>
#import <IDSXPCReunionSyncInterface.h>
#import <_IDSAccount.h>
#import <_IDSAccountController.h>
#import <_IDSBatchIDQueryController.h>
#import <_IDSCompletionHandler.h>
#import <_IDSConnection.h>
#import <_IDSContinuity.h>
#import <_IDSDataChannelLinkContext.h>
#import <_IDSDatagramChannel.h>
#import <_IDSDevice.h>
#import <_IDSDeviceConnection.h>
#import <_IDSDeviceConnectionActiveMap.h>
#import <_IDSGenericCompletionHandler.h>
#import <_IDSGroupSession.h>
#import <_IDSIDQueryController.h>
#import <_IDSPasswordManager.h>
#import <_IDSRealTimeEncryptionProxy.h>
#import <_IDSService.h>
#import <_IDSSession.h>

NSString* IDSCopyIDForPhoneNumber(CFStringRef);
NSString* IDSCopyIDForEmailAddress(CFStringRef);
NSString* IDSCopyIDForBusinessID(CFStringRef);
extern NSString* IDSServiceNameiMessage;
extern NSString* IDSServiceNameSMSRelay;
extern NSString* IDSServiceNameFaceTime;
extern NSString* IDSServiceNameFaceTimeMultiway;
extern NSString* IDSServiceNameFaceTimeMulti;
extern NSString* IDSServiceNameQuickRelayFaceTime;
extern NSString* IDSServiceNameCalling;
extern NSString* IDSServiceNameSpringBoardNotificationSync;
extern NSString* IDSServiceNamePhotoStream;
extern NSString* IDSServiceNameMaps;
extern NSString* IDSServiceNameScreenSharing;
extern NSString* IDSServiceNameMultiplex1;
extern NSString* IDSServiceNameiMessageForBusiness;

#import <Foundation/Foundation.h>

@interface IDSMessageContext: NSObject
- (instancetype) initWithDictionary: (NSDictionary*) dictionary boostContext: (id) boostContext;
@property (nonatomic, readwrite, copy) NSString * outgoingResponseIdentifier;
@property (nonatomic, readwrite, copy) NSString * incomingResponseIdentifier;
@property (nonatomic, readwrite, copy) NSString * serviceIdentifier;
@property (nonatomic, readwrite, copy) NSString * fromID;
@property (nonatomic, readwrite, copy) NSString * originalGUID;
@property (nonatomic, readwrite, copy) NSString * toID;
@property (nonatomic, readwrite, copy) NSString * originalDestinationDevice;
@property (nonatomic, readwrite, copy) NSData * engramGroupID;
@property (nonatomic, readwrite, copy) NSNumber * originalCommand;
@property (nonatomic, readwrite, copy) NSNumber * serverTimestamp;
@property (nonatomic, readwrite, assign) BOOL expectsPeerResponse;
@property (nonatomic, readwrite, assign) BOOL wantsManualAck;
@property (nonatomic, readwrite, assign) BOOL fromServerStorage;
@property (nonatomic, readonly) NSDate * serverReceivedTime;
@property (nonatomic, readonly) NSTimeInterval averageLocalRTT;
//@property (nonatomic, readonly) IDSLocalMessageState localMessageState;
@property (nonatomic, readonly) BOOL deviceBlackedOut;
@property (nonatomic, readonly) NSError * wpConnectionError;
@property (nonatomic, readwrite, copy) NSString * senderCorrelationIdentifier;
@end


@protocol IDSServiceDelegate
@optional
- (void)service:(IDSService *)service account:(IDSAccount *)account incomingMessage:(NSDictionary *)message fromID:(NSString *)fromID context:(IDSMessageContext *)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account incomingData:(NSData *)data fromID:(NSString *)fromID context:(IDSMessageContext *)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account incomingUnhandledProtobuf:(IDSProtobuf *)protobuf fromID:(NSString *)fromID context:(IDSMessageContext *)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account incomingResourceAtURL:(NSURL *)resourceURL fromID:(NSString *)fromID context:(IDSMessageContext *)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account incomingResourceAtURL:(NSURL *)resourceURL metadata:(NSDictionary *)metadata fromID:(NSString *)fromID context:(IDSMessageContext *)context;
- (void)service:(IDSService *)service activeAccountsChanged:(NSSet *)accounts;
- (void)service:(IDSService *)service devicesChanged:(NSArray *)devices;
- (void)service:(IDSService *)service nearbyDevicesChanged:(NSArray *)devices;
- (void)service:(IDSService *)service connectedDevicesChanged:(NSArray *)devices;
- (void)service:(IDSService *)service account:(IDSAccount *)account identifier:(NSString *)identifier didSendWithSuccess:(BOOL)success error:(NSError *)error;
- (void)service:(IDSService *)service account:(IDSAccount *)account identifier:(NSString *)identifier didSendWithSuccess:(BOOL)success error:(NSError *)error context:(IDSMessageContext *)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account identifier:(NSString *)identifier sentBytes:(NSInteger)sentBytes totalBytes:(NSInteger)totalBytes;
- (void)service:(IDSService *)service account:(IDSAccount *)account identifier:(NSString *)identifier hasBeenDeliveredWithContext:(id)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account identifier:(NSString *)identifier fromID:(NSString *)fromID hasBeenDeliveredWithContext:(id)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account inviteReceivedForSession:(IDSSession *)session fromID:(NSString *)fromID;
- (void)service:(IDSService *)service account:(IDSAccount *)account inviteReceivedForSession:(IDSSession *)session fromID:(NSString *)fromID withOptions:(NSDictionary *)inviteOptions;
- (void)service:(IDSService *)service account:(IDSAccount *)account inviteReceivedForSession:(IDSSession *)session fromID:(NSString *)fromID withContext:(NSData *)context;
- (void)service:(IDSService *)service account:(IDSAccount *)account receivedGroupSessionParticipantUpdate:(IDSGroupSessionParticipantUpdate *)groupSessionParticipantUpdate;
- (void)serviceSpaceDidBecomeAvailable:(IDSService *)service;
- (void)serviceAllowedTrafficClassifiersDidReset:(IDSService *)service;
- (void)service:(IDSService *)service didSwitchActivePairedDevice:(IDSDevice *)activePairedDevice acknowledgementBlock:(void (^)(void))acknowledgementBlock;
@end

NS_ASSUME_NONNULL_BEGIN;

NSString *const IDSGlobalLinkAttributeIPFamilyKey;
NSString *const IDSGlobalLinkAttributeCounterKey;
NSString *const IDSGlobalLinkAttributeTransportKey;
NSString *const IDSGlobalLinkAttributeMTUKey;
NSString *const IDSGlobalLinkAttributeRATKey;
NSString *const IDSGlobalLinkAttributeSKEDataKey;
NSString *const IDSGlobalLinkAttributeConnDataKey;
NSString *const IDSGlobalLinkAttributeAcceptDelayKey;
NSString *const IDSGlobalLinkAttributeRelayRemoteAddressKey;
NSString *const IDSGlobalLinkAttributeHMacKey;
NSString *const IDSGlobalLinkAttributeRTTReportKey;
NSString *const IDSGlobalLinkAttributeLinkUUIDKey;
NSString *const IDSGlobalLinkAttributeCapabilityKey;
NSString *const IDSGlobalLinkAttributeDefaultLocalCBUUIDKey;
NSString *const IDSGlobalLinkAttributeDefaultRemoteCBUUIDKey;
NSString *const IDSGlobalLinkAttributeRelaySessionTokenKey;
NSString *const IDSGlobalLinkAttributeRelaySessionKeyKey;
NSString *const IDSGlobalLinkAttributeRelaySessionIDKey;
NSString *const IDSGlobalLinkAttributeGenericDataKey;
NSString *const IDSGlobalLinkAttributeZUDPDataKey;
NSString *const IDSGlobalLinkAttributeRelayServerDegradedKey;

NSString *const IDSQuickRelayServerProviderKey;

NSString *const IDSGlobalLinkOptionLinkIDKey;
NSString *const IDSGlobalLinkOptionLinkIDToQueryKey;
NSString *const IDSGlobalLinkOptionForceRelayKey;
NSString *const IDSGlobalLinkOptionDisallowCellularKey;
NSString *const IDSGlobalLinkOptionDisallowWiFiKey;
NSString *const IDSGlobalLinkOptionPreferCellularForCallSetupKey;
NSString *const IDSGlobalLinkOptionClientTypeKey;
NSString *const IDSGlobalLinkOptionEnableSKEKey;
NSString *const IDSGlobalLinkOptionPreferredAddressFamilyKey;
NSString *const IDSGlobalLinkOptionInviteSentTimeKey;
NSString *const IDSGlobalLinkOptionInviteRecvTimeKey;
NSString *const IDSGlobalLinkOptionUseSecureControlMessageKey;
NSString *const IDSGlobalLinkOptionQRABlockKey;
NSString *const IDSGlobalLinkOptionNewLinkOptionsKey;
NSString *const IDSGlobalLinkOptionQRSessionInfoKey;
NSString *const IDSGlobalLinkOptionSessionInfoRequestTypeKey;
NSString *const IDSGlobalLinkOptionSessionInfoRequestIDKey;
NSString *const IDSGlobalLinkOptionSessionInfoRelayLinkIDKey;
NSString *const IDSGlobalLinkOptionSessionInfoLinkIDToQueryKey;
NSString *const IDSGlobalLinkOptionSessionInfoGenerationCounterKey;
NSString *const IDSGlobalLinkOptionSessionInfoCookieKey;
NSString *const IDSGlobalLinkOptionSessionInfoPublishedStreamsKey;
NSString *const IDSGlobalLinkOptionSessionInfoSubscribedStreamsKey;
NSString *const IDSGlobalLinkOptionSessionInfoPeerPublishedStreamsKey;
NSString *const IDSGlobalLinkOptionSessionInfoPeerSubscribedStreamsKey;
NSString *const IDSGlobalLinkOptionSessionInfoMaxConcurrentStreamsKey;
NSString *const IDSGlobalLinkOptionSessionInfoResponseParticipantsKey;
NSString *const IDSGlobalLinkOptionSessionInfoResponseStreamInfoKey;
NSString *const IDSGlobalLinkOptionSessionInfoRequestBytesSentKey;
NSString *const IDSGlobalLinkOptionSessionInfoResponseBytesReceivedKey;
NSString *const IDSGlobalLinkOptionStatsIdentifierKey;
NSString *const IDSGlobalLinkOptionStatsSentPacketsKey;
NSString *const IDSGlobalLinkOptionStatsReceivedPacketsKey;
NSString *const IDSGlobalLinkOptionStatsServerTimestampKey;
NSString *const IDSGlobalLinkOptionStatsUplinkBWKey;
NSString *const IDSGlobalLinkOptionGenericDataKey;
NSString *const IDSGlobalLinkOptionAdditionalBindingKey;
NSString *const IDSGlobalLinkOptionTestOptionsKey;

/* Incoming message keys */
NSString *const IDSIncomingMessagePushPayloadKey;
NSString *const IDSIncomingMessageDecryptedDataKey;
NSString *const IDSIncomingMessageOriginalEncryptionTypeKey;
NSString *const IDSIncomingMessageEngramEncryptedDataKey;
NSString *const IDSIncomingMessageEngramGroupKey;
NSString *const IDSIncomingMessageShouldShowPeerErrorsKey;

NSString *const IDSSendMessageOptionSkipPayloadCheckKey;
NSString *const IDSSendMessageOptionTopLevelDictionaryKey;
NSString *const IDSSendMessageOptionDataToEncryptKey;
NSString *const IDSSendMessageOptionWantsResponseKey;
NSString *const IDSSendMessageOptionFromIDKey;
NSString *const IDSSendMessageOptionCommandKey;
NSString *const IDSSendMessageOptionWantsDeliveryStatusKey;
NSString *const IDSSendMessageOptionDeliveryStatusContextKey;
NSString *const IDSSendMessageOptionUUIDKey;
NSString *const IDSSendMessageOptionAlternateCallbackIdentifierKey;
NSString *const IDSSendMessageOptionLocalDeliveryKey;
NSString *const IDSSendMessageOptionRequireBluetoothKey;
NSString *const IDSSendMessageOptionRequireLocalWiFiKey;
NSString *const IDSSendMessageOptionDuetKey;
NSString *const IDSSendMessageOptionOpportunisticDuetKey;
NSString *const IDSSendMessageOptionTetheringKey;
NSString *const IDSSendMessageOptionActivityContinuationKey;
NSString *const IDSSendMessageOptionNSURLSessionKey;
NSString *const IDSSendMessageOptionMapTileKey;
NSString *const IDSSendMessageOptionBypassDuetKey;
NSString *const IDSSendMessageOptionFakeMessage;
NSString *const IDSSendMessageOptionNonWakingKey;
NSString *const IDSSendMessageOptionQueueOneIdentifierKey;
NSString *const IDSSendMessageOptionSockPuppetKey;
NSString *const IDSSendMessageOptionDuetIdentifiersOverrideKey;
NSString *const IDSSendMessageOptionEnforceRemoteTimeoutsKey;
NSString *const IDSSendMessageOptionForceEncryptionOffKey;

NSString *const IDSSendMessageOptionRequireAllRegistrationPropertiesKey;
NSString *const IDSSendMessageOptionRequireLackOfRegistrationPropertiesKey;
NSString *const IDSSendMessageOptionInterestingRegistrationPropertiesKey;
NSString *const IDSSendMessageOptionAccessTokenKey;
NSString *const IDSSendMessageOptionHomeKitMessageKey;
NSString *const IDSSendMessageOptionDisableAliasValidationKey;
NSString *const IDSSendMessageOptionSubServiceKey;
NSString *const IDSSendMessageOptionAllowCloudDeliveryKey;
NSString *const IDSSendMessageOptionAlwaysSkipSelfKey;
NSString *const IDSSendMessageOptionNonCloudWakingKey;
NSString *const IDSSendMessageOptionMetricReportIdentifierKey;
NSString *const IDSSendMessageOptionLiveMessageDeliveryKey;

NSString * const IDSDevicePropertyHardwareVersion;
NSString * const IDSDevicePropertyName;
NSString * const IDSDevicePropertyIdentities;
NSString * const IDSDevicePropertyIdentitiesURI;
NSString * const IDSDevicePropertyPushToken;
NSString * const IDSDevicePropertyService;
NSString * const IDSDevicePropertySubServices;
NSString * const IDSDevicePropertyLinkedUserURIs;
NSString * const IDSDevicePropertyLocallyPresent;
NSString * const IDSDevicePropertyDefaultPairedDevice;
NSString * const IDSDevicePropertyNSUUID;
NSString * const IDSDevicePropertyDefaultLocalDevice;
NSString * const IDSDevicePropertyPrivateDeviceData;
NSString * const IDSDevicePropertyIdentifier;
NSString * const IDSDevicePropertyIdentifierOverride;
NSString * const IDSDevicePropertyEncryptionKey;
NSString * const IDSDevicePropertyEncryptionClassAKey;
NSString * const IDSDevicePropertyEncryptionClassCKey;
NSString * const IDSDevicePropertyClientData;
NSString * const IDSDevicePropertyPairingProtocolVersion;
NSString * const IDSDevicePropertyMinCompatibilityVersion;
NSString * const IDSDevicePropertyMaxCompatibilityVersion;
NSString * const IDSDeviceServicePropertyMinCompatibilityVersion;
NSString * const IDSDevicePropertyIsHSATrustedDevice;
NSString * const IDSDevicePropertyIsActivePairedDevice;
NSString * const IDSPrivateDeviceDataVersion;
NSString * const IDSPrivateDeviceDataUniqueID;
NSString * const IDSPrivateDeviceDataProductName;
NSString * const IDSPrivateDeviceDataProductVersion;
NSString * const IDSPrivateDeviceDataProductBuildVersion;
NSString * const IDSPrivateDeviceDataRegistrationDate;
NSString * const IDSPrivateDeviceDataSupportsApplePay;
NSString * const IDSPrivateDeviceDataSupportsHandoff;
NSString * const IDSPrivateDeviceDataSupportsTethering;
NSString * const IDSPrivateDeviceDataSupportsSMSRelay;
NSString * const IDSPrivateDeviceDataSupportsMMSRelay;
NSString * const IDSPrivateDeviceDataColor;
NSString * const IDSPrivateDeviceDataEnclosureColor;
NSString * const IDSPrivateDeviceDataSupportsPhoneCalls;

NSString * const IDSAuthenticationDictionaryKeyHandles;
NSString * const IDSAuthenticationDictionaryKeyEmailAddress;
NSString * const IDSAuthenticationDictionaryKeyAuthToken;
NSString * const IDSAuthenticationDictionaryKeySelfHandle;
NSString * const IDSAuthenticationDictionaryKeyInvitationContext;
NSString * const IDSAuthenticationDictionaryKeyAppleID;
NSString * const IDSAuthenticationDictionaryKeyProfileID;
NSString * const IDSAuthenticationDictionaryKeyPassword;
NSString * const IDSAuthenticationDictionaryKeyAlert;
NSString * const IDSAuthenticationDictionaryKeyAccountInfo;
NSString * const IDSAuthenticationDictionaryKeyAuthTokenClientReceiptDate;
NSString * const IDSAuthenticationDictionaryKeyStatus;

NS_ASSUME_NONNULL_END;


void IDSiCloudSignIn(NSString * userName, NSString * authToken, NSString * password, NSDictionary * accountInfo, NSNumber * status, NSArray<NSDictionary *> * handles);
