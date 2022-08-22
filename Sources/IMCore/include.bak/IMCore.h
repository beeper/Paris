#ifndef IMCore_H
#define IMCore_H

#include <Foundation/Foundation.h>
#include <IMFoundation.h>
#include <IMSharedUtilities.h>
#include <IMChatItems.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IMGUIDProtocol
@property(retain, nonatomic, readonly) NSString* guid NS_SWIFT_NAME(id);
@end

@protocol IMRemoteDaemonProtocol, IMDaemonListenerProtocol;

// IMCore
@interface IMService: NSObject
+(instancetype)SMS;
+(instancetype)iMessage;
@property (nonatomic, readonly, strong) NSString* name;
@property (nonatomic, readonly, strong) NSArray<NSString*>* accountIDs;
@end

// IMCore
@interface IMServiceImpl: IMService
@end

// IMCore
@interface IMHandle: NSObject <IMGUIDProtocol>
+(instancetype _Nullable)bestIMHandleInArray:(NSArray<IMHandle*> *)imHandles;
@property (nonatomic, readonly, weak) IMServiceImpl * service;
@property (nonatomic, readonly, assign) BOOL isLoginIMHandle;
@property (nonatomic, readonly, assign) BOOL isBusiness;
@property (nonatomic, readonly, retain) NSString * guid;
@end

// IMCore
@interface IMAccount: NSObject
@property (nonatomic, readonly, weak) IMServiceImpl* service;
@property (nonatomic, readonly, strong) NSString* name;
@property (nonatomic, readonly, strong) NSString* shortName;
@property (nonatomic, readonly, strong) NSString* serviceName;
@property (nonatomic, readonly, strong) IMHandle* loginIMHandle;
@property (nonatomic, readonly, strong) NSString *uniqueID;
@end

// IMCore
@interface IMAccountController: NSObject
+(instancetype)sharedInstance;
-(IMAccount* _Nullable)bestAccountForService:(IMService*)service;
@end

// IMCore
@interface IMMessage: NSObject <IMGUIDProtocol>
@property (nonatomic, readwrite, retain) NSString *guid;
@property (nonatomic, readwrite, copy, nullable, setter=_messageSummaryInfo:) NSDictionary* messageSummaryInfo;
@end

// IMCore
@interface IMChat: NSObject <IMGUIDProtocol>
@property (nonatomic, readwrite, retain) NSString *guid;
@property (nonatomic, readwrite, strong) NSString *lastAddressedHandleID;
@property (nonatomic, readwrite, strong) NSString *lastAddressedSIMID;
@property (nonatomic, nullable, strong) IMHandle * recipient;
@property (nonatomic, readwrite, strong, setter=_setAccount:) IMAccount * account;
- (instancetype)_initWithDictionaryRepresentation:(NSDictionary*)arg1 items:(id _Nullable)arg2 participantsHint:(id _Nullable)arg3 accountHint:(id _Nullable)arg4;
@property (nonatomic, readonly, strong) NSArray<IMHandle*> * participants;

@property (nonatomic, readonly, assign) IMChatStyle chatStyle;

-(void)sendMessage:(IMMessage*)message;
-(void)_targetToService:(IMService*)service newComposition:(BOOL)newComposition;
@end

// IMCore
@interface IMChatRegistry: NSObject
@property (nonatomic, readonly, strong) NSArray<IMChat*> * allExistingChats;
+(instancetype) sharedInstance;

-(IMChat* _Nullable)existingChatWithGUID:(NSString*)guid;
-(IMChat* _Nullable)existingChatWithChatIdentifier:(NSString*)chatIdentifier;
-(IMChat* _Nullable)existingChatWithGroupID:(NSString*)chatIdentifier;

-(NSString*)_sortedParticipantIDHashForParticipants:(NSArray<IMHandle*>*)participants;
-(void)_addChat:(IMChat*)chat participantSet:(NSString*)set;
@end

// IMCore
@interface IMDaemonListener: NSObject
-(void)addHandler:(id<IMDaemonListenerProtocol>)arg1;
-(void)removeHandler:(id<IMDaemonListenerProtocol>)handler;

@property (nonatomic, readonly, strong) NSDictionary * properties;
@property (nonatomic, readonly, strong) NSDictionary * persistentProperties;

- (id) valueOfProperty:(NSString *)property;
- (id) valueOfPersistentProperty:(NSString *)property;
@end

// IMCore
@interface IMDaemonController: NSObject <IMRemoteDaemonProtocol>
+(instancetype) sharedInstance;
+(instancetype) sharedController;
@property (nonatomic,readonly,strong) IMDaemonListener* listener;
-(id<IMRemoteDaemonProtocol>)synchronousReplyingRemoteDaemon;

@property (nonatomic, readonly, assign) BOOL isConnected;

-(BOOL)addListenerID:(NSString *)ID capabilities:(FZListenerCapabilities)caps;

-(BOOL)connectToDaemon;
-(void)blockUntilConnected;
@end

@interface IMMessageItem ()
@property (nonatomic, readonly, strong) IMMessage* message;
@end

NS_ASSUME_NONNULL_END

#endif /* #ifndef PARIS_H */
