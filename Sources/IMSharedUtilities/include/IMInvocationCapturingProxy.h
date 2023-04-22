//
//  IMInvocationCapturingProxy.h
//  
//
//  Created by June Welker on 4/21/23.
//

#ifndef IMInvocationCapturingProxy_h
#define IMInvocationCapturingProxy_h

#import <Foundation/Foundation.h>

// This overwrites `conformsToProtocol:` to just return `protocol_conformsToProtocol(self->protocol)`
// When this is retrieved from `(IMDaemonController.sharedInstance() as IMDistributingProxy).targets`, the `protocol`
// it contains is `IMDaemonProtocol`.
@interface IMInvocationCapturingProxy: NSProxy
- (instancetype _Nonnull)initWithProtocol:(Protocol * _Nonnull)protocol forwardingHandler:(id _Nonnull)forwardingHandler;
- (Protocol * _Nonnull)protocol;
- (id _Nonnull)forwardingHandler;
@end

#endif /* IMInvocationCapturingProxy_h */
