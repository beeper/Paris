//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <DDBasicRegexp.h>

#import <Foundation/Foundation.h>

@class NSString;

__attribute__((visibility("hidden")))
@interface DDVariable : DDBasicRegexp <NSCopying>
{
    NSString *_name;
}

- (void)appendDescriptionToString:(id)arg1 depth:(int)arg2;
- (BOOL)acceptEmptyWordWithManager:(id)arg1;
- (int)splitRegexpWithDelegate:(id)arg1 owner:(id)arg2;
- (id)name;
- (void)dealloc;
- (id)initWithVariableName:(id)arg1;
- (id)symbolsInGrammar:(id)arg1 container:(id)arg2 withManager:(id)arg3;
- (id)monElement;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)computeTypeFromParent:(id)arg1 withManager:(id)arg2;
- (void)appendToDescription:(id)arg1 priority:(int)arg2 withManager:(id)arg3;

@end

