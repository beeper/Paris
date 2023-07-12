//
//  IMAudioPreviewGenerator.h
//  
//
//  Created by June Welker on 7/10/23.
//

@interface IMAudioPreviewGenerator
+ (id _Nullable)generateAndPersistMetadataFromSourceURL:(NSURL * _Nonnull)sourceURL withPreviewConstraints:(id _Nullable)constraints error:(NSError * _Nullable * _Nonnull)error;
@end
