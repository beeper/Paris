#import "Broadcaster.h"
#import "IDSSendXPCProtocol.h"
#import "IMAVDaemonProtocol.h"
#import "IMAllocTracking.h"
#import "IMCallMonitor.h"
#import "IMCapturedInvocationTrampoline.h"
#import "IMConnectionMonitor.h"
#import "IMConnectionMonitorDelegate.h"
#import "IMDelayedInvocationTrampoline.h"
#import "IMDeviceSupport.h"
#import "IMDoubleLinkedList.h"
#import "IMDoubleLinkedListNode.h"
#import "IMFileCopier.h"
#import "IMFileCopierDelegate.h"
#import "IMFileManager.h"
#import "IMFoundation.h"
#import "IMIDSLog.h"
#import "IMInvocationQueue.h"
#import "IMInvocationTrampoline.h"
#import "IMLocalObject.h"
#import "IMLocalObjectInternal.h"
#import "IMLockdownManager.h"
#import "IMLogging.h"
#import "IMMacNotificationCenterManager.h"
#import "IMManualUpdater.h"
#import "IMMessageContext.h"
#import "IMMobileNetworkManager.h"
#import "IMMockURLResponse.h"
#import "IMMultiDict.h"
#import "IMMultiQueue.h"
#import "IMMultiQueueItem.h"
#import "IMNetworkAvailability.h"
#import "IMNetworkConnectionMonitor.h"
#import "IMNetworkReachability.h"
#import "IMOrderedMutableDictionary.h"
#import "IMPair.h"
#import "IMPerfNSLogProfilerSink.h"
#import "IMPerfProfiler.h"
#import "IMPerfProfilerBehavior.h"
#import "IMPerfProfilerDefaultBehavior.h"
#import "IMPerfProfilerSink.h"
#import "IMPerfSinkPair.h"
#import "IMPingStatistics.h"
#import "IMPingTest.h"
#import "IMPowerAssertion.h"
#import "IMPurgableObject.h"
#import "IMRGLog.h"
#import "IMRKMessageResponseManager.h"
#import "IMRKResponse.h"
#import "IMReachability.h"
#import "IMReachabilityDelegate.h"
#import "IMRemoteObject.h"
#import "IMRemoteObjectBroadcaster.h"
#import "IMRemoteObjectCoding.h"
#import "IMRemoteObjectInternal.h"
#import "IMRemoteURLConnection.h"
#import "IMRemoteURLConnectionMockScheduler.h"
#import "IMScheduledUpdater.h"
#import "IMSystemMonitor.h"
#import "IMSystemMonitorListener.h"
#import "IMSystemProxySettingsFetcher.h"
#import "IMThreadedInvocationTrampoline.h"
#import "IMTimer.h"
#import "IMTimingCollection.h"
#import "IMURLResponseToPlist.h"
#import "IMUserDefaults.h"
#import "IMUserNotification.h"
#import "IMUserNotificationCenter.h"
#import "IMWeakObjectCache.h"
#import "IMWeakReference.h"
#import "NSArray-FezAdditions.h"
#import "NSAttributedString-FezAdditions.h"
#import "NSBundle-FezBundleHelpers.h"
#import "NSCharacterSet-IMFoundationAdditions.h"
#import "NSCopying.h"
#import "NSData-FezAdditions.h"
#import "NSDictionary-FezAdditions.h"
#import "NSError-FezAdditions.h"
#import "NSFastEnumeration.h"
#import "NSFileManager-FezAdditions.h"
#import "NSInvocation-IMInvocationQueueAdditions.h"
#import "NSMutableArray-FezAdditions.h"
#import "NSMutableAttributedString-FezAdditions.h"
#import "NSMutableDictionary-IMFoundation_Additions.h"
#import "NSMutableSet-FezAdditions.h"
#import "NSMutableString-FezAdditions.h"
#import "NSNotificationCenter-_IMNotificationCenterAdditions.h"
#import "NSNumber-FezAdditions.h"
#import "NSObject-FezAdditions.h"
#import "NSObject.h"
#import "NSProtocolChecker-FezAdditions.h"
#import "NSSet-FezAdditions.h"
#import "NSString-FezAdditions.h"
#import "NSThread-_IMThreadBlockSupport.h"
#import "NSURL-FezAdditions.h"
#import "NSUserDefaults-SpecificDomainAdditions.h"
#import "NetworkChangeNotifier.h"
#import "OSLogHandleManager.h"
#import "_IMLogFileCompressor.h"
#import "_IMNotificationObservationHelper.h"
#import "_IMPingPacketData.h"
#import "_IMPingStatisticsCollector.h"
#import "_IMTimingInstance.h"

BOOL IMStringIsEmail( NSString * string );
BOOL IMStringIsPhoneNumber( NSString * string );
BOOL IMStringIsBusinessID( NSString * string );
CFStringRef IMCountryCodeForNumber(CFStringRef);
NSString * IMFormatPhoneNumber(NSString *inputNumber, BOOL allowSpecialCharacters);
NSString * IMFormattedDisplayStringForID(NSString * ID, NSInteger *outType);

#ifndef IMFOUNDATION_CONST

#define IMFOUNDATION_CONST

NSString* const kFZPersonFirstName;
NSString* const kFZPersonLastName;

extern NSString* IMAttachmentCharacterString;
extern NSString* IMBreadcrumbCharacterString;
extern NSString* IMNonBreakingSpaceString;
extern NSString* IMFontFamilyAttributeName;
extern NSString* IMFontSizeAttributeName;
extern NSString* IMItalicAttributeName;
extern NSString* IMBoldAttributeName;
extern NSString* IMUnderlineAttributeName;
extern NSString* IMStrikethroughAttributeName;
extern NSString* IMLinkAttributeName;
extern NSString* IMAddressAttributeName;
extern NSString* IMCalendarEventAttributeName;
extern NSString* IMDataDetectedAttributeName;
extern NSString* IMPhoneNumberAttributeName;
extern NSString* IMMoneyAttributeName;
extern NSString* IMPreformattedAttributeName;
extern NSString* IMForegroundColorAttributeName;
extern NSString* IMBackgroundColorAttributeName;
extern NSString* IMMessageBackgroundColorAttributeName;
extern NSString* IMBaseWritingDirectionAttributeName;
extern NSString* IMUniqueSmileyNumberAttributeName;
extern NSString* IMSmileyLengthAttributeName;
extern NSString* IMMyNameAttributeName;
extern NSString* IMDataDetectorResultAttributeName;
extern NSString* IMMessageForegroundAttributeName;
extern NSString* IMSmileyDescriptionAttributeName;
extern NSString* IMSmileySpeechDescriptionAttributeName;
extern NSString* IMInlineMediaWidthAttributeName;
extern NSString* IMInlineMediaHeightAttributeName;
extern NSString* IMSearchTermAttributeName;
extern NSString* IMReferencedHandleAttributeName;
extern NSString* IMFileTransferGUIDAttributeName;
extern NSString* IMFilenameAttributeName;
extern NSString* IMFileBookmarkAttributeName;
extern NSString* IMMessagePartAttributeName;
extern NSString* IMAnimatedEmojiAttributeName;
extern NSString* IMBreadcrumbTextMarkerAttributeName;
extern NSString* IMBreadcrumbTextOptionFlags;
extern NSString* IMPluginPayloadAttributeName;
extern NSString* IMOneTimeCodeAttributeName;
extern NSString* IMPhotoSharingAttributeName;

typedef uint32_t FZListenerCapabilities;
const FZListenerCapabilities
                kFZListenerCapManageStatus,
                kFZListenerCapBlackholedChatRegistry,
                kFZListenerCapNotifications,
                kFZListenerCapChats,
                kFZListenerCapAppleVC,
                kFZListenerCapAVChatInfo,
                kFZListenerCapAuxInput,
                kFZListenerCapVCInvitations,
                kFZListenerCapAppleLegacyVC,
                kFZListenerCapFileTransfers,
                kFZListenerCapAccounts,
                kFZListenerCapBuddyList,
                kFZListenerCapSendMessages,
                kFZListenerCapMessageHistory,
                kFZListenerCapIDQueries,
                kFZListenerCapChatCountsObserver,
                kFZListenerCapSentMessageObserver,
                kFZListenerCapDatabaseUpdateObserver,
                kFZListenerCapModifyReadState,
                kFZListenerCapAppleAC,
                kFZListenerCapAVObserver,
                kFZListenerCapOnDemandChatRegistry,
                kFZListenerCapTruncatedChatRegistry,
                kFZListenerCapOneTimeCode,
                kFZListenerCapSkipLastMessageLoad,
                kFZListenerCapOnDemandChatRegistry;

NSString * JWUUIDPushObjectToString(NSData * data);

typedef NS_ENUM(UInt8, IMChatStyle) {
    IMChatStyleInstantMessage = '-',
    IMChatStyleGroup          = '+'
};

void IMComponentsFromChatGUID(NSString *guid, NSString **chatIdentifier, NSString **service, IMChatStyle *style);
size_t IMiMessageMaxFileSizeForUTI(NSString * UTI, BOOL *allowedLargerRepresentation);


typedef NS_ENUM(uint32_t, FZErrorType) {
    kFZErrorNoError              = 0,

    kFZErrorUnknownError,

    kFZErrorCancelled,
    kFZErrorTimeout,
    kFZErrorSendFailed,
    kFZErrorInternalFailure,
    
    kFZErrorNetworkFailure,
    kFZErrorNetworkLookupFailure,
    kFZErrorNetworkConnectionFailure,
    kFZErrorNoNetworkFailure,
    kFZErrorNetworkBusyFailure,      // 10
    kFZErrorNetworkDeniedFailure,
    
    kFZErrorServerSignatureError,
    kFZErrorServerDecodeError,
    kFZErrorServerParseError,
    kFZErrorServerInternalError,
    kFZErrorServerInvalidRequestError,
    kFZErrorServerMalformedRequestError,
    kFZErrorServerUnknownRequestError,
    kFZErrorServerInvalidTokenError,
    kFZErrorServerRejectedError,     // 20
    
    kFZErrorRemoteUserInvalid,
    kFZErrorRemoteUserDoesNotExist,
    kFZErrorRemoteUserIncompatible,
    kFZErrorRemoteUserRejected,
    
    kFZErrorTranscodingFailure,
    
    kFZErrorEncryptionFailure,
    kFZErrorDecryptionFailure,
    
    kFZErrorOTREncryptionFailure,
    kFZErrorOTRDecryptionFailure,
    
    kFZErrorLocalAccountDisabled,
    kFZErrorLocalAccountDoesNotExist,
    kFZErrorLocalAccountNeedsUpdate,
    kFZErrorLocalAccountInvalid,

    kFZErrorAttachmentUploadFailure,
    kFZErrorAttachmentDownloadFailure,

    kFZErrorMessageAttachmentUploadFailure,
    kFZErrorMessageAttachmentDownloadFailure,

    kFZErrorSystemNeedsUpdate,

    kFZErrorServiceCrashed,

    kFZErrorInvalidLocalCredentials,

    kFZErrorAttachmentDownloadFailureFileNotFound,
    
    kFZErrorTextRenderingPreflightFailed,
};

NSString* IMRemoteObjectsRunLoopMode;

NSString* const kFZDaemonPropertyEnableReadReceipts;
NSString* const kFZDaemonPropertyGlobalReadReceiptsVersionID;

NSString * _IMStringFromFZRegistrationErrorReason(int32_t errorReason);

id IMGetCachedDomainValueForKey(NSString * domain, NSString * key);
id IMGetDomainValueForKey(NSString * domain, NSString * key);
void IMSetDomainValueForKey(NSString * domain, NSString * key, id value);

NSString* const kFZServiceDefaultsAliasesKey;
NSString* const kFZServiceDefaultsAliasKey;
NSString* const kFZServiceDefaultsAliasStatusKey;
NSString* const kFZServiceDefaultsAliasValidationErrorCodeKey;
NSString* const kFZServiceDefaultsAliasValidationAlertInfoKey;
NSString* const kFZServiceDefaultsVettedAliasesKey;

#endif
