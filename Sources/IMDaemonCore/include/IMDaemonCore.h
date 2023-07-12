#import <Foundation/Foundation.h>

@class IMFileTransfer, IMMessageItem;

typedef struct _IMDAttachmentRecordStruct *IMDAttachmentRecordRef;

IMFileTransfer *IMFileTransferFromIMDAttachmentRecordRef(IMDAttachmentRecordRef attachmentRecord) NS_RETURNS_RETAINED;

NS_ASSUME_NONNULL_BEGIN

@interface IMDCKAttachmentSyncController : NSObject
+(instancetype)sharedInstance;

typedef void (^IMAttachmentSyncPerTransferProgressBlock)(IMFileTransfer *transfer, float percentComplete, BOOL complete, NSError * _Nullable error);
typedef void (^IMAttachmentSyncFetchOperationCompletionBlock)(NSError * _Nullable error, NSArray<IMFileTransfer *> *failedTransfers);

- (void) fetchAttachmentDataForTransfers:(NSArray *)transfers
                             highQuality:(BOOL)highQuality
               useNonHSA2ManateeDatabase:(BOOL)useNonHSA2ManateeDatabase
                     perTransferProgress:(IMAttachmentSyncPerTransferProgressBlock)perTransferProgress
                              completion:(IMAttachmentSyncFetchOperationCompletionBlock)completion;

@end

@interface IMDMessageStore: NSObject
+(instancetype)sharedInstance;
- (IMMessageItem *) storeMessage:(IMMessageItem *)message forceReplace:(BOOL)force modifyError:(BOOL)modifyError modifyFlags:(BOOL)modifyFlags flagMask:(uint64_t)flagMask updateMessageCache:(BOOL)updateMessageCache calculateUnreadCount:(BOOL)calculateUnreadCount;
- (IMMessageItem *) storeMessage:(IMMessageItem *)message forceReplace:(BOOL)force modifyError:(BOOL)modifyError modifyFlags:(BOOL)modifyFlags flagMask:(uint64_t)flagMask;
- (void)setSuppressDatabaseUpdates:(BOOL)suppress;
- (BOOL)isSuppressDatabaseUpdates;
@end

@interface IMDService
@end

@interface IMDChat: NSObject
- (int)smsHandshakeState;
- (void)updateSMSHandshakeState:(int)newState;
- (NSDictionary<NSString *, id>* _Nullable)properties;
- (NSString * _Nullable)serviceName;
- (IMDService * _Nullable)service;
- (NSString * _Nullable)accountID;
@end

@interface IMDChatRegistry: NSObject
+ (instancetype)sharedInstance;
- (IMDChat * _Nullable)existingChatWithGUID:(NSString * _Nonnull)guid;
@end

@interface IMDFileTransfer: NSObject
@end

@interface IMDFileTransferCenter: NSObject
- (NSArray * _Nonnull)sizePreviewsForTransferGUIDs:(NSArray<NSString *> * _Nonnull)guids;
- (IMDFileTransfer * _Nullable)transferForGUID:(NSString * _Nonnull)guid;
- (BOOL)_transferRequiresPreviewSizing:(IMDFileTransfer * _Nonnull)transfer;
- (NSDictionary<NSString *, IMDFileTransfer *> * _Nonnull)guidToTransferMap;
- (id)_clientPreviewConstraints;
+ (instancetype)sharedInstance;
@end

/*@interface IMTransferServicesController (PreviewGeneration)
- (float)generatePreviewForTransfer:(IMFileTransfer * _Nonnull)transfer
                     attachmentPath:(NSString *)path
                    balloonBundleID:(NSString * _Nullable)balloonBundleID
                           isFromMe:(BOOL)fromMe
                    completionBlock:(void (^)(NSString * _Nullable, id arg1, id arg2))completionBlock;
@end*/

NS_ASSUME_NONNULL_END
