
grammar Brill;

//#######################################################
// PARSER

expression : '.' ;

//#######################################################
// LEXER

/////////////////////////////////////////////////////////
// Identifiers

identifier : IdentifierHead IdentifierCharacters
           | '`' IdentifierHead IdentifierCharacters? '`'
           | ImplicitParameterName
           ;
identifier_list : identifier | identifier ',' identifier_list ;

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
IdentifierCharacters : ItentifierCharacter IdentifierCharacters ;
fragment ItentifierCharacter : [0-9]
                             | '\u0300'..'\u036F' | '\u1DC0'..'\u1DFF' | '\u20D0'..'\u20FF' | '\uFE20'..'\uFE2F'
                             | IdentifierHead
                             ;

/////////////////////////////////////////////////////////
// Literal

literal : NumericLiteral | StringLiteral | BooleanLiteral | NilLiteral ;

fragment NumericLiteral : '-'? IntegerLiteral | '-'? FloatingPointLiteral ;
fragment BooleanLiteral : 'true' | 'false' ;
fragment NilLiteral : 'nil' ;

// Integer Literals
fragment IntegerLiteral : BinaryLiteral
                        | OctalLiteral
                        | DecimalLiteral
                        | HexadecimalLiteral
                        ;

fragment BinaryLiteral : '0b' BinaryDigit BinaryLiteralCharacters? ;
fragment BinaryDigit : '0' | '1' ;
fragment BinaryLiteralCharacter : BinaryDigit | '_' ;
fragment BinaryLiteralCharacters : BinaryLiteralCharacter BinaryLiteralCharacters? ;

fragment OctalLiteral : '0o' OctalDigit OctalLiteralCharacters? ;
fragment OctalDigit : [0-7] ;
fragment OctalLiteralCharacter : OctalDigit | '_' ;
fragment OctalLiteralCharacters : OctalLiteralCharacter OctalLiteralCharacters? ;

fragment DecimalLiteral : DecimalDigit DecimalLiteralCharacters? ;
fragment DecimalDigit : [0-9] ;
fragment DecimalDigits : DecimalDigit DecimalDigits? ;
fragment DecimalLiteralCharacter : DecimalDigit | '_' ;
fragment DecimalLiteralCharacters : DecimalLiteralCharacter DecimalLiteralCharacters? ;

fragment HexadecimalLiteral : '0x' HexadecimalDigit HexadecimalLiteralCharacters? ;
fragment HexadecimalDigit : [0-9a-fA-F] ;
fragment HexadecimalLiteralCharacter : HexadecimalDigit | '_' ;
fragment HexadecimalLiteralCharacters : HexadecimalLiteralCharacter HexadecimalLiteralCharacters? ;

// Floating point literals
fragment FloatingPointLiteral : DecimalLiteral DecimalFraction? DecimalExponent?
                              | HexadecimalLiteral HexadecimalFraction? HexadecimalExponent
                              ;

fragment DecimalFraction : '.' DecimalLiteral ;
fragment DecimalExponent : FloatingPointE Sign? DecimalLiteral ;

fragment HexadecimalFraction : '.' HexadecimalDigit HexadecimalLiteralCharacters ;
fragment HexadecimalExponent : FloatingPointP Sign? DecimalLiteral ;

fragment FloatingPointE : 'e' | 'E' ;
fragment FloatingPointP : 'p' | 'P' ;
fragment Sign : '+' | '-' ;

// String literals
fragment StringLiteral : StaticStringLiteral | InterpolatedStringLiteral ;

fragment StringLiteralOpeningDelimiter : ExtendedStringLiteralDelimiter? '"' ;
fragment StringLiteralClosingDelimiter : '"' ExtendedStringLiteralDelimiter? ;

fragment StaticStringLiteral : StringLiteralOpeningDelimiter QuotedText? StringLiteralClosingDelimiter
                             | MultilineStringLiteralOpeningDelimiter MultilineQuotedText? MultilineStringLiteralClosingDelimiter
                             ;

fragment MultilineStringLiteralOpeningDelimiter : ExtendedStringLiteralDelimiter '"""' ;
fragment MultilineStringLiteralClosingDelimiter : '"""' ExtendedStringLiteralDelimiter ;
fragment ExtendedStringLiteralDelimiter : '#' ExtendedStringLiteralDelimiter? ;

fragment QuotedText : QuotedTextItem QuotedText? ;
fragment QuotedTextItem : EscapedCharacter
                        | ~('"' | '\\' | '\u000A' | '\u000D')
                        ;

fragment MultilineQuotedText : MultilineQuotedTextItem MultilineQuotedText? ;
fragment MultilineQuotedTextItem : EscapedCharacter
                                 | ~('\\')
                                 | EscapedNewLine
                                 ;

fragment InterpolatedStringLiteral : StringLiteralOpeningDelimiter InterpolatedText? StringLiteralClosingDelimiter
                                   | MultilineStringLiteralOpeningDelimiter InterpolatedText? MultilineStringLiteralClosingDelimiter
                                   ;

fragment InterpolatedText : InterpolatedTextItem InterpolatedText? ;
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

WS : WSItem WS? -> skip ;

fragment WSItem : LB
                | Comment
                | MultiLineComment
                | '\u0000' | '\u0009' | '\u000B' | '\u000C' | '\u0020'
                ;

// Comment
Comment : '//' CommentText LB ;

fragment CommentText : CommentTextItem CommentText? ;
fragment CommentTextItem : ~[\u000A\u000D] ;

// Multi-line comment
MultiLineComment : '/*' MultiLineCommentText '*/'  ;

fragment MultiLineCommentText : MultiLineCommentTextItem MultiLineCommentText? ;
fragment MultiLineCommentTextItem : MultiLineComment
                                  | CommentTextItem
	| ('/' ~'*' | ~'/' . | '*' ~'/' | ~'*' .)
;

// Line break
LB : '\u000A'
   | '\u000D'
   | '\u000D\u000A'
   ;
