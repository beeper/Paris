#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSMutableDictionary;
@protocol OS_dispatch_queue, OS_nw_path_monitor;

@interface AKNetworkObserver : NSObject
{
    NSObject<OS_nw_path_monitor> *_pathMonitor;
    NSObject<OS_dispatch_queue> *_observerQueue;
    NSMutableDictionary *_invocationByObserver;
    BOOL _isNetworkReachable;
}

+ (id)sharedNetworkObserver;

- (void)removeNetworkReachableObserver:(id)arg1;
- (void)addNetworkReachableObserver:(id)arg1 selector:(SEL)arg2;
@property(readonly) BOOL isNetworkReachable; // @synthesize isNetworkReachable=_isNetworkReachable;
- (void)_networkReachabilityDidChange;
- (void)_stopPathMonitor;
- (void)_startPathMonitor;
- (void)dealloc;
- (id)init;

@end

