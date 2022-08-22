#ifndef AOSKit_H
#define AOSKit_H

#include <Foundation/Foundation.h>

CF_IMPLICIT_BRIDGING_ENABLED
NS_ASSUME_NONNULL_BEGIN

@class AOSTransaction;

typedef struct CF_BRIDGED_TYPE(AOSTransaction) AOSTransactionC* AOSTransactionRef;

typedef void (*AOSCallback)(AOSTransactionRef transaction);
typedef void (^AOSCallbackBlock)(AOSTransaction* transaction);

CFStringRef const kAOSInfoVersionKey;

CFStringRef const kAOSAppleAccountInfoKey;
CFStringRef const kAOSAuthInfoKey;
CFStringRef const kAOSFirstNameKey;
CFStringRef const kAOSLastNameKey;
CFStringRef const kAOSAppleIDKey;
CFStringRef const kAOSAppleIDAliasKey;
CFStringRef const kAOSAppleIDAliasesKey;
CFStringRef const kAOSPersonIDKey;
CFStringRef const kAOSAlternatePersonIDKey;
CFStringRef const kAOSPrimaryEmailKey;
CFStringRef const kAOSPrimaryEmailVerifiedKey;

CFStringRef const kAOSTokensKey;
CFStringRef const kAOSMMeAuthTokenKey;
CFStringRef const kAOSBTMMTokenKey;

CFStringRef const kAOSValidDomainsKey;

CFStringRef const kAOSMMeInfoKey;

CFStringRef const kAOSAvailableDataclassesKey;
CFStringRef const kAOSAvailableFeaturesKey;
CFStringRef const kAOSContactsKey;
CFStringRef const kAOSCalendarsKey;
CFStringRef const kAOSBookmarksKey;
CFStringRef const kAOSMailKey;
CFStringRef const kAOSQuotaKey;
CFStringRef const kAOSAccountKey;
CFStringRef const kAOSBTMMKey;
CFStringRef const kAOSAvailabilityKey;

CFStringRef const kAOSAuthTypeKey;
CFStringRef const kAOSTokenAuth;
CFStringRef const kAOSPasswordAuth;

CFStringRef const kAOSProtocolKey;
CFStringRef const kAOSDAVProtocol;

CFStringRef const kAOSURLKey;

CFStringRef const kAOSAccountStatusCodeKey;
CFStringRef const kAOSEnvironmentKey;

CFStringRef const kAOSRequestMethodKey;
CFStringRef const kAOSRequestURLKey;
CFStringRef const kAOSRequestHeadersKey;
CFStringRef const kAOSRequestBodyKey;

CFStringRef const kAOSCookieURLKey;
CFStringRef const kAOSCookieNameKey;

Boolean _AOSRelayCookie(CFDictionaryRef cookieInfo, CFErrorRef *error);

@interface AOSPushManager: NSObject
+(instancetype)sharedManager;
-(NSString* _Nullable)tokenString;
@end


typedef struct AOSTransactionC {
    Class                       isa;
    Boolean                     didSucceed;
    Boolean                     didFinish;
    CFTypeRef                   result;
    CFErrorRef                  error;
    AOSCallback                 callbackFunction;
    AOSCallbackBlock            callbackBlock;
    dispatch_queue_t            callbackQueue;
    void *                      context;
    NSConditionLock *           waitLock;
    CFAllocatorRetainCallBack   contextRetain;
    CFAllocatorReleaseCallBack  contextRelease;
} AOSTransactionC;

@interface AOSTransaction : NSObject <NSSecureCoding> {
    Boolean                     didSucceed;
    Boolean                     didFinish;
    CFTypeRef                   result;
    CFErrorRef                  error;
    AOSCallback                 callbackFunction;
    AOSCallbackBlock            callbackBlock;
    dispatch_queue_t            callbackQueue;
    void *                      context;
    NSConditionLock *           waitLock;
    CFAllocatorRetainCallBack   contextRetain;
    CFAllocatorReleaseCallBack  contextRelease;
}
- (BOOL)isSuccessful;
- (id)result;
- (NSError *)error;
@end

typedef struct AOSAccount* AOSAccountRef;

const CFStringRef kAOSGSServiceIdKey;
const CFStringRef kAOSGSServiceIdsKey;
const CFStringRef kAOSIsAnisetteRequiredKey;
const CFStringRef kAOSIsAbsintheRequiredKey;

const CFStringRef kAOSAppleIdService;
const CFStringRef kAOSiCloudService;


NS_ASSUME_NONNULL_END

struct AOSCallbackInfo {
    CFIndex version;
    AOSCallback callback;
    void *context;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
    __unsafe_unretained AOSCallbackBlock callbackBlock;
    __unsafe_unretained dispatch_queue_t callbackQueue;
};
typedef struct AOSCallbackInfo AOSCallbackInfo;

AOSTransactionRef _AOSAccountRetrieveDeviceList(AOSAccountRef account, CFDictionaryRef info, AOSCallbackInfo *callbackInfo) CF_RETURNS_RETAINED;

AOSAccountRef AOSAccountCreate(CFAllocatorRef allocator,
                               CFStringRef user,
                               CFStringRef password,
                               CFDictionaryRef properties);

CFDictionaryRef AOSAccountCopyInfo(AOSAccountRef account) CF_RETURNS_RETAINED;
AOSTransactionRef AOSAccountRefreshInfo(AOSAccountRef account, AOSCallbackInfo *callbackInfo) CF_RETURNS_RETAINED;

CFStringRef AOSAccountGetAppleID(AOSAccountRef account);
CFDictionaryRef AOSAccountGetProperties(AOSAccountRef account);

AOSTransactionRef _AOSAccountRetrieveInfo(AOSAccountRef account, CFDictionaryRef params, AOSCallbackInfo *callbackInfo) CF_RETURNS_RETAINED;

Boolean _AOSRemoveAppleID(CFStringRef appleID, CFErrorRef *error);
Boolean _AOSAccountRelayCredentials(AOSAccountRef account);

AOSTransactionRef _AOSAccountRetrieveGSToken(AOSAccountRef account, CFDictionaryRef info, AOSCallbackInfo *callbackInfo) CF_RETURNS_RETAINED;
AOSTransactionRef _AOSAccountGenerateRequestHeaders(AOSAccountRef account, CFDictionaryRef info, AOSCallbackInfo *callbackInfo) CF_RETURNS_RETAINED;
AOSTransactionRef _AOSAccountRetrievePushToken(AOSAccountRef account, CFDictionaryRef info, AOSCallbackInfo *callbackInfo)  CF_RETURNS_RETAINED;
void _AOSAccountRefreshAll(void);
CFStringRef AOSAccountGetPassword(AOSAccountRef account);
Boolean _AOSRemoveAppleID(CFStringRef appleID, CFErrorRef *error);


CF_IMPLICIT_BRIDGING_DISABLED

#endif /* #ifndef AOSKit_H */
