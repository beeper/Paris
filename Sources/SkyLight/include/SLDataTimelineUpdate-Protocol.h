//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <SLDataTimelineSnapshotCollectionMetadata-Protocol.h>

@protocol SLDataTimelineConnection, SLDataTimelineSnapshotCollection;

@protocol SLDataTimelineUpdate <SLDataTimelineSnapshotCollectionMetadata>
@property(readonly, nonatomic) unsigned int action;
@property(readonly, nonatomic)  id  connection;
- ( id )claimSnapshotCollection;
@end

