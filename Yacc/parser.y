%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "sym_table_lab.h"
#include "hash_func.h"
#include "tn.h"

extern void semantic(int);
extern void ReportParserError(char* message);
HTpointer getIdentHash(const char *identifier);
bool checkIdentExists(const char *identifier);
void updateReturnType(int returntype, const char *identifier); 
void updateIdentType(const char *type, const char *identifier);

int returnType = 0;
unsigned int currlinenum;
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
type_specifier             : TINT                                                            { semantic(14); returnType = 1;}
                           | TFLOAT                                                          { returnType = 2;}
                           | TVOID                                                           { semantic(15); returnType = 0;};
function_name              : TIDENT                                                          { semantic(16); updateIdentType("function", identStr); updateReturnType(returnType, identStr);};
                           | TERROR
                           |                                                                 {yyerrok; ReportParserError("NO_FUNC_NAME")};
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
declarator                 : TIDENT                                                          { semantic(33); updateIdentType("scalar variable", identStr);}  // int scalar variable
                           | TERROR
                           | TIDENT TLBRACKET opt_number TRBRACKET                           { semantic(34);}; // 배열 선언
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
                           | logical_or_exp TOR error                                        { yyerrok; ReportParserError("NO_RIGHT_LOGICAL_OR_EXP");};
logical_and_exp            : equality_exp                                                    { semantic(63); }
                           | logical_and_exp TAND equality_exp                               { semantic(64); };
                           | logical_and_exp TAND error                                      { yyerrok; ReportParserError("NO_RIGHT_LOGICAL_AND_EXP");};
equality_exp               : relational_exp                                                  { semantic(65); }
                           | equality_exp TEQUAL relational_exp                              { semantic(66); }
                           | equality_exp TNOTEQU relational_exp                             { semantic(67); }
                           | equality_exp TEQUAL error                                       { yyerrok; ReportParserError("NO_RIGHT_TEQUAL_EXP");}
                           | equality_exp TNOTEQU error                                      { yyerrok; ReportParserError("NO_RIGHT_TNOTEQU_EXP");}
                           ;
relational_exp             : additive_exp                                                    { semantic(68); }
                           | relational_exp TGREAT additive_exp                              { semantic(69); }
                           | relational_exp TLESS additive_exp                               { semantic(70); }
                           | relational_exp TGREATE additive_exp                             { semantic(71); }
                           | relational_exp TLESSE additive_exp                              { semantic(72); }
                           | relational_exp TGREAT error                                     { yyerrok; ReportParserError("NO_RIGHT_TGREAT_EXP");}
                           | relational_exp TLESS error                                      { yyerrok; ReportParserError("NO_RIGHT_TELSE_EXP");}
                           | relational_exp TGREATE error                                    { yyerrok; ReportParserError("NO_RIGHT_TGREATE_EXP");}
                           | relational_exp TLESSE error                                     { yyerrok; ReportParserError("NO_RIGHT_TLESSE_EXP");}
                           ;
additive_exp               : multiplicative_exp                                              { semantic(73); }
                           | additive_exp TADD multiplicative_exp                            { semantic(74); }
                           | additive_exp TSUB multiplicative_exp                            { semantic(75); }
                           | additive_exp TADD error                                         { yyerrok; ReportParserError("NO_RIGHT_TADD_EXP");}
                           | additive_exp TSUB error                                         { yyerrok; ReportParserError("NO_RIGHT_TSUB_EXP");}
                           ;
multiplicative_exp         : unary_exp                                                       { semantic(76); }
                           | multiplicative_exp TMUL unary_exp                               { semantic(77); }
                           | multiplicative_exp TDIV unary_exp                               { semantic(78); }
                           | multiplicative_exp TMOD unary_exp                               { semantic(79); }
                           | multiplicative_exp TMUL error                                   { yyerrok; ReportParserError("NO_RIGHT_TMUL_EXP"); }
                           | multiplicative_exp TDIV error                                   { yyerrok; ReportParserError("NO_RIGHT_TDIV_EXP");}
                           | multiplicative_exp TMOD error                                   { yyerrok; ReportParserError("NO_RIGHT_TMOD_EXP"); }
                           ;
unary_exp                  : postfix_exp                                                     { semantic(80); }
                           | TSUB unary_exp                                                  { semantic(81); }
                           | TNOT unary_exp                                                  { semantic(82); }
                           | TINC unary_exp                                                  { semantic(83); }
                           | TDEC unary_exp                                                  { semantic(84); };
postfix_exp                : primary_exp                                                     { semantic(85); }
                           | postfix_exp TLBRACKET expression TRBRACKET                      { semantic(86); } // 배열 인덱스 접근
                           | postfix_exp TLPAREN opt_actual_param TRPAREN                    { semantic(87); } // 함수 호출
                           | postfix_exp TINC                                                { semantic(88); } // a++
                           | postfix_exp TDEC                                                { semantic(89); } // a--
                           | postfix_exp TLBRACKET expression error                          { yyerrok; ReportParserError("postfix_exp"); }
                           | postfix_exp TLPAREN opt_actual_param error                      { yyerrok; ReportParserError("postfix_exp"); };
opt_actual_param           : actual_param                                                    { semantic(90); }
                           |                                                                 { semantic(91); };
actual_param               : actual_param_list                                               { semantic(92); };
actual_param_list          : assignment_exp                                                  { semantic(93); }
                           | actual_param_list TCOMMA assignment_exp                         { semantic(94); };
primary_exp                : TIDENT                                                          { } 
                           | TERROR                                                          
                           | TNUMBER                                                         { semantic(96); }   
                           | TFNUMBER                               
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

HTpointer getIdentHash(const char *identifier)
{
   // 해당 identifier의 해시코드 구하기
   int hashValue = divisionMethod(identifier, HASH_TABLE_SIZE);
   // 인식된 identifier의 해시값으로 해시테이블과 심볼테이블에 접근해 identifier가 저장되어있는지 확인
   HTpointer hash_ident = lookup_hash_table(identifier, hashValue);
   bool isExist = false; 	// Hash Table을 읽기 전, false로 초기화

   // hash_ident 값이 NULL이라면, 해당 identifier가 해시테이블에 저장된 적이 없다는 뜻

   // lookup_sym_table 함수를 통해 심볼테이블의 hash_ident.index 번째 인덱스에 identifier가 저장되어있는지 확인 후 bool 값 return
   // isExist가 false라면 연결된 다음 identifier를 hash_ident에 저장 후 다시 반복
   while (hash_ident != NULL && !isExist) {	// 현재 가리키는 위치에 문자가 있고 아직 identifier가 발견되지 않은 경우
      isExist = lookup_sym_table(identifier, hash_ident->index);  // 새로운 함수를 사용하여 비교
      if (!isExist) {
         hash_ident = hash_ident->next;  // linked list의 다음 identifier로 이동
      }
   }
   return hash_ident;
}

bool checkIdentExists(const char *identifier)
{
   HTpointer hash_ident = getIdentHash(identifier);
   if (hash_ident != NULL)
   {
      struct Ident sym_ident = sym_table[hash_ident->index];   
      if (sym_ident.ident_type == NULL || strcmp(sym_ident.ident_type, "none") == 0) {
         return true;
      }
   }
   return false;
}

void updateIdentType(const char *type, const char *identifier)
{
    printf("-------------------------updateIdentType-------------------------\n");
    HTpointer hash_ident = getIdentHash(identifier); 
    printf("identifier: %s\n", identifier);

    if (hash_ident == NULL){
        // 처리해주기
    }

    // sym_table에서 identifier 정보 가져오기
    struct Ident sym_ident = sym_table[hash_ident->index];     

    // identifier의 type 정보가 NULL이거나 "none"이라면 identifier의 type 정보를 업데이트
    if (sym_ident.ident_type == NULL || strcmp(sym_ident.ident_type, "none") == 0) {
        strncpy_s(sym_ident.ident_type, sizeof(sym_ident.ident_type), type, _TRUNCATE);	
        sym_ident.ident_type[sizeof(sym_ident.ident_type) - 1] = '\0'; 
        sym_table[hash_ident->index] = sym_ident;
        printf("sym_ident.ident_type: %s", sym_ident.ident_type);
    } 
    else {
        if (sym_ident.linenumber != currlinenum) {
            printf("Already declared\n");
        }
    }
    printf("updateIdentType complete\n");
}

void updateReturnType(int returntype, const char *identifier)
{
   printf("-------------------------updateReturnType-------------------------\n");
   HTpointer hash_ident = getIdentHash(identifier);    
    
   if (hash_ident != NULL) {
        // 처리해주기
   }

   // identifier의 type 정보가 function일 경우에만 return값 정보 업데이트
   struct Ident sym_ident = sym_table[hash_ident->index];   
   if (strcmp(sym_ident.ident_type, "function") == 0) {	// type이 function name인 경우
      snprintf(sym_ident.return_type, sizeof(sym_ident.return_type), "%d", returntype);	// 매개변수로 받은 returntype 설정
      printf("sym_ident.return_type: %s", sym_ident.return_type);
      sym_table[hash_ident->index] = sym_ident;
   } 
   else {
      snprintf(sym_ident.return_type, sizeof(sym_ident.return_type), "-1");	// function name이 아닌 경우는 -1로 설정
      sym_table[hash_ident->index] = sym_ident;
   }
   printf("updateReturnType complete\n");
}