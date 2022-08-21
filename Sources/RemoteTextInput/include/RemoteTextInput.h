#ifndef RemoteTextInput_H
#define RemoteTextInput_H

#include <Foundation/Foundation.h>
#include <TextInput.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTIDocumentState : NSObject <NSSecureCoding, NSCopying> {
    TIDocumentState* _documentState;
    NSAttributedString* _textCheckingAnnotatedString;
    NSMutableDictionary* __selectionRects;
    CGRect _caretRectInWindow;
    CGRect _firstSelectionRectInWindow;
}
@property (nonatomic,retain) NSMutableDictionary * _selectionRects;                       //@synthesize _selectionRects=__selectionRects - In the implementation block
@property (nonatomic,retain) TIDocumentState * documentState;                             //@synthesize documentState=_documentState - In the implementation block
@property (assign,nonatomic) CGRect caretRectInWindow;                                    //@synthesize caretRectInWindow=_caretRectInWindow - In the implementation block
@property (assign,nonatomic) CGRect firstSelectionRectInWindow;                           //@synthesize firstSelectionRectInWindow=_firstSelectionRectInWindow - In the implementation block
@property (assign,nonatomic) NSRange selectedTextRange;
@property (nonatomic,readonly) NSRange markedTextRange;
@property (nonatomic,copy) NSAttributedString * textCheckingAnnotatedString;              //@synthesize textCheckingAnnotatedString=_textCheckingAnnotatedString - In the implementation block
+(BOOL)supportsSecureCoding;
-(void)setSelectedTextRange:(NSRange)arg1 ;
-(id)init;
-(TIDocumentState *)documentState;
-(NSRange)markedTextRange;
-(NSRange)selectedTextRange;
-(id)initWithCoder:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(NSRange)deltaForSelectionRange:(NSRange)arg1 ;
-(void)resetTextRects;
-(NSMutableDictionary *)_selectionRects;
-(void)set_selectionRects:(NSMutableDictionary *)arg1 ;
-(void)addTextRect:(CGRect)arg1 forCharacterRange:(NSRange)arg2 ;
-(BOOL)isEqual:(id)arg1 ;
-(void)setDocumentState:(TIDocumentState *)arg1 ;
-(id)description;
-(id)copyWithZone:(NSZone*)arg1 ;
-(unsigned long long)characterIndexForPoint:(CGPoint)arg1 ;
-(CGRect)firstRectForCharacterRange:(NSRange)arg1 ;
-(CGRect)caretRectInWindow;
-(CGRect)firstSelectionRectInWindow;
-(NSAttributedString *)textCheckingAnnotatedString;
-(void)setCaretRectInWindow:(CGRect)arg1 ;
-(void)setFirstSelectionRectInWindow:(CGRect)arg1 ;
-(void)setTextCheckingAnnotatedString:(NSAttributedString *)arg1 ;
@end

@interface RTIDocumentTraits : NSObject <NSCopying, NSSecureCoding> {
    
    NSString* _appId;
    NSString* _bundleId;
    NSString* _appName;
    NSString* _localizedAppName;
    NSArray* _associatedDomains;
    NSString* _title;
    NSString* _prompt;
    TITextInputTraits* _textInputTraits;
    NSIndexSet* _PINEntrySeparatorIndexes;
    unsigned long long _autofillMode;
    NSDictionary* _autofillContext;
    NSRange _validTextRange;
}
@property (nonatomic,copy) NSString * appId;                                     //@synthesize appId=_appId - In the implementation block
@property (nonatomic,copy) NSString * bundleId;                                  //@synthesize bundleId=_bundleId - In the implementation block
@property (nonatomic,copy) NSString * appName;                                   //@synthesize appName=_appName - In the implementation block
@property (nonatomic,copy) NSString * localizedAppName;                          //@synthesize localizedAppName=_localizedAppName - In the implementation block
@property (nonatomic,retain) NSArray * associatedDomains;                        //@synthesize associatedDomains=_associatedDomains - In the implementation block
@property (nonatomic,copy) NSString * title;                                     //@synthesize title=_title - In the implementation block
@property (nonatomic,copy) NSString * prompt;                                    //@synthesize prompt=_prompt - In the implementation block
@property (nonatomic,retain) TITextInputTraits * textInputTraits;                //@synthesize textInputTraits=_textInputTraits - In the implementation block
@property (nonatomic,retain) NSIndexSet * PINEntrySeparatorIndexes;              //@synthesize PINEntrySeparatorIndexes=_PINEntrySeparatorIndexes - In the implementation block
@property (assign,nonatomic) NSRange validTextRange;                             //@synthesize validTextRange=_validTextRange - In the implementation block
@property (assign,nonatomic) unsigned long long autofillMode;                    //@synthesize autofillMode=_autofillMode - In the implementation block
@property (nonatomic,retain) NSDictionary * autofillContext;                     //@synthesize autofillContext=_autofillContext - In the implementation block
+(BOOL)supportsSecureCoding;
-(void)setPrompt:(NSString *)arg1 ;
-(TITextInputTraits *)textInputTraits;
-(void)setAutofillMode:(unsigned long long)arg1 ;
-(NSString *)appId;
-(id)init;
-(void)setBundleId:(NSString *)arg1 ;
-(void)setPINEntrySeparatorIndexes:(NSIndexSet *)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(void)setAutofillContext:(NSDictionary *)arg1 ;
-(NSString *)localizedAppName;
-(void)encodeWithCoder:(id)arg1 ;
-(NSArray *)associatedDomains;
-(NSDictionary *)autofillContext;
-(NSString *)bundleId;
-(void)setValidTextRange:(NSRange)arg1 ;
-(void)setAppName:(NSString *)arg1 ;
-(BOOL)isEqual:(id)arg1 ;
-(NSString *)prompt;
-(void)setAssociatedDomains:(NSArray *)arg1 ;
-(NSRange)validTextRange;
-(id)description;
-(NSString *)title;
-(void)setTextInputTraits:(TITextInputTraits *)arg1 ;
-(void)setAppId:(NSString *)arg1 ;
-(void)setTitle:(NSString *)arg1 ;
-(NSIndexSet *)PINEntrySeparatorIndexes;
-(unsigned long long)autofillMode;
-(NSString *)appName;
-(void)setLocalizedAppName:(NSString *)arg1 ;
-(id)copyWithZone:(NSZone*)arg1 ;
-(void)copyContextualPropertiesFromDocumentTraits:(id)arg1 ;
@end

@protocol RTIInputSystemSessionDelegate
@end

@interface RTIStyledIntermediateText: NSObject
@end

@interface RTITextOperations : NSObject
@property (nonatomic,retain) NSDictionary * attributedPlaceholders;                              //@synthesize attributedPlaceholders=_attributedPlaceholders - In the implementation block
@property (nonatomic,readonly) NSMutableDictionary * mutableAttributedPlaceholders;
@property (nonatomic,readonly) TIKeyboardOutput * keyboardOutput;                                //@synthesize keyboardOutput=_keyboardOutput - In the implementation block
@property (nonatomic,retain) TIKeyboardIntermediateText * intermediateText;                      //@synthesize intermediateText=_intermediateText - In the implementation block
@property (nonatomic,retain) RTIStyledIntermediateText * styledIntermediateText;                 //@synthesize styledIntermediateText=_styledIntermediateText - In the implementation block
@property (nonatomic,copy) NSString * textToAssert;                                              //@synthesize textToAssert=_textToAssert - In the implementation block
@property (assign,nonatomic) NSRange selectionRangeToAssert;                                     //@synthesize selectionRangeToAssert=_selectionRangeToAssert - In the implementation block
@property (assign,nonatomic) SEL editingActionSelector;                                          //@synthesize editingActionSelector=_editingActionSelector - In the implementation block
@property (nonatomic,readonly) NSAttributedString * attributedInsertionText;
@property (assign,nonatomic) NSRange textCheckingAnnotationRange;                                //@synthesize textCheckingAnnotationRange=_textCheckingAnnotationRange - In the implementation block
@property (assign,nonatomic) NSRange textCheckingReplacementRange;                               //@synthesize textCheckingReplacementRange=_textCheckingReplacementRange - In the implementation block
@property (nonatomic,copy) NSAttributedString * textCheckingAnnotatedString;                     //@synthesize textCheckingAnnotatedString=_textCheckingAnnotatedString - In the implementation block
@property (assign,nonatomic) NSRange textCheckingAnnotationRemovalRange;                         //@synthesize textCheckingAnnotationRemovalRange=_textCheckingAnnotationRemovalRange - In the implementation block
@property (nonatomic,copy) NSString * textCheckingAnnotationToRemove;                            //@synthesize textCheckingAnnotationToRemove=_textCheckingAnnotationToRemove - In the implementation block
-(void)insertAttributedText:(id)arg1 ;
-(void)setIntermediateText:(TIKeyboardIntermediateText *)arg1 ;
-(NSString *)textToAssert;
-(NSRange)selectionRangeToAssert;
-(SEL)editingActionSelector;
-(TIKeyboardOutput *)keyboardOutput;
-(void)setTextToAssert:(NSString *)arg1 ;
-(void)setSelectionRangeToAssert:(NSRange)arg1 ;
-(TIKeyboardIntermediateText *)intermediateText;
-(NSAttributedString *)textCheckingAnnotatedString;
-(void)setTextCheckingAnnotatedString:(NSAttributedString *)arg1 ;
-(RTIStyledIntermediateText *)styledIntermediateText;
-(NSRange)textCheckingAnnotationRange;
-(NSRange)textCheckingReplacementRange;
-(NSRange)textCheckingAnnotationRemovalRange;
-(NSString *)textCheckingAnnotationToRemove;
-(void)_createAttributedPlaceholdersIfNecessary;
-(NSMutableDictionary *)mutableAttributedPlaceholders;
-(void)insertText:(id)arg1 replacementRange:(NSRange)arg2 ;
-(void)insertAttributedText:(id)arg1 replacementRange:(NSRange)arg2 ;
-(NSAttributedString *)attributedInsertionText;
-(void)setStyledIntermediateText:(RTIStyledIntermediateText *)arg1 ;
-(NSDictionary *)attributedPlaceholders;
-(void)setAttributedPlaceholders:(NSDictionary *)arg1 ;
-(void)setEditingActionSelector:(SEL)arg1 ;
-(void)setTextCheckingAnnotationRange:(NSRange)arg1 ;
-(void)setTextCheckingReplacementRange:(NSRange)arg1 ;
-(void)setTextCheckingAnnotationRemovalRange:(NSRange)arg1 ;
-(void)setTextCheckingAnnotationToRemove:(NSString *)arg1 ;
@end

@interface RTIInputSystemSession : NSObject
@property (nonatomic,retain) NSHashTable * extraSessionDelegates;                                   //@synthesize extraSessionDelegates=_extraSessionDelegates - In the implementation block
@property (nonatomic,retain) NSUUID * uuid;                                                         //@synthesize uuid=_uuid - In the implementation block
@property (nonatomic,retain) RTIDocumentTraits * documentTraits;                                    //@synthesize documentTraits=_documentTraits - In the implementation block
@property (nonatomic,retain) RTIDocumentState * documentState;                                      //@synthesize documentState=_documentState - In the implementation block
@property (nonatomic,retain) RTITextOperations * textOperations;                                    //@synthesize textOperations=_textOperations - In the implementation block
@property (nonatomic,readonly) RTITextOperations * _textOperations;
@property (assign,nonatomic) id<RTIInputSystemSessionDelegate> sessionDelegate;              //@synthesize sessionDelegate=_sessionDelegate - In the implementation block
-(RTIDocumentState *)documentState;
-(NSUUID *)uuid;
-(void)setTextOperations:(RTITextOperations *)arg1 ;
-(void)addSessionDelegate:(id)arg1 ;
-(RTIDocumentTraits *)documentTraits;
-(RTITextOperations *)textOperations;
-(void)setSessionDelegate:(id<RTIInputSystemSessionDelegate>)arg1 ;
-(void)setDocumentState:(RTIDocumentState *)arg1 ;
-(void)setUuid:(NSUUID *)arg1 ;
-(void)flushOperations;
-(id<RTIInputSystemSessionDelegate>)sessionDelegate;
-(void)_applyLocalTextOperations:(id)arg1 toDocumentState:(id)arg2 ;
-(void)setDocumentTraits:(RTIDocumentTraits *)arg1 ;
-(RTITextOperations *)_textOperations;
-(void)enumerateSessionDelegatesUsingBlock:(/*^block*/id)arg1 ;
-(void)_createTextOperationsIfNecessary;
-(void)applyLocalTextOperations:(id)arg1 toDocumentState:(id)arg2 ;
-(void)removeSessionDelegate:(id)arg1 ;
-(NSHashTable *)extraSessionDelegates;
-(void)setExtraSessionDelegates:(NSHashTable *)arg1 ;
@end


@interface RTIInputSystemSourceSession: RTIInputSystemSession
@end

NS_ASSUME_NONNULL_END

#endif /* #ifndef RemoteTextInput_H */
