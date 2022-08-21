#import <IMAbstractDatabaseArchiver.h>
#import <IMAbstractDatabaseTrimmer.h>
#import <IMDAbstractDatabaseDowngrader.h>
#import <IMDCNAliasResolver.h>
#import <IMDCNPersonAliasResolver.h>
#import <IMDCoreSpotlightBaseIndexer.h>
#import <IMDCoreSpotlightChatParticipant.h>
#import <IMDCoreSpotlightContactCache.h>
#import <IMDCoreSpotlightDispatchObject.h>
#import <IMDCoreSpotlightIndexer.h>
#import <IMDCoreSpotlightManager.h>
#import <IMDCoreSpotlightMessageAttachmentIndexer.h>
#import <IMDCoreSpotlightMessageBalloonPluginIndexer.h>
#import <IMDCoreSpotlightMessageBodyIndexer.h>
#import <IMDCoreSpotlightMessageDataDetectorsIndexer.h>
#import <IMDCoreSpotlightMessageMetadataIndexer.h>
#import <IMDCoreSpotlightMessageSubjectIndexer.h>
#import <IMDCoreSpotlightRecipientIndexer.h>
#import <IMDDatabaseDowngradeHelper.h>
#import <IMDHistoryAppKitToSuperParserContext.h>
#import <IMDHistoryAttachment.h>
#import <IMDHistoryHandle.h>
#import <IMDHistoryImporter.h>
#import <IMDHistoryMessage.h>
#import <IMDHistoryUnarchiver.h>
#import <IMDMessageAutomaticHistoryDeletion.h>
#import <IMDNotificationsController.h>
#import <IMDPersistence.h>
#import <IMDPersistentAttachmentController.h>
#import <IMDSqlQuery.h>
#import <IMDSqlSelectQuery.h>
#import <IMDSuggestions.h>
#import <IMDTaskProgress.h>
#import <IMDWhitetailToCoralDowngradeHelper.h>
#import <IMDWhitetailToCoralDowngrader.h>
#import <IMDatabaseAnonymizer.h>
#import <IMTrimDatabaseToDays.h>
#import <IMTrimDatabaseToMessageCount.h>
#import <NSCoding.h>
#import <NSObject.h>
#import <SGMessagesSuggestionsServiceDelegate.h>
#import <IMSharedUtilities.h>

struct IMDSqlOperation {
    
};

struct CSDBSqliteDatabase {
    
};

CFArrayRef IMDAttachmentRecordCopyPurgedAttachmentsForChatIdentifiersOnServices(CFArrayRef chatIdentifiers, CFArrayRef services, NSInteger limit) CF_RETURNS_RETAINED;

CFStringRef IMDMessageRecordCopyGUID(CFAllocatorRef, IMDMessageRecordRef);

struct CSDBSqliteDatabase *IMDSharedSqliteDatabase();
void IMDEnsureSharedRecordStoreInitialized();
//NSArray *_IMDSqlOperationGetRowsWithBindingBlock(IMDSqlOperation *, CFStringRef, dispatch_block_t);
//NSArray *_IMDSqlOperationGetRowsForQueryWithBindingBlock(CFStringRef, NSError **, void (^)(id));
void IMDSetIsRunningInDatabaseServerProcess(char);
BOOL IMDIsRunningInDatabaseServerProcess(void);

typedef struct _IMDChatRecordStruct *IMDChatRecordRef;
typedef struct _IMDMessageRecordStruct *IMDMessageRecordRef;

NSArray* IMDMessageRecordCopyMessagesForRowIDs(NSArray*);

IMItem * IMDCreateIMItemFromIMDMessageRecordRefWithServiceResolve(id messageRecord, NSString * inputHandleString, BOOL useAttachmentCache, NSString *(^serviceResolve)(NSString *account, NSString *serviceName)) API_DEPRECATED("", macos(10.0,12.0), ios(3.0,15.0),watchos(1.0,8.0)) NS_RETURNS_RETAINED;

IMItem * IMDCreateIMItemFromIMDMessageRecordRefWithAccountLookup(id messageRecord, NSString * inputHandleString, BOOL useAttachmentCache, NSString *(^accountLookup)(NSString *account, NSString *serviceName)) NS_RETURNS_RETAINED API_AVAILABLE(macos(12.0), ios(15.0), watchos(8.0));

_Nullable CFArrayRef IMDMessageRecordCopyMessagesForGUIDs(id) CF_RETURNS_RETAINED;
id IMDAttachmentRecordCopyAttachmentForGUID(CFStringRef) CF_RETURNS_RETAINED;

int64_t IMDMessageRecordGetIndentifierForMessageWithGUID(CFStringRef guid);
IMDChatRecordRef IMDChatRecordCopyChatForMessageID(int64_t messageID) CF_RETURNS_RETAINED;
int64_t IMDChatRecordCachedUnreadCount(IMDChatRecordRef chat);
CFStringRef IMDChatRecordCopyGUID(CFAllocatorRef allocator, IMDChatRecordRef chat) CF_RETURNS_RETAINED;
IMDMessageRecordRef IMDMessageRecordCopyMessageForGUID(CFStringRef guid) CF_RETURNS_RETAINED;
int64_t IMDMessageRecordGetIdentifier(IMDMessageRecordRef message);

//CFArrayRef IMDMessageRecordCopyArrayOfAssociatedMessagesForMessageGUIDFromSender(NSString *, NSString *, NSError **) CF_RETURNS_RETAINED;
//CFArrayRef IMDMessageRecordCopyMessagesForAssociatedGUID(NSString *) CF_RETURNS_RETAINED;
//CFArrayRef IMDMessageRecordCopyMessagesWithChatIdentifiersOnServicesUpToGUIDOrLimit(CFArrayRef, CFArrayRef, CFStringRef, Boolean, Boolean, int64_t) CF_RETURNS_RETAINED;
//CFArrayRef IMDMessageRecordCopyMessagesWithChatIdentifiersOnServicesUpToGUIDOrLimitWithOptionalThreadIdentifier(CFArrayRef, CFArrayRef, CFStringRef, CFStringRef, Boolean, Boolean, int64_t) CF_RETURNS_RETAINED;

typedef struct _IMDChatRecordStruct *IMDChatRecordRef;
IMDChatRecordRef IMDChatRecordCopyChatForMessageID(int64_t messageID) CF_RETURNS_RETAINED;
CFStringRef IMDChatRecordCopyGUID(CFAllocatorRef allocator, IMDChatRecordRef chat) CF_RETURNS_RETAINED;
