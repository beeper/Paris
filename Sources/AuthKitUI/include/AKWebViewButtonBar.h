#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@protocol NSTouchBarProvider;

@class AKTouchBarController, NSArray, NSButton, NSDictionary, NSProgressIndicator, NSString, NSTextField, NSTouchBar, NSView;
@protocol AKWebViewButtonBarDelegate;

@interface AKWebViewButtonBar : NSObject <NSTouchBarProvider>
{
    NSView *_buttonBarView;
    NSButton *_button1;
    NSButton *_button2;
    NSButton *_button3;
    NSProgressIndicator *_spinner;
    NSTextField *_spinnerTitle;
    NSButton *_helpButton;
    NSDictionary *_buttonBarDict;
    NSArray *_buttonArray;
     id  _delegate;
    AKTouchBarController *_touchBarController;
}


@property(retain) AKTouchBarController *touchBarController; // @synthesize touchBarController=_touchBarController;
@property __weak  id  delegate; // @synthesize delegate=_delegate;
@property(retain) NSDictionary *buttonBarDict; // @synthesize buttonBarDict=_buttonBarDict;
- (void)updateDefaultButtons;
- (void)updateButtonBarDict:(id)arg1;
- (void)disableSpinner;
- (void)disableButtons;
- (void)helpPressed:(id)arg1;
- (void)button3Pressed:(id)arg1;
- (void)button2Pressed:(id)arg1;
- (void)button1Pressed:(id)arg1;
- (id)buttonBarView;
@property(readonly) NSTouchBar *touchBar;
- (id)initWithDict:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end
