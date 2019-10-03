
grammar Brill;

options {
language=Cpp;
}

//#######################################################
// PARSER

topLevel : declarations? EOF ;

/////////////////////////////////////////////////////////
// Expressions

expression : tryOperator? prefixExpression binaryExpressions? ;
expressionList : expression ( ',' expression )* ;

prefixExpression : prefixOperator? postfixExpression
                 | inoutExpression
                 ;
inoutExpression : '&' Identifier ;

tryOperator : 'try' ( '?' | '!' )? ;

binaryExpression : binaryOperator prefixExpression
                 | assignmentOperator tryOperator? prefixExpression
                 | conditionalOperator tryOperator? prefixExpression
                 | typeCastingOperator
                 ;
binaryExpressions : binaryExpression+ ;

assignmentOperator : '=' ;

conditionalOperator : '?' expression ':' ;

typeCastingOperator : 'is' type
                    | 'as' ( '?' | '!' )? type
                    ;

primaryExpression : Identifier genericArgumentClause?
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
arrayLiteralItems : arrayLiteralItem ( ',' arrayLiteralItem )* ;
arrayLiteralItem : expression ;

dictionaryLiteral : '[' ( dictionaryLiteralItems | ':' ) ']' ;
dictionaryLiteralItems : dictionaryLiteralItem ( ',' dictionaryLiteralItem )* ;
dictionaryLiteralItem : expression ':' expression ;

selfExpression : 'self' | selfMethodExpression | selfSubscriptExpression | selfInitializerExpression ;
selfMethodExpression : 'self' '.' Identifier ;
selfSubscriptExpression : 'self' '[' functionCallArgumentList ']' ;
selfInitializerExpression : 'self' '.' 'init' ;

superclassExpression : superclassMethodExpression | superclassSubscriptExpression | superclassInitializerExpression ;
superclassMethodExpression : 'super' '.' Identifier ;
superclassSubscriptExpression : 'super' '[' functionCallArgumentList ']' ;
superclassInitializerExpression : 'super' '.' 'init' ;

closureExpression : '{' closureSignature? statements? '}' ;
closureSignature : captureList? closureParameterClause 'throws'? functionResult? 'in'
                 | captureList 'in'
                 ;
closureParameterClause : '(' closureParameterList? ')' | identifierList ;
closureParameterList : closureParameter ( ',' closureParameter )* ;
closureParameter : closureParameterName typeAnnotation?
                 | closureParameterName typeAnnotation '...'
                 ;
closureParameterName : Identifier ;
captureList : '[' captureListItems ']' ;
captureListItems : captureListItem ( ',' captureListItem )* ;
captureListItem : captureSpecifier? expression ;
captureSpecifier : 'weak' | 'unowned' ( '(' ( 'safe' | 'unsafe' ) ')' )? ;

implicitMemberExpression : '.' Identifier ;

parenthesizedExpression : '(' expression ')' ;

tupleExpression : '(' ( tupleElement ',' tupleElementList )? ')' ;
tupleElementList : tupleElement ( ',' tupleElement )* ;
tupleElement : ( Identifier ':' )? expression ;

wildcardExpression : '_' ;

keyPathExpression : '\\' type? '.' keyPathComponents ;
keyPathComponents : keyPathComponent ( '.' keyPathComponent )* ;
keyPathComponent : Identifier keyPathPostfixes? | keyPathPostfixes ;
keyPathPostfixes : keyPathPostfix+ ;
keyPathPostfix : '?' | '!' | 'self' | '[' functionCallArgumentList ']' ;

selectorExpression : '#selector' '(' ( ( 'getter' | 'setter' ) ':' )? expression ')' ;

keyPathStringExpression : '#keypath' '(' expression ')' ;

//postfixExpression : primaryExpression #postfixPrimaryExpression
//                  | postfixExpression postfixOperator #postfixOperatorExpression
//                  | postfixExpression ( functionCallArgumentClause | functionCallArgumentClause? trailingClosure ) #functionCallExpression
//                  | postfixExpression '.' 'init' ( '(' argumentNames ')' )? #initializerExpression
//                  | postfixExpression '.' ( DecimalDigits | Identifier ( genericArgumentClause? | '(' argumentNames ')' ) ) #explicitMemberExpression
//                  | postfixExpression '.' 'self' #postfixSelfExpression
//                  | postfixExpression '[' functionCallArgumentList ']' #subscriptExpression
//                  | postfixExpression '!' #forcedValueExpression
//                  | postfixExpression '?' #optionalChainingExpression
//                  ;
postfixExpression : postfixBaseExpression ( postfixFunctionExpression | postfixPostExpression )? ;
postfixBaseExpression : primaryExpression postfixDotExpression? ;
postfixDotExpression : '.' ( 'init' | DecimalDigits | Identifier | 'self' ) ;
postfixFunctionExpression : functionCallArgumentClause | functionCallArgumentClause? trailingClosure ;
postfixPostExpression : '[' functionCallArgumentList ']' | '!' | '?'  ;

//functionCallExpression : postfixExpression functionCallArgumentClause
//                       | postfixExpression functionCallArgumentClause? trailingClosure
//                       ;
functionCallArgumentClause : '(' functionCallArgumentList? ')' ;
functionCallArgumentList : functionCallArgument ( ',' functionCallArgument )* ;
functionCallArgument : ( Identifier ':' )? ( expression | op ) ;
trailingClosure : closureExpression ;

//initializerExpression : postfixExpression '.' 'init'
//                      | postfixExpression '.' 'init' '(' argumentNames ')'
//                      ;

//explicitMemberExpression : postfixExpression '.' DecimalDigits
//                         | postfixExpression '.' identifier genericArgumentClause?
//                         | postfixExpression '.' identifier '(' argumentNames ')'
//                         ;
argumentNames : argumentName+ ;
argumentName : Identifier ':' ;

//postfixSelfExpression : postfixExpression '.' 'self' ;
//
//subscriptExpression : postfixExpression '[' functionCallArgumentList ']' ;
//
//forcedValueExpression : postfixExpression '!' ;
//
//optionalChainingExpression : postfixExpression '?' ;

/////////////////////////////////////////////////////////
// Types

type : functionType
     | arrayType
     | dictionaryType
     | typeIdentifier
     | tupleType
     | type ( '?' | '!' )
     | protocolCompositionType
     | opaqueType
     | type '.' ( 'Type' | 'Protocol' )
     | selfType
     | 'Any'
     | '(' type ')'
     ;

typeAnnotation : attributes? 'inout'? type ;

typeIdentifier : typeName genericArgumentClause? ('.' typeIdentifier)?
               | Identifier
               ;
typeName : Identifier ;

tupleType : '(' ( tupleTypeElement ',' tupleTypeElementList )? ')' ;
tupleTypeElementList : tupleTypeElement ( ',' tupleTypeElementList )* ;
tupleTypeElement : elementName typeAnnotation | type ;
elementName : Identifier ;

functionType : attributes? functionTypeArgumentClause 'throws'? '->' type ;
functionTypeArgumentClause : '(' ( functionTypeArgumentList '...'? )? ')' ;
functionTypeArgumentList : functionTypeArgument ( ',' functionTypeArgument )* ;
functionTypeArgument : attributes? 'inout'? type | argumentLabel typeAnnotation ;
argumentLabel : Identifier ;

arrayType : '[' type ']' ;

dictionaryType : '[' type ':' type ']' ;

//optionalType : type '?' ;

//implicitlyUnwrappedOptionalType : type '!' ;

protocolCompositionType : typeIdentifier ( '&' typeIdentifier )+ ;

opaqueType : 'some' type ;

//metatypeType : type '.' 'Type' | type '.' 'Protocol' ;

selfType : 'Self' ;

typeInheritanceClause : ':' typeInheritanceList ;
typeInheritanceList : typeIdentifier ( ',' typeIdentifier )* ;

/////////////////////////////////////////////////////////
// Statements

statement : ( expression
              | declaration
              | loopStatement
              | branchStatement
              | labeledStatement
              | controlTransferStatement
              | deferStatement
              | doStatement
              | compilerControlStatement
          ) ';'?
          ;
statements : statement+ ;

loopStatement : forInStatement
              | whileStatement
              | repeatWhileStatement
              ;

forInStatement : 'for' 'case'? pattern 'in' expression whereClause? codeBlock ;

whileStatement : 'while' conditionList codeBlock ;
conditionList : condition ( ',' condition )* ;
condition : expression | availabilityCondition | caseCondition | optionalBindingCondition ;
caseCondition : 'case' pattern initializer ;
optionalBindingCondition : ( 'let' | 'var' ) pattern initializer ;

repeatWhileStatement : 'repeat' codeBlock 'while' expression ;

branchStatement : ifStatement
                | guardStatement
                | switchStatement
                ;

ifStatement : 'if' conditionList codeBlock elseClause? ;
elseClause : 'else' ( codeBlock | ifStatement ) ;

guardStatement : 'guard' conditionList 'else' codeBlock ;

switchStatement : 'switch' expression '{' switchCases? '}' ;
switchCases : switchCase+ ;
switchCase : ( caseLabel | defaultLabel ) statements
           | conditionalSwitchCase
           ;
caseLabel : attributes? 'case' caseItemList ':' ;
caseItemList : pattern whereClause? ( ',' caseItemList )? ;
defaultLabel : attributes? 'default' ':' ;
whereClause : 'where' whereExpression ;
whereExpression : expression ;
conditionalSwitchCase : switchIfDirectiveClause switchElseifDirectiveClauses? switchElseDirectiveClause? endifDirective ;
switchIfDirectiveClause : ifDirective compilationCondition switchCases? ;
switchElseifDirectiveClauses : elseifDirectiveClause+ ;
switchElseifDirectiveClause : elseifDirective compilationCondition switchCases? ;
switchElseDirectiveClause : elseDirective switchCases? ;

labeledStatement : statementLabel ( loopStatement | ifStatement | switchStatement | doStatement ) ;
statementLabel : labelName ':' ;
labelName : Identifier ;

controlTransferStatement : breakStatement
                         | continueStatement
                         | fallthroughStatement
                         | returnStatement
                         | throwStatement
                         ;

breakStatement : 'break' labelName? ;

continueStatement : 'continue' labelName? ;

fallthroughStatement : 'fallthrough' ;

returnStatement : 'return' expression? ;

throwStatement : 'throw' expression ;

deferStatement : 'defer' codeBlock ;

doStatement : 'do' codeBlock catchClauses? ;
catchClauses : catchClause+ ;
catchClause : 'catch' pattern? whereClause? codeBlock ;

compilerControlStatement : conditionalCompilationBlock
                         | lineControlStatement
                         | diagnosticStatement
                         ;

conditionalCompilationBlock : ifDirectiveClause elseifDirectiveClauses? elseDirectiveClause? endifDirective ;
ifDirectiveClause : ifDirective compilationCondition statements? ;
elseifDirectiveClauses : elseifDirectiveClause+ ;
elseifDirectiveClause : elseifDirective compilationCondition statements? ;
elseDirectiveClause : elseDirective statements? ;
ifDirective : '#if' ;
elseifDirective : '#elseif' ;
elseDirective : '#else' ;
endifDirective : '#endif' ;
compilationCondition : platformCondition
                     | Identifier
                     | booleanLiteral
                     | '(' compilationCondition ')'
                     | '!' compilationCondition
                     | compilationCondition ( '&&' | '||' ) compilationCondition
                     ;
platformCondition : 'os' '(' operatingSystem ')'
                  | 'arch' '(' architecture ')'
                  | ( 'brill' | 'compiler' ) '(' ( '>=' | '<' ) brillVersion ')'
                  | 'canImport' '(' moduleName ')'
                  | 'targetEnvironment' '(' environment ')'
                  ;
operatingSystem : 'macOS' | 'windows' | 'linux' ;
architecture : 'i386' | 'x86_64' | 'arm' | 'arm64' ;
brillVersion : DecimalDigits brillVersionContinuation? ;
brillVersionContinuation : ('.' DecimalDigits)+ ;
moduleName : Identifier ;
environment : 'library' | 'executable' ;

lineControlStatement : '#sourceLocation' '(' ( 'file' ':' fileName ',' 'line' ':' LineNumber )? ')' ;
fileName : StaticStringLiteral ;

diagnosticStatement : ( '#error' | '#warning' | '#todo' ) '(' diagnosticMessage ')' ;
diagnosticMessage : StaticStringLiteral ;

availabilityCondition : '#available' '(' availabilityArguments ')' ;
availabilityArguments : availabilityArgument ( ',' availabilityArgument )* ;
availabilityArgument : platformName platformVersion
                     | '*'
                     ;
platformName : 'macOS'
             | 'windows'
             | 'linux'
             ;
platformVersion : DecimalDigits ( '.' DecimalDigits ( '.' DecimalDigits )? )? ;

/////////////////////////////////////////////////////////
// Declarations

declaration : importDeclaration
            | constantDeclaration
            | variableDeclaration
            | typealiasDeclaration
            | functionDeclaration
            | enumDeclaration
            | structDeclaration
            | classDeclaration
            | protocolDeclaration
            | initializerDeclaration
            | deinitializerDeclaration
            | extensionDeclaration
            | subscriptDeclaration
            | operatorDeclaration
            | precedenceGroupDeclaration
            ;
declarations : declaration+ ;

topLevelDeclaration : statements? ;

codeBlock : '{' statements? '}' ;

importDeclaration : attributes? 'import' importKind? importPath ;
importKind : 'typealias' | 'struct' | 'class' | 'enum' | 'protocol' | 'let' | 'var' | 'func' ;
importPath : importPathIdentifier ( '.' importPathIdentifier )* ;
importPathIdentifier : Identifier | op ;

constantDeclaration : attributes? declarationModifiers? 'let' patternInitializerList ;
patternInitializerList : patternInitializer ( ',' patternInitializer )* ;
patternInitializer : pattern initializer? ;
initializer : expression ;

variableDeclaration : variableDeclarationHead ( patternInitializerList
                    | variableName ( typeAnnotation ( codeBlock | getterSetterBlock | getterSetterKeywordBlock | initializer? willSetDidSetBlock ) | initializer willSetDidSetBlock )  ) ;
variableDeclarationHead : attributes? declarationModifiers? 'var' ;
variableName : Identifier ;
getterSetterBlock : codeBlock
                  | '{' ( getterClause setterClause? | setterClause getterClause ) '}'
                  ;
getterClause : attributes? mutationModifier? 'get' codeBlock ;
setterClause : attributes? mutationModifier? 'set' setterName? codeBlock ;
setterName : '(' Identifier ')' ;
getterSetterKeywordBlock : '{' ( getterKeywordClause setterKeywordClause? | setterKeywordClause getterKeywordClause ) '}' ;
getterKeywordClause : attributes? mutationModifier? 'get' ;
setterKeywordClause : attributes? mutationModifier? 'set' ;
willSetDidSetBlock : '{' ( willSetClause didSetClause? | didSetClause willSetClause? ) '}' ;
willSetClause : attributes? 'willSet' setterName? codeBlock ;
didSetClause : attributes? 'didSet' setterName? codeBlock ;

typealiasDeclaration : attributes? accessLevelModifier? 'typealias' typealiasName genericParameterClause? typealiasAssignment ;
typealiasName : Identifier ;
typealiasAssignment : '=' type ;

functionDeclaration : functionHead functionName genericParameterClause? functionSignature genericWhereClause? functionBody? ;
functionHead : attributes? declarationModifiers? 'func' ;
functionName : Identifier | op ;
functionSignature : parameterClause ( 'throws' | 'rethrows' )? functionResult? ;
functionResult : '->' attributes? type ;
functionBody : codeBlock ;
parameterClause : '(' parameterList? ')' ;
parameterList : parameter ( ',' parameter )* ;
parameter : externalParameterName? localParameterName typeAnnotation ( defaultArgumentClause | '...' )? ;
externalParameterName : Identifier ;
localParameterName : Identifier ;
defaultArgumentClause : '=' expression ;

enumDeclaration : attributes? accessLevelModifier? ( unionStyleEnum | rawValueStyleEnum ) ;
unionStyleEnum : 'indirect'? 'enum' enumName genericParameterClause? typeInheritanceClause? genericWhereClause? '{' unionStyleEnumMembers? '}' ;
unionStyleEnumMembers : unionStyleEnumMember+ ;
unionStyleEnumMember : declaration | unionStyleEnumCaseClause | compilerControlStatement ;
unionStyleEnumCaseClause : attributes? 'indirect'? 'case' unionStyleEnumCaseList ;
unionStyleEnumCaseList : unionStyleEnumCase ( ',' unionStyleEnumCase )* ;
unionStyleEnumCase : enumCaseName tupleType? ;
enumName : Identifier ;
enumCaseName : Identifier ;
rawValueStyleEnum : 'enum' enumName genericParameterClause? typeInheritanceClause genericWhereClause? '{' rawValueStyleEnumMembers '}' ;
rawValueStyleEnumMembers : rawValueStyleEnumMember+ ;
rawValueStyleEnumMember : declaration | rawValueStyleEnumCaseClause | compilerControlStatement ;
rawValueStyleEnumCaseClause : attributes? 'case' rawValueStyleEnumCaseList ;
rawValueStyleEnumCaseList : rawValueStyleEnumCase ( ',' rawValueStyleEnumCase )* ;
rawValueStyleEnumCase : enumCaseName rawValueAssignment? ;
rawValueAssignment : '=' rawValueLiteral ;
rawValueLiteral : numericLiteral | StaticStringLiteral | booleanLiteral ;

structDeclaration : attributes? accessLevelModifier? 'struct' structName genericParameterClause? typeInheritanceClause? genericWhereClause? structBody ;
structName : Identifier ;
structBody : '{' structMembers? '}' ;
structMembers : structMember+ ;
structMember : declaration | compilerControlStatement ;

classDeclaration : attributes? ( accessLevelModifier? 'final'? | 'final' accessLevelModifier? ) 'class' className genericParameterClause? typeInheritanceClause? genericWhereClause? classBody ;
className : Identifier ;
classBody : '{' classMembers? '}' ;
classMembers : classMember+ ;
classMember : declaration | compilerControlStatement ;

protocolDeclaration : attributes? accessLevelModifier? 'protocol' protocolName typeInheritanceClause? genericWhereClause? protocolBody ;
protocolName : Identifier ;
protocolBody : '{' protocolMembers? '}' ;
protocolMembers : protocolMember+ ;
protocolMember : protocolMemberDeclaration | compilerControlStatement ;
protocolMemberDeclaration : protocolPropertyDeclaration
                          | protocolMethodDeclaration
                          | protocolInitializerDeclaration
                          | protocolSubscriptDeclaration
                          | protocolAssociatedTypeDeclaration
                          | typealiasDeclaration
                          ;

protocolPropertyDeclaration : variableDeclarationHead variableName typeAnnotation getterSetterKeywordBlock ;

protocolMethodDeclaration : functionHead functionName genericParameterClause? functionSignature genericWhereClause? ;

protocolInitializerDeclaration : initializerHead genericParameterClause? parameterClause ( 'throws' | 'rethrows' )? genericWhereClause? ;

protocolSubscriptDeclaration : subscriptHead subscriptResult genericWhereClause? getterSetterKeywordBlock ;

protocolAssociatedTypeDeclaration : attributes? accessLevelModifier? 'associatedtype' typealiasName typeInheritanceClause? typealiasAssignment genericWhereClause? ;

initializerDeclaration : initializerHead genericParameterClause? parameterClause ( 'throws' | 'rethrows' )? genericWhereClause? initializerBody ;
initializerHead : attributes? declarationModifiers? 'init' ( '?' | '!' )? ;
initializerBody : codeBlock ;

deinitializerDeclaration : attributes? 'deinit' codeBlock ;

extensionDeclaration : attributes? accessLevelModifier? 'extension' typeIdentifier typeInheritanceClause? genericWhereClause? extensionBody ;
extensionBody : '{' extensionMembers '}' ;
extensionMembers : extensionMember+ ;
extensionMember : declaration | compilerControlStatement ;

subscriptDeclaration : subscriptHead subscriptResult genericWhereClause? ( codeBlock | getterSetterBlock | getterSetterKeywordBlock ) ;
subscriptHead : attributes? declarationModifiers? 'subscript' genericParameterClause? parameterClause ;
subscriptResult : '->' attributes? type ;

operatorDeclaration : prefixOperatorDeclaration | postfixOperatorDeclaration | infixOperatorDeclaration ;
prefixOperatorDeclaration : 'prefix' 'operator' op ;
postfixOperatorDeclaration : 'postfix' 'operator' op ;
infixOperatorDeclaration : 'infix' 'operator' op infixOperatorGroup? ;
infixOperatorGroup : ':' precedenceGroupName ;

precedenceGroupDeclaration : 'precedencegroup' precedenceGroupName '{' precedenceGroupAttributes? '}' ;
precedenceGroupAttributes : precedenceGroupAttribute+ ;
precedenceGroupAttribute : precedenceGroupRelation
                         | precedenceGroupAssignment
                         | precedenceGroupAssociativity
                         ;
precedenceGroupRelation : ( 'higherThan' | 'lowerThan' ) ':' precedenceGroupNames ;
precedenceGroupAssignment : 'assignment' ':' booleanLiteral ;
precedenceGroupAssociativity : 'associativity' ':' ( 'left' | 'right' | 'none' ) ;
precedenceGroupNames : precedenceGroupName ( ',' precedenceGroupName )* ;
precedenceGroupName : Identifier ;

declarationModifier : 'class' | 'convenience' | 'dynamic' | 'final' | 'infix' | 'lazy' | 'optional' | 'override' | 'postfix' | 'prefix' | 'required' | 'static' | 'unowned' ( '(' ( 'safe' | 'unsafe' ) ')' )? | 'weak'
                    | accessLevelModifier
                    | mutationModifier
                    ;
declarationModifiers : declarationModifier+ ;
accessLevelModifier : ( 'private' | 'fileprivate' | 'internal' | 'public' | 'open' ) ( '(' 'set' ')' )? ;
mutationModifier : 'mutating' | 'nonmutating' ;

/////////////////////////////////////////////////////////
// Attributes

attribute : '@' attributeName attributeArgumentClause? ;
attributeName : Identifier ;
attributeArgumentClause : '(' balancedTokens? ')' ;
attributes : attribute+ ;
balancedTokens : balancedToken+ ;
balancedToken : '(' balancedTokens? ')'
              | '[' balancedTokens? ']'
              | '{' balancedTokens? '}'
              | Identifier | /*keyword |*/ literal | op
              | ~('('|')'|'['|']'|'{'|'}')
              ;

/////////////////////////////////////////////////////////
// Patterns

pattern : ( wildcardPattern | identifierPattern | tuplePattern ) typeAnnotation?
        | valueBindingPattern
        | enumCasePattern
        | optionalPattern
        | 'is' type | pattern 'as' type
        | expressionPattern
        ;

wildcardPattern : '_' ;

identifierPattern : Identifier ;

valueBindingPattern : ( 'var' | 'let' ) pattern ;

tuplePattern : '(' tuplePatternElementList? ')' ;
tuplePatternElementList : tuplePatternElement ( ',' tuplePatternElement )* ;
tuplePatternElement : ( Identifier ':' )? pattern ;

enumCasePattern : typeIdentifier? '.' enumCaseName tuplePattern? ;

optionalPattern : identifierPattern '?' ;

//typeCastingPattern : 'is' type | pattern 'as' type ;
//isPattern : 'is' type ;
//asPattern : pattern 'as' type ;

expressionPattern : expression ;

/////////////////////////////////////////////////////////
// Generic parameters and arguments

genericParameterClause : '<' genericParameterList '>' ;
genericParameterList : genericParameter ( ',' genericParameter )* ;
genericParameter : typeName ( ':' ( typeIdentifier | protocolCompositionType ) )? ;
genericWhereClause : 'where' requirementList ;
requirementList : requirement ( ',' requirement )* ;
requirement : conformanceRequirement | sameTypeRequirement ;
conformanceRequirement : typeIdentifier ':' ( typeIdentifier | protocolCompositionType ) ;
sameTypeRequirement : typeIdentifier '==' type ;

genericArgumentClause : '<' genericArgumentList '>' ;
genericArgumentList : genericArgument ( ',' genericArgument )* ;
genericArgument : type ;

//#######################################################
// LEXER

/////////////////////////////////////////////////////////
// Operators

op : OperatorHead OperatorCharacters?
         | '.' DotOperatorCharacters?
         ;

binaryOperator : op ;
prefixOperator : op ;
postfixOperator : op ;

/////////////////////////////////////////////////////////
// Identifiers
identifierList : Identifier ( ',' Identifier )* ;

/////////////////////////////////////////////////////////
// Literal

literal : numericLiteral | StringLiteral | booleanLiteral | nilLiteral ;

numericLiteral : '-'? ( integerLiteral | floatingPointLiteral ) ;
booleanLiteral : 'true' | 'false' ;
nilLiteral : 'nil' ;

// Integer Literals
integerLiteral : binaryLiteral
               | octalLiteral
               | decimalLiteral
               | hexadecimalLiteral
               ;

binaryLiteral : '0b' BinaryDigit BinaryLiteralCharacters? ;
octalLiteral : '0o' OctalDigit OctalLiteralCharacters? ;
decimalLiteral : DecimalDigit DecimalLiteralCharacters? ;
hexadecimalLiteral : '0x' HexadecimalDigit HexadecimalLiteralCharacters? ;

// Floating point literals
floatingPointLiteral : decimalLiteral decimalFraction? decimalExponent?
                     | hexadecimalLiteral hexadecimalFraction? hexadecimalExponent
                     ;

decimalFraction : '.' decimalLiteral ;
decimalExponent : FloatingPointE Sign? decimalLiteral ;

hexadecimalFraction : '.' HexadecimalDigit HexadecimalLiteralCharacters ;
hexadecimalExponent : FloatingPointP Sign? decimalLiteral ;

TRY : 'try' ;
SELF : 'self' ;
SSELF : 'Self' ;
SUPER : 'super' ;
TRUE : 'true' ;
FALSE : 'false' ;
NIL : 'nil' ;
LET : 'let' ;
VAR : 'var' ;
TYPEALIAS : 'typealias' ;
INDIRECT : 'indirect' ;
FINAL : 'final' ;
THROWS : 'throws' ;
RETHROWS : 'rethrows' ;
WHERE : 'where' ;
IS : 'is' ;
AS : 'as' ;
DEFAULT : 'default' ;
SOME : 'some' ;
INOUT : 'inout' ;
PPROTOCOL : 'Protocol' ;
TTYPE : 'Type' ;
ANY : 'Any' ;
SAFE : 'safe' ;
UNSAFE : 'unsafe' ;
FILE : 'file' ;
LINE : 'line' ;

PREFIX : 'prefix' ;
POSTFIX : 'postfix' ;
INFIX : 'infix' ;
PRECEDENCEGROUP : 'precedencegroup' ;
ASSOCIATIVITY : 'associativity' ;
HIGHER_THAN : 'higherThan' ;
LOWER_THAN : 'lowerThan' ;
OPERATOR : 'operator' ;
ASSIGNMENT : 'assignment' ;

LEFT : 'left' ;
RIGHT : 'right' ;
NONE : 'none' ;

WEAK : 'weak' ;
UNOWNED : 'unowned' ;
CONVENIENCE : 'convenience' ;
DYNAMIC : 'dynamic' ;
LAZY : 'lazy' ;
OPTIONAL : 'optional' ;
OVERRIDE : 'override' ;
REQUIRED : 'required' ;
STATIC : 'static' ;
MUTATING : 'mutating' ;
NONMUTATING : 'nonmutating' ;

PRIVATE : 'private' ;
FILEPRIVATE : 'fileprivate' ;
INTERNAL : 'internal' ;
PUBLIC : 'public' ;
OPEN : 'open' ;

INIT : 'init' ;
STRUCT : 'struct' ;
CLASS : 'class' ;
ENUM : 'enum' ;
PROTOCOL : 'protocol' ;
FUNC : 'func' ;
DEINIT : 'deinit' ;
EXTENSION : 'extension' ;
SUBSCRIPT : 'subscript' ;
ASSOCIATEDTYPE : 'associatedtype' ;
CASE : 'case' ;
WILL_SET : 'willSet' ;
DID_SET : 'didSet' ;
GET : 'get' ;
SET : 'set' ;
GETTER : 'getter' ;
SETTER : 'setter' ;

FOR : 'for' ;
WHILE : 'while' ;
REPEAT : 'repeat' ;
IF : 'if' ;
GUARD : 'guard' ;
SWITCH : 'switch' ;
DEFER : 'defer' ;
DO : 'do' ;
ELSE : 'else' ;
CATCH : 'catch' ;
IN : 'in' ;

BREAK : 'break' ;
CONTINUE : 'continue' ;
FALLTHROUGH : 'fallthrough' ;
RETURN : 'return' ;
THROW : 'throw' ;
IMPORT : 'import' ;

MACOS : 'macOS' ;
WINDOWS : 'windows' ;
LINUX : 'linux' ;
I386 : 'i386' ;
X86_64 : 'x86_64' ;
ARM : 'arm' ;
ARM64 : 'arm64' ;
LIBRARY : 'library' ;
EXECUTABLE : 'executable' ;

OS : 'os' ;
ARCH : 'arch' ;
BRILL : 'brill' ;
COMPILER : 'compiler' ;
CAN_IMPORT : 'canImport' ;
TARGET_ENVIRONMENT : 'targetEnvironment' ;

FILED : '#file';
LINED : '#line' ;
COLUMN : '#column' ;
FUNCTION : '#function' ;
DSOHANDLE : '#dsohandle' ;
SELECTOR : '#selector' ;
KEYPATH : '#keypath' ;
SOURCELOCATION : '#sourceLocation' ;
ERROR : '#error' ;
WARNING : '#warning' ;
TODO : '#todo' ;
AVAILABLE : '#available' ;

IFD : '#if' ;
ELSEIFD : '#elseif' ;
ELSED : '#else' ;
ENDIFD : '#endif' ;

AND : '&' ;
OR : '|' ;
DAND : '&&' ;
DOR : '||' ;
PLUS : '+' ;
MINUS : '-' ;
MULTIPLY : '*' ;
DIVIDE : '/' ;
CARROT : '^' ;
EQUALS : '==' ;

OPEN_CURLY : '{' ;
CLOSE_CURLY : '}' ;
OPEN_PARENTHESIS : '(' ;
CLOSE_PARENTHESIS : ')';
OPEN_SQUARE : '[' ;
CLOSE_SQUARE : ']' ;
OPEN_ANGLE : '<' ;
CLOSE_ANGLE : '>' ;

SEMICOLON : ';' ;
COLON : ':' ;
COMMA : ',' ;
PERIOD : '.' ;
QUESTION : '?' ;
EXCLEMATION : '!' ;
POUND : '#' ;
EQUAL : '=' ;
BACKSLASH : '\\' ;
AT : '@' ;
ARROW : '->' ;
LTE : '<=' ;
GTE : '>=' ;
ELIPSES : '...' ;

SINGLE_QUOTE : '\'' ;
DOUBLE_QUOTE : '"' ;

COMMENT : '//' ;
MULTILINE_COMMENT_OPEN : '/*' ;
MULTILINE_COMMENT_CLOSE : '*/' ;

Identifier : IdentifierHead IdentifierCharacters
           | '`' IdentifierHead IdentifierCharacters? '`'
           | ImplicitParameterName
           ;

// Identifier head
IdentifierHead : [a-zA-Z]
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

LineNumber : [1-9] [0-9]* ;
OperatorHead : '/' | '=' | '-' | '+' | '!' | '*' | '%' | '<' | '>' | '&' | '|' | '^' | '~' | '?'
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
OperatorCharacters : OperatorCharacter+ ;

//DotOperatorHead : '.' ;
fragment DotOperatorCharacter : '.' | OperatorCharacter ;
DotOperatorCharacters : DotOperatorCharacter+ ;

ImplicitParameterName : '$' DecimalDigits ;

BinaryPrefix : '0b' ;
BinaryDigit : '0' | '1' ;
fragment BinaryLiteralCharacter : BinaryDigit | '_' ;
BinaryLiteralCharacters : BinaryLiteralCharacter+ ;

OctalPrefix : '0o' ;
OctalDigit : [0-7] ;
fragment OctalLiteralCharacter : OctalDigit | '_' ;
OctalLiteralCharacters : OctalLiteralCharacter+ ;

DecimalDigit : [0-9] ;
DecimalDigits : DecimalDigit+ ;
fragment DecimalLiteralCharacter : DecimalDigit | '_' ;
DecimalLiteralCharacters : DecimalLiteralCharacter+ ;

HexadecimalPrefix : '0x' ;
HexadecimalDigit : [0-9a-fA-F] ;
fragment HexadecimalLiteralCharacter : HexadecimalDigit | '_' ;
HexadecimalLiteralCharacters : HexadecimalLiteralCharacter+ ;

FloatingPointE : 'e' | 'E' ;
FloatingPointP : 'p' | 'P' ;
Sign : '+' | '-' ;

StringLiteralOpeningDelimiter : ExtendedStringLiteralDelimiter? '"' ;
StringLiteralClosingDelimiter : '"' ExtendedStringLiteralDelimiter? ;

MultilineStringLiteralOpeningDelimiter : ExtendedStringLiteralDelimiter '"""' ;
MultilineStringLiteralClosingDelimiter : '"""' ExtendedStringLiteralDelimiter ;
fragment ExtendedStringLiteralDelimiter : '#'+ ;

EscapeSequence : '\\' ExtendedStringLiteralDelimiter ;
EscapedCharacter : EscapeSequence '0' | EscapeSequence '\\' | EscapeSequence 't' | EscapeSequence 'n' | EscapeSequence 'r' | EscapeSequence '"' | EscapeSequence '\''
                          | EscapeSequence 'u' '{' UnicodeScalarDigits '}'
                          ;
fragment UnicodeScalarDigits : HexadecimalDigit ; // TODO: limit this to 8 characters

EscapedNewLine : EscapeSequence WS? LB ;

// String literals
StringLiteral : StaticStringLiteral | InterpolatedStringLiteral ;

StaticStringLiteral : StringLiteralOpeningDelimiter QuotedText? StringLiteralClosingDelimiter
                             | MultilineStringLiteralOpeningDelimiter MultilineQuotedText? MultilineStringLiteralClosingDelimiter
                             ;

InterpolatedStringLiteral : StringLiteralOpeningDelimiter InterpolatedText? StringLiteralClosingDelimiter
                                   | MultilineStringLiteralOpeningDelimiter InterpolatedText? MultilineStringLiteralClosingDelimiter
                                   ;

fragment QuotedText : QuotedTextItem+ ;
fragment QuotedTextItem : EscapedCharacter
                        | ~('"' | '\\' | '\u000A' | '\u000D')
                        ;

fragment MultilineQuotedText : MultilineQuotedTextItem+ ;
fragment MultilineQuotedTextItem : EscapedCharacter
                                 | ~('\\')
                                 | EscapedNewLine
                                 ;

fragment InterpolatedText : InterpolatedTextItem+ ;
fragment InterpolatedTextItem : '\\(' . ')' | QuotedTextItem ;

fragment MultilineInterpolatedText : MultilineInterpolatedTextItem MultilineInterpolatedText? ;
fragment MultilineInterpolatedTextItem : '\\(' . ')' | MultilineQuotedTextItem ;

fragment CommentTextItem : ~('\u000A'|'\u000B'|'\u000C'|'\u000D') ;

// Comment
Comment : '//' CommentText LB ;

// Multi-line comment
MultiLineComment : '/*' MultiLineCommentText '*/'  ;

fragment MultiLineCommentText : MultiLineCommentTextItem+ ;
fragment MultiLineCommentTextItem : MultiLineComment
                         | CommentTextItem
	                     | NotMultiLineCommentDelimiter
                         ;
fragment CommentText : CommentTextItem+ ;

fragment NotMultiLineCommentDelimiter : ( NotMultiLineCommentOpeningDelimiter | NotMultilineCommentClosingDelimiter ) ;
fragment NotMultiLineCommentOpeningDelimiter : '/' ~'*' | ~'/' . ;
fragment NotMultilineCommentClosingDelimiter : '*' ~'/' | ~'*' . ;

/////////////////////////////////////////////////////////
// Whitespace

WS : WSItem+ -> skip ;

fragment WSItem : LB
                | Comment
                | MultiLineComment
                | '\u0000' | '\u0009' | '\u000B' | '\u000C' | '\u0020'
                ;

// Line break
LB : '\u000A'
   | '\u000D'
   | '\u000D\u000A'
   ;
