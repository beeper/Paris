//
//  IMTransferServices.h
//  
//
//  Created by June Welker on 7/10/23.
//

#include <Foundation/Foundation.h>

@class IMDFileTransfer;

@interface IMTransferServicesController: NSObject
+ (instancetype _Nonnull)sharedInstance;
// Technically, the `generatePreviewForTransfer:` method should be in IMDaemonCore 'cause it's defined there in a category
// but that's causing linking issues and such so we're just gonna define it here for now
- (float)generatePreviewForTransfer:(IMDFileTransfer * _Nonnull)transfer
                     attachmentPath:(NSString * _Nonnull)path
                    balloonBundleID:(NSString * _Nullable)balloonBundleID
                           isFromMe:(BOOL)fromMe
                    completionBlock:(void (^_Nonnull)(NSString * _Nullable, id _Nullable arg1, id _Nullable arg2))completionBlock;
@end
