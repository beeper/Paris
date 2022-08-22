//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSDictionary, NSMutableDictionary;

@interface MCXPrefObject : NSObject
{
    NSMutableDictionary *mMCXDict;
    NSDictionary *mUnionPolicyKeys;
}

+ (id)objectWithRAWDictionary:(id)arg1;
- (BOOL)hasSettingsForDomains:(id)arg1;
- (void)removeDictionaryForDomains:(id)arg1;
- (void)removeDictionaryForDomain:(id)arg1;
- (void)setDictionary:(id)arg1 forDomain:(id)arg2;
- (id)dictionaryForDomain:(id)arg1;
- (id)objectForKey:(id)arg1 inDomain:(id)arg2;
- (id)MCXRAWDict;
- (void)setMCXRAWDict:(id)arg1;
- (void)setUnionPolicyKeys:(id)arg1;
- (void)dealloc;
- (id)initWithRAWDictionary:(id)arg1;

@end

