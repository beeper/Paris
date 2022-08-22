#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <AKiCDPDeviceValidationFlowViewController.h>

@interface AKiCDPWaitForApprovalViewController : AKiCDPDeviceValidationFlowViewController
{
    BOOL _resetButtonEnabled;
    AKiCDPDeviceValidationFlowViewController *_flowController;
}

@property AKiCDPDeviceValidationFlowViewController *flowController; // @synthesize flowController=_flowController;
@property BOOL resetButtonEnabled; // @synthesize resetButtonEnabled=_resetButtonEnabled;
- (void)resetPressed:(id)arg1;
@property(readonly) BOOL shouldAllowReset;
- (void)showResetInfoSheet;
- (void)viewWillAppear;
- (id)initWithFlowController:(id)arg1;

@end
