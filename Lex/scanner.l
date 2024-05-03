%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tn.h"
	#include "symtable.h"
%}

%%
"const"		return(TCONST);
"else"		return(TELSE);
"if"		return(TIF);
"int"		return(TINT);
"return"	return(TRETURN);
"void"		return(TVOID);
"float"     return(TFLOAT);
"while"		return(TWHILE);
"=="		return(TEQUAL);
"!="		return(TNOTEQU);
"<="		return(TLESSE);
">="		return(TGREATE);
"&&"		return(TAND);
"||"		return(TOR);
"++"		return(TINC);
"--"		return(TDEC);
"+="		return(TADDASSIGN);
"-="		return(TSUBASSIGN);
"*="		return(TMULASSIGN);
"/="		return(TDIVASSIGN);
"%="		return(TMODASSIGN);
";"         return(TSEMICOLON);
"+"         return(TPLUS);
"-"         return(TMINUS);
"."         return(TDOT);
","         return(TCOMMA);
"="         return(TASSIGN);
   
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?    return(TINTEGER);
[0-9]*"."[0-9]+([eE][+-]?[0-9]+)? 			return (TREALNUM); // report error except for floating point

[0-9]+[A-Za-z_][A-Za-z0-9_]* 				{ printf("Error - start with digit\n"); return (TERROR); }

[A-Za-z_][A-Za-z0-9_]* {
	int symbol_num = lookup_sym_table(yytext);
	if (symbol_num != -1) { // already in symbol table
		return(TIDENT);
	}
	if (yyleng >= 15) {
		printf("Error - too long identifier\n");
		return (TERROR);
	}
	if (check_strpool_overflow(yytext)) { // string pool overflow 
		printf("Error - Strpool_Overflow\n"); 
		return (TERROR);
	}
	if (check_symtable_overflow()) { // symboltable overflow
		printf("Error - Symtable_Overflow\n");
		return (TERROR);
	} 
	// didn't include hashtable overflow because it's handled by backward method

	int val = validate_identifier(yytext);

    if (val == 1) {
		process_symbol(yytext, TIDENT);
		return(TIDENT);
    } 
}

[^\w \,\.\t\n\r\(\)\{\};]+    				{ printf("Error - illegal identifier\n"); return(TERROR); }

"\n"										return(TNEWLINE);
"/*"([^*]|\*+[^*/])*\**"*/"					;
"//".*										;
[ \t]										;
.                                           return(yytext[0]);

%%
extern lookup_sym_table(char* str);
int yywrap() 
{
	printf(" End of Lex\n");
	return 1;
}