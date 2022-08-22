#ifndef IMFoundation_H
#define IMFoundation_H

#include <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef uint32_t FZListenerCapabilities;
const FZListenerCapabilities kFZListenerCapManageStatus, kFZListenerCapNotifications, kFZListenerCapChats, kFZListenerCapAppleVC, kFZListenerCapAVChatInfo, kFZListenerCapAuxInput, kFZListenerCapVCInvitations, kFZListenerCapAppleLegacyVC,
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
kFZListenerCapSkipLastMessageLoad;

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

typedef NS_ENUM(UInt8, IMChatStyle) {
    IMInstantMessageChatStyle = '-',
    IMGroupChatStyle = '+',
    IMRoomChatStyle = '#',
};

typedef NS_ENUM(int32_t, FZChatStatus) {
    kFZChatCouldntJoin = -1,
    kFZChatUnjoined,
    kFZChatJoining,
    kFZChatJoined,
    kFZChatLeft,
    kFZChatKicked,
    kFZChatBanned,
    kFZChatPasswordNeeded
};

@interface NSString ()
-(NSString*)_bestGuessURI;
@end

@interface NSArray (FezAdditions)
- (BOOL)containsObjectIdenticalTo:(id)arg1;
@end

typedef NS_ENUM(uint32_t, FZBlockingMode) {
    kFZBlockingAllowAll = 0,
    kFZBlockingAllowBuddies,
    kFZBlockingAllowListed,
    kFZBlockingBlockListed,
    kFZBlockingBlockAll,
};

typedef NS_ENUM(uint32_t, FZServiceStatus) {
    kFZServiceLoggedOut,
    kFZServiceDisconnected,
    kFZServiceLoggingOut,
    kFZServiceLoggingIn,
    kFZServiceLoggedIn
};

typedef NS_ENUM(int32_t, FZDisconnectReason) {
    kFZReasonNoReason = -1,
    kFZReasonUnknown = 0,
    kFZReasonBadUserOrPass,
    kFZReasonTempOffline,
    kFZReasonDisabled,
    kFZReasonLoggedInElsewhere,
    kFZReasonBadSSLCertificate,
    kFZReasonSSLFailed,
    kFZReasonRateLimited,
    kFZReasonNetworkError,
    kFZReasonNetworkDisconnectedError,
    kFZReasonNetworkConnectionError,
    kFZReasonBadOAuthToken,
};

typedef NS_ENUM(int32_t, FZChatMemberStatus) {
    kFZChatMemberInviteFailed = -1,
    kFZChatMemberDeciding,
    kFZChatMemberDeclined,
    kFZChatMemberJoined,
    kFZChatMemberLeft,
    kFZChatMemberKicked,
    kFZChatMemberBanned
};

NS_ASSUME_NONNULL_END

#endif /* #ifndef PARIS_H */
