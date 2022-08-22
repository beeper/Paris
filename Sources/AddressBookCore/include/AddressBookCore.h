#ifndef AddressBookCore_H
#define AddressBookCore_H

#include <Foundation/Foundation.h>
#include <AddressBook/AddressBook.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const kABCardDAVSourceClassName;
extern NSString* const kABExchangeSourceClassName;

typedef enum {
    PHXSourceTypeServer  =  0,
    PHXSourceTypeShared =  1,
    PHXSourceTypeDirectory = 2,
    PHXSourceTypeOther   = 100,
    PHXSourceTypeLocal   = 101
} PHXSourceType;

@interface ABWorkQueue: NSOperationQueue
@end

@interface PHXSource: NSObject
@property (readonly, copy) NSString* uid;
@property (readwrite, assign) BOOL enabled;
@property (readonly) ABWorkQueue* workQueue;

@property (readwrite, copy) NSString* name;
@property (readonly) NSString* displayName;
@property (readwrite, copy) NSString* subname;

@property (readwrite, assign) BOOL hasChanges;
@property (readwrite, assign) BOOL canCreateGroups;
@property (readwrite, assign) BOOL canCreatePeople;
@property (readonly) BOOL canDeletePeople;

@property (readonly, getter=isUnloaded) BOOL unloaded;
@property (retain) NSDate * lastPushSubscription;

-(void)sourceShouldRefresh:(NSArray*)items;
-(PHXSourceType)sourceType;
-(void)_sourceShouldRefreshImmediately:(BOOL)immediately;
@end

@protocol CardDAVSource
-(BOOL)maySync;
-(BOOL)allowSyncWithinCurrentApp;
-(void)resetSyncTag;
-(void)updateSourcePermissions;
-(BOOL)canTalkToServer;
@end

@interface ABAccount: NSObject
@property (copy, readonly) NSString * identifier;
@end

@interface ABAccountRepository: NSObject
+(instancetype)sharedRepository;
-(NSArray<ABAccount*>*)allAccounts;
-(PHXSource*)sourceWithUID:(NSString*)uid;
@end

NS_ASSUME_NONNULL_END

#endif /* #ifndef AddressBookCore_H */
