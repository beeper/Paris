//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@protocol NSXPCListenerDelegate;

@class LFListener, NSString;

@interface LFListenerDelegate : NSObject <NSXPCListenerDelegate>
{
    LFListener *_listener;
}

+ (id)delegateWithListener:(id)arg1;
@property(readonly) LFListener *listener; // @synthesize listener=_listener;
- (id)initWithListener:(id)arg1;
- (id)init;
- (BOOL)listener:(id)arg1 shouldAcceptNewConnection:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long hash;
@property(readonly) Class superclass;

@end

