#ifndef IMSharedUtilities_H
#define IMSharedUtilities_H

#include <IMFoundation.h>
#include <Foundation/Foundation.h>
#include <IMFileTransfer.h>

NS_ASSUME_NONNULL_BEGIN

@class IMMessageItem, IMItem;

// IMSharedUtilities
@protocol IMDaemonListenerProtocol
@optional
- (void) setupComplete:(BOOL)success info:(NSDictionary *)info;
- (void) setupComplete;
- (void) chat:(NSString *)persistentIdentifier updated:(NSDictionary *)updateDictionary;
- (void) chat:(NSString *)persistentIdentifier propertiesUpdated:(NSDictionary *)properties;
- (void) chat:(NSString *)persistentIdentifier engramIDUpdated:(NSString * _Nullable)engramID;
- (void) loadedChats:(NSArray<NSDictionary*>*)chats queryID:(NSString*)queryID;
- (void) loadedChats:(NSArray<NSDictionary*>*)chats;
- (void) chatLoadedWithChatIdentifier:(NSString *)chatIdentifier chats:(NSArray *)chatDictionaries;
- (void) lastMessageForAllChats:(NSDictionary *)chatIDToLastMessageDictionary;
- (void) service:(NSString *)serviceID chat:(NSString*)chatIdentifier style:(IMChatStyle)chatStyle messagesUpdated:(NSArray<NSDictionary*>*)messages;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties messageUpdated:(IMItem *)msg;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties notifySentMessage:(IMMessageItem *)msg sendTime:(NSNumber *)sendTime;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties messagesUpdated:(NSArray<NSDictionary*> *)messages;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties error:(NSError *)error;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties groupID:(NSString *)groupID chatPersonCentricID:(NSString * _Nullable) personCentricID messageSent:(IMMessageItem *)msg;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties groupID:(NSString *)groupID chatPersonCentricID:(NSString * _Nullable) personCentricID messageReceived:(IMItem *)msg;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties groupID:(NSString *)groupID chatPersonCentricID:(NSString * _Nullable) personCentricID messagesReceived:(NSArray<IMItem *> *)messages;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties groupID:(NSString * _Nullable)groupID chatPersonCentricID:(NSString * _Nullable) personCentricID messagesReceived:(NSArray<IMItem *> *)messages messagesComingFromStorage:(BOOL)fromStorage;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties groupID:(NSString * _Nullable)groupID chatPersonCentricID:(NSString * _Nullable) personCentricID statusChanged:(FZChatStatus)status handleInfo:(NSArray *)handleInfo;
- (void) account:(NSString *)accountUniqueID chat:(NSString *)chatIdentifier style:(IMChatStyle)chatStyle chatProperties:(NSDictionary * _Nullable)properties updateProperties:(NSDictionary * _Nullable)update;
@end

@interface IMItem: NSObject
@property (nonatomic, readwrite, retain, nullable) NSString* sender;
@property (nonatomic, readwrite, retain) NSString *guid;
@property (nonatomic, readwrite, assign, setter = _setMessageID:) int64_t messageID;
@property (nonatomic, readwrite, nullable, retain) NSString *accountID;
@property (nonatomic, readwrite, nullable, retain) NSString *service;
@property (nonatomic, readwrite, nullable, retain) NSDate *time;
@property (nonatomic, readonly, assign) BOOL isFromMe;
@end

@interface IMMessageItem: IMItem
@property (nonatomic, readwrite, retain, nullable) NSString *threadIdentifier;
@property (nonatomic, readwrite, retain, nullable) NSArray *fileTransferGUIDs;

@property (nonatomic, readwrite, copy, nullable) NSDictionary* messageSummaryInfo;

@property (nonatomic, readwrite, retain, nullable) NSString *account;
@property (nonatomic, readwrite, retain, nullable) NSString *accountID;

@property (nonatomic, readwrite, assign) uint64_t flags;

@property (nonatomic, readonly, assign) BOOL isDelivered;
@property (nonatomic, readonly, assign) BOOL isSent;
@property (nonatomic, readonly, assign) BOOL isRead;
@property (nonatomic, readonly, assign) BOOL isPlayed;
@property (nonatomic, readonly, assign) BOOL isFinished;
@property (nonatomic, readonly, assign) BOOL isEmpty;
@property (nonatomic, readonly, assign) BOOL isAlert;
@property (nonatomic, readonly, assign) BOOL isPrepared;
@property (nonatomic, readonly, assign) BOOL isTypingMessage;
@property (nonatomic, readonly, assign) BOOL isLocatingMessage;
@property (nonatomic, readonly, assign) BOOL isEmote;
@property (nonatomic, readonly, assign) BOOL isAudioMessage;
@property (nonatomic, readonly, assign) BOOL isExpirable;
@property (nonatomic, readonly, assign) BOOL isFromExternalSource;
@property (nonatomic, readonly, assign) BOOL isCorrupt;

@property (nonatomic, readonly, assign) BOOL wasDataDetected;
@property (nonatomic, readonly, assign) BOOL wasDowngraded;

@property (nonatomic, readwrite, assign) BOOL isSOS;
@property (nonatomic, readwrite, assign) BOOL isSpam;
@property (nonatomic, readwrite, assign) BOOL isBeingRetried;
@property (nonatomic, readwrite, assign) FZErrorType errorCode;

@property (nonatomic, readwrite, nullable, retain) NSDate *timeRead;
@property (nonatomic, readwrite, nullable, retain) NSDate *timeDelivered;
@property (nonatomic, readwrite, nullable, retain) NSDate *timePlayed;

-(void)_updateFlags:(uint64_t)flags;
@end

// IMSharedUtilities
@protocol IMRemoteDaemonProtocol
-(void)loadChatsWithGroupID:(NSString*)groupID queryID:(NSString*)queryID;
-(void)updateMessage:(IMMessageItem*)message;
- (void) loadHistoryForIDs:(NSArray *)chatIdentifiers
                     style:(IMChatStyle)chatStyle
                onServices:(NSArray *)services
                     limit:(NSUInteger)limit
                beforeGUID:(NSString *)GUID
                 afterGUID:(NSString *)afterGUID
                    chatID:(NSString *)chatID
                   queryID:(NSString *)queryID;
@end

NS_ASSUME_NONNULL_END

#endif /* #ifndef PARIS_H */
