//
//  IMTapback.h
//  
//
//  Created by June on 10/21/22.
//

#ifndef IMTapback_h
#define IMTapback_h

#import <Foundation/Foundation.h>

NS_CLASS_AVAILABLE(13_0, 16_0)
@interface IMTapback: NSObject
@property(readonly, nonatomic) long long associatedMessageType;
- (NSString *)previewStringWithMessageSummaryInfo:(NSDictionary *)arg2 senderDisplayName:(NSString *)arg3 isFromMe:(BOOL)arg4;

@end

#endif /*IMTapback _h */
