#import "CGXConnectionBox.h"
#import "MTLResource-Protocol.h"
#import "MTLResourceSPI-Protocol.h"
#import "SLDataTimelineConfig.h"
#import "SLDataTimelineConnection-Protocol.h"
#import "SLDataTimelineConnection.h"
#import "SLDataTimelineProcess-Protocol.h"
#import "SLDataTimelineProcessEntry.h"
#import "SLDataTimelineProcessWindows-Protocol.h"
#import "SLDataTimelineServerSnapshot-Protocol.h"
#import "SLDataTimelineServerSnapshotEntry.h"
#import "SLDataTimelineSession-Protocol.h"
#import "SLDataTimelineSessionEntry.h"
#import "SLDataTimelineSessionPlaceholderEntry.h"
#import "SLDataTimelineSessionProcessCollection-Protocol.h"
#import "SLDataTimelineSessionSnapshotEntry.h"
#import "SLDataTimelineSnapshotCollection-Protocol.h"
#import "SLDataTimelineSnapshotCollection.h"
#import "SLDataTimelineSnapshotCollectionMetadata-Protocol.h"
#import "SLDataTimelineUpdate-Protocol.h"
#import "SLDataTimelineUpdate.h"
#import "SLSecureCursorAssertion.h"
#import "SLSecureCursorAssertionManager.h"
#import "SLSessionOwner.h"
#import "SLXPCConvertible-Protocol.h"
#import "SLXPCExportable-Protocol.h"
#import "SLXPCImportable-Protocol.h"

#import <CoreFoundation/CoreFoundation.h>

NSDictionary* SLSSessionCopyCurrentSessionProperties(void);
CFArrayRef _Nullable SLSSessionCopyAllSessionProperties(void);
int SLSSessionCreateLoginSessionID(NSData* _Nullable data, BOOL visible);
mach_port_t SLSGetConnectionPortById(int);
