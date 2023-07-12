//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>
#import "IMFileTransfer.h"

@class NSArray, NSDictionary, NSMutableArray, NSMutableDictionary, NSMutableSet;

@interface IMFileTransferCenter : NSObject
{
    NSMutableDictionary *_guidToTransferMap;
    NSMutableDictionary *_guidToRemovedTransferMap;
    NSMutableDictionary *_accountIDToTransferGUIDsMap;
    NSMutableArray *_preauthorizedInfos;
    NSMutableArray *_preauthorizedGUIDs;
    NSMutableSet *_activeTransfers;
    NSMutableSet *_pendingTransfers;
    BOOL _disconnectionListenerSetUp;
    NSMutableDictionary *_fetchHighQualityVariantCompletionHandlers;
}

+ (Class)fileTransferClass;
+ (Class)transferCenterClass;
+ (void)setTransferCenterClass:(Class)arg1;
+ (IMFileTransferCenter* _Nonnull)sharedInstance;
- (void)preWarmConnection;
- (void)_daemonRestarted:(id)arg1;
- (void)_initiateHighQualityVariantDownloadWithDaemonForGUID:(id)arg1;
- (void)_fetchHighQualityVariantForTransferGUID:(id)arg1 completion:(id)arg2;
- (void)fetchHighQualityVariantForTransfer:(id)arg1 completion:(id)arg2;
- (id)guidsForStoredAttachmentPayloadData:(id)arg1 messageGUID:(id)arg2;
- (void)setAuxVideoForTransfer:(id)arg1 value:(BOOL)arg2;
- (void)setAuxImageForTransfer:(id)arg1 value:(BOOL)arg2;
- (void)_handleFileTransferHighQualityDownloadFailed:(id)arg1;
- (void)_handleFileTransfer:(id)arg1 highQualityDownloadSucceededWithPath:(id)arg2;
- (void)_handleFileTransfer:(id)arg1 updatedWithCurrentBytes:(unsigned long long)arg2 totalBytes:(unsigned long long)arg3 averageTransferRate:(unsigned long long)arg4;
- (void)_handleFileTransfer:(id)arg1 updatedWithProperties:(id)arg2;
- (void)_handleFileTransfers:(id)arg1 createdWithLocalPaths:(id)arg2;
- (void)_handleFileTransfer:(id)arg1 createdWithProperties:(id)arg2;
- (void)_handleAllFileTransfers:(id)arg1;
- (void)acceptFileTransferIfPreauthorzed:(id)arg1;
- (BOOL)wasFileTransferPreauthorized:(id)arg1;
- (void)preauthorizeFileTransferFromOtherPerson:(id)arg1 account:(id)arg2 filename:(id)arg3 saveToPath:(id)arg4;
- (BOOL)isFileTransfer:(id)arg1 preauthorizedWithDictionary:(id)arg2;
- (void)clearFinishedTransfers;
@property(readonly, nonatomic) NSArray *orderedTransfersGUIDs;
@property(readonly, nonatomic) __weak NSArray *orderedTransfers;
@property(readonly, nonatomic) NSArray *activeTransferGUIDs;
@property(readonly, nonatomic) __weak NSArray *activeTransfers;
@property(readonly, nonatomic) NSDictionary<NSString*, IMFileTransfer*> *transfers;
- (id)transfersForAccount:(id)arg1;
// NOTICE: for retargetTransfer:, arg1 is an IMFileTransfer in < macOS 13.0, and it is an NSString in >= macOS 13.0 (the guid of the transfer)
- (void)retargetTransfer:(id)arg1 toPath:(NSString *)path;
- (void)deleteTransfer:(id)arg1;
- (void)removeTransfer:(id)arg1;
- (void)stopTransfer:(id)arg1;
- (void)acceptTransfer:(id)arg1;
- (void)acceptTransfer:(id)arg1 withPath:(id)arg2 autoRename:(BOOL)arg3 overwrite:(BOOL)arg4;
- (void)sendTransfer:(NSString*)arg1;
- (IMFileTransfer*)transferForGUID:(NSString*)arg1 includeRemoved:(BOOL)arg2;
- (IMFileTransfer*)transferForGUID:(NSString*)arg1;
- (IMChat*)chatForTransfer:(id)arg1;
- (void)registerTransferWithDaemon:(NSString*)arg1;
- (void)assignTransfer:(id)arg1 toHandle:(id)arg2;
- (void)assignTransfer:(id)arg1 toMessage:(id)arg2 account:(id)arg3;
- (void)_addSpotlightProperties:(id)arg1 sender:(id)arg2 recipients:(id)arg3 incoming:(BOOL)arg4;
- (BOOL)registerGUID:(id)arg1 forNewOutgoingTransferWithLocalURL:(id)arg2;
- (NSString*)guidForNewOutgoingTransferWithLocalURL:(NSURL*)arg1;
- (NSString*)guidForNewOutgoingTransferWithLocalURL:(NSURL*)arg1 useLegacyGuid:(BOOL)arg2 API_AVAILABLE(macos(10.16), ios(14.0), watchos(7.0));
- (BOOL)doesLocalURLRequireArchiving:(id)arg1 toHandle:(id)arg2;
- (void)_addTransfer:(IMFileTransfer*)arg1;
- (void)_addTransfer:(IMFileTransfer*)arg1 toAccount:(NSString*)arg2;
- (void)_clearTransfers;
- (void)_removeAllActiveTransfers;
- (void)_removeActiveTransfer:(id)arg1;
- (void)_addActiveTransfer:(id)arg1;
@property(readonly, nonatomic) BOOL hasActiveFileTransfers;
- (void)acknowledgeAllPendingTransfers;
- (void)acknowledgePendingTransfer:(id)arg1;
- (void)_removePendingTransfer:(id)arg1;
- (void)_addPendingTransfer:(id)arg1;
@property(readonly, nonatomic) BOOL hasPendingFileTransfers;
- (void)setIssueSandboxEstensionsForTransfers:(BOOL)issue;
- (BOOL)shouldIssueSandboxEstensionsForTransfers;
- (void)dealloc;

@end

