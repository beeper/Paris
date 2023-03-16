#ifndef IDSFoundation_H
#define IDSFoundation_H

#include <Foundation/Foundation.h>
#import "IDSIDInfoOptions.h"
#import "IDSIDInfoResult.h"
#import "IDSIDKTData.h"

@class IDSBaseMessage, IDSMessage;

typedef NS_ENUM(NSInteger, IDSMessageImportanceLevel) {
    IDSMessageImportanceLevelLow = 0,
    IDSMessageImportanceLevelMedium = 1,
    IDSMessageImportanceLevelHigh = 2,
};

typedef NS_ENUM(NSInteger, IDSMessageDeliveryMechanism) {
    IDSMessageDeliveryMechanismUnknown = 0,
    IDSMessageDeliveryMechanismAPS = 1,
    IDSMessageDeliveryMechanismHTTP = 2,
};

typedef void (^IDSBaseMessageDeliveryDeliveryAcknowledgementBlock)(IDSBaseMessage * message);
typedef void (^IDSBaseMessageDeliveryCompletionBlock)(IDSBaseMessage * message, NSError * error, NSInteger resultCode, NSDictionary * resultDictionary);

@interface IDSBaseMessage: NSObject
@property (readonly, assign) BOOL wantsIDSServer;
@property (readonly, assign) BOOL isValidMessage;
@property (readonly, assign) BOOL payloadCanBeLogged;
@property (readwrite, assign) NSUInteger uniqueID;
@property (readonly, strong) NSString * uniqueIDString;
@property (readonly, strong) NSString * dataUsageBundleIdentifier;
@property (readwrite, assign) NSTimeInterval timeout;
@property (readwrite, assign) NSTimeInterval timeSent;
@property (readwrite, copy) IDSBaseMessageDeliveryCompletionBlock completionBlock;
@property (readwrite, copy) IDSBaseMessageDeliveryDeliveryAcknowledgementBlock deliveryAcknowledgementBlock;
@property (readonly, strong) NSString * bagKey;
@property (readwrite, strong) NSString * topic;
@property (readonly, assign) NSInteger command;
@property (readonly, assign) NSInteger responseCommand;
@property (readwrite, assign) BOOL hasReceivedPushAck;
@property (readwrite, assign) BOOL hasAttemptedAPSDelivery;
@property (readwrite, strong) /*APSOutgoingMessageCheckpointTrace */id apsdCheckpointTrace;
@property (readwrite, assign) IDSMessageImportanceLevel importanceLevel;
@property (readwrite, assign) IDSMessageDeliveryMechanism deliveryMechanism;
@property (copy) NSString * service;
@property (copy) NSString * subService;
@property (copy) NSString * underlyingService;
@property (readwrite, assign) BOOL forceCellular;
@property (readwrite, assign) BOOL alwaysForceCellular;
@property (readwrite, assign) BOOL highPriority;
@property (readonly, assign) BOOL wantsSignature;
@property (readonly, assign) BOOL wantsBodySignature;
@property (readonly, assign) BOOL wantsCFNetworkTimeout;
@property (readonly, assign) BOOL wantsManagedRetries;
@property (readonly, assign) BOOL wantsExtraTimeoutRetry;
@property (readonly, assign) int maxTimeoutRetries;
@property (readonly, assign) BOOL wantsHTTPHeaders;
@property (readonly, assign) BOOL wantsCompressedBody;
@property (readwrite, assign) BOOL wantsBinaryPush;
@property (readwrite, assign) BOOL wantsIntegerUniqueIDs;
@property (readonly, assign) BOOL wantsJSONBody;
@property (readonly, assign) BOOL wantsBagKey;
@property (readonly, assign) BOOL wantsUserAgentInHeaders;
@property (readonly, assign) BOOL wantsHTTPGet;
@property (readonly, assign) BOOL wantsAPSRetries;
@property (readonly, assign) NSTimeInterval anisetteHeadersTimeout;
@property (readonly, assign) BOOL allowsServerProvidedLenientAnisetteTimeout;
@property (readwrite, assign) BOOL wantsResponse;
@property (readwrite, assign) BOOL wantsMultipleResponses;
@property (readonly, assign)  BOOL isWebTunnelMessage;
@property (readonly, assign)  BOOL wantsIDSSignatures;
@property (readwrite, assign)  BOOL httpDoNotDecodeData;
@property (readwrite, assign) int timeoutRetries;
@property (readonly, assign) BOOL ignoresNetworkConnectivity;
@property (readonly, assign) BOOL wantsCustomRetryInterval;
@property (readonly, assign) NSTimeInterval customRetryInterval;
@property (readonly, strong) NSArray * requiredKeys;
@property (copy) NSDictionary * responseAlertInfo;
@property (readonly, strong) NSDictionary * messageBody;
@property (readonly, strong) NSDictionary * messageBodyUsingCache;
@property (readonly, strong) NSDictionary * additionalMessageHeaders;
@property (readonly, strong) NSDictionary * additionalQueryStringParameters;
@property (readonly, strong) NSDictionary * additionalInternalHeaders;
@property (readonly, strong) NSDictionary * additionalMessageHeadersForOutgoingPush;
@property (readonly, strong) NSDictionary * nonStandardMessageHeadersForOutgoingPush;
@property (nonatomic, readwrite, assign) SecKeyRef pushPrivateKey;
@property (nonatomic, readwrite, assign) SecKeyRef pushPublicKey;
@property (nonatomic, readwrite, copy) NSData * pushCertificate;
@property (nonatomic, copy) NSData * pushToken;
@property (nonatomic, readwrite, copy) NSMutableArray * certDataArray;
@property (nonatomic, readwrite, copy) NSMutableArray * publicKeyArray;
@property (nonatomic, readwrite, copy) NSMutableArray * privateKeyArray;
@property (nonatomic, readwrite, copy) NSMutableArray * userIDArray;
@property (nonatomic, readwrite, copy) NSNumber * serverTimestamp;
@property (nonatomic, readwrite, copy) NSNumber * serverTimestampReceivedDate;
@property (nonatomic, readonly, assign) SecKeyRef identityPrivateKey;
@property (nonatomic, readonly, assign) SecKeyRef identityPublicKey;
@property (nonatomic, readonly, copy) NSData * IDCertificate;
@property (nonatomic, readwrite, strong) id/*<IDSBaseMessageSigningSession>*/ signingSession;
@property (nonatomic, copy, setter=setDSAuthID:) NSString * dsAuthID;
@property (readwrite, copy) NSData * serviceData;
@property (readwrite, copy) NSDictionary * clientInfo;
@property (readonly, strong) NSString * userAgentHeaderString;
@property (nonatomic, copy) NSNumber * retryCount;
@property (readonly, strong) NSString * retryCountKey;
@property (readwrite, copy) NSURL * URLOverride;
@property (readonly, assign) BOOL allowDualDelivery;
@property (readwrite, copy) NSDictionary * userInfo;
@property (readonly, strong) NSDate * creationDate;
@property (readwrite, strong) id context;
@property (nonatomic) NSUInteger sentByteCount;
@property (nonatomic) NSUInteger receivedByteCount;
@property (nonatomic, strong) NSDate *requestStart;
@property (nonatomic, strong) NSDate *requestEnd;
@property (nonatomic, strong) NSDate *responseReceived;
- (void) handleResponseHeaders:(NSDictionary *)headers;
- (void) handleResponseDictionary:(NSDictionary *)response;
- (void) handleResponseBody:(NSData *)body;
- (void) handleResponseStatus:(NSUInteger)statusCode;
- (BOOL) isIDSMessage;
- (void) logFailureInfo;
- (NSData *)messageBodyDataOverride;
@end

@interface IDSMessage : IDSBaseMessage
@property (copy) NSNumber * wantsDeliveryStatus;
@property (copy) NSDictionary * deliveryStatusContext;
@end

#endif /* #ifndef IDSFoundation_H */
