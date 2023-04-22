//
//  IMDistributingProxy.h
//  
//
//  Created by June Welker on 4/21/23.
//

#ifndef IMDistributingProxy_h
#define IMDistributingProxy_h

#import <Foundation/Foundation.h>

// An `IMDistributingProxy` is a special object. It's basically just a proxy for method invocation forwarding, as far as I can tell.
// Its `init` is `initWithTargets:targetQueue:asynchronous:filterBlock:`, where `targets` is a list of objects that it will forward method calls to.
// As of my testing (macos 13.2.1, Apr 21 2023), it contains an `IMDaemonController` (presumably `IMDaemonController.sharedController`) and an
// `IMInvocationCapturingProxy`
@interface IMDistributingProxy: NSProxy
- (instancetype _Nonnull)initWithTargets:(NSArray * _Nonnull)targets, ...;
- (instancetype _Nonnull)initWithTargets:(NSArray * _Nonnull)targets targetQueue:(dispatch_queue_t _Nullable)targetQueue asynchronous:(BOOL)asynchronous filterBlock:(id _Nullable)filterBlock;

- (NSArray * _Nonnull)targets;
- (dispatch_queue_t _Nullable)targetQueue;
- (BOOL)isAsynchronous;
- (id _Nullable)filterBlock;

@end

#endif /* IMDistributingProxy_h */
