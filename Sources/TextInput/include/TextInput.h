#ifndef TextInput_H
#define TextInput_H

#include <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TIKeyboardIntermediateText: NSObject
@end

@interface TIKeyboardOutput: NSObject
@property (nonatomic, copy) NSString *textToCommit;
- (void)insertText:(NSString *)insertionText;
- (void)deleteBackward:(NSUInteger)deletionCount;
- (void)deleteBackward;
- (void)insertTextAfterSelection:(NSString *)insertionText;
- (void)deleteForward:(NSUInteger)deletionCount;
- (void)deleteForward;
@end

@interface TIDocumentState: NSObject
@property (nonatomic, readonly) NSString *contextBeforeInput; // [contextRange.begin, inputRange.begin]
@property (nonatomic, readonly) NSString *markedText;         // [markedTextRange.begin, markedTextRange.end]
@property (nonatomic, readonly) NSString *selectedText;       // [selectedTextRange.begin, selectedTextRange.end]
@property (nonatomic, readonly) NSString *contextAfterInput;  // [inputRange.end, contextRange.end]
@end

@interface TITextInputTraits: NSObject
@end

NS_ASSUME_NONNULL_END

#endif /* #ifndef TextInput_H */
