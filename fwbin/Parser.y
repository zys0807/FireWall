

%{
#include<stdio.h>
#include"Lexer.h"
#include "../Inc/Rules.h"

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#define _BISON_DEBUG_PRINT_
#define _BISON_DEBUG_

#ifdef _BISON_DEBUG_PRINT_ 
#define BisonPrint printf
#else 
#define  BisonPrint
#endif

//extern Rule TempRule;
extern RulesHead head ;

int yyerror(char* msg) ;

%}

%output  "Parser.c"
%defines "Parser.h"
%start Program

%union{
	char * str;
}

%type <str> port 
%type <str> dir 
%type <str> RuleRight 

%token	TOKEN_RULEIP 
%token	TOKEN_RULEPROCESS
%token	TOKEN_RULEDOMAIN
%token	<str> TOKEN_RULEIN
%token	<str> TOKEN_RULEOUT
%token	<str> TOKEN_RULEINOUT
%token	<str> TOKEN_IP_V4
%token	<str> TOKEN_IP_V6
%token	<str> TOKEN_PORT
%token	<str> TOKEN_PORTRANGE
%token	<str> TOKEN_DOMAIN
%token	<str> TOKEN_PROCESS
%token	<str> TOKEN_RULEALLOW
%token	<str> TOKEN_RULEDENY
%token	TOKEN_EQ
%token	TOKEN_COMMENT
%token  EOL

%%

Program
	:       { BisonPrint("Bison NULL Program.\n");}
	| Rules { BisonPrint("Bison Rules.\n");}
	| EolLoop   { BisonPrint("Bison EolLoop.\n") ; }
	;

Rules
	:   { BisonPrint("Bison NULL Rules.\n");}
	| EolLoop Rule Rules EolLoop
	| EolLoop Rule  EolLoop
	;

Rule
	: TOKEN_RULEIP TOKEN_EQ TOKEN_IP_V4 port dir RuleRight RuleEnd      { 
																		/* BisonPrint("Bison Rule IP. IP = %d.%d.%d.%d .\n", Ipv4.IP[0], Ipv4.IP[1], Ipv4.IP[2], Ipv4.IP[3]); */
																		BisonPrint("BisonPrint IP = %s\n", $3) ;
																		BisonPrint("BisonPrint port = %s\n", $4) ;
																		LPRuleList TempRuleList = (LPRuleList)malloc(sizeof(RuleList)) ;
																		if(!TempRuleList)
																		{
																			printf("Could not malloc memory!\n") ;
																		}
																		TempRuleList->rule.type = TYPE_IPV4 ;
																		GetIpV4(&(TempRuleList->rule), $3) ;
																		GetPortRange(&(TempRuleList->rule), $4, PORTTYPE_PORT) ;
																		GetDir(&(TempRuleList->rule), $5) ;
																		GetRight(&(TempRuleList->rule), $6) ;
																		free($3) ;
																		free($4) ;
																		free($5) ;
																		free($6) ;
																		InitRulesList(&head, TempRuleList) ;
																	}

	| TOKEN_RULEPROCESS TOKEN_EQ TOKEN_PROCESS port dir RuleRight RuleEnd { BisonPrint("Bison Rule Process.\n");
																		LPRuleList TempRuleList = (LPRuleList)malloc(sizeof(RuleList)) ;
																		if(!TempRuleList)
																		{
																			printf("Could not malloc memory!\n") ;
																		}
																		TempRuleList->rule.type = TYPE_PROCESS ;
																		GetProcessName(&(TempRuleList->rule), $3) ;
																		GetPortRange(&(TempRuleList->rule), $4, PORTTYPE_PORT) ;
																		GetDir(&(TempRuleList->rule), $5) ;
																		GetRight(&(TempRuleList->rule), $6) ;
																		free($3) ;
																		free($4) ;
																		free($5) ;
																		free($6) ;
																			InitRulesList(&head, TempRuleList) ;
																			}
	| TOKEN_RULEDOMAIN TOKEN_EQ TOKEN_IP_V4 port dir RuleRight RuleEnd  { BisonPrint("Bison Rule Domain.\n");
																		
																		LPRuleList TempRuleList = (LPRuleList)malloc(sizeof(RuleList)) ;
																		if(!TempRuleList)
																		{
																			printf("Could not malloc memory!\n") ;
																		}
																		TempRuleList->rule.type = TYPE_DOMAIN ;
																		GetDomainName(&(TempRuleList->rule), $3) ;
																		GetPortRange(&(TempRuleList->rule), $4, PORTTYPE_PORT) ;
																		GetDir(&(TempRuleList->rule), $5) ;
																		GetRight(&(TempRuleList->rule), $6) ;
																		free($3) ;
																		free($4) ;
																		free($5) ;
																		free($6) ;
																		InitRulesList(&head, TempRuleList) ;
																		}
	;

RuleEnd
	: EOL	
	;

EolLoop
	: 
	| EolLoop EOL 
	| EOL
	;
	
dir
	: TOKEN_RULEIN    {$$ = $1 ; BisonPrint("Bison Rule In.\n");}
	| TOKEN_RULEOUT   {$$ = $1 ; BisonPrint("Bison Rule Out.\n");}
	| TOKEN_RULEINOUT {$$ = $1 ; BisonPrint("Bison Rule InOut.\n");}
	;

RuleRight
	: TOKEN_RULEALLOW {$$ = $1 ; BisonPrint("Bison Rule Allow.\n");}
	| TOKEN_RULEDENY  {$$ = $1 ; BisonPrint("Bison Rule Deny.\n");}
	;

port
	: TOKEN_PORT      {$$ = $1; BisonPrint("Bison Rule Port.\n");}
	| TOKEN_PORTRANGE  {$$ = $1; BisonPrint("Bison Rule PortRange.\n");}
	;
%%

int yyerror(char* msg)
{
	//yytext ;
	printf("yyerror Error: %s encountered at line number:%d, str = %s\n", msg, yylineno, yytext);
	return 0 ;
}

#ifdef _BISON_DEBUG_
int main(int argc, const char *argv[])
{
	FILE* fp = fopen("Rules.r", "r") ;
	if(!fp)
	{
		printf("No Such File.\n") ;
		return 1 ;
	}
	yyrestart(fp) ;

	yyparse() ;
	system("pause") ;
	return 0 ;
}
#endif