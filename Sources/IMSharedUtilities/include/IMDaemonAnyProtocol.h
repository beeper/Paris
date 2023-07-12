//
//  IMDaemonAnyProtocol.h
//  
//
//  Created by June Welker on 4/29/23.
//

#ifndef IMDaemonAnyProtocol_h
#define IMDaemonAnyProtocol_h

NS_CLASS_AVAILABLE(13_0, 16_0)
@protocol IMDaemonAnyProtocol <NSObject>
- (void)requestSetupWithClientID:(NSString* _Nonnull)clientID capabilities:(unsigned int)capabilities context:(id _Nullable)context reply:(void (^_Nonnull)(id))replyBlock;
- (void)requestSetupXPCObjectWithClientID:(NSString* _Nonnull)clientID capabilities:(unsigned int)capabilities context:(id _Nullable)context reply:(void (^_Nonnull)(id))replyBlock;
- (void)setValue:(id _Nullable)value ofProperty:(NSString* _Nonnull)property;
- (void)setValue:(id _Nullable)value ofPersistentProperty:(NSString* _Nonnull)property;
- (void)markUnreadForMessageGUID:(NSString* _Nonnull)messageGUID IDs:(NSArray* _Nullable)ids style:(unsigned char)style services:(NSArray* _Nullable)services;
- (void)markMessageAsReadWithGUID:(NSString* _Nonnull)messageGUID callerOrigin:(long long)origin reply:(void (^_Nonnull)(BOOL))replyBlock;
- (void)markPlayedForMessageGUID:(NSString* _Nonnull)messageGUID;
- (void)markPlayedForIDs:(NSArray* _Nonnull)ids style:(unsigned char)style onServices:(NSArray* _Nonnull)services message:(IMMessage* _Nullable)message;
- (void)playSendSoundForMessageGUID:(NSString* _Nonnull)messageGUID callerOrigin:(long long)origin;
- (void)requestNetworkDataAvailability;
- (void)requestBuddyPicturesAndPropertiesForAccount:(NSString* _Nonnull)account;
- (void)forceReloadChatRegistryWithQueryID:(NSString* _Nonnull)queryID;
- (void)requestOneTimeCodeStatus;
- (void)consumeCodeWithMessageGUID:(NSString* _Nonnull)messageGUID;
- (void)simulateOneTimeCodeArriving:(NSDictionary* _Nonnull)oneTimeCode;
- (void)preWarm;
- (void)downloadPurgedAttachmentsForIDs:(NSArray* _Nonnull)ids style:(unsigned char)style onServices:(NSArray* _Nullable)services chatID:(NSString* _Nonnull)chatID;
- (void)initiateQuickSwitch;
- (void)requestQOSClassWhileServicingRequestsWithID:(NSString* _Nonnull)requestID;
- (void)fetchNicknames;
- (void)fetchHandleSharingState;
- (void)clearPendingNicknameUpdatesForHandleIDs:(NSArray* _Nonnull)handleIDs;
- (void)ignorePendingNicknameUpdatesForHandleIDs:(NSArray* _Nonnull)handleIDs;
- (void)allowHandleIDsForNicknameSharing:(NSArray* _Nonnull)handleIDs onChatGUIDs:(NSArray* _Nonnull)chatGUIDs;
- (void)denyHandleIDsForNicknameSharing:(NSArray* _Nonnull)handleIDs;
- (void)nicknamePreferencesDidChange;
// Methods like `fetchPersonalNickname` and `userNicknameForRecordID:` feel like they should return something, but they just seem to invoke some delegate methods
// on some internally-stored broadcaster objects, e.g. `[broadcaster nicknameRequestResponse:encodedNicknameData:]`, so you have to listen to those if you want a response
- (void)fetchPersonalNickname;
- (void)setNewPersonalNickname:(IMNickname* _Nullable)nickname;
- (void)userNicknameForRecordID:(NSString* _Nonnull)recordID decryptionKey:(NSString* _Nonnull)decryptionKey requestID:(NSString* _Nonnull)requestID;
- (void)markAllNicknamesAsPending;
- (void)eagerUploadTransfer:(id _Nonnull)upload recipients:(NSArray* _Nonnull)recipients;
- (void)eagerUploadCancel:(id _Nonnull)upload;
- (void)downloadStickerWithGUID:(NSString* _Nonnull)guid;
- (void)downloadStickerPackWithGUID:(NSString* _Nonnull)guid isIncomingMessage:(BOOL)isIncoming ignoreCache:(BOOL)ignoreCache;
- (void)holdBuddyUpdatesAccount:(NSString* _Nonnull)account;
- (void)resumeBuddyUpdatesAccount:(NSString* _Nonnull)account;
- (void)startWatchingBuddy:(NSString* _Nonnull)buddy account:(NSString* _Nonnull)account;
- (void)stopWatchingBuddy:(NSString* _Nonnull)buddy account:(NSString* _Nonnull)account:
- (void)requestProperty:(id _Nonnull)property ofPerson:(id _Nonnull)person account:(NSString* _Nonnull)account;
- (void)setValue:(id _Nullable)value ofProperty:(id _Nonnull)property ofPerson:(id _Nonnull)person account:(NSString* _Nonnull)account;
- (void)requestGroupsAccount:(NSString* _Nonnull)account;
// Don't ask me about the type of `command`. It gets passed into `[NSDictionary dictionaryWithObjects:command forKeys:... count:...]` so yeah
- (void)sendNotificationMessageToUniqueID:(NSString* _Nonnull)uniqueID withCommand:(const void * _Nonnull)command;
- (void)inviteHandleIDToShareMyScreen:(NSString* _Nonnull)handleID isContact:(BOOL)isContact;
- (void)askHandleIDToShareTheirScreen:(NSString* _Nonnull)handleID isContact:(BOOL)isContact;
- (void)requestPendingVCInvites;
// The next two methods are completely ignored (have a log line saying they're ignoring the method call) by the only implementer of this protocol that I can find,
// IMDaemonAnyRequestHandler in imagent. So I can't find the param types.
- (void)conference:(id _Nonnull)conference account:(NSString* _Nonnull)account notifyInvitationCancelledFromPerson:(id _Nonnull)person;
- (void)terminateForcingIfNeeded:(id _Nonnull)forcing;
- (void)sendNotice:(IMCollaborationNoticeTransmission* _Nonnull)notice toHandles:(NSArray* _Nonnull)recipients fromHandle:(NSString* _Nonnull)handle reply:(void (^_Nonnull)(BOOL))replyBlock;
- (void)sendClearNotice:(IMCollaborationClearTransmission* _Nonnull)clearTransmission toHandles:(NSArray* _Nonnull)handles reply:(void (^_Nonnull)(BOOL))replyBlock;
- (void)markReadForMessageGUID:(NSString* _Nonnull)guid callerOrigin:(long long)origin queryID:(NSString* _Nonnull)queryID;
@end

#endif /* IMDaemonAnyProtocol_h */
