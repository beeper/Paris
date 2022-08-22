#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AppKit/NSViewController.h>

#import <AKPinFieldViewDelegate-Protocol.h>

@class AKNoCodeReceivedController, AKPinFieldView, NSButton, NSLayoutConstraint, NSNumber, NSObject, NSProgressIndicator, NSString, NSTextField, NSView, NSWindow;
@protocol AKSecondFactorCodeEntryDelegate;

@interface AKAppleIDAuthenticationiCloudPrefPaneSecondFactorViewController : NSViewController <AKPinFieldViewDelegate>
{
    BOOL _makeSheetCritical;
    BOOL _isCodeEditable;
    NSObject<AKSecondFactorCodeEntryDelegate> *_delegate;
    NSView *_pinContainerView;
    NSTextField *_instructionLabel;
    NSTextField *_errorLabel;
    NSProgressIndicator *_progressIndicator;
    NSButton *_noCodeButton;
    NSButton *_cancelButton;
    NSButton *_doneButton;
    NSLayoutConstraint *_widthOfPinViewConstraint;
    id _noCodeButtonAction;
    id _cancelButtonAction;
    id _doneButtonAction;
    NSWindow *_hostWindow;
    NSNumber *_defaultCode;
    NSNumber *_codeLength;
    AKPinFieldView *_pinView;
    NSString *_code;
    NSString *_message;
    AKNoCodeReceivedController *_noCodeRecievedController;
}


@property(retain) AKNoCodeReceivedController *noCodeRecievedController; // @synthesize noCodeRecievedController=_noCodeRecievedController;
@property(retain) NSString *message; // @synthesize message=_message;
@property(retain) NSString *code; // @synthesize code=_code;
@property(retain) AKPinFieldView *pinView; // @synthesize pinView=_pinView;
@property(retain) NSNumber *codeLength; // @synthesize codeLength=_codeLength;
@property(setter=setCodeEditable:) BOOL isCodeEditable; // @synthesize isCodeEditable=_isCodeEditable;
@property(readonly) NSNumber *defaultCode; // @synthesize defaultCode=_defaultCode;
@property BOOL makeSheetCritical; // @synthesize makeSheetCritical=_makeSheetCritical;
@property __weak NSWindow *hostWindow; // @synthesize hostWindow=_hostWindow;
@property(copy) id doneButtonAction; // @synthesize doneButtonAction=_doneButtonAction;
@property(copy) id cancelButtonAction; // @synthesize cancelButtonAction=_cancelButtonAction;
@property(copy) id noCodeButtonAction; // @synthesize noCodeButtonAction=_noCodeButtonAction;
@property(retain) NSLayoutConstraint *widthOfPinViewConstraint; // @synthesize widthOfPinViewConstraint=_widthOfPinViewConstraint;
@property(retain) NSButton *doneButton; // @synthesize doneButton=_doneButton;
@property(retain) NSButton *cancelButton; // @synthesize cancelButton=_cancelButton;
@property(retain) NSButton *noCodeButton; // @synthesize noCodeButton=_noCodeButton;
@property(retain) NSProgressIndicator *progressIndicator; // @synthesize progressIndicator=_progressIndicator;
@property(retain) NSTextField *errorLabel; // @synthesize errorLabel=_errorLabel;
@property(retain) NSTextField *instructionLabel; // @synthesize instructionLabel=_instructionLabel;
@property(retain) NSView *pinContainerView; // @synthesize pinContainerView=_pinContainerView;
@property(retain) NSObject<AKSecondFactorCodeEntryDelegate> *delegate; // @synthesize delegate=_delegate;
- (void)doneButtonPressed:(id)arg1;
- (void)cancelButtonPressed:(id)arg1;
- (void)noCodeButtonPressed:(id)arg1;
- (void)_codeEntered;
- (void)_resetPinView;
- (void)pinFieldViewTextDidComplete:(id)arg1;
- (void)pinFieldViewTextDidChange:(id)arg1;
- (void)_hideError;
- (void)showError:(id)arg1;
- (void)makePinViewActive;
@property(readonly) NSNumber *enteredPin;
- (void)setDefaultCode:(id)arg1;
- (void)awakeFromNib;
- (id)initWithMessage:(id)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end
