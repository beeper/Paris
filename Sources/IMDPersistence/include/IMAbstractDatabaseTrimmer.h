//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <IMAbstractDatabaseArchiver.h>

@interface IMAbstractDatabaseTrimmer : IMAbstractDatabaseArchiver
{
}

- (BOOL)copyDatabase:(id)arg1;
- (BOOL)trimDatabaseWithOperation:(struct IMDSqlOperation *)arg1;
- (void)performMessageSelectionWithOperation:(struct IMDSqlOperation *)arg1;

@end

