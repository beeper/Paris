//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <Foundation/Foundation.h>

@class CNContact, CNContactStore, NSArray, NSData, NSDictionary, NSMutableDictionary;

@interface IMContactStore : NSObject
{
    BOOL _batchFetchingForLaunchCompleted;
    CNContactStore *_contactStore;
    NSData *_changeHistoryToken;
    NSDictionary *_handleIDToCNIDMap;
    NSMutableDictionary *_CNIDToHandleIDsMap;
    NSMutableDictionary *_IDToCNContactMap;
    double _lastContactStoreSync;
    double _lastMeContactStoreSync;
    CNContact *_meContact;
    NSArray *_CNIDsForBatchFetch;
}

+ (id)validateAndCleanupID:(id)arg1;
+ (id)validateAndFilterIDsForContactsBatchFetch:(id)arg1;
+ (id)descriptionForCNContact:(id)arg1;
+ (BOOL)isCNContactAKnownContact:(id)arg1;
+ (id)dialingForCurrentLocale;
+ (id)dialingCodeForID:(id)arg1;
+ (BOOL)isContactsCachingEnabled;
+ (BOOL)isContactsBatchingEnabled;
+ (id)keysForNicknameHandling;
+ (id)keysForMeContact;
+ (id)keysForCNContact;
+ (id)mePredicate;
+ (id)predicateForID:(id)arg1;
+ (id)createMutableContactWithID:(id)arg1;
+ (BOOL)shouldShowAbbreviatedNames;
+ (BOOL)shouldShowNickNames;
+ (id)phoneNumbersForCNContact:(id)arg1;
+ (id)emailsForCNContact:(id)arg1;
+ (id)IDsFromCNContact:(id)arg1;
+ (id)abbreviatedNameForCNContact:(id)arg1;
+ (id)nickNameForCNContact:(id)arg1;
+ (id)companyNameForCNContact:(id)arg1;
+ (id)_stringFromContact:(id)arg1 withStyle:(long long)arg2;
+ (id)fullNameForCNContact:(id)arg1;
+ (id)lastNameForCNContact:(id)arg1;
+ (id)firstNameForCNContact:(id)arg1;
+ (id)displayNameForContact:(id)arg1;
+ (id)displayNameWithPhoneNumberOrEmailForContact:(id)arg1;
+ (id)displayNameWithCNNickNameOrFullNameOrCompanyNameForContact:(id)arg1;
+ (id)kIMCNContactThumbnailImageDataKey;
+ (id)kIMCNContactImageDataKey;
+ (id)kIMCNContactImageDataAvailableKey;
+ (id)kIMCNContactEmailAddressesKey;
+ (id)kIMCNContactPhoneNumbersKey;
+ (id)kIMCNContactLinkIdentifierKey;
+ (id)kIMCNContactIdentifierKey;
+ (Class)IMCNGeminiManagerClass;
+ (Class)IMCNMeCardSharingPickerViewControllerClass;
+ (Class)IMCNChangeHistoryFetchRequestClass;
+ (Class)IMCNPhoneNumberClass;
+ (Class)IMCNLabeledValueClass;
+ (Class)IMCNMutableContactClass;
+ (Class)IMCNContactFetchRequestClass;
+ (Class)IMCNContactFormatterClass;
+ (IMContactStore*)sharedInstance;

@property(retain, nonatomic) NSArray *CNIDsForBatchFetch; // @synthesize CNIDsForBatchFetch=_CNIDsForBatchFetch;
@property(retain, nonatomic) CNContact *meContact; // @synthesize meContact=_meContact;
@property(nonatomic) double lastMeContactStoreSync; // @synthesize lastMeContactStoreSync=_lastMeContactStoreSync;
@property(nonatomic) double lastContactStoreSync; // @synthesize lastContactStoreSync=_lastContactStoreSync;
@property(nonatomic) BOOL batchFetchingForLaunchCompleted; // @synthesize batchFetchingForLaunchCompleted=_batchFetchingForLaunchCompleted;
NS_ASSUME_NONNULL_BEGIN
@property(retain, nonatomic) NSMutableDictionary<NSString*,CNContact*> *IDToCNContactMap; // @synthesize IDToCNContactMap=_IDToCNContactMap;
@property(retain, nonatomic) CNContactStore *contactStore; // @synthesize contactStore=_contactStore;
- (CNContact* _Nullable)fetchCNContactForHandleID:(NSString*)arg1 withKeys:(NSArray<NSString*>*)arg2;
NS_ASSUME_NONNULL_END
@property(retain, nonatomic) NSMutableDictionary *CNIDToHandleIDsMap; // @synthesize CNIDToHandleIDsMap=_CNIDToHandleIDsMap;
@property(retain, nonatomic) NSDictionary *handleIDToCNIDMap; // @synthesize handleIDToCNIDMap=_handleIDToCNIDMap;
@property(retain, nonatomic) NSData *changeHistoryToken; // @synthesize changeHistoryToken=_changeHistoryToken;
- (id)getCurrentHistoryToken;
- (id)getIDToCNContactMap;
- (id)getCNIDToHandleIDsMap;
- (id)getHandleIDToCNIDMap;
- (void)checkForContactStoreChanges;
- (void)handleDropEverythingEvent;
- (id)fetchMeContactWithKeys:(id)arg1;
- (void)meCardChanged:(id)arg1;
- (void)resetMeCard;
- (void)contactStoreChanged:(id)arg1;
- (void)addEntriesToIDToCNContactMap:(id)arg1;
- (id)getAllKeysFromIDToCNContactMap;
- (void)replaceWithMutableContactForID:(id)arg1;
- (void)replaceContact:(id)arg1 withID:(id)arg2;
- (void)removeContactWithID:(id)arg1;
- (id)getContactForID:(id)arg1;
- (void)addContact:(id)arg1 withID:(id)arg2;
- (BOOL)isContactWithIDAlreadyFetched:(id)arg1;
- (void)generateCNIDToHandleIDMap;
- (id)handleIDsForCNID:(id)arg1;
- (void)setBatchFetchingCompleted;
- (BOOL)isBatchFetchingForLaunchCompleted;
- (id)completedContact:(id)arg1 withKeys:(id)arg2;
- (CNContact* _Nullable)fetchCNContactForHandleWithID:(id)arg1;
- (void)fetchCNContactsForHandlesWithIDs:(id)arg1 isFinalBatch:(BOOL)arg2;
- (void)cacheBatchFetchResults:(id)arg1 handleIDsWithoutCNID:(id)arg2;
- (id)getContactStore;
- (void)dealloc;
- (id)initWithContactStore:(id)arg1;
- (id)init;
- (void)_logDictionaryInformation:(id)arg1 inRange:(struct _NSRange)arg2;
- (void)_logArrayInBatches:(id)arg1 ofBatchSize:(long long)arg2;
- (void)_logDictionaryInBatches:(id)arg1 ofBatchSize:(long long)arg2;
- (void)logHandleID:(id)arg1;
- (void)logCNContact:(id)arg1 andID:(id)arg2;
- (void)logCNContact:(id)arg1;
- (void)logCurrentHistoryToken;
- (void)logContactFetchRequestResults:(id)arg1;
- (void)logHandleIDs:(id)arg1;
- (void)logCNIDToHandleIDMap;
- (void)logIDToCNContactMap;
- (void)loghandleIDToCNIDMap;

@end
