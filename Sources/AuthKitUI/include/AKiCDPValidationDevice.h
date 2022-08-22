#import <Foundation/Foundation.h>
//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 15 2018 10:31:50).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@protocol NSSecureCoding;

@class NSDate, NSImage, NSNumber, NSString, NSUUID;

@interface AKiCDPValidationDevice : NSObject <NSSecureCoding>
{
    BOOL _usesPasscode;
    BOOL _usesNumericPasscode;
    BOOL _usesRandomPasscode;
    BOOL _isCurrentDevice;
    NSString *_deviceName;
    NSString *_deviceModel;
    NSString *_deviceModelClass;
    NSNumber *_numericPasscodeLength;
    NSImage *_deviceIcon;
    NSUUID *_deviceID;
    NSDate *_recordDate;
}

+ (BOOL)supportsSecureCoding;

@property(retain) NSDate *recordDate; // @synthesize recordDate=_recordDate;
@property BOOL isCurrentDevice; // @synthesize isCurrentDevice=_isCurrentDevice;
@property(retain) NSUUID *deviceID; // @synthesize deviceID=_deviceID;
@property(retain) NSImage *deviceIcon; // @synthesize deviceIcon=_deviceIcon;
@property(retain) NSNumber *numericPasscodeLength; // @synthesize numericPasscodeLength=_numericPasscodeLength;
@property BOOL usesRandomPasscode; // @synthesize usesRandomPasscode=_usesRandomPasscode;
@property BOOL usesNumericPasscode; // @synthesize usesNumericPasscode=_usesNumericPasscode;
@property BOOL usesPasscode; // @synthesize usesPasscode=_usesPasscode;
@property(copy) NSString *deviceModelClass; // @synthesize deviceModelClass=_deviceModelClass;
@property(copy) NSString *deviceModel; // @synthesize deviceModel=_deviceModel;
@property(copy) NSString *deviceName; // @synthesize deviceName=_deviceName;
- (BOOL)isEqual:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

