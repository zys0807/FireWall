#ע��
#Ĭ�����е�IP��ַ����ͨ��
RuleIP = 25.255.255.255 0-65535 InOut Allow

#����IP��ַ��ֹͨ��
RuleIP = 255.255.255.255 0-65535 InOut Deny

RuleIP = 192.168.1.1 80   In    Allow
RuleIP = 192.168.1.1 1-20 Out   Deny
RuleIP = 127.0.0.1   80   In    Allow


#����
#RuleDomain = *.baidu.com 80   Out   Allow
#RuleDomain = baidu.com 80 Out Deny

#����
RuleProcess = C:\Windows\123.exe 68 Out Deny




