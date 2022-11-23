//#!env swift

import Foundation

_ = dlopen("/System/Library/PrivateFrameworks/IMCore.framework/IMCore", RTLD_LAZY)

var count: UInt32 = 0
let classList = objc_copyClassList(&count)!
defer { free(UnsafeMutableRawPointer(classList)) }

objc_copyClassNamesForImage(<#T##Int8#>, <#T##Int32?#>)
