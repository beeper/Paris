//
//  IDSIDInfoOptions.h
//  
//
//  Created by June Welker on 3/16/23.
//

#ifndef IDSIDInfoOptions_h
#define IDSIDInfoOptions_h

NS_CLASS_AVAILABLE(13_0, 16_0)
@interface IDSIDInfoOptions
- (instancetype)initWithBypassLimit:(BOOL)bypassLimit allowRefresh:(BOOL)allowRefresh forceRefresh:(BOOL)forceRefresh respectExpiry:(BOOL)respectExpiry waitForReply:(BOOL)waitForReply;

// The `sync_` variants return the same object as their non-`sync_` counterparts, except that waitForReply == TRUE on `sync_` variants
// `current` and `refresh` return the same object, except that `refresh` has `allowRefresh == TRUE`
// All four of these methods return objects where bypassLimit == FALSE, forceRefresh == FALSE, and respectExpiry == TRUE
+ (IDSIDInfoOptions *)currentIDInfo;
+ (IDSIDInfoOptions *)sync_currentIDInfo;
+ (IDSIDInfoOptions *)refreshIDInfo;
+ (IDSIDInfoOptions *)sync_refreshIDInfo;
@end

#endif /* IDSIDInfoOptions_h */
