//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <MTLResource-Protocol.h>

@class MTLResourceAllocationInfo;
@protocol MTLResource;

@protocol MTLResourceSPI <MTLResource>
@property(readonly) unsigned long long unfilteredResourceOptions;
@property(readonly) unsigned long long protectionOptions;
@property(readonly) unsigned long long allocationID;
@property(readonly) MTLResourceAllocationInfo *cachedAllocationInfo;
@property(readonly) MTLResourceAllocationInfo *sharedAllocationInfo;
@property int responsibleProcess;
- (BOOL)doesAliasAnyResources:(const id *)arg1 count:(unsigned long long)arg2;
- (BOOL)doesAliasAllResources:(const id *)arg1 count:(unsigned long long)arg2;
- (BOOL)doesAliasResource:( id )arg1;
- (void)waitUntilComplete;
- (BOOL)isComplete;
- (BOOL)isPurgeable;
@end
