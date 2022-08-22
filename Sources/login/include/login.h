#import <LFConnection.h>
#import <LFListener.h>
#import <LFListenerDelegate.h>
#import <LFLogindConnection.h>
#import <LFLogindConnectionInterface-Protocol.h>
#import <LFLogindListener.h>
#import <LFLogindListenerInterface-Protocol.h>
#import <LFLogindListenerLookupInterface-Protocol.h>
#import <LFMachPortWrapper.h>
#import <LFSMSession.h>
#import <LFSessionAgentConnection.h>
#import <LFSessionAgentConnectionInterface-Protocol.h>
#import <LFSessionAgentListener.h>
#import <LFSessionAgentListenerDelegate.h>
#import <LFSessionAgentListenerInterface-Protocol.h>
#import <LFSessionAgentMessageHandler.h>
#import <LFSessionLogoutConnection.h>
#import <LFSessionLogoutConnectionInterface-Protocol.h>
#import <LFSessionLogoutDelegate.h>
#import <LFSessionLogoutListener.h>
#import <LFSessionLogoutListenerInterface-Protocol.h>
#import <LFSessionOwnerConnection.h>
#import <LFSessionOwnerListener.h>
#import <LFSessionOwnerListenerInterface-Protocol.h>
#import <LFlogindListenerDelegate.h>
#import <LoginUserServiceProtocol-Protocol.h>

void LFSMCreateSessionWithOptionsByStartingServer(NSDictionary* options, id endpoint);
void LogindSetMessageHandler(id handler);
void LFSMRegisterSessionAgent(id agent);
void LFSMRegisterSessionOwner(id owner);
NSObject<LFLogindListenerInterface>* LogindRemoteObjectProxy(void);
_Nullable CFArrayRef LFSMCopyAllSessions(void);
int32_t SASSessionStateForUser(uid_t uid);
CFStringRef SASCopyDescriptionForSessionState(int32_t state) CF_RETURNS_RETAINED;

extern const CFStringRef LFSMSessionOptionProcessPathKey;
extern const CFStringRef LFSMSessionOptionProcessArgsKey;
extern const CFStringRef LFSMSessionOptionSwitchToForegroundKey;
extern const CFStringRef LFSMSessionOptionLaunchDataKey;

uint64_t LFSMCreateSessionTemporaryBridge(CFDictionaryRef inOptions);
