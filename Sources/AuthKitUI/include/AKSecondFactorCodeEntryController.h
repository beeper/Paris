#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSViewController.h>

#import <AKPinFieldViewDelegate-Protocol.h>
@protocol NSTouchBarProvider;

@class AKNoCodeReceivedController, AKPinFieldView, AKTouchBarController, NSButton, NSImage, NSImageCell, NSLayoutConstraint, NSNumber, NSObject, NSProgressIndicator, NSString, NSTextField, NSTouchBar, NSView;
@protocol AKSecondFactorCodeEntryDelegate;

@interface AKSecondFactorCodeEntryController : NSViewController <NSTouchBarProvider, AKPinFieldViewDelegate>
{
    BOOL _isCodeEditable;
    NSView *_mainView;
    NSObject<AKSecondFactorCodeEntryDelegate> *_delegate;
    NSView *_pinContainerView;
    NSTextField *_instructionLabel;
    NSTextField *_errorLabel;
    NSImageCell *_imageView;
    NSProgressIndicator *_progressIndicator;
    NSButton *_noCodeButton;
    NSButton *_cancelButton;
    NSButton *_doneButton;
    NSLayoutConstraint *_widthOfPinViewConstraint;
    NSLayoutConstraint *_dontShowErrorConstraint;
    NSLayoutConstraint *_showErrorConstraint;
    id _noCodeButtonAction;
    id _cancelButtonAction;
    id _doneButtonAction;
    NSImage *_displayImage;
    AKPinFieldView *_pinView;
    NSString *_code;
    NSNumber *_pinCodeLength;
    AKNoCodeReceivedController *_noCodeRecievedController;
    AKTouchBarController *_touchBarController;
}


@property(retain) AKTouchBarController *touchBarController; // @synthesize touchBarController=_touchBarController;
@property(retain) AKNoCodeReceivedController *noCodeRecievedController; // @synthesize noCodeRecievedController=_noCodeRecievedController;
@property(retain) NSNumber *pinCodeLength; // @synthesize pinCodeLength=_pinCodeLength;
@property(retain) NSString *code; // @synthesize code=_code;
@property(retain) AKPinFieldView *pinView; // @synthesize pinView=_pinView;
@property(setter=setCodeEditable:) BOOL isCodeEditable; // @synthesize isCodeEditable=_isCodeEditable;
@property(retain, nonatomic, setter=setDisplayImage:) NSImage *displayImage; // @synthesize displayImage=_displayImage;
@property(copy) id doneButtonAction; // @synthesize doneButtonAction=_doneButtonAction;
@property(copy) id cancelButtonAction; // @synthesize cancelButtonAction=_cancelButtonAction;
@property(copy) id noCodeButtonAction; // @synthesize noCodeButtonAction=_noCodeButtonAction;
@property(retain) NSLayoutConstraint *showErrorConstraint; // @synthesize showErrorConstraint=_showErrorConstraint;
@property(retain) NSLayoutConstraint *dontShowErrorConstraint; // @synthesize dontShowErrorConstraint=_dontShowErrorConstraint;
@property(retain) NSLayoutConstraint *widthOfPinViewConstraint; // @synthesize widthOfPinViewConstraint=_widthOfPinViewConstraint;
@property(retain) NSButton *doneButton; // @synthesize doneButton=_doneButton;
@property(retain) NSButton *cancelButton; // @synthesize cancelButton=_cancelButton;
@property(retain) NSButton *noCodeButton; // @synthesize noCodeButton=_noCodeButton;
@property(retain) NSProgressIndicator *progressIndicator; // @synthesize progressIndicator=_progressIndicator;
@property(retain) NSImageCell *imageView; // @synthesize imageView=_imageView;
@property(retain) NSTextField *errorLabel; // @synthesize errorLabel=_errorLabel;
@property(retain) NSTextField *instructionLabel; // @synthesize instructionLabel=_instructionLabel;
@property(retain) NSView *pinContainerView; // @synthesize pinContainerView=_pinContainerView;
@property(retain) NSObject<AKSecondFactorCodeEntryDelegate> *delegate; // @synthesize delegate=_delegate;
@property(readonly) NSView *mainView; // @synthesize mainView=_mainView;
- (void)doneButtonPressed:(id)arg1;
- (void)cancelButtonPressed:(id)arg1;
- (void)noCodeButtonPressed:(id)arg1;
- (void)_codeEntered;
- (void)_resetPinView;
- (void)pinFieldViewTextDidComplete:(id)arg1;
- (void)pinFieldViewTextDidChange:(id)arg1;
- (void)_hideError;
- (void)showError:(id)arg1;
- (void)setFocusToPinView;
@property(readonly) NSNumber *enteredPin;
- (void)setMessage:(id)arg1;
- (void)setCodeLength:(id)arg1;
@property(readonly) NSTouchBar *touchBar;
- (void)awakeFromNib;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end

