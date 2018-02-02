﻿#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

enum IoCommand
{
    IoCommand_Start_Service = 0x800,
    IoCommand_Stop_Service ,
    IoCommand_Add_Rule,
    IoCommand_Delete_Rule,
    IoCommand_UNKNOW
};

#define IO_COMMAND_START_SERVICE CTL_CODE(FILE_DEVICE_UNKNOWN, IoCommand_Start_Service, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_COMMAND_STOP_SERVICE  CTL_CODE(FILE_DEVICE_UNKNOWN, IoCommand_Stop_Service, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_COMMAND_ADD_RULE      CTL_CODE(FILE_DEVICE_UNKNOWN, IoCommand_Add_Rule, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IO_COMMAND_DELETE_RULE   CTL_CODE(FILE_DEVICE_UNKNOWN, IoCommand_Delete_Rule, METHOD_BUFFERED, FILE_ANY_ACCESS)

#endif // COMMAND_H_INCLUDED