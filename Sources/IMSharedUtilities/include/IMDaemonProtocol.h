//
//  IMDaemonProtocol.h
//  
//
//  Created by June Welker on 4/29/23.
//

#ifndef IMDaemonProtocol_h
#define IMDaemonProtocol_h

#import <Foundation/Foundation.h>

NS_CLASS_AVAILABLE(13_0, 16_0)
@protocol IMDaemonProtocol <
    NSObject,
    IMDaemonAccountsProtocol,
    IMDaemonAnyProtocol,
    IMDaemonAutomationProtocol,
    IMDaemonBuddyListProtocol,
    IMDaemonChatFileTransferProtocol,
    IMDaemonChatMessageHistoryProtocol,
    IMDaemonChatModifyReadStateProtocol,
    IMDaemonChatProtocol,
    IMDaemonChatSendMessageProtocol,
    IMDaemonCloudSyncProtocol,
    IMDaemonFileTransferProtocol,
    IMDaemonFileProviderProtocol,
    IMDaemonManageStatusProtocol,
    IMDaemonModifyReadStateProtocol,
    IMDaemonVCACProtocol,
    IMDaemonVCInvitationsAVObserverProtocol,
    IMDaemonVCProtocol
>
- (void)setVCCapabilities:(unsigned long long)arg1;
- (void)setListenerCapabilities:(unsigned int)arg1;
@end

#endif /* IMDaemonProtocol_h */
