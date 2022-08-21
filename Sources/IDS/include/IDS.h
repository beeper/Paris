#ifndef IDS_H
#define IDS_H

#include <Foundation/Foundation.h>
#include <IDSFoundation.h>

@class IDSAccount;
@class IDSMessageContext;
@class IDSBaseMessage;

@protocol IDSServiceDelegate
@optional
-(void)service:(id)arg1 devicesChanged:(id)arg2;
-(void)service:(id)arg1 account:(IDSAccount*)account incomingMessage:(NSDictionary*)message fromID:(NSString*)fromID context:(IDSMessageContext*)ctx;
@end

@interface IDSAccount : NSObject

@end

@interface IDSMessageContext : NSObject

@end

@interface IDSService : NSObject
-(instancetype)initWithService:(NSString*)service;
-(void)addDelegate:(id<IDSServiceDelegate>)delegate queue:(dispatch_queue_t)q;
@end

#endif /* #ifndef IDS_H */
