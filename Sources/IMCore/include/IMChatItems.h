//
//  IMChatItems.h
//  
//
//  Created by Eric Rabil on 8/20/22.
//

#ifndef IMChatItems_h
#define IMChatItems_h

@class IMBalloonPluginDataSource, IMMessageChatItem, NSData, NSString, IMHandle, IMMessage;
@class IMServiceImpl;

@protocol IMGUIDProtocol;

@protocol IMGUIDItem <IMGUIDProtocol>
@property(copy, nonatomic, setter=_setGUID:) NSString *guid;
@end

@protocol IMChatTranscriptItem
@property(readonly, nonatomic) IMHandle *handle;
@property(readonly, nonatomic) IMServiceImpl *service;
@property(readonly, nonatomic) NSDate *transcriptDate;
@property(readonly, copy, nonatomic) NSAttributedString *transcriptText;
@property(readonly, nonatomic) BOOL wantsTail;
@property(readonly, nonatomic, getter=isFromMe) BOOL fromMe;
@end

@interface IMChatItem : NSObject
@property(readonly, retain, nonatomic) NSString *balloonBundleID;
- (void)_setTimeAdded:(id)arg1;
- (NSDate*)_timeAdded;
- (id)_timeStale;
- (IMItem*)_item;
- (id)_initWithItem:(id)arg1;
@property(readonly, nonatomic) BOOL canDelete;
- (BOOL)itemIsThreadOriginator API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (BOOL)itemIsThreadOriginatorWithThreadIdentifier:(NSString*)arg1 API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (NSString*)threadGroupIdentifier API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (BOOL) itemIsReply API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (BOOL) itemIsReplyContextPreview API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (BOOL) itemIsReplyCount API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (BOOL) canReply API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
@end

@interface IMTranscriptChatItem : IMChatItem <IMChatTranscriptItem, IMGUIDItem>
@property(copy, nonatomic, setter=_setGUID:) NSString *guid;
- (void)_setAttachmentContiguousType:(unsigned char)arg1;
- (void)_setContiguousType:(unsigned char)arg1;
- (void)_setContiguousLoaded:(BOOL)arg1;
- (BOOL)_isContiguousLoaded;
@property(readonly, nonatomic) IMHandle *handle;
@property(readonly, nonatomic) IMServiceImpl *service;
@property(readonly, nonatomic) NSDate *transcriptDate;
@property(readonly, copy, nonatomic) NSAttributedString *transcriptText;
@property(readonly, nonatomic) BOOL wantsTail;
@property(readonly, nonatomic, getter=isFromMe) BOOL fromMe;
@property(readonly, nonatomic, getter=isContiguous) BOOL contiguous;
@property(readonly, nonatomic) unsigned char attachmentContiguousType;
@property(readonly, nonatomic) unsigned char contiguousType;
- (BOOL)isAttachmentContiguousWithChatItem:(id)arg1;
- (BOOL)isContiguousWithChatItem:(id)arg1;
- (BOOL)isEqual:(id)arg1;
@end

@interface IMAssociatedMessageChatItem : IMTranscriptChatItem
@property(readonly, nonatomic) IMHandle *sender; // @synthesize sender=_sender;
@property(readonly, nonatomic) struct IMAssociatedMessageGeometryDescriptor geometryDescriptor; // @synthesize geometryDescriptor=_geometryDescriptor;
@property(readonly, nonatomic) NSDictionary *messageSummaryInfo;
@property(readonly, nonatomic) BOOL failed;
- (void)_setParentMessageIsFromMe:(BOOL)arg1;
@property(readonly, nonatomic) BOOL parentMessageIsFromMe;
@property(readonly, nonatomic) struct _NSRange associatedMessageRange;
@property(readonly, nonatomic) long long associatedMessageType;
@property(readonly, nonatomic) NSString *associatedMessageGUID;
@property(readonly, nonatomic) BOOL isFromMe;
@property(readonly, nonatomic) NSDate *time;
- (id)message;
- (id)_imAssociatedMessageItem;
- (id)_initWithItem:(id)arg1 sender:(id)arg2;
@end

@interface IMAssociatedStickerChatItem : IMAssociatedMessageChatItem
@property(readonly, copy, nonatomic) NSString *transferGUID;
- (id)_initWithItem:(id)arg1 sender:(id)arg2 transferGUID:(id)arg3;
- (BOOL)canDelete;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)description;
@end

@interface IMMessageChatItem : IMTranscriptChatItem
@property(readonly, nonatomic) IMHandle *sender;
@property(readonly, nonatomic) NSDate *time;
@property(readonly, nonatomic) BOOL failed;
@property(readonly, nonatomic) BOOL isFromMe;
@property(readonly, nonatomic) IMMessage *message;
@end

@interface IMMessagePartChatItem : IMMessageChatItem
+ (BOOL)isSiriEnabled;
+ (id)_messageItemWithPartsDeleted:(id)arg1 fromMessageItem:(id)arg2;
+ (BOOL)_shouldAggregateForTransferType:(id)arg1;
+ (id)_newMessagePartsForMessageItem:(id)arg1 shouldDisplayLink:(BOOL)arg2 isBusiness:(BOOL)arg3 parentChatIsSpam:(BOOL)arg4 hasKnownParticipants:(BOOL)arg5;
+ (BOOL)_supportsRichLinkURL:(id)arg1 forSender:(id)arg2 isWhitelistedRichLinkSender:(BOOL)arg3;
+ (id)_richLinkRangesForMessageText:(id)arg1 sender:(id)arg2 isWhitelistedRichLinkSender:(BOOL)arg3;
+ (id)_additionalSupportedRichLinkSchemesForWhitelistedSender:(id)arg1;
+ (BOOL)_isWhitelistedRichLinkSender:(id)arg1 isBusiness:(BOOL)arg2;
+ (BOOL)_isWhiteListedURL:(id)arg1;
+ (id)_defaultRichLinkWhiteList;
+ (id)_newMessagePartsForMessageItem:(id)arg1;
+ (id)_guidForMessage:(id)arg1 url:(id)arg2;
@property(nonatomic, getter=isWhitelistedRichLinkSender) BOOL whitelistedRichLinkSender; // @synthesize whitelistedRichLinkSender=_whitelistedRichLinkSender;
@property(readonly, copy, nonatomic) NSAttributedString *fallbackCorruptText; // @synthesize fallbackCorruptText=_fallbackCorruptText;
@property(nonatomic) BOOL chatInScrutinyMode; // @synthesize chatInScrutinyMode=_chatInScrutinyMode;
@property(readonly, nonatomic) NSArray *messageEditChatItems; // @synthesize messageEditChatItems=_messageEditChatItems;
@property(retain, nonatomic, setter=_setVisibleAssociatedMessageChatItems:) NSArray *visibleAssociatedMessageChatItems; // @synthesize visibleAssociatedMessageChatItems=_visibleAssociatedMessageChatItems;
@property(nonatomic) struct _NSRange messagePartRange; // @synthesize messagePartRange=_messagePartRange;
@property(nonatomic) long long index; // @synthesize index=_index;
@property(readonly, copy, nonatomic, nullable) NSAttributedString *text; // @synthesize text=_text;
@property(readonly, nonatomic) BOOL requiresSiriAttribution;
- (BOOL)canSendMessageAcknowledgment;
- (void)_setMessageEditChatItems:(id)arg1;
- (id)_initWithItem:(id)arg1 text:(id)arg2 index:(long long)arg3 messagePartRange:(struct _NSRange)arg4 visibleAssociatedMessageChatItems:(id)arg5;
- (id)_initWithItem:(id)arg1 messagePartRange:(struct _NSRange)arg2;
@property(readonly, nonatomic) BOOL isCorrupt;
- (id)transcriptText;
@property(nonatomic) BOOL isBusiness; // @synthesize isBusiness=_isBusiness;
- (BOOL)canDelete;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (NSString*) threadIdentifier API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (IMMessageItem*) threadOriginator API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
@end



@interface IMTypingChatItem : IMMessageChatItem
- (id)_initWithItem:(id)arg1;
@end

@interface IMTypingPluginChatItem : IMTypingChatItem
@property(retain, nonatomic) IMBalloonPluginDataSource *dataSource;
@property(readonly, nonatomic) NSData *typingIndicatorIcon;
@property(readonly, retain, nonatomic) NSString *type;
@property(readonly, nonatomic) BOOL isFromMe;
- (id)_initWithItem:(id)arg1 dataSource:(id)arg2;
@end



#endif /* IMChatItems_h */
