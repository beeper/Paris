#import <CommunicationFilterItem.h>
#import <CommunicationFilterItemCache.h>
#import <CommunicationsFilterBlockList.h>
#import <CommunicationsFilterBlockListCache.h>

CommunicationFilterItem* CreateCMFItemFromString(NSString*);
Boolean CMFBlockListIsItemBlocked(CommunicationFilterItem* item);
NSString* CMFBlockListUpdatedNotification;
void CMFBlockListCopyItemsForAllServicesService(CFArrayRef * items);
