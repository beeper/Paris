#ifndef IMDPersistence_H
#define IMDPersistence_H

#include <Foundation/Foundation.h>
#include <IMFoundation.h>
#include <IMSharedUtilities.h>

NS_ASSUME_NONNULL_BEGIN

// MARK: - IMDPersistence

NSArray* IMDMessageRecordCopyMessagesForGUIDs(NSArray<NSString*>* guids);

void IMDSetIsRunningInDatabaseServerProcess(char);
BOOL IMDIsRunningInDatabaseServerProcess(void);

NS_ASSUME_NONNULL_END

typedef struct _IMDChatRecordStruct *IMDChatRecordRef;
IMDChatRecordRef IMDChatRecordCopyChatForMessageID(int64_t messageID) CF_RETURNS_RETAINED;
CFStringRef IMDChatRecordCopyGUID(CFAllocatorRef allocator, IMDChatRecordRef chat) CF_RETURNS_RETAINED;

typedef void* IMDSqlDatabaseRef;
typedef CFStringRef IMDSqlTransactionRef;
typedef void* IMDSqlConnectionRef;
typedef void* IMDDatabaseObject;

typedef struct IMDSqlStatement {
    void* sql_statement;
    int step;
    CFStringRef query;
    void* sqlite3;
    int bindCount;
    int bindCountTotal;
    int stepCount;
    struct Measurement {
        struct nested1 {
            const char* file;
            const char* name;
            const char* function;
            const char* originalFunction;
            int line;
        } location;
        uint64_t identifier;
        uint64_t filter;
        CFStringRef comment;
        double startTime;
        double stopTime;
        double elapsedTime;
    } measurement;
} IMDSqlStatement;

typedef struct IMDSqlOperation {
    void* database;
    void* connection;
    void* transaction;
    void* databaseObject;
    IMDSqlStatement statement;
    CFErrorRef error;
} IMDSqlOperation;

void IMDSqlStatementBindTextFromCFString(IMDSqlStatement* statement, CFStringRef string);
void IMDSqlStatementBindTextFromArrayOfCFStrings(IMDSqlStatement* statement, CFArrayRef strings);
void IMDSqlStatementBindInt64(IMDSqlStatement* statement, int64_t val);
void IMDSqlStatementBindInt(IMDSqlStatement* statement, int32_t val);

IMDSqlOperation IMDSqlOperationInitWithSharedCSDBDatabase(void);

typedef void (^IMDBlock)();
BOOL IMDSqlOperationExecuteQuery(IMDSqlOperation* operation, NSString* query, IMDBlock bindingOrCompletionBlock);

#endif /* #ifndef PARIS_H */
