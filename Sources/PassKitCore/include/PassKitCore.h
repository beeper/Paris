#ifndef PassKitCore_H
#define PassKitCore_H

#include <Foundation/Foundation.h>

@class PKCreditAccountStatement;
@class PKAccountWebServiceExportTransactionDataResponse;

typedef void (^PKAccountStatementExportBlock)(PKAccountWebServiceExportTransactionDataResponse*, NSError*);
typedef void (^PKAccountStatementListBlock)(NSSet<PKCreditAccountStatement*>*, NSError*);

NS_ASSUME_NONNULL_BEGIN

@interface PKWebServiceResponse : NSObject <NSSecureCoding>
@property (nonatomic,readonly) NSData * rawData;
@property (nonatomic,readonly) id JSONObject;
@end

@interface PKPaymentWebServiceResponse : PKWebServiceResponse
@end

@interface PKAccountWebServiceResponse : PKPaymentWebServiceResponse
@end


@interface PKAccountWebServiceExportTransactionDataResponse : PKAccountWebServiceResponse
@property (nonatomic,copy,readonly) NSData * transactionData;
@property (nonatomic,copy,readonly) NSString * transactionDataFilename;
@property (nonatomic,copy,readonly) NSString * transactionDataHash;
@end

@interface PKCreditAccountStatement: NSObject
@property (nonatomic,copy) NSString * identifier;
@property (nonatomic,copy) NSDate * openingDate;
@property (nonatomic,copy) NSDate * closingDate;
@property (nonatomic,copy) NSDate * paymentDueDate;
@property (nonatomic,copy) NSString * currencyCode;
@property (nonatomic,copy) NSDecimalNumber * statementBalance;
@property (nonatomic,copy) NSDecimalNumber * totalBalance;
@property (nonatomic,copy) NSDecimalNumber * minimumDue;
@property (nonatomic,copy) NSDecimalNumber * purchases;
@property (nonatomic,copy) NSDecimalNumber * feesCharged;
@property (nonatomic,copy) NSDecimalNumber * interestCharged;
@property (nonatomic,copy) NSDecimalNumber * balanceTransfers;
@property (nonatomic,copy) NSDecimalNumber * paymentsAndCredits;
@property (nonatomic,copy) NSDecimalNumber * payments;
@property (nonatomic,copy) NSDecimalNumber * credits;
@property (nonatomic,copy) NSDecimalNumber * rewardsBalance;
@property (nonatomic,copy) NSDecimalNumber * rewardsEarned;
@property (nonatomic,copy) NSDecimalNumber * rewardsRedeemed;
@property (nonatomic,copy) NSDecimalNumber * rewardsYTD;
@property (nonatomic,copy) NSDecimalNumber * rewardsLifetime;
@end

@protocol PKAccountServiceExportedInterface
@required
-(void)accountAdded:(id)arg1;
-(void)accountRemoved:(id)arg1;
-(void)scheduledPaymentsChangedForAccountIdentifier:(id)arg1;
-(void)statementsChangedForAccountIdentifier:(id)arg1;
-(void)accountChanged:(id)arg1;
@end

@class PKAccount;

typedef void (^PKAccountCompletionBlock)(NSArray<PKAccount*>*);

@interface PKAccountDetails: NSObject
@end

@interface PKCreditAccountSummary: NSObject
@property (nonatomic,copy) NSDecimalNumber * creditLimit;
@property (nonatomic,copy) NSDecimalNumber * availableCredit;
@property (nonatomic,copy) NSDecimalNumber * currentBalance;
@property (nonatomic,copy) NSDecimalNumber * adjustedBalance;
@property (nonatomic,copy) NSDecimalNumber * rewardsBalance;
@property (nonatomic,copy) NSDecimalNumber * remainingStatementBalance;
@property (nonatomic,copy) NSDecimalNumber * remainingMinimumPayment;
@property (nonatomic,copy) NSDecimalNumber * remainingMinimumPaymentExcludedFromInterestCalculation;
@property (nonatomic,copy) NSDecimalNumber * installmentBalance;
@end

@interface PKCreditAccountRates: NSObject
@property (nonatomic,copy) NSDecimalNumber * aprForPurchases;
@end

@interface PKCurrencyAmount: NSObject
@property (nonatomic,copy) NSDecimalNumber * amount;
@property (nonatomic,copy) NSString * currency;
@property (assign,nonatomic) long long exponent;
@property (nonatomic,copy) NSString * preformattedString;
@end

@interface PKPhysicalCard: NSObject
@property (nonatomic,copy) NSString * identifier;
@property (assign,nonatomic) unsigned long long state;
@property (nonatomic,copy) NSURL * frontFaceImageURL;
@property (nonatomic,copy) NSString * nameOnCard;
@property (nonatomic,copy) NSDate * lastUpdated;
@property (nonatomic,copy) NSString * FPANSuffix;
@property (nonatomic,copy) NSString * trackingNumber;
@property (nonatomic,copy) NSString * shippingCompany;
@property (nonatomic,copy) NSSet * orderActivity;
@property (nonatomic,copy) NSSet * shippingActivity;
@end

@interface PKVirtualCardCredentials: NSObject
@property (nonatomic,copy) NSString * primaryAccountNumber;
@property (nonatomic,copy) NSString * cardSecurityCode;
@property (assign,nonatomic) long long cardType;
@end

@interface PKVirtualCard: NSObject
@property (nonatomic,copy) NSString * identifier;
@property (nonatomic,copy) NSString * cardholderName;
@property (assign,nonatomic) long long state;
@property (assign,nonatomic) long long type;
@property (nonatomic,copy) NSString * FPANSuffix;
@property (nonatomic,copy) NSString * expiration;
@property (nonatomic,copy) NSDate * lastUpdatedDate;
@property (nonatomic,copy) NSData * encryptedData;
@property (nonatomic,copy) NSData * ephemeralPublicKey;
@property (nonatomic,copy) NSString * displayName;
@property (nonatomic,copy) NSDate * lastAutoFilledBySafari;
@property (assign,nonatomic) BOOL supportsLocalStorage;
@property (assign,nonatomic) BOOL requiresAuthentication;
@property (nonatomic,copy) PKVirtualCardCredentials * keychainCardCredentials;
@end

@interface PKCreditAccountDetails: NSObject
@property (nonatomic,copy) NSDate * lastUpdatedDate;
@property (nonatomic,copy) NSString * currencyCode;
@property (nonatomic,retain) NSTimeZone * productTimeZone;
@property (nonatomic,copy) NSSet<PKPhysicalCard*> * physicalCards;
@property (nonatomic,copy) NSSet<PKVirtualCard*> * virtualCards;
@property (nonatomic,retain) PKCreditAccountSummary * accountSummary;
@property (nonatomic,retain) PKCreditAccountRates * rates;
@property (nonatomic,copy,readonly) PKCurrencyAmount * cardBalance;
@property (nonatomic,copy,readonly) PKCurrencyAmount * totalBalance;
@end

@interface PKAccount: NSObject
@property (nonatomic,copy) NSString * accountIdentifier;
@property (assign,nonatomic) unsigned long long feature;
@property (nonatomic,retain) PKAccountDetails * details;
@property (nonatomic,copy) NSSet * supportedFeatures;
@property (nonatomic,readonly) PKCreditAccountDetails * creditDetails;

-(BOOL)supportsSchedulePayment;
-(BOOL)supportsScheduleRecurringPayments;
-(BOOL)supportsViewStatement;
-(BOOL)supportsRequestStatement;
-(BOOL)supportsExportTransactionData;
-(BOOL)supportsRequestPhysicalCard;
-(BOOL)supportsRedeemRewards;
-(BOOL)supportsShowNotifications;
-(BOOL)supportsShowAccountSummary;
-(BOOL)supportsAddFundingSource;
-(BOOL)supportsShowVirtualCard;
@end

@interface PKAccountService: NSObject
+(instancetype)sharedInstance;
-(void)accountsWithCompletion:(PKAccountCompletionBlock)arg1;
-(void)exportTransactionDataForAccountIdentifier:(NSString*)arg1 withFileFormat:(NSString*)arg2 beginDate:(NSDate*)arg3 endDate:(NSDate*)arg4 productTimeZone:(NSTimeZone*)arg5 completion:(PKAccountStatementExportBlock)arg6 ;
-(void)creditStatementsForAccountIdentifier:(NSString*)arg1 completion:(PKAccountStatementListBlock)arg2 ;
@end

@interface PKPass: NSObject
@property (assign,nonatomic) unsigned long long passType;
@property (nonatomic,copy) NSString * organizationName;
@property (nonatomic,copy,readonly) NSString * localizedName;
@property (nonatomic,copy,readonly) NSString * localizedDescription;
@end

@interface PKSecureElementPass: PKPass
@end

@interface PKPaymentPass: PKSecureElementPass
@end

@interface PKPassLibrary: NSObject
+(instancetype)sharedInstance;
-(NSArray<PKPass*>*)passes;
@end

NS_ASSUME_NONNULL_END

#endif /* #ifndef PassKitCore_H */
