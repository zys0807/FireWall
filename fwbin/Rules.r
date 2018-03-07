#注释
#默认所有的IP地址允许通过
RuleIP = 25.255.255.255 0-65535 InOut Allow

#所有IP地址禁止通过
RuleIP = 255.255.255.255 0-65535 InOut Deny

RuleIP = 192.168.1.1 80   In    Allow
RuleIP = 192.168.1.1 1-20 Out   Deny
RuleIP = 127.0.0.1   80   In    Allow


#域名
#RuleDomain = *.baidu.com 80   Out   Allow
#RuleDomain = baidu.com 80 Out Deny

#进程
RuleProcess = C:\Windows\123.exe 68 Out Deny




