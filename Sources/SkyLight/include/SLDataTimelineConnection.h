//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import <SLDataTimelineConnection-Protocol.h>

@class NSString, SLDataTimelineSnapshotCollection;
@protocol OS_dispatch_queue, OS_xpc_object;

__attribute__((visibility("hidden")))
@interface SLDataTimelineConnection : NSObject <SLDataTimelineConnection>
{
    BOOL _connected;
    BOOL _updateBlockEnqueued;
    NSString *_name;
    SLDataTimelineSnapshotCollection *_collection;
    NSObject<OS_xpc_object> *_connection;
    NSObject<OS_dispatch_queue> *_connectionQueue;
    id _errorHandler;
    id _updateBlock;
    NSObject<OS_dispatch_queue> *_updateBlockQueue;
}

+ (id)connectionWithConnection:(id)arg1 config:(id)arg2 andErrorHandler:(id)arg3;
@property(nonatomic) BOOL updateBlockEnqueued; // @synthesize updateBlockEnqueued=_updateBlockEnqueued;
@property(readonly, retain, nonatomic) NSObject<OS_dispatch_queue> *updateBlockQueue; // @synthesize updateBlockQueue=_updateBlockQueue;
@property(readonly, copy, nonatomic) id updateBlock; // @synthesize updateBlock=_updateBlock;
@property(copy, nonatomic) id errorHandler; // @synthesize errorHandler=_errorHandler;
@property(readonly, nonatomic) NSObject<OS_dispatch_queue> *connectionQueue; // @synthesize connectionQueue=_connectionQueue;
@property(retain, nonatomic) NSObject<OS_xpc_object> *connection; // @synthesize connection=_connection;
@property(nonatomic) BOOL connected; // @synthesize connected=_connected;
@property(retain, nonatomic) SLDataTimelineSnapshotCollection *collection; // @synthesize collection=_collection;
@property(readonly, nonatomic) NSString *name; // @synthesize name=_name;
- (void)addSnapshots:(id)arg1 forAction:(unsigned int)arg2;
- (void)announceSnapshotsForAction:(unsigned int)arg1;
- (void)close;
- (void)handleMessage:(id)arg1;
- (void)dealloc;
- (id)initWithConnection:(id)arg1 config:(id)arg2 andErrorHandler:(id)arg3;

@end

