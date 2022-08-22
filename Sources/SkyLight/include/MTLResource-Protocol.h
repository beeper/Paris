//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

@protocol NSObject;

@class NSString;
@protocol MTLDevice, MTLHeap;

@protocol MTLResource <NSObject>
@property(readonly) unsigned long long allocatedSize;
@property(readonly) unsigned long long heapOffset;
@property(readonly)  id  heap;
@property(readonly) unsigned long long resourceOptions;
@property(readonly) unsigned long long hazardTrackingMode;
@property(readonly) unsigned long long storageMode;
@property(readonly) unsigned long long cpuCacheMode;
@property(readonly)  id  device;
@property(copy) NSString *label;
- (BOOL)isAliasable;
- (void)makeAliasable;
- (unsigned long long)setPurgeableState:(unsigned long long)arg1;
@end

