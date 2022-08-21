//
//  IMFileTransfer_h.h
//  
//
//  Created by Eric Rabil on 8/20/22.
//

#ifndef IMFileTransfer_h
#define IMFileTransfer_h

@interface IMFileTransfer : NSObject
+ (id)guidByStrippingAuxPrefix:(id)arg1;
+ (id)AuxGUIDFromFileTransferGUID:(id)arg1;
+ (BOOL)_doesLocalURLRequireArchiving:(id)arg1;
@property(retain, nonatomic) NSString *originalGUID; // @synthesize originalGUID=_originalGUID;
@property(nonatomic) BOOL appMessageFallbackImage; // @synthesize appMessageFallbackImage=_appMessageFallbackImage;
@property(retain, nonatomic) NSDictionary *attributionInfo; // @synthesize attributionInfo=_attributionInfo;
@property(retain, nonatomic) NSURL *temporaryHighQualityLocalURL; // @synthesize temporaryHighQualityLocalURL=_temporaryHighQualityLocalURL;
@property(retain, nonatomic, setter=_setLocalURL:) NSURL *localURL; // @synthesize localURL=_localURL;
@property(retain, nonatomic) NSString *srCloudKitRecordID; // @synthesize srCloudKitRecordID=_srCloudKitRecordID;
@property(retain, nonatomic) NSData *srCloudKitServerChangeTokenBlob; // @synthesize srCloudKitServerChangeTokenBlob=_srCloudKitServerChangeTokenBlob;
@property(nonatomic) long long srCloudKitSyncState; // @synthesize srCloudKitSyncState=_srCloudKitSyncState;
@property(retain, nonatomic) NSString *cloudKitRecordID; // @synthesize cloudKitRecordID=_cloudKitRecordID;
@property(retain, nonatomic) NSData *cloudKitServerChangeTokenBlob; // @synthesize cloudKitServerChangeTokenBlob=_cloudKitServerChangeTokenBlob;
@property(nonatomic) long long cloudKitSyncState; // @synthesize cloudKitSyncState=_cloudKitSyncState;
@property(nonatomic) BOOL isContact; // @synthesize isContact=_isContact;
@property(nonatomic) BOOL isLocation; // @synthesize isLocation=_isLocation;
@property(retain, nonatomic) NSArray *attachmentSendContexts; // @synthesize attachmentSendContexts=_attachmentSendContexts;
@property(nonatomic) BOOL hideAttachment; // @synthesize hideAttachment=_hideAttachment;
@property(retain, nonatomic) NSDictionary *stickerUserInfo; // @synthesize stickerUserInfo=_stickerUserInfo;
@property(nonatomic) BOOL isSticker; // @synthesize isSticker=_isSticker;
@property(retain, nonatomic) NSDictionary *AuxTranscoderUserInfo; // @synthesize AuxTranscoderUserInfo=_AuxTranscoderUserInfo;
@property(nonatomic) BOOL isAuxVideo; // @synthesize isAuxVideo=_isAuxVideo;
@property(nonatomic) BOOL isAuxImage; // @synthesize isAuxImage=_isAuxImage;
@property(retain, nonatomic) NSDictionary *transcoderUserInfo; // @synthesize transcoderUserInfo=_transcoderUserInfo;
@property(retain, nonatomic) NSString *transferredFilename; // @synthesize transferredFilename=_transferredFilename;
@property(nonatomic, setter=_setNeedsWrapper:) BOOL _needsWrapper; // @synthesize _needsWrapper;
@property(retain, nonatomic) NSDictionary *userInfo; // @synthesize userInfo=_localUserInfo;
@property(nonatomic, setter=_setForceArchive:) BOOL shouldForceArchive; // @synthesize shouldForceArchive=_shouldForceArchive;
@property(nonatomic, setter=setRegisteredAsStandalone:) BOOL wasRegisteredAsStandalone; // @synthesize wasRegisteredAsStandalone=_wasRegisteredAsStandalone;
@property(retain, nonatomic, setter=_setErrorDescription:) NSString *errorDescription; // @synthesize errorDescription=_errorDescription;
@property(nonatomic, setter=_setError:) long long error; // @synthesize error=_error;
@property(nonatomic) BOOL shouldAttemptToResume; // @synthesize shouldAttemptToResume=_shouldAttemptToResume;
@property(nonatomic) BOOL isDirectory; // @synthesize isDirectory=_isDirectory;
@property(nonatomic) unsigned long long averageTransferRate; // @synthesize averageTransferRate=_averageTransferRate;
@property(nonatomic) unsigned long long totalBytes; // @synthesize totalBytes=_totalBytes;
@property(nonatomic) unsigned long long currentBytes; // @synthesize currentBytes=_currentBytes;
@property(retain, nonatomic) NSString *otherPerson; // @synthesize otherPerson=_otherPerson;
@property(retain, nonatomic) NSString *accountID; // @synthesize accountID=_accountID;
@property(nonatomic) unsigned int hfsCreator; // @synthesize hfsCreator=_hfsCreator;
@property(nonatomic) unsigned short hfsFlags; // @synthesize hfsFlags=_hfsFlags;
@property(nonatomic) unsigned int hfsType; // @synthesize hfsType=_hfsType;
@property(retain, nonatomic) NSString *type; // @synthesize type=_utiType;
@property(retain, nonatomic, setter=_setTransferDataURL:) NSURL *transferDataURL; // @synthesize transferDataURL=_transferDataURL;
@property(retain, nonatomic) NSString *filename; // @synthesize filename=_filename;
@property(nonatomic) BOOL isIncoming; // @synthesize isIncoming=_isIncoming;
@property(nonatomic, setter=_setTransferState:) long long transferState; // @synthesize transferState=_transferState;
@property(retain, nonatomic) NSDate *createdDate; // @synthesize createdDate=_createdDate;
@property(retain, nonatomic, setter=_setStartDate:) NSDate *startDate; // @synthesize startDate=_startDate;
@property(retain, nonatomic) NSString *messageGUID; // @synthesize messageGUID=_messageGUID;
@property(retain, nonatomic, nullable) NSString *guid; // @synthesize guid=_guid;
@property(readonly, nonatomic) unsigned long long _lastAveragedBytes; // @synthesize _lastAveragedBytes;
@property(nonatomic, setter=_setLastAveragedInterval:) double _lastAveragedInterval; // @synthesize _lastAveragedInterval;
@property(nonatomic, setter=_setLastUpdatedInterval:) double _lastUpdatedInterval; // @synthesize _lastUpdatedInterval;
- (void)_swizzleTransferStateIfMissingAttachmentCanBeDownloadedFromCloudKit;
- (BOOL)_missingAttachmentCanBeDownloadedFromCloudKit;
- (BOOL)_isCloudKitEnabled;
- (id)_auxVideoPathIfItExists;
- (id)description;
@property(readonly, retain, nonatomic, nullable) NSString *mimeType; // @synthesize mimeType=_mimeType;
@property(retain, nonatomic, setter=_setLocalPath:) NSString *localPath;
@property(readonly, retain, nonatomic) NSString *permanentHighQualityLocalPath;
@property(readonly, retain, nonatomic) NSString *temporaryHighQualityLocalPath;
@property(readonly, nonatomic) BOOL isHEVCWithAlphaVideo;
@property(readonly, nonatomic) BOOL isOpusAudioMessage;
@property(readonly, nonatomic) BOOL isAutoloopVideo;
@property(readonly, nonatomic) BOOL isRecipeBasedSticker;
@property(readonly, nonatomic) BOOL canMarkPurgable;
@property(readonly, nonatomic) BOOL wantsAlphaRemoved;
@property(readonly, nonatomic) BOOL isAnimojiV2;
@property(readonly, nonatomic) BOOL existsAtLocalPath;
@property(readonly, retain, nonatomic) NSString *displayName;
@property(readonly, nonatomic) BOOL isFinished;
@property(readonly, nonatomic) BOOL canBeAccepted;
- (void)_calculateTypeInformation;
- (id)_dictionaryRepresentation;
- (BOOL)_updateWithDictionaryRepresentation:(id)arg1;
- (void)_clear;
- (void)_setDirectory:(BOOL)arg1 hfsType:(unsigned int)arg2 hfsCreator:(unsigned int)arg3 hfsFlags:(unsigned short)arg4;
- (void)_setAveragedTransferRate:(unsigned long long)arg1 lastAveragedInterval:(double)arg2 lastAveragedBytes:(unsigned long long)arg3;
- (void)_setCurrentBytes:(unsigned long long)arg1 totalBytes:(unsigned long long)arg2;
- (void)_setAccount:(id)arg1 otherPerson:(id)arg2;
- (IMFileTransfer*)_initWithGUID:(id)arg1 filename:(id)arg2 isDirectory:(BOOL)arg3 localURL:(id)arg4 account:(id)arg5 otherPerson:(id)arg6 totalBytes:(unsigned long long)arg7 hfsType:(unsigned int)arg8 hfsCreator:(unsigned int)arg9 hfsFlags:(unsigned short)arg10 isIncoming:(BOOL)arg11;
- (id)init;
- (void)dealloc;

@end




#endif /* IMFileTransfer_h */
