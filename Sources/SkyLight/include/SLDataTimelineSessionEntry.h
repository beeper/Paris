//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import <SLDataTimelineSession-Protocol.h>
#import <SLXPCConvertible-Protocol.h>

@protocol SLDataTimelineSessionProcessCollection;

__attribute__((visibility("hidden")))
@interface SLDataTimelineSessionEntry : NSObject <SLDataTimelineSession, SLXPCConvertible>
{
    unsigned int _cgID;
    int _auditID;
}

+ (id)entryWithXPCObject:(id)arg1;
@property(readonly, nonatomic) int auditID; // @synthesize auditID=_auditID;
@property(readonly, nonatomic) unsigned int cgID; // @synthesize cgID=_cgID;
- (id)createXPCObject;
- (id)initWithXPCObject:(id)arg1;
@property(readonly, nonatomic)  id  processData;
@property(readonly, nonatomic) BOOL currentSnapshotMember;

@end

