#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AKAppleIDAuthenticationInAppContext.h>

#import <AuthWebViewDelegate-Protocol.h>

@class AKAppleIDAuthenticationiCloudPrefPaneSecondFactorViewController, AKAppleIDAuthenticationiCloudPrefPaneViewController, AKAuthWebTabView, NSString;

@interface AKAppleIDAuthenticationiCloudPrefPaneContext : AKAppleIDAuthenticationInAppContext <AuthWebViewDelegate>
{
    AKAppleIDAuthenticationiCloudPrefPaneViewController *_prefPaneSignInViewController;
    AKAppleIDAuthenticationiCloudPrefPaneSecondFactorViewController *_prefPaneSignInViewSecondFactorController;
    AKAuthWebTabView *_webviewController;
}


@property(retain) AKAuthWebTabView *webviewController; // @synthesize webviewController=_webviewController;
@property(retain) AKAppleIDAuthenticationiCloudPrefPaneSecondFactorViewController *prefPaneSignInViewSecondFactorController; // @synthesize prefPaneSignInViewSecondFactorController=_prefPaneSignInViewSecondFactorController;
@property(retain) AKAppleIDAuthenticationiCloudPrefPaneViewController *prefPaneSignInViewController; // @synthesize prefPaneSignInViewController=_prefPaneSignInViewController;
- (void)skipAndContinueSignIn;
- (void)sizeChangedFrom:(struct CGSize)arg1 toSize:(struct CGSize)arg2 webViewName:(id)arg3 callback:(id)arg4;
- (void)loadFailed:(id)arg1 withError:(id)arg2;
- (void)endWebView:(id)arg1;
- (void)closeWebViewAndCleanUp:(id)arg1 andError:(id)arg2;
- (BOOL)showInline:(id)arg1;
- (id)hostWindow;
- (void)switchToView:(id)arg1;
- (void)presentBiometricOrPasscodeValidationForAppleID:(id)arg1 completion:(id)arg2;
- (void)dismissServerProvidedUIWithCompletion:(id)arg1;
- (void)presentServerProvidedUIWithConfiguration:(id)arg1 completion:(id)arg2;
- (void)presentSecondFactorAlertWithError:(id)arg1 title:(id)arg2 message:(id)arg3 completion:(id)arg4;
- (void)dismissSecondFactorUIWithCompletion:(id)arg1;
- (void)presentSecondFactorUIWithCompletion:(id)arg1;
- (void)dismissBasicLoginUIWithCompletion:(id)arg1;
- (void)presentServerUIErrorAlertWithTitle:(id)arg1 message:(id)arg2 completion:(id)arg3;
- (void)_setupEscapeOffersWithCompletion:(id)arg1;
- (void)_setupLoginActionWithCompletion:(id)arg1;
- (void)_presentLoginAlertWithError:(id)arg1 title:(id)arg2 message:(id)arg3 completion:(id)arg4;
- (void)presentLoginAlertWithError:(id)arg1 title:(id)arg2 message:(id)arg3 completion:(id)arg4;
- (void)dismissKeepUsingUIWithCompletion:(id)arg1;
- (void)presentKeepUsingUIForAppleID:(id)arg1 completion:(id)arg2;
- (void)presentBasicLoginUIWithCompletion:(id)arg1;
- (BOOL)_shouldSkipInitialReachabilityCheck;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) NSUInteger hash;
@property(readonly) Class superclass;

@end
