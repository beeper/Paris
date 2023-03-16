//
//  IDSIDInfoResult.h
//  
//
//  Created by June Welker on 3/16/23.
//

#ifndef IDSIDInfoResult_h
#define IDSIDInfoResult_h

@class IDSIDKTData;

NS_CLASS_AVAILABLE(13_0, 16_0)
@interface IDSIDInfoResult
- (NSString * _Nonnull)uri;
- (long long)status;
- (id _Nullable)endpoints;
- (IDSIDKTData * _Nullable)ktData;
- (id _Nullable)gameCenterData;
@end

#endif /* IDSIDInfoResult_h */
