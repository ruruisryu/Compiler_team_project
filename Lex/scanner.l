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
","         return(TCOMA);
"="         return(TASSIGN);
   
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TINTEGER);
[0-9]*"."[0-9]+([eE][+-]?[0-9]+)? { return TREALNUM; }

[A-Za-z_][A-Za-z0-9_]{14}[A-Za-z0-9_]+ {
    printf("Error - too long identifier\n");
    return TERROR;
}
[0-9]+[A-Za-z_][A-Za-z0-9_]* { printf("Error - start with digit\n"); return TERROR; }

[A-Za-z_][A-Za-z0-9_]* {
	if (check_overflow()) {
		printf("Error - Overflow\n");
		return TERROR;
	}
	int val = validate_identifier(yytext);

    if (val == 1) {
		return TIDENT;
    } 
}

[^\w \,\.\t\n\r\(\)\{\};]+    { printf("Error - invalid character\n"); return TERROR; }


"/*"([^*]|\*+[^*/])*\**"*/"					;
"//".*										;
[ \t\n]										;
.                                           return(yytext[0]);

%%
int yywrap() 
{
	printf(" End of Lex\n");
	return 1;
}