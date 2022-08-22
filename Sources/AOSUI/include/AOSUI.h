#ifndef AOSUI_H
#define AOSUI_H

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <Accounts/Accounts.h>

NS_ASSUME_NONNULL_BEGIN

NSString * const MMAccountSignInShouldConfigureKey;

@interface MM_Account: NSObject
+ (MM_Account *) accountWithID:(NSString *)accountID fetchAccountImage:(BOOL)fetch;
@property(readwrite, retain) NSDictionary *context;
- (ACAccount*) appleAccount;
- (void)refresh;
@end

@interface MMAccountMgr: NSObject
+ (MMAccountMgr *) sharedMgr;
- (nullable MM_Account *) accountWithID:(NSString *) accountID createIfMissing:(BOOL) create fetchAccountImage:(BOOL)shouldFetch;
- (void) signOutAccount:(MM_Account *) account withOptions:(NSDictionary *)options;
@end

@protocol iCloudPrefDelegate <NSObject>
@optional
- (void)updateSignIn;
- (BOOL)handleSignInCompleted;
- (void)startProgress;
- (void)endProgress;
- (void)topLevelShowSetUpUI:(NSView*) viewToShow withAccountID:(NSString*)accountID;
- (void)showUIForAccountTopLevel;
- (void) reloadNameStrings;
- (NSWindow *)mainWindow;
@end

@interface CastlePlugin: NSObject
+ (instancetype) sharedCastlePlugin;
@property (readwrite, assign) id<iCloudPrefDelegate> delegate;
- (void) loginWithUsername:(NSString*)username andPassword:(NSString*) password withContext:(NSDictionary*) context;
@end


NS_ASSUME_NONNULL_END

#endif /* #ifndef AOSUI_H */
