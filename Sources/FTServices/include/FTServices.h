#ifndef FTServices_H
#define FTServices_H

#include <Foundation/Foundation.h>
#include <IDSFoundation.h>

typedef NS_ENUM(NSInteger, FTMessageDeliveryType) {
    FTMessageDeliveryTypeHTTP     = 1,
    FTMessageDeliveryTypeAPS      = 2,
    FTMessageDeliveryTypeDualModeHTTPOnly = 3,
};

@interface FTMessageDelivery_DualMode: NSObject
- (instancetype)initWithPreferedType:(FTMessageDeliveryType)deliveryType;
- (BOOL)sendMessage:(IDSBaseMessage *)message;
- (void)cancelMessage:(IDSBaseMessage *)message;
- (void)setUserAgent:(NSString*)userAgent;
@end

typedef enum : NSUInteger {
    FTURLRequestTypeGet,
    FTURLRequestTypePost,
} FTURLRequestType;

@interface FTIDSMessage : IDSBaseMessage
@property (nonatomic, readwrite, assign) SecKeyRef pushPrivateKey;
@property (nonatomic, readwrite, assign) SecKeyRef pushPublicKey;
@property (nonatomic, readwrite, copy) NSData * pushCertificate;
@property (nonatomic, copy) NSData * pushToken;
- (void) addAuthUserID:(NSString *)userID certificate:(NSData *)certData privateKey:(SecKeyRef)privateKey publicKey:(SecKeyRef)publicKey;
@property (nonatomic, readwrite, copy) NSString * selfURI;
@property (nonatomic, readwrite, copy) NSMutableArray * certDataArray;
@property (nonatomic, readwrite, copy) NSMutableArray * publicKeyArray;
@property (nonatomic, readwrite, copy) NSMutableArray * privateKeyArray;
@property (nonatomic, readwrite, copy) NSMutableArray * userIDArray;
@property (nonatomic, readwrite, assign) SecKeyRef identityPrivateKey;
@property (nonatomic, readwrite, assign) SecKeyRef identityPublicKey;
@property (nonatomic, readwrite, copy) NSData * IDCertificate;
@property (readonly, assign) BOOL wantsIDSProtocolVersion;
@end

@interface FTURLRequestMessage: FTIDSMessage
@property (nonatomic, readwrite, assign) FTURLRequestType requestType;
@property (nonatomic, readwrite, copy) NSURL    *requestURL;
@property (nonatomic, readwrite, copy) NSDictionary *requestHeaders;
@property (nonatomic, readwrite, copy) NSDictionary *requestStringParams;
@property (nonatomic, readwrite, copy) NSData *requestBody;
@property (nonatomic, readwrite, copy) NSDictionary *responseHeaders;
@property (nonatomic, readwrite, copy) NSData *responseBody;
@property (nonatomic, readwrite, copy) NSNumber *responseStatusCode;
@property (nonatomic, readwrite, copy) NSDictionary *timingData;
- (instancetype)initWithURL:(NSURL*)url type:(FTURLRequestType)type headers:(NSDictionary*)headers stringParams:(NSDictionary*)stringParams body:(NSData*)body;
@end

#endif /* #ifndef FTServices_H */
