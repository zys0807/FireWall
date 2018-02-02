#ifndef __RULES_H__
#define __RULES_H__


typedef struct _Rule
{
    ULONG   RemoteIP ;
    WORD    RemotePort ;
    ULONG   LocalIP ;
	ULONG   ProcessID;
    WORD    LocalPort ;
    WORD    IsAllowPass ; //是否允许通过
    WORD    Direction ;   //方向
    WORD    ProTocol ;    //协议

} Rule, *LpRule ;

#endif
