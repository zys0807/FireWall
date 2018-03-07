%option outfile="Lexer.c" header-file="Lexer.h"
%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <string.h>
#include "Parser.h"
#include "..\Inc\Rules.h"


//#define _FLEX_DEBUG_ 
#define _FLEX_DEBUG_PRINT_

#ifdef _FLEX_DEBUG_PRINT_ 
#define FlexPrint printf
#else 
#define  FlexPrint
#endif

//#define YYSTYPE (char *)

int lex_yyerror(char* msg) ;

//extern Rule TempRule;


%}

IPPART_V4 25[0-5]|2[0-4][0-9]|1?[0-9]?[0-9]
IPPORT (6553[0-5]|655[0-2][0-9])|(65[0-4][0-9][0-9])|(6[0-4][0-9][0-9][0-9])|([0-5]?[0-9]?[0-9]?[0-9]?[0-9]?)

%%
[ \t]+       { /* Do Nothing */ }
"\n"            {FlexPrint("Flex \\n.\n") ;return EOL ;}

"RuleIP"      {FlexPrint("Flex TOKEN_RULEIP.\n");return TOKEN_RULEIP ;}
"RuleProcess" {FlexPrint("Flex TOKEN_RULEPROCESS.\n");return TOKEN_RULEPROCESS ;}
"RuleDomain"  {FlexPrint("Flex TOKEN_RULEDOMAIN.\n");return TOKEN_RULEDOMAIN ;}
"Allow"       {yylval.str = _strdup(yytext) ;FlexPrint("Flex TOKEN_RULEALLOW.\n");return TOKEN_RULEALLOW ;}
"Deny"        {yylval.str = _strdup(yytext) ;FlexPrint("Flex TOKEN_RULEDENY.\n");return TOKEN_RULEDENY ;}
"In"          {yylval.str = _strdup(yytext) ;FlexPrint("Flex TOKEN_RULEIN.\n");return TOKEN_RULEIN ;}
"Out"         {yylval.str = _strdup(yytext) ;FlexPrint("Flex TOKEN_RULEOUT.\n");return TOKEN_RULEOUT ;}
"InOut"       {yylval.str = _strdup(yytext) ;FlexPrint("Flex TOKEN_RULEINOUT.\n");return TOKEN_RULEINOUT ;}
"="           {FlexPrint("Flex TOKEN_EQ.\n");return TOKEN_EQ ;}

{IPPORT}      {
					FlexPrint("Flex TOKEN_PORT.\n"); 
					yylval.str = _strdup(yytext) ;
					//GetPortRange(&rule, yylval.str, PORTTYPE_PORT) ;
					//FlexPrint("Flex IPPORT = %d.\n", yylval.str) ;
					return TOKEN_PORT ;
			}

{IPPORT}"-"{IPPORT} {
						FlexPrint("Flex TOKEN_PORTRANGE.\n"); 
						yylval.str = _strdup(yytext) ;
						FlexPrint("PortRange = %s\n", yylval.str) ;
						//GetPortRange(&TempRule, yylval.str, PORTTYPE_PORTRANGE) ;
						/* GetPortRange() ; */
						return TOKEN_PORTRANGE ;
					}

{IPPART_V4}\.{IPPART_V4}\.{IPPART_V4}\.{IPPART_V4} {
														FlexPrint("Flex TOKEN_IP.\n") ;
														yylval.str = _strdup(yytext); 
														 //FlexPrint("IP = %s.\n", yylval.str) ;
														//GetIpV4(&TempRule, yylval.str) ;
														/* FlexPrint("IP Test: %d.%d.%d.%d .\n", Ipv4.IP[0], Ipv4.IP[1], Ipv4.IP[2], Ipv4.IP[3]) ; */
														return TOKEN_IP_V4 ;
													}
[a-zA-Z]":\\".*"exe"     {FlexPrint("Flex TOKEN_PROCESS.\n");yylval.str = _strdup(yytext);   return TOKEN_PROCESS ;}

#.*\n           {FlexPrint("Flex TOKEN_COMMENT.\n"); }
.             { lex_yyerror(yytext); }

%%


int lex_yyerror(char* msg)
{
	//yytext ;
	printf("Error: %s encountered at line number:%d\n", msg, yylineno);
	return 0 ;
}


#ifdef _FLEX_DEBUG_
int main(int argc, const char *argv[])
{

	yyin = fopen("Rules.r", "r") ;
	if(!yyin)
	{
		printf("No such file.\n") ;
	}
    while( yylex());

	system("PAUSE");

    return 0;
}
#endif
