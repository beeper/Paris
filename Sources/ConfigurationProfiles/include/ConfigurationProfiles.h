#ifndef ConfigurationProfiles_H
#define ConfigurationProfiles_H

#include <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface CPProfile: NSObject
-(instancetype _Nullable)initWithData:(NSData*)data error:(NSError* _Nullable* _Nullable)error;
@end

@interface CPProfileManager: NSObject
+(instancetype)sharedProfileManager NS_SWIFT_NAME(shared);
-(BOOL)profilesAreInstalled;
-(NSError* _Nullable)installProfile:(CPProfile*)profile forUser:(id _Nullable)user;
@end

@interface CPProvisioningManager: NSObject
+(instancetype)sharedProvisioningManager NS_SWIFT_NAME(shared);
-(NSError* _Nullable)installProvisioningProfile:(NSData*)profile withUserData:(NSData* _Nullable)userData;
@end
NS_ASSUME_NONNULL_END

#endif /* #ifndef ConfigurationProfiles_H */
