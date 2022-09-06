//
//  LinkPresentation.h
//  paris
//
//  Created by Eric Rabil on 8/16/22.
//

#ifndef LinkPresentation_h
#define LinkPresentation_h

#include <LinkPresentation/LinkPresentation.h>

@class LPAudioMetadata;
@class LPIconMetadata;
@class LPImageMetadata;
@class LPVideoMetadata;
@class LPImage;
@class LPVideo;
@class LPAudio;

@interface LPLinkMetadata (Private)
@property (nonatomic, copy, nullable) NSURL *URL;
@property (nonatomic, copy, nullable) NSString *title;
@property (nonatomic, copy, nullable) NSString *summary;
@property (nonatomic, copy, nullable) NSString *selectedText;
@property (nonatomic, copy, nullable) NSString *siteName;
@property (nonatomic, copy, nullable) NSString *itemType;
@property (nonatomic, copy, nullable) NSURL *relatedURL;
@property (nonatomic, copy, nullable) NSString *creator;
@property (nonatomic, copy, nullable) NSString *creatorFacebookProfile;
@property (nonatomic, copy, nullable) NSString *creatorTwitterUsername;
@property (nonatomic, copy, nullable) NSArray<LPIconMetadata *> *icons;
@property (nonatomic, copy, nullable) NSArray<LPImageMetadata *> *images;
@property (nonatomic, copy, nullable) NSArray<LPVideoMetadata *> *videos;
@property (nonatomic, copy, nullable) NSArray<LPVideoMetadata *> *streamingVideos;
@property (nonatomic, copy, nullable) NSArray<LPAudioMetadata *> *audios;
@property (nonatomic, retain, nullable) LPImage *icon;
@property (nonatomic, retain, nullable) LPIconMetadata *iconMetadata;
@property (nonatomic, retain, nullable) LPImage *image;
@property (nonatomic, retain, nullable) LPImageMetadata *imageMetadata;
@property (nonatomic, retain, nullable) LPVideo *video;
@property (nonatomic, retain, nullable) LPVideoMetadata *videoMetadata;
@property (nonatomic, retain, nullable) LPAudio *audio;
@property (nonatomic, retain, nullable) LPAudioMetadata *audioMetadata;
@end

@interface LPVideoProperties: NSObject
@property (nonatomic, assign) BOOL hasAudio;
@property (nonatomic, copy) NSString *accessibilityText;
@end

@interface LPImageProperties: NSObject
@property (nonatomic, copy) NSString *accessibilityText;
@end

@interface LPAudioProperties: NSObject
@property (nonatomic, copy) NSString *accessibilityText;
@end

@interface LPIconMetadata: NSObject
@property (nonatomic, readonly) uint32_t version;
@property (nonatomic, copy, nullable) NSURL *URL;
@property (nonatomic, copy, nullable) NSString *type;
@property (nonatomic, copy, nullable) NSString *accessibilityText;
@end

@interface LPImageMetadata: NSObject
@property (nonatomic, readonly) uint32_t version;
@property (nonatomic, copy, nullable) NSURL *URL;
@property (nonatomic, copy, nullable) NSString *type;
@property (nonatomic, copy, nullable) NSString *accessibilityText;
@property (nonatomic, assign) CGSize size;
@end

@interface LPVideoMetadata: NSObject
@property (nonatomic, readonly) uint32_t version;
@property (nonatomic, copy, nullable) NSURL *URL;
@property (nonatomic, copy, nullable) NSString *type;
@property (nonatomic, copy, nullable) NSString *accessibilityText;
@property (nonatomic, assign) CGSize size;
@end

@interface LPAudioMetadata: NSObject
@property (nonatomic, readonly) uint32_t version;
@property (nonatomic, copy, nullable) NSURL *URL;
@property (nonatomic, copy, nullable) NSString *type;
@property (nonatomic, copy, nullable) NSString *accessibilityText;
@end

@interface LPImage: NSObject
@property (nonatomic, copy, readonly, nullable) NSData *data;
@property (nonatomic, copy, readonly, nullable) NSString *MIMEType;
@property (nonatomic, retain, nullable) NSURL *fileURL;
- (instancetype)initByReferencingFileURL:(NSURL *)fileURL MIMEType:(NSString *)MIMEType;
- (instancetype)initWithData:(NSData *)data MIMEType:(NSString *)MIMEType;
- (instancetype)initByReferencingFileURL:(NSURL *)fileURL MIMEType:(NSString *)MIMEType properties:(LPImageProperties *)properties;
- (instancetype)initWithData:(NSData *)data MIMEType:(NSString *)MIMEType properties:(LPImageProperties *)properties;
@end

@interface LPVideo: NSObject
@property (nonatomic, copy, readonly, nullable) NSData *data;
@property (nonatomic, copy, readonly, nullable) NSString *MIMEType;
@property (nonatomic, retain, nullable) NSURL *fileURL;
@property (nonatomic, retain, readonly, nullable) NSURL *streamingURL;
@property (nonatomic, retain, readonly, nullable) NSURL *youTubeURL;
@property (nonatomic, readonly) BOOL hasAudio;
- (instancetype)initByReferencingFileURL:(NSURL *)fileURL MIMEType:(NSString *)MIMEType;
- (instancetype)initWithData:(NSData *)data MIMEType:(NSString *)MIMEType;
- (instancetype)initByReferencingFileURL:(NSURL *)fileURL MIMEType:(NSString *)MIMEType properties:(LPVideoProperties *)properties;
- (instancetype)initWithData:(NSData *)data MIMEType:(NSString *)MIMEType properties:(LPVideoProperties *)properties;
- (instancetype)initWithStreamingURL:(NSURL *)URL hasAudio:(BOOL)hasAudio;
- (instancetype)initWithStreamingURL:(NSURL *)URL properties:(LPVideoProperties *)properties;
- (instancetype)initWithYouTubeURL:(NSURL *)URL;
- (instancetype)initWithYouTubeURL:(NSURL *)URL properties:(LPVideoProperties *)properties;
@end

@interface LPAudio: NSObject
@property (nonatomic, copy, readonly, nullable) NSData *data;
@property (nonatomic, copy, readonly, nullable) NSString *MIMEType;
@property (nonatomic, retain, nullable) NSURL *fileURL;
- (instancetype)initByReferencingFileURL:(NSURL *)fileURL MIMEType:(NSString *)MIMEType;
- (instancetype)initWithData:(NSData *)data MIMEType:(NSString *)MIMEType;
- (instancetype)initByReferencingFileURL:(NSURL *)fileURL MIMEType:(NSString *)MIMEType properties:(LPAudioProperties *)properties;
- (instancetype)initWithData:(NSData *)data MIMEType:(NSString *)MIMEType properties:(LPAudioProperties *)properties;
@end


#endif /* LinkPresentation_h */
