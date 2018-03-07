#pragma once
#ifndef __Rule_H_

#include <Windows.h>
typedef unsigned char RuleType;

typedef TCHAR String;


#ifndef MAX_PATH
#define MAX_PATH 260
#endif // !MAX_PATH

#ifndef MAX_DOMAIN
#define MAX_DOMAIN 260
#endif // !MAX_DOMAIN

enum  Rule_Type
{
	TYPE_UNKONOW = 0 ,
	TYPE_IPV4 = 1 ,
	TYPE_IPV6 ,
	TYPE_PROCESS ,
	TYPE_DOMAIN
};

enum Rule_Dir
{
	DIR_INOUT = 0,
	DIR_IN,
	DIR_OUT,
	DIR_OTHER
};
enum Rule_Right
{
	RIGHT_ALLOW = 0,
	RIGHT_DENY,
	RIGHT_OTHRRT
};

enum PortType
{
	PORTTYPE_PORT,
	PORTTYPE_PORTRANGE
};


typedef struct _IPV4
{
	unsigned char IP[4];
	unsigned char Dir : 2;
	unsigned char Right : 2;
	unsigned int minIPV4Port : 16;
	unsigned int maxIPV4Port : 16;

}IPV4, *LPIPV4;

typedef struct _RuleDomain
{
	unsigned char Dir : 2;
	unsigned char Right : 2;
	unsigned int minDomainPort : 16;
	unsigned int maxDomainPort : 16;
	String strURL[MAX_DOMAIN];

}RuleDomain, *LPRuleDomain;

typedef struct _RuleProcess
{
	unsigned char Dir : 2;
	unsigned char Right : 2;
	unsigned int minProcessPort : 16;
	unsigned int maxProcessPort : 16;
	String strURL[MAX_PATH];

}RuleProcess, *LPRuleProcess;

typedef struct _Rule
{
	RuleType type;		/* ��������� */
	union RuleItem
	{
		IPV4 IpV4;
		RuleDomain Domain;
		RuleProcess Process;
	};

}Rule , *LPRule;

typedef struct _RuleList
{
	struct _RuleList * PreRuleList;      /* ��һ�������б� */
	struct _RuleList * NextRuleList;	  /* ��һ�������б� */
	Rule rule;
}RuleList, *LPRuleList;

typedef struct _RulesHead
{
	LPRuleList FirstRuleList; /* ��һ������ڵ㣬 û����Ϊ NULL */
	LPRuleList LastRuleList;  /* ���һ������ڵ㣬û����Ϊ NULL */
	unsigned int ListLength;  /* �ڵ���� */

}RulesHead;

int GetIpV4(LPRule rule, char *IpStr );
int GetPortRange(LPRule rule, char* PortRange, int type);
int GetDir(LPRule rule, char* dir);
int GetRight(LPRule rule, char* right);
int InitRulesList(RulesHead* rulHead, LPRuleList lpRuleList);
int UnloadRulesList(RulesHead* rulHead);
int GetProcessName(LPRule rule, char* ProcessName);
int GetDomainName(LPRule rule, char* DomainName);

#endif // !__Rule_H_