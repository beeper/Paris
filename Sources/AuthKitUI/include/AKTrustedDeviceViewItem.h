#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

//#import <AppKit/NSCollectionViewItem.h>

@class NSImageView, NSTextField;

@interface AKTrustedDeviceViewItem : NSObject
{
    BOOL _hideSelectedState;
    NSTextField *_mainTextField;
    NSTextField *_subTextField;
    NSImageView *_mainImageView;
}

+ (id)keyPathsForValuesAffectingShouldDrawSelected;
@property BOOL hideSelectedState; // @synthesize hideSelectedState=_hideSelectedState;
@property NSImageView *mainImageView; // @synthesize mainImageView=_mainImageView;
@property NSTextField *subTextField; // @synthesize subTextField=_subTextField;
@property NSTextField *mainTextField; // @synthesize mainTextField=_mainTextField;
@property(readonly) BOOL shouldDrawSelected;
- (void)awakeFromNib;

@end

