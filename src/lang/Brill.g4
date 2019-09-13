
grammar Brill;

//#######################################################
// PARSER

/////////////////////////////////////////////////////////
// Expressions

expression : tryOperator? prefixExpression binaryExpressions? ;
expressionList : expression ( ',' expression )* ;

prefixExpression : prefixOperator? postfixExpression
                 | inoutExpression
                 ;
inoutExpression : '&' identifier ;

tryOperator : 'try' | 'try' '?' | 'try' '!' ;

binaryExpression : binaryOperator prefixExpression
                 | assignmentOperator tryOperator? prefixExpression
                 | conditionalOperator tryOperator? prefixExpression
                 | typeCastingOperator
                 ;
binaryExpressions : binaryExpression+ ;

assignmentOperator : '=' ;

conditionalOperator : '?' expression ':' ;

typeCastingOperator : 'is' type
                    | 'as' type
                    | 'as' '?' type
                    | 'as' '!' type
                    ;

primaryExpression : identifier genericArgumentClause?
                  | literalExpression
                  | selfExpression
                  | superclassExpression
                  | closureExpression
                  | parenthesizedExpression
                  | tupleExpression
                  | implicitMemberExpression
                  | wildcardExpression
                  | keyPathExpression
                  | selectorExpression
                  | keyPathStringExpression
                  ;

literalExpression : literal
                  | arrayLiteral | dictionaryLiteral
                  | '#file' | '#line' | '#column' | '#function' | '#dsohandle'
                  ;

arrayLiteral : '[' arrayLiteralItems? ']' ;
arrayLiteralItems : arrayLiteralItem ','? | arrayLiteralItem ',' arrayLiteralItems ;
arrayLiteralItem : expression ;

dictionaryLiteral : '[' dictionaryLiteralItems ']' | '[' ':' ']' ;
dictionaryLiteralItems : dictionaryLiteralItem ','? | dictionaryLiteralItem ',' dictionaryLiteralItems ;
dictionaryLiteralItem : expression ':' expression ;

selfExpression : 'self' | selfMethodExpression | selfSubscriptExpression | selfInitializerExpression ;
selfMethodExpression : 'self' '.' identifier ;
selfSubscriptExpression : 'self' '[' functionCallArgumentList ']' ;
selfInitializerExpression : 'self' '.' 'init' ;

superclassExpression : superclassMethodExpression | superclassSubscriptExpression | superclassInitializerExpression ;
superclassMethodExpression : 'super' '.' identifier ;
superclassSubscriptExpression : 'super' '[' functionCallArgumentList ']' ;
superclassInitializerExpression : 'super' '.' 'init' ;

closureExpression : '{' closureSignature? statements? '}' ;
closureSignature : captureList? closureParameterClause 'throws'? functionResult? 'in'
                 | captureList 'in'
                 ;
closureParameterClause : '(' ')' | '(' closureParameterList ')' | identifierList ;
closureParameterList : closureParameter ( ',' closureParameter )* ;
closureParameter : closureParameterName typeAnnotation?
                 | closureParameterName typeAnnotation '...'
                 ;
closureParameterName : identifier ;
captureList : '[' captureListItems ']' ;
captureListItems : captureListItem ( ',' captureListItem )* ;
captureListItem : captureSpecifier? expression ;
captureSpecifier : 'weak' | 'unowned' | 'unowned(safe)' | 'unowned(unsafe)' ;

implicitMemberExpression : '.' identifier ;

parenthesizedExpression : '(' expression ')' ;

tupleExpression : '(' ')' | '(' tupleElement ',' tupleElementList ')' ;
tupleElementList : tupleElement ( ',' tupleElement )* ;
tupleElement : expression | identifier ':' expression ;

wildcardExpression : '_' ;

keyPathExpression : '\\' type? '.' keyPathComponents ;
keyPathComponents : keyPathComponent ( '.' keyPathComponent )* ;
keyPathComponent : identifier keyPathPostfixes? | keyPathPostfixes ;
keyPathPostfixes : keyPathPostfix+ ;
keyPathPostfix : '?' | '!' | 'self' | '[' functionCallArgumentList ']' ;

/////////////////////////////////////////////////////////
// Types

type : functionType
     | arrayType
     | dictionaryType
     | typeIdentifier
     | tupleType
     | optionalType
     | implicitlyUnwrappedOptionalType
     | protocolCompositionType
     | opaqueType
     | metatypeType
     | selfType
     | 'Any'
     | '(' type ')'
     ;

typeAnnotation : attributes? 'inout'? type ;

typeIdentifier : typeName genericArgumentClause? ('.' typeIdentifier)?
               | identifier
               ;

tupleType : '(' ')' | '(' tupleTypeElement ',' tupleTypeElementList ')' ;
tupleTypeElementList : tupleTypeElement ( ',' tupleTypeElementList )* ;
tupleTypeElement : elementName typeAnnotation | type ;
elementName : identifier ;

functionType : attributes? functionTypeArgumentClause 'throws'? '->' type ;
functionTypeArgumentClause : '(' ')'
                           | '(' functionTypeArgumentList '...'? ')'
                           ;
functionTypeArgumentList : functionTypeArgument ( ',' functionTypeArgument )* ;
functionTypeArgument : attributes? 'inout'? type | argumentLabel typeAnnotation ;
argumentLabel : identifier ;

arrayType : '[' type ']' ;

dictionaryType : '[' type ':' type ']' ;

optionalType : type '?' ;

implicitlyUnwrappedOptionalType : type '!' ;

protocolCompositionType : typeIdentifier ( '&' typeIdentifier )+ ;

opaqueType : 'some' type ;

metatypeType : type '.' 'Type' | type '.' 'Protocol' ;

selfType : 'Self' ;

typeInheritanceClause : ':' typeInheritanceList ;
typeInheritanceList : typeIdentifier ( ',' typeIdentifier )* ;

//#######################################################
// LEXER

/////////////////////////////////////////////////////////
// Operators

op : OperatorHead OperatorCharacters?
         | DotOperatorHead DotOperatorCharacters?
         ;

fragment OperatorHead : '/' | '=' | '-' | '+' | '!' | '*' | '%' | '<' | '>' | '&' | '|' | '^' | '~' | '?'
                      | '\u00A1'..'\u00A7'
                      | '\u00A9' | '\u00AB'
                      | '\u00AC' | '\u00AE'
                      | '\u00B0'..'\u00B1'
                      | '\u00B6' | '\u00BB' | '\u00BF' | '\u00D7' | '\u00F7'
                      | '\u2016'..'\u2017'
                      | '\u2020'..'\u2027'
                      | '\u2030'..'\u203E'
                      | '\u2041'..'\u2053'
                      | '\u2055'..'\u205E'
                      | '\u2190'..'\u23FF'
                      | '\u2500'..'\u2775'
                      | '\u2794'..'\u2BFF'
                      | '\u2E00'..'\u2E7F'
                      | '\u3001'..'\u3003'
                      | '\u3008'..'\u3020'
                      | '\u3030'
                      ;
fragment OperatorCharacter : OperatorHead
                           | '\u0300'..'\u036F'
                           | '\u1DC0'..'\u1DFF'
                           | '\u20D0'..'\u20FF'
                           | '\uFE00'..'\uFE0F'
                           | '\uFE20'..'\uFE2F'
                           | '\u{E0100}'..'\u{E01EF}'
                           ;
fragment OperatorCharacters : OperatorCharacter+ ;

fragment DotOperatorHead : '.' ;
fragment DotOperatorCharacter : '.' | OperatorCharacter ;
fragment DotOperatorCharacters : DotOperatorCharacter+ ;

binaryOperator : op ;
prefixOperator : op ;
postfixOperator : op ;

/////////////////////////////////////////////////////////
// Identifiers

identifier : IdentifierHead IdentifierCharacters
           | '`' IdentifierHead IdentifierCharacters? '`'
           | ImplicitParameterName
           ;
identifierList : identifier ( ',' identifier )* ;

ImplicitParameterName : '$' DecimalDigits ;

// Identifier head
fragment IdentifierHead : [a-zA-Z]
                        | '_'
                        | '\u00A8' | '\u00AA' | '\u00AD' | '\u00AF' | '\u00B2'..'\u00B5' | '\u00B7'..'\u00BA'
                        | '\u00BC'..'\u00BE' | '\u00C0'..'\u00D6' | '\u00D8'..'\u00F6' | '\u00F8'..'\u00FF'
                        | '\u0100'..'\u02FF' | '\u0370'..'\u167F' | '\u1681'..'\u180D' | '\u180F'..'\u1DBF'
                        | '\u1E00'..'\u1FFF'
                        | '\u200B'..'\u200D' | '\u202A'..'\u202E' | '\u203F'..'\u2040' | '\u2054' | '\u2060'..'\u206F'
                        | '\u2070'..'\u20CF' | '\u2100'..'\u218F' | '\u2460'..'\u24FF' | '\u2776'..'\u2793'
                        | '\u2C00'..'\u2DFF' | '\u2E80'..'\u2FFF'
                        | '\u3004'..'\u3007' | '\u3021'..'\u302F' | '\u3031'..'\u303F' | '\u3040'..'\uD7FF'
                        | '\uF900'..'\uFD3D' | '\uFD40'..'\uFDCF' | '\uFDF0'..'\uFE1F' | '\uFE30'..'\uFE44'
                        | '\uFE47'..'\uFFFD'
                        | '\u{10000}'..'\u{1FFFD}' | '\u{20000}'..'\u{2FFFD}' | '\u{30000}'..'\u{3FFFD}' | '\u{40000}'..'\u{4FFFD}'
                        | '\u{50000}'..'\u{5FFFD}' | '\u{60000}'..'\u{6FFFD}' | '\u{70000}'..'\u{7FFFD}' | '\u{80000}'..'\u{8FFFD}'
                        | '\u{90000}'..'\u{9FFFD}' | '\u{A0000}'..'\u{AFFFD}' | '\u{B0000}'..'\u{BFFFD}' | '\u{C0000}'..'\u{CFFFD}'
                        | '\u{D0000}'..'\u{DFFFD}' | '\u{E0000}'..'\u{EFFFD}'
                        ;

// Identifier characters
IdentifierCharacters : ItentifierCharacter+ ;
fragment ItentifierCharacter : [0-9]
                             | '\u0300'..'\u036F' | '\u1DC0'..'\u1DFF' | '\u20D0'..'\u20FF' | '\uFE20'..'\uFE2F'
                             | IdentifierHead
                             ;

/////////////////////////////////////////////////////////
// Literal

literal : numericLiteral | stringLiteral | booleanLiteral | nilLiteral ;

numericLiteral : '-'? integerLiteral | '-'? floatingPointLiteral ;
booleanLiteral : 'true' | 'false' ;
nilLiteral : 'nil' ;

// Integer Literals
integerLiteral : binaryLiteral
               | octalLiteral
               | decimalLiteral
               | hexadecimalLiteral
               ;

binaryLiteral : '0b' BinaryDigit BinaryLiteralCharacters? ;
fragment BinaryDigit : '0' | '1' ;
fragment BinaryLiteralCharacter : BinaryDigit | '_' ;
fragment BinaryLiteralCharacters : BinaryLiteralCharacter+ ;

octalLiteral : '0o' OctalDigit OctalLiteralCharacters? ;
fragment OctalDigit : [0-7] ;
fragment OctalLiteralCharacter : OctalDigit | '_' ;
fragment OctalLiteralCharacters : OctalLiteralCharacter+ ;

decimalLiteral : DecimalDigit DecimalLiteralCharacters? ;
fragment DecimalDigit : [0-9] ;
fragment DecimalDigits : DecimalDigit+ ;
fragment DecimalLiteralCharacter : DecimalDigit | '_' ;
fragment DecimalLiteralCharacters : DecimalLiteralCharacter+ ;

hexadecimalLiteral : '0x' HexadecimalDigit HexadecimalLiteralCharacters? ;
fragment HexadecimalDigit : [0-9a-fA-F] ;
fragment HexadecimalLiteralCharacter : HexadecimalDigit | '_' ;
fragment HexadecimalLiteralCharacters : HexadecimalLiteralCharacter+ ;

// Floating point literals
floatingPointLiteral : decimalLiteral decimalFraction? decimalExponent?
                     | hexadecimalLiteral hexadecimalFraction? hexadecimalExponent
                     ;

decimalFraction : '.' decimalLiteral ;
decimalExponent : FloatingPointE Sign? decimalLiteral ;

hexadecimalFraction : '.' HexadecimalDigit HexadecimalLiteralCharacters ;
hexadecimalExponent : FloatingPointP Sign? decimalLiteral ;

fragment FloatingPointE : 'e' | 'E' ;
fragment FloatingPointP : 'p' | 'P' ;
fragment Sign : '+' | '-' ;

// String literals
stringLiteral : staticStringLiteral | interpolatedStringLiteral ;

fragment StringLiteralOpeningDelimiter : ExtendedStringLiteralDelimiter? '"' ;
fragment StringLiteralClosingDelimiter : '"' ExtendedStringLiteralDelimiter? ;

staticStringLiteral : StringLiteralOpeningDelimiter QuotedText? StringLiteralClosingDelimiter
                             | MultilineStringLiteralOpeningDelimiter MultilineQuotedText? MultilineStringLiteralClosingDelimiter
                             ;

fragment MultilineStringLiteralOpeningDelimiter : ExtendedStringLiteralDelimiter '"""' ;
fragment MultilineStringLiteralClosingDelimiter : '"""' ExtendedStringLiteralDelimiter ;
fragment ExtendedStringLiteralDelimiter : '#'+ ;

fragment QuotedText : QuotedTextItem+ ;
fragment QuotedTextItem : EscapedCharacter
                        | ~('"' | '\\' | '\u000A' | '\u000D')
                        ;

fragment MultilineQuotedText : MultilineQuotedTextItem+ ;
fragment MultilineQuotedTextItem : EscapedCharacter
                                 | ~('\\')
                                 | EscapedNewLine
                                 ;

interpolatedStringLiteral : StringLiteralOpeningDelimiter InterpolatedText? StringLiteralClosingDelimiter
                                   | MultilineStringLiteralOpeningDelimiter InterpolatedText? MultilineStringLiteralClosingDelimiter
                                   ;

fragment InterpolatedText : InterpolatedTextItem+ ;
fragment InterpolatedTextItem : '\\(' . ')' | QuotedTextItem ;

fragment MultilineInterpolatedText : MultilineInterpolatedTextItem MultilineInterpolatedText? ;
fragment MultilineInterpolatedTextItem : '\\('  ')' | MultilineQuotedTextItem ;

fragment EscapeSequence : '\\' ExtendedStringLiteralDelimiter ;
fragment EscapedCharacter : EscapeSequence '0' | EscapeSequence '\\' | EscapeSequence 't' | EscapeSequence 'n' | EscapeSequence 'r' | EscapeSequence '"' | EscapeSequence '\''
                          | EscapeSequence 'u' '{' UnicodeScalarDigits '}'
                          ;
fragment UnicodeScalarDigits : HexadecimalDigit ; // TODO: limit this to 8 characters

fragment EscapedNewLine : EscapeSequence WS? LB ;

/////////////////////////////////////////////////////////
// Whitespace

WS : WSItem+ -> skip ;

fragment WSItem : LB
//                | comment
//                | multiLineComment
                | '\u0000' | '\u0009' | '\u000B' | '\u000C' | '\u0020'
                ;

// Comment
comment : '//' CommentText LB ;

fragment CommentText : CommentTextItem+ ;
fragment CommentTextItem : ~[\u000A\u000D] ;

// Multi-line comment
multiLineComment : '/*' multiLineCommentText '*/'  ;

multiLineCommentText : multiLineCommentTextItem+ ;
multiLineCommentTextItem : multiLineComment
                         | CommentTextItem
	                     | NotMultiLineCommentDelimiter
                         ;

NotMultiLineCommentDelimiter : ( NotMultiLineCommentOpeningDelimiter | NotMultilineCommentClosingDelimiter ) ;
fragment NotMultiLineCommentOpeningDelimiter : '/' ~'*' | ~'/' . ;
fragment NotMultilineCommentClosingDelimiter : '*' ~'/' | ~'*' . ;

// Line break
LB : '\u000A'
   | '\u000D'
   | '\u000D\u000A'
   ;
