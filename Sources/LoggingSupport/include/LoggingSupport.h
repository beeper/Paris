#ifndef LoggingSupport_H
#define LoggingSupport_H

#import <Foundation/Foundation.h>
#import <os/log.h>
#import <os/activity.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSObject OSLogDevice;

typedef NS_OPTIONS(NSUInteger, OSActivityStreamOption) {
    OSActivityStreamOptionProcessOnly = 0x00000001,
    OSActivityStreamOptionTracePayload = 0x00000002,
    OSActivityStreamOptionLiveStream = 0x00000004,
    OSActivityStreamOptionPreciseTimestamps = 0x00000008,
    OSActivityStreamOptionTypeInfo = 0x00000100,
    OSActivityStreamOptionTypeDebug = 0x00000200,
    OSActivityStreamOptionNoPrivateData = 0x80000000,
};

typedef NS_OPTIONS(NSUInteger, OSActivityEventType) {
    OSActivityEventTypeActivityCreate = 0x0201,
    OSActivityEventTypeActivityTransition = 0x0202,
    OSActivityEventTypeUserAction = 0x0203,
    OSActivityEventTypeTraceMessage = 0x0300,
    OSActivityEventTypeLogMessage = 0x0400,
    OSActivityEventTypeLegacyLogMessage = 0x0480,
    OSActivityEventTypeTimesync = 0x500,
    OSActivityEventTypeSignpost = 0x600,
    OSActivityEventTypeLoss = 0x700,
    OSActivityEventTypeStatedumpEvent = 0x0A00,
};

typedef NS_ENUM(NSInteger, OSLogDeviceEvent) {
    kOSLogDeviceEventNew,
    kOSLogDeviceEventDelete,
    kOSLogDeviceNotTrusted
};

typedef NS_OPTIONS(NSUInteger, OSActivityEventFilter) {
    OSActivityEventFilterActivities = 0x000001,
    OSActivityEventFilterTraceMessages = 0x000002,
    OSActivityEventFilterLogMessages = 0x000004,
    OSActivityEventFilterDefault =
            OSActivityEventFilterActivities |
            OSActivityEventFilterTraceMessages |
            OSActivityEventFilterLogMessages,
};

typedef NS_ENUM(uint8_t, OSActivityEventMessageType) {
    OSActivityEventMessageTypeRelease = 0x00,
    OSActivityEventMessageTypeInfo = 0x01,
    OSActivityEventMessageTypeDebug = 0x02,
    OSActivityEventMessageTypeError = 0x10,
    OSActivityEventMessageTypeFault = 0x11,
};

@interface OSActivityEvent : NSObject
@property (nonatomic, readonly) pid_t processID;
@property (nonatomic, readonly) uint64_t processUniqueID;
@property (nonatomic, readonly, copy, nullable) NSUUID *processImageUUID;
@property (nonatomic, readonly, copy, nullable) NSString *processImagePath;
@property (nonatomic, readonly, copy, nullable) NSString *process;
@property (nonatomic, readonly) OSActivityEventType eventType;
@property (nonatomic, readonly) os_activity_id_t parentActivityID;
@property (nonatomic, readonly) os_activity_id_t activityID;
@property (nonatomic, readonly) uint64_t traceID;
@property (nonatomic, readonly) uint64_t threadID;
@property (nonatomic, readonly) uint64_t machTimestamp;
@property (nonatomic, readonly, copy, nullable) NSDate *timestamp;
@property (nonatomic, readonly, copy, nullable) NSTimeZone *timezone;
@property (nonatomic, readonly, copy, nullable) NSUUID *senderImageUUID;
@property (nonatomic, readonly, copy, nullable) NSString *senderImagePath;
@property (nonatomic, readonly, copy, nullable) NSString *sender;
@property (nonatomic, copy, nullable) NSString *eventMessage;
@property (nonatomic, readonly) BOOL persisted;
-(NSDictionary<NSString*, NSObject*> * _Nonnull) properties;
-(void) _addProperties:(NSMutableDictionary<NSString*, NSObject*>  * _Nonnull )dict;
@end

@interface OSActivityEventMessage : OSActivityEvent
@property (readonly, copy, nullable) NSString *format;
@end

@interface OSActivityLogMessageEvent : OSActivityEventMessage
@property (nonatomic, readonly, copy, nullable) NSString *subsystem;
@property (nonatomic, readonly, copy, nullable) NSString *category;
@property (nonatomic, readonly) NSUInteger senderProgramCounter;
@property (nonatomic, readonly) OSActivityEventMessageType messageType;
-(void) _addProperties:(NSMutableDictionary<NSString*, NSObject*> * _Nonnull)properties;
@end

@class OSActivityStream;

@protocol OSActivityStreamDelegate<NSObject>
@required
- (BOOL) activityStream:(OSActivityStream *)stream results:(nullable NSArray<OSActivityEvent *> *)results;
@optional
- (void) streamDidStart:(OSActivityStream *)stream;
- (void) streamDidFail:(OSActivityStream *)stream error:(NSError *)error;
- (void) streamDidStop:(OSActivityStream *)stream;
@end

@protocol OSDeviceDelegate<NSObject>
@required
- (BOOL) activityStream:(OSActivityStream *)stream deviceUDID:(NSString*)udid deviceID:(OSLogDevice*)devID status:(OSLogDeviceEvent)status error:(nullable NSError *)error;
@end

@interface OSActivityStream : NSObject
- (nullable instancetype) init NS_DESIGNATED_INITIALIZER;
- (void) addProcessID:(pid_t)processID;
- (void) addFilterForActivity:(NSString *)activity andBinary:(NSString *)binary;
- (nullable id)getInfoForDevice:(OSLogDevice*)aDevice andKey:(NSString *)aKey;
- (BOOL) establishTrust:(OSLogDevice*)aDevice;
- (void) start;
- (void) stop;
@property (nonatomic, assign) OSActivityStreamOption options;
@property (nonatomic, assign) OSActivityEventFilter eventFilter;
@property (nonatomic) OSActivityEventType events;
@property (nonatomic, nullable, weak, nonatomic) id<OSActivityStreamDelegate> delegate;
@property (nonatomic, nullable, copy) NSCompoundPredicate *predicate;
@property (nonatomic, nullable, weak) id<OSDeviceDelegate> deviceDelegate;
@property (nonatomic, nullable, assign) OSLogDevice *device;
@property (nonatomic, nullable, assign) NSMutableDictionary<NSString *, NSMutableArray *> *activityFilters;
@end

NS_ASSUME_NONNULL_END

#endif /* #ifndef LoggingSupport_H */
