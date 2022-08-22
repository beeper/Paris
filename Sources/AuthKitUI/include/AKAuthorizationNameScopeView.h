#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSView.h>

@class AKAuthorizationNameScopeViewController, NSTextField;

@interface AKAuthorizationNameScopeView : NSView
{
    BOOL _mouseDownInValueLabel;
    AKAuthorizationNameScopeViewController *_internalViewController;
    NSTextField *_valueLabel;
}


@property(retain) NSTextField *valueLabel; // @synthesize valueLabel=_valueLabel;
@property BOOL mouseDownInValueLabel; // @synthesize mouseDownInValueLabel=_mouseDownInValueLabel;
@property __weak AKAuthorizationNameScopeViewController *internalViewController; // @synthesize internalViewController=_internalViewController;
- (BOOL)_isEvent:(id)arg1 inFrame:(struct CGRect)arg2;
- (void)mouseUp:(id)arg1;
- (void)mouseDown:(id)arg1;

@end

