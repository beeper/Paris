//
//  CUTResult.h
//  
//
//  Created by June Welker on 3/6/23.
//

#ifndef CUTResult_h
#define CUTResult_h

#import <Foundation/Foundation.h>

@interface CUTResult<__covariant Success>: NSObject {
	long long _state;
}

- (Success)value;
- (NSError *)error;
@end

#endif /* CUTResult_h */
