%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

extern void semantic(int);
extern void ReportParserError(char* message);
%}

%token TIDENT TNUMBER TCONST TELSE TIF	TEIF TINT TRETURN TVOID TWHILE
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN 	
%token TOR TAND TEQUAL TNOTEQU TGREATE TLESSE TINC TDEC TEOF TERROR TCOMMENT 	
%token TFNUMBER TFLOAT TADD TSUB TMUL TDIV TMOD TASSIGN 	
%token TNOT TLESS TGREAT TLPAREN TRPAREN TCOMMA TLBRACE TRBRACE TLBRACKET TRBRACKET TSEMI LOWER_THAN_ELSE 

%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE

%%
mini_c                     : translation_unit                                                { semantic(1); };
translation_unit           : external_dcl                                                    { semantic(2); }
                           | translation_unit external_dcl                                   { semantic(3); };
external_dcl               : function_def                                                    { semantic(4); }
                           | declaration                                                     { semantic(5); };
function_def               : function_header compound_st                                     { semantic(6); }
                           | error compound_st                                               { yyerrok; ReportParserError("function_def"); };
function_header            : dcl_spec function_name formal_param                             { semantic(7); };
// function_definition: int main(int x, int y) {} / function_prototype: int main(int x, int);
// formal_param: (int x, float y)                 / type_only_param: (int, float)
function_prototype         : function_name type_only_param                                   { semantic(7); }
                           | function_name formal_param                                      { semantic(7); };
type_only_param            : TLPAREN type_only_param_list TRPAREN                            { semantic(17); }
                           | TLPAREN type_only_param_list error                              { yyerrok; ReportParserError("type_only_param"); };
type_only_param_list       : type_only_param_dcl                                             { semantic(20); }
                           | type_only_param_list TCOMMA type_only_param_dcl                 { semantic(21); }
                           | type_only_param_list TCOMMA param_dcl                           { semantic(21); }
                           | formal_param_list TCOMMA type_only_param_dcl                    { semantic(21); };
type_only_param_dcl        : dcl_specifier                                                   { semantic(22); };
//
dcl_spec                   : dcl_specifiers                                                  { semantic(8); };
dcl_specifiers             : dcl_specifier                                                   { semantic(9); }
                           | dcl_specifiers dcl_specifier                                    { semantic(10); };
dcl_specifier              : type_qualifier                                                  { semantic(11); }
                           | type_specifier                                                  { semantic(12); };
type_qualifier             : TCONST                                                          { semantic(13); };
type_specifier             : TINT                                                            { semantic(14); }
                           | TFLOAT  
                           | TVOID                                                           { semantic(15); };
function_name              : TIDENT                                                          { semantic(16); };
                           | TERROR
formal_param               : TLPAREN opt_formal_param TRPAREN                                { semantic(17); }
                           | TLPAREN opt_formal_param error                                  { yyerrok; ReportParserError("formal_param"); };
opt_formal_param           : formal_param_list                                               { semantic(18); }
                           |                                                                 { semantic(19); };
formal_param_list          : param_dcl                                                       { semantic(20); }
                           | formal_param_list TCOMMA param_dcl                              { semantic(21); };
param_dcl                  : dcl_specifier declarator                                        { semantic(22); }
                           | dcl_specifier function_prototype                                ;
compound_st                : TLBRACE TRBRACE                                                 { semantic(23); }
                           | TLBRACE block_item_list TRBRACE                                 { semantic(23); }
                           | TLBRACE error                                                   { yyerrok; ReportParserError("compound_st MISSING RBRACE"); }
                           | TLBRACE block_item_list error                                   { yyerrok; ReportParserError("compound_st MISSING RBRACE"); };
block_item_list            : block_item                                                      { semantic(26); }
                           | block_item_list block_item                                      { semantic(27); };
block_item                 : declaration                                                     { semantic(28); }
                           | statement                                                       { semantic(29); };
declaration                : dcl_spec init_dcl_list TSEMI                                    { semantic(28); }
                           | dcl_spec init_dcl_list error                                    { yyerrok; ReportParserError("declaration MISSING SEMI"); };
init_dcl_list              : init_declarator                                                 { semantic(29); }
                           | init_dcl_list TCOMMA init_declarator                            { semantic(30); };
init_declarator            : declarator                                                      { semantic(31); }
                           | declarator TASSIGN TNUMBER                                      { semantic(32); }
                           | declarator TASSIGN TFNUMBER            
                           | declarator TASSIGN error                                        { yyerrok; ReportParserError("init_declarator"); };
                           | function_prototype                                              ;
declarator                 : TIDENT                                                          { semantic(33); }
                           | TERROR
                           | TIDENT TLBRACKET opt_number TRBRACKET                           { semantic(34); }; // 배열 선언
                           | TERROR TLBRACKET opt_number TRBRACKET 
                           | TIDENT TLBRACKET opt_number error                               { yyerrok; ReportParserError("declarator MISSING RBRAKET"); }  
                           | TERROR TLBRACKET opt_number error                               ;
opt_number                 : TNUMBER                                                         { semantic(35); }
                           |                                                                 { semantic(36); };
statement                  : compound_st                                                     { semantic(41); }
                           | expression_st                                                   { semantic(42); }
                           | if_st                                                           { semantic(43); }
                           | while_st                                                        { semantic(44); }
                           | return_st                                                       { semantic(45); }
                           ;                                  
expression_st              : expression TSEMI                                                { semantic(46); }
                           | TSEMI                                                           { semantic(46); }
                           | expression error                                                { yyerrok; ReportParserError("expression_st MISSING SEMI"); };
if_st                      : TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE  { semantic(49); }
                           | TIF TLPAREN expression TRPAREN statement TELSE statement        { semantic(50); }
                           | TIF TLPAREN expression error statement                          { yyerrok; ReportParserError("if_st MISSING RPAREN"); }
                           | TIF error expression TRPAREN statement                          { yyerrok; ReportParserError("if_st MISSING LPAREN"); };
while_st                   : TWHILE TLPAREN expression TRPAREN statement                     { semantic(51); }
                           | TWHILE TLPAREN expression error statement                       { yyerrok; ReportParserError("while_st MISSING RPAREN"); }
                           | TWHILE error expression TRPAREN statement                       { yyerrok; ReportParserError("while_st MISSING LPAREN"); };
return_st                  : TRETURN expression_st                                           { semantic(52); };
expression                 : assignment_exp                                                  { semantic(53); };
assignment_exp             : logical_or_exp                                                  { semantic(54); }
                           | unary_exp TASSIGN assignment_exp                                { semantic(55); }
                           | unary_exp TADDASSIGN assignment_exp                             { semantic(56); }
                           | unary_exp TSUBASSIGN assignment_exp                             { semantic(57); }
                           | unary_exp TMULASSIGN assignment_exp                             { semantic(58); }
                           | unary_exp TDIVASSIGN assignment_exp                             { semantic(59); }
                           | unary_exp TMODASSIGN assignment_exp                             { semantic(60); }
                           | unary_exp TASSIGN error                                         { yyerrok; ReportParserError("NO_RIGHT_EXP"); }
                           | unary_exp TADDASSIGN error                                      { yyerrok; ReportParserError("NO_RIGHT_ADDASSIGN_EXP"); }
                           | unary_exp TSUBASSIGN error                                      { yyerrok; ReportParserError("NO_RIGHT_SUBASSIGN_EXP"); }
                           | unary_exp TMULASSIGN error                                      { yyerrok; ReportParserError("NO_RIGHT_MULTIASSIGN_EXP"); }
                           | unary_exp TDIVASSIGN error                                      { yyerrok; ReportParserError("NO_RIGHT_DIVASSIGN_EXP"); }
                           | unary_exp TMODASSIGN error                                      { yyerrok; ReportParserError("NO_RIGHT_MODASSIGN_EXP"); }
                                                                                             ;
logical_or_exp             : logical_and_exp                                                 { semantic(61); }
                           | logical_or_exp TOR logical_and_exp                              { semantic(62); };
logical_and_exp            : equality_exp                                                    { semantic(63); }
                           | logical_and_exp TAND equality_exp                               { semantic(64); };
equality_exp               : relational_exp                                                  { semantic(65); }
                           | equality_exp TEQUAL relational_exp                              { semantic(66); }
                           | equality_exp TNOTEQU relational_exp                             { semantic(67); };
relational_exp             : additive_exp                                                    { semantic(68); }
                           | relational_exp TGREAT additive_exp                              { semantic(69); }
                           | relational_exp TLESS additive_exp                               { semantic(70); }
                           | relational_exp TGREATE additive_exp                             { semantic(71); }
                           | relational_exp TLESSE additive_exp                              { semantic(72); };
additive_exp               : multiplicative_exp                                              { semantic(73); }
                           | additive_exp TADD multiplicative_exp                            { semantic(74); }
                           | additive_exp TSUB multiplicative_exp                            { semantic(75); };
multiplicative_exp         : unary_exp                                                       { semantic(76); }
                           | multiplicative_exp TMUL unary_exp                               { semantic(77); }
                           | multiplicative_exp TDIV unary_exp                               { semantic(78); }
                           | multiplicative_exp TMOD unary_exp                               { semantic(79); };
unary_exp                  : postfix_exp                                                     { semantic(80); }
                           | TSUB unary_exp                                                  { semantic(81); }
                           | TNOT unary_exp                                                  { semantic(82); }
                           | TINC unary_exp                                                  { semantic(83); }
                           | TDEC unary_exp                                                  { semantic(84); };
postfix_exp                : primary_exp                                                     { semantic(85); }
                           | postfix_exp TLBRACKET expression TRBRACKET                      { semantic(86); }
                           | postfix_exp TLPAREN opt_actual_param TRPAREN                    { semantic(87); }
                           | postfix_exp TINC                                                { semantic(88); }
                           | postfix_exp TDEC                                                { semantic(89); }
                           | postfix_exp TLBRACKET expression error                          { yyerrok; ReportParserError("postfix_exp"); }
                           | postfix_exp TLPAREN opt_actual_param error                      { yyerrok; ReportParserError("postfix_exp"); };
opt_actual_param           : actual_param                                                    { semantic(90); }
                           |                                                                 { semantic(91); };
actual_param               : actual_param_list                                               { semantic(92); };
actual_param_list          : assignment_exp                                                  { semantic(93); }
                           | actual_param_list TCOMMA assignment_exp                         { semantic(94); };
primary_exp                : TIDENT                                                          { semantic(95); }
                           | TERROR
                           | TNUMBER                                                         { semantic(96); }                                  
                           | TLPAREN expression error                                        { yyerrok; ReportParserError("primary_exp"); }
                           | TLPAREN expression TRPAREN                                      { semantic(97); };
%%  

void semantic(int n)
{
   // printf("reduced rule number = %d\n", n);
}


/* void ReportParserError(char* message, in)
{
   printf("--------------------- %s %d\n", message);
} */