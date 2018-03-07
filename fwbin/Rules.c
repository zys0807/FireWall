#include "../Inc/Rules.h"
#include "..\Inc\Rules.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN_STRING "In"
#define OUT_STRING "Out"
#define INOUT_STRING "InOut"
#define ALLOW_STRING "Allow"
#define DENY_STRING "Deny"

int DEBUG_PRINT = 1;

Rule TempRule = { 0 };
RulesHead head = { 0 };

int GetIpV4( LPRule rule, char * IpStr)
{
	int i = 4;
	unsigned char* p = rule->IpV4.IP;

	//printf("sizeof unsigned char %d\n", sizeof(unsigned char));
//	printf("IpStr = %s \nSize of IpStr = %d\n", IpStr, strlen(IpStr));
	char* ptr;

	if (!IpStr || !rule)
	{
		return -1;
	}

	ptr = strtok(IpStr, ".");
	while ((ptr) && (i--))
	{
		*p++ = atoi(ptr);
		ptr = strtok(NULL, ".");
	}

	//printf("GetIpV4 = %d.%d.%d.%d \n", rule->IpV4.IP[0], rule->IpV4.IP[1], rule->IpV4.IP[2], rule->IpV4.IP[3] );
	
	return 0;
}

int GetPortRange(LPRule rule, char * PortRange, int type)
{
	int temp;
	char *ptr;

	if (!PortRange || !rule)
	{
		return -1;
	}
#if (DEBUG_PRINT == 0)
	printf("GetPortRange = %s\n", PortRange);
#endif

	switch (type)
	{
	case PORTTYPE_PORT:
		rule->IpV4.maxIPV4Port = rule->IpV4.minIPV4Port = atoi(PortRange);
		break;

	case PORTTYPE_PORTRANGE:
		ptr = strtok(PortRange, "-");
		rule->IpV4.minIPV4Port = atoi(ptr);
		ptr = strtok(NULL, "-");
		rule->IpV4.maxIPV4Port = atoi(ptr);
		if (rule->IpV4.minIPV4Port > rule->IpV4.maxIPV4Port)
		{
			temp = rule->IpV4.minIPV4Port;
			rule->IpV4.minIPV4Port = rule->IpV4.maxIPV4Port;
			rule->IpV4.maxIPV4Port = temp;
		}
		break;
	default:
		break;
	}

	return 0;
}

int GetDir(LPRule rule, char * dir)
{
	if (!strcmp(dir, IN_STRING))
	{
		rule->IpV4.Dir = DIR_IN;
		return 0;
	}
	if (!strcmp(dir, OUT_STRING))
	{
		rule->IpV4.Dir = DIR_OUT;
		return 0;
	}
	if (!strcmp(dir, INOUT_STRING))
	{
		rule->IpV4.Dir = DIR_INOUT;
		return 0;
	}
	return 0;
}

int GetRight(LPRule rule, char * right)
{
	if (!strcmp(right, ALLOW_STRING))
	{
		rule->IpV4.Right = RIGHT_ALLOW;
		return 0;
	}
	if (!strcmp(right, DENY_STRING))
	{
		rule->IpV4.Right = RIGHT_DENY;
		return 0;
	}
	return 0;
}

int InitRulesList(RulesHead * rulHead, LPRuleList lpRuleList)
{
	if (!rulHead || !lpRuleList)
	{
		return -1;
	}
	if (rulHead->FirstRuleList)
	{
		lpRuleList->PreRuleList = rulHead->LastRuleList;
		lpRuleList->NextRuleList = NULL;
		rulHead->LastRuleList = lpRuleList;
		rulHead->ListLength++;
	}
	else
	{
		rulHead->FirstRuleList = rulHead->LastRuleList = lpRuleList;
		lpRuleList->PreRuleList = lpRuleList->NextRuleList = NULL;
		rulHead->ListLength++;
	}
	return 0;
}

int UnloadRulesList(RulesHead * rulHead)
{
	LPRuleList lpPreRuleList = rulHead->LastRuleList;
	LPRuleList lpNextRuleList = rulHead->LastRuleList->PreRuleList;
	while (lpPreRuleList)
	{
		free(lpPreRuleList);
		lpPreRuleList = lpNextRuleList;
		lpNextRuleList = lpNextRuleList->PreRuleList;
	}
	rulHead->FirstRuleList = rulHead->LastRuleList = NULL;
	rulHead->ListLength = 0;
	return 0;
}

int GetProcessName(LPRule rule, char * ProcessName)
{
	if (!rule || !ProcessName)
	{
		return -1;
	}
	strcpy(rule->Process.strURL, ProcessName);
	return 0;
}

int GetDomainName(LPRule rule, char * DomainName)
{
	if (!rule || !DomainName)
	{
		return -1;
	}
	strcpy(rule->Domain.strURL, DomainName);
	return 0;
}
