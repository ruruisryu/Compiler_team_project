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

extern int lineNumber; 
extern const char* dataTypesChar[];
extern void reportParserError(char* message);
HTpointer getIdentHash(const char *identifier);
dataType getIdentType(const char *identifier);
int checkIdentExists(const char *identifier);
void updateIdentType(int numType, dataType variableType, const char *identifier); 
void updateReturnType(int returnType, const char *identifier); 
void updateFunctionParameter(int type, dataType variableType, const char *function_name);
void updateInvokedFuncArgs(dataType argument_type);
void isIllegalInvoke(const char *function_name);

int numType = 0;
char currentFunctionName[1000]; // 함수 이름 저장용 전역 변수

// 함수 정상 사용 체크를 위한 파라미터 배열과 파라미터 개수 변수
dataType* invoked_func_args;
dataType currentArgumentType; // 현재 인수의 타입을 저장하기 위한 전역 변수
int invoked_func_args_cnt = 0;
%}

/*
1 int scalar variable
2 float scalar variable
3 int array variable
4 float array variable

5 int scalar parameter
6 float scalar parameter
7 int array parameter
8 float array parameter
*/

%token TIDENT TNUMBER TCONST TELSE TIF	TEIF TINT TRETURN TVOID TWHILE
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN 	
%token TOR TAND TEQUAL TNOTEQU TGREATE TLESSE TINC TDEC TEOF TERROR TCOMMENT 	
%token TFNUMBER TFLOAT TADD TSUB TMUL TDIV TMOD TASSIGN 	
%token TNOT TLESS TGREAT TLPAREN TRPAREN TCOMMA TLBRACE TRBRACE TLBRACKET TRBRACKET TSEMI LOWER_THAN_ELSE 

%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE

%%
mini_c                     : translation_unit                                                ;
translation_unit           : external_dcl                                                    
                           | translation_unit external_dcl                                   ;
external_dcl               : function_def                                                    
                           | declaration                                                     ;
function_def               : function_header compound_st                                     
                           | error compound_st                                               { yyerrok; reportParserError("function_def"); };
function_header            : dcl_spec function_name formal_param                             ;
// function_definition: int main(int x, int y) {} / function_prototype: int main(int x, int);
// formal_param: (int x, float y)                 / type_only_param: (int, float)
function_prototype         : function_name type_only_param                                   
                           | function_name formal_param                                      ;
type_only_param            : TLPAREN type_only_param_list TRPAREN                            
                           | TLPAREN type_only_param_list error                              { yyerrok; reportParserError("type_only_param"); };
type_only_param_list       : type_only_param_dcl                                             
                           | type_only_param_list TCOMMA type_only_param_dcl                 
                           | type_only_param_list TCOMMA param_dcl                           
                           | formal_param_list TCOMMA type_only_param_dcl                    ;
type_only_param_dcl        : dcl_specifier                                                   { updateFunctionParameter(numType, scalar, currentFunctionName); };
dcl_spec                   : dcl_specifiers                                                  ;
dcl_specifiers             : dcl_specifier                                                   
                           | dcl_specifiers dcl_specifier                                    ;
dcl_specifier              : type_qualifier                                                  
                           | type_specifier                                                  ;
type_qualifier             : TCONST                                                          ;
type_specifier             : TINT                                                            { numType = 1; }
                           | TFLOAT                                                          { numType = 2; }
                           | TVOID                                                           { numType = 0; }
                           ;
function_name              : TIDENT                                                          { updateIdentType(numType, function, 0, identStr); updateReturnType(numType, identStr); 
                                                                                                strncpy(currentFunctionName, identStr, 1000); }                                                                                             
                           | TERROR
                           |                                                                 { yyerrok; reportParserError("NO_FUNC_NAME")}
                           ;
formal_param               : TLPAREN opt_formal_param TRPAREN                                
                           | TLPAREN opt_formal_param error                                  { yyerrok; reportParserError("formal_param"); };
opt_formal_param           : formal_param_list                                               
                           |                                                                 ;
formal_param_list          : param_dcl                                                       
                           | formal_param_list TCOMMA param_dcl                              
                           | formal_param_list param_dcl error                               { yyerrok; reportParserError("NO_COMMA"); }
                           ;
param_dcl                  : dcl_specifier ident                                             { updateIdentType(numType, scalar, 1, identStr); updateFunctionParameter(numType, scalar, currentFunctionName); }  
                           | dcl_specifier array                                             { updateIdentType(numType, array, 1, identStr); updateFunctionParameter(numType, array, currentFunctionName); }  
                           | dcl_specifier function_prototype                                ;
compound_st                : TLBRACE opt_block_items TRBRACE                                 
                           | TLBRACE opt_block_items error                                   { yyerrok; reportParserError("compound_st MISSING RBRACE"); }
                           ;
opt_block_items            : block_item_list
                           |
                           ;
block_item_list            : block_item                                                      
                           | block_item_list block_item                                      ;
block_item                 : declaration                                                     
                           | statement                                                       
                           ;
declaration                : dcl_spec init_dcl_list TSEMI                                    
                           | dcl_spec init_dcl_list error                                    { yyerrok; reportParserError("declaration MISSING SEMI"); };
init_dcl_list              : init_declarator                                                 
                           | init_dcl_list TCOMMA init_declarator                            ;
init_declarator            : ident                                                           { updateIdentType(numType, scalar, 0, identStr); } 
                           | array                                                           { updateIdentType(numType, array, identStr); }
                           | ident TASSIGN TNUMBER                                           { updateIdentType(numType, scalar, 0, identStr);
                                                                                                if (getIdentType(identStr) != 1) reportParserError("type mismatch in initialization"); }
                           | ident TASSIGN TFNUMBER                                          { updateIdentType(numType, scalar, 0, identStr); 
                                                                                                if (getIdentType(identStr) != 2) reportParserError("type mismatch in initialization"); }                                                                                              
                           | array TASSIGN TNUMBER                                           { updateIdentType(numType, array, 0, identStr);}   
                           | array TASSIGN TFNUMBER                                          { updateIdentType(numType, array, 0, identStr); 
                                                                                                if (getIdentType(identStr) != 2) reportParserError("type mismatch in initialization"); } 
                           | ident TASSIGN error                                             { yyerrok; reportParserError("init_declarator"); }
                           | array TASSIGN error                                             { yyerrok; reportParserError("init_declarator"); }
                           | function_prototype                                              
                           ;
ident                      : TIDENT                                                           
                           | TERROR
                           ;
array                      : ident TLBRACKET opt_number TRBRACKET   
                           | ident TLBRACKET opt_number error                               { yyerrok; reportParserError("declarator MISSING BRAKET"); }  
                           ;
opt_number                 : TNUMBER                                                         
                           |                                                                 ;
statement                  : compound_st                                                     
                           | expression_st                                                   
                           | if_st                                                           
                           | while_st                                                        
                           | return_st                                                       
                           ;                                  
expression_st              : expression TSEMI                                                
                           | TSEMI                                                           
                           | expression error                                                { yyerrok; reportParserError("expression_st MISSING SEMI"); }
                           | expression error assignment_op                                  { yyerrok; reportParserError("cannot assign to invalid lvalue");}
                           ;
if_st                      : TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE  
                           | TIF TLPAREN expression TRPAREN statement TELSE statement        
                           | TIF TLPAREN expression error statement                          { yyerrok; reportParserError("if_st MISSING PAREN"); }
                           | TIF error expression TRPAREN statement                          { yyerrok; reportParserError("if_st MISSING PAREN"); };
while_st                   : TWHILE TLPAREN expression TRPAREN statement                     
                           | TWHILE TLPAREN expression error statement                       { yyerrok; reportParserError("while_st MISSING PAREN"); }
                           | TWHILE error expression TRPAREN statement                       { yyerrok; reportParserError("while_st MISSING PAREN"); };
return_st                  : TRETURN expression_st                                           ;
expression                 : assignment_exp                                                  
                           ;
assignment_exp             : logical_or_exp 
                           | postfix_exp assignment_op assignment_exp                        
                           | postfix_exp assignment_op error                                 { yyerrok; reportParserError("NO_RIGHT_ASSIGNMENT_EXP"); }
                           ;
assignment_op              : TASSIGN                                                  
                           | TADDASSIGN
                           | TSUBASSIGN
                           | TMULASSIGN
                           | TDIVASSIGN
                           | TMODASSIGN
                           ;
logical_or_exp             : logical_and_exp                                                 
                           | logical_or_exp TOR logical_and_exp                              ;
                           | logical_or_exp TOR error                                        { yyerrok; reportParserError("NO_RIGHT_LOGICAL_OR_EXP");};
logical_and_exp            : equality_exp                                                    
                           | logical_and_exp TAND equality_exp                               ;
                           | logical_and_exp TAND error                                      { yyerrok; reportParserError("NO_RIGHT_LOGICAL_AND_EXP");};
equality_exp               : relational_exp                                                  
                           | equality_exp TEQUAL relational_exp                              
                           | equality_exp TNOTEQU relational_exp                             
                           | equality_exp TEQUAL error                                       { yyerrok; reportParserError("NO_RIGHT_TEQUAL_EXP");}
                           | equality_exp TNOTEQU error                                      { yyerrok; reportParserError("NO_RIGHT_TNOTEQU_EXP");}
                           ;
relational_exp             : additive_exp                                                    
                           | relational_exp TGREAT additive_exp                              
                           | relational_exp TLESS additive_exp                               
                           | relational_exp TGREATE additive_exp                             
                           | relational_exp TLESSE additive_exp                              
                           | relational_exp TGREAT error                                     { yyerrok; reportParserError("NO_RIGHT_TGREAT_EXP");}
                           | relational_exp TLESS error                                      { yyerrok; reportParserError("NO_RIGHT_TELSE_EXP");}
                           | relational_exp TGREATE error                                    { yyerrok; reportParserError("NO_RIGHT_TGREATE_EXP");}
                           | relational_exp TLESSE error                                     { yyerrok; reportParserError("NO_RIGHT_TLESSE_EXP");}
                           ;
additive_exp               : multiplicative_exp                                              
                           | additive_exp TADD multiplicative_exp                            
                           | additive_exp TSUB multiplicative_exp                            
                           | additive_exp TADD error                                         { yyerrok; reportParserError("NO_RIGHT_TADD_EXP");}
                           | additive_exp TSUB error                                         { yyerrok; reportParserError("NO_RIGHT_TSUB_EXP");}
                           ;
multiplicative_exp         : unary_number                                                    
                           | multiplicative_exp TMUL unary_number                            
                           | multiplicative_exp TDIV unary_number                            
                           | multiplicative_exp TMOD unary_number                            
                           | multiplicative_exp TMUL error                                   { yyerrok; reportParserError("NO_RIGHT_TMUL_EXP"); }
                           | multiplicative_exp TDIV error                                   { yyerrok; reportParserError("NO_RIGHT_TDIV_EXP"); }
                           | multiplicative_exp TMOD error                                   { yyerrok; reportParserError("NO_RIGHT_TMOD_EXP"); }
                           ;
unary_number               : unary_exp
                           | TNUMBER                                                         { if (getIdentType(identStr) != int_scalar_variable) reportParserError("type mismatch in assignment"); }
                           | TFNUMBER                                                        { if (getIdentType(identStr) != float_scalar_variable) reportParserError("type mismatch in assignment"); }                                  
                           ;
unary_exp                  : postfix_exp                                                      // 할당문 좌변
                           | TSUB unary_exp                                                  
                           | TNOT unary_exp                                                  
                           | TINC unary_exp                                                  
                           | TDEC unary_exp                                                  
                           ;
postfix_exp                : primary_exp                                                     
                           | postfix_exp TLBRACKET expression TRBRACKET                       // 배열 인덱스 접근
                           | postfix_exp TLPAREN opt_actual_param TRPAREN                    { isIllegalInvoke(currentFunctionName); } // 함수 호출
                           | postfix_exp TINC                                                 // a++
                           | postfix_exp TDEC                                                 // a--
                           | postfix_exp TLBRACKET expression error                          { yyerrok; reportParserError("postfix_exp"); }
                           | postfix_exp TLPAREN opt_actual_param error                      { yyerrok; reportParserError("postfix_exp"); }
                           ;
opt_actual_param           : actual_param                                                    
                           |                                                                 ;
actual_param               : actual_param_list                                               ;
param_type                 : ident                                                           { if (!checkIdentExists(identStr)) reportParserError("identifier does not exists");
                                                                                                updateInvokedFuncArgs(getParamType(identStr));}
                           | TNUMBER                                                         { updateInvokedFuncArgs(int_scalar_parameter);}
                           | TFNUMBER                                                        { updateInvokedFuncArgs(float_scalar_parameter);}
                           ;
actual_param_list          : param_type                                                       
                           | actual_param_list TCOMMA param_type                              
                           ;
primary_exp                : TIDENT                                                          { strcpy_s(currentFunctionName, sizeof(currentFunctionName), identStr);
                                                                                                dataType* invoked_func_args = (dataType*)malloc(0);
                                                                                                invoked_func_args_cnt = 0;
                                                                                                if (!checkIdentExists(identStr)) reportParserError("identifier does not exists"); }
                           | TERROR                           
                           | TLPAREN expression error                                        { yyerrok; reportParserError("primary_exp"); }
                           | TLPAREN expression TRPAREN                                      ;
%%  
// identifier의 해시테이블 포인터 값을 반환하는 함수
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

// identifier의 타입을 반환하는 함수
dataType getIdentType(const char *identifier)
{
   HTpointer hash_ident = getIdentHash(identifier);
   struct Ident sym_ident = sym_table[hash_ident->index];  
   return sym_ident.ident_type;
}

// parameter의 타입을 반환하는 함수
dataType getParamType(const char *identifier)
{
   HTpointer hash_ident = getIdentHash(identifier);
   struct Ident sym_ident = sym_table[hash_ident->index];
   if(sym_ident.ident_type == int_scalar_variable){
      return int_scalar_parameter;
   }
   else if(sym_ident.ident_type == float_scalar_variable){
      return float_scalar_parameter;
   }
   return sym_ident.ident_type;
}

// identifier가 심볼 테이블에 저장되어 있는지 확인하는 함수
int checkIdentExists(const char *identifier)
{
   HTpointer hash_ident = getIdentHash(identifier);
   if (hash_ident == NULL) {
      return 0;
   }

   struct Ident sym_ident = sym_table[hash_ident->index];   
   if (sym_ident.ident_type == NULL || sym_ident.ident_type == none) {
      return 0;
   }
   return 1;
}

// identifier의 구체적인 타입 값을 구하는 함수
dataType classifyDataType(int numType, dataType variableType, int is_param) {
    dataType type = none;

    if (numType == 1) { // int
        if (variableType == scalar) {
            type = is_param ? int_scalar_parameter : int_scalar_variable;
        } else {
            type = is_param ? int_array_parameter : int_array_variable;
        }
    } else if (numType == 2) { // float
        if (variableType == scalar) {
            type = is_param ? float_scalar_parameter : float_scalar_variable;
        } else {
            type = is_param ? float_array_parameter : float_array_variable;
        }
    }

    if (variableType == function) {
        type = function;
    }
    return type;
}

// identifier의 타입을 저장하는 함수
void updateIdentType(int numType, dataType variableType, int is_param, const char *identifier) 
{
    // 자료형 구분
    dataType identType = classifyDataType(numType, variableType, is_param);

    // sym_table에서 identifier 정보 가져오기
    HTpointer hash_ident = getIdentHash(identifier); 
    struct Ident sym_ident = sym_table[hash_ident->index];     

    // identifier의 type 정보가 NULL이거나 none이라면 identifier의 type 정보를 업데이트
    // 그 외라면 이미 선언된 identifier를 재선언하고 있는 것이므로 에러 발생
    if (sym_ident.ident_type == NULL || sym_ident.ident_type == none) {
        sym_ident.ident_type = identType;
        sym_table[hash_ident->index] = sym_ident;
    } 
    else {
        if (sym_ident.linenumber != lineNumber) {
            reportParserError("identifier is already declared");
        }
    }
}

// 함수의 리턴 타입을 업데이트하는 함수
void updateReturnType(int returnType, const char *identifier)
{
   HTpointer hash_ident = getIdentHash(identifier);    

   // identifier의 type 정보가 function일 경우에만 return값 정보 업데이트
   struct Ident sym_ident = sym_table[hash_ident->index];   
   if (sym_ident.ident_type == function) {	// type이 function name인 경우
      sym_ident.return_type = returnType;	// 매개변수로 받은 returntype 설정
      sym_table[hash_ident->index] = sym_ident;
   } 
   else {
      sym_ident.return_type = none;
      sym_table[hash_ident->index] = sym_ident;
   }
}

// 함수의 파라미터 정보를 업데이트하는 함수
void updateFunctionParameter(int type, dataType variableType, const char *function_name)
{
   HTpointer hash_ident = getIdentHash(function_name);    

   // 자료형 구분
   dataType paramType = classifyDataType(type, variableType, 1);
   struct Ident sym_ident = sym_table[hash_ident->index];   
   
   // function_name type이 function일 경우에만 파라미터 타입 정보 업데이트
   if (sym_ident.ident_type == function) {	
      sym_ident.param_count++;
      sym_ident.param = (dataType*)realloc(sym_ident.param, (sym_ident.param_count)*sizeof(dataType));
      sym_ident.param[sym_ident.param_count-1] = paramType;
      
      sym_table[hash_ident->index] = sym_ident;
   }
}

// 함수 호출 시 전달된 parameter list의 타입을 저장하는 함수
void updateInvokedFuncArgs(dataType argument_type){
   if(invoked_func_args == NULL){
      invoked_func_args = (dataType*)malloc(sizeof(dataType));
      if (invoked_func_args == NULL) {
          fprintf(stderr, "Memory allocation failed\n");
          exit(EXIT_FAILURE);
      }
      invoked_func_args_cnt = 1;
   } else {
      invoked_func_args_cnt++;
      dataType* temp = (dataType*)realloc(invoked_func_args, invoked_func_args_cnt * sizeof(dataType));
      if (temp == NULL) {
          fprintf(stderr, "Memory reallocation failed\n");
          free(invoked_func_args);  // 기존 메모리를 해제하여 메모리 누수를 방지
          exit(EXIT_FAILURE);
      }
      invoked_func_args = temp;
   }
   invoked_func_args[invoked_func_args_cnt-1] = argument_type;
}

// 함수 정의와 일치하는 호출인지 확인하는 함수
void isIllegalInvoke(const char *function_name){
   HTpointer hash_ident = getIdentHash(function_name);    
   struct Ident sym_ident = sym_table[hash_ident->index];

   // function_name의 type 정보가 function이 아니거나 파라미터 개수가 맞지 않으면 에러 발생
   if (sym_ident.ident_type != function || sym_ident.param_count != invoked_func_args_cnt) {
      reportParserError("invalid function call");
      return;
   }

   // 파라미터 타입 배열을 돌면서 일치하지 않는 파라미터 타입이 있다면 에러 발생
   for(int i=0; i<invoked_func_args_cnt; i++){
      if (i >= sym_ident.param_count) {
         printf("Index out of bounds: sym_ident.param[%d] (max %d)\n", i, sym_ident.param_count);
         return;
      }

      if(sym_ident.param[i] != invoked_func_args[i]){
         reportParserError("Invalid function call.");
         return;
      }
   }
}