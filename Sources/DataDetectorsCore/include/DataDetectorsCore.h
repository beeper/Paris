#import "DDAbstractType.h"
#import "DDAtomicRegexp.h"
#import "DDBasicRegexp.h"
#import "DDBindableRegexp.h"
#import "DDBinderInfo.h"
#import "DDCompilationNote.h"
#import "DDCompilerState.h"
#import "DDConcatenationRegexp.h"
#import "DDDictionaryError.h"
#import "DDDisjunctionRegexp.h"
#import "DDEmptyPatternError.h"
#import "DDErrorRegexp.h"
#import "DDGrammar.h"
#import "DDInvalidRangeError.h"
#import "DDLRItem.h"
#import "DDLocation.h"
#import "DDLookupRegexp.h"
#import "DDMessageCache.h"
#import "DDMessageCacheElement.h"
#import "DDNonTerminal.h"
#import "DDOneOrMoreExp.h"
#import "DDOperatorRegexp.h"
#import "DDOptionalExp.h"
#import "DDParserState.h"
#import "DDProduction.h"
#import "DDRegexpManager.h"
#import "DDRepeatCount.h"
#import "DDRepeatMax.h"
#import "DDRepeatMinMax.h"
#import "DDScanServer.h"
#import "DDScanServerDispatcher.h"
#import "DDScanStepBlockContainer.h"
#import "DDScannerList.h"
#import "DDScannerObject.h"
#import "DDScannerResult.h"
#import "DDScannerService.h"
#import "DDScannerServiceConfiguration.h"
#import "DDStarExp.h"
#import "DDStatsBuilder.h"
#import "DDSymbol.h"
#import "DDTokenRegexp.h"
#import "DDTypeChecker.h"
#import "DDTypeCheckerDelegate.h"
#import "DDTypeInhabitant.h"
#import "DDURLMatch.h"
#import "DDURLifier.h"
#import "DDUnaryOperator.h"
#import "DDVariable.h"
#import "DDVariableNotFoundError.h"
#import "DataDetectorsSourceAccess.h"
#import "DataDetectorsSourceAccessProtocol.h"

typedef void* DDResultRef;
typedef void* DDScanQueryRef;

DDResultRef DDResultCreateEmpty(void);
typedef struct __DDQueryOffset {
    CFIndex         p0:32;
    CFIndex         p1:32;
} DDQueryOffset;
typedef struct __DDQueryRange {
    DDQueryOffset     p0;
    DDQueryOffset     p1;
} DDQueryRange;
DDResultRef DDResultCreate(CFStringRef arg0, DDQueryRange arg1);
void DDResultSetContent(DDResultRef result, DDScanQueryRef query);
DDScanQueryRef DDScanQueryCreateFromString(CFAllocatorRef allocator, CFStringRef string, CFRange range);
