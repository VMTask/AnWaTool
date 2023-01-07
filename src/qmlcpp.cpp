#include "qmlcpp.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <thread>
extern bool connected_status = false;
QmlCpp::QmlCpp(QObject *parent)
    : QObject{parent}
{

}
std::string QmlCpp::command_popen(const char* cmd) {
	char buffer[128];                         //定义缓冲区                     
	char result[1024 * 4] = "";
	FILE* pipe = _popen(cmd, "r");            //打开管道，并执行命令
	if (!pipe)
		return 0;                      //返回0表示运行失败 

	while (!feof(pipe)) {
		if (fgets(buffer, 128, pipe)) {             //将管道输出到result中 
			strcat(result, buffer);
		}
	}
	_pclose(pipe);                            //关闭管道 
	return std::string(result);                                 //返回1表示运行成功 
}
QString QmlCpp::qstring_command_popen(QString command){
	std::string stdStr = command.toStdString();//正常
	QString execcommand = QString::fromStdString(command_popen(stdStr.c_str()));
	return execcommand;
}
void QmlCpp::OpenAdbCommandLine()
{
    system("start cmd.exe");
	std::string get = command_popen("dir");
}
void QmlCpp::getAndroidDeviceStatus() {
	while (1) {
		try {
			std::string::size_type idx;
			std::string check = command_popen("adb get-state");
			idx = check.find("device");
			if (idx == std::string::npos)
			{
				connected_status = false;
			}
			else {
				connected_status = true;
			}
		}
		catch (...) {
		}
	}
}
void QmlCpp::threadStart() {
	std::thread getAndroidDeviceStatus_thread(&QmlCpp::getAndroidDeviceStatus,this);
	getAndroidDeviceStatus_thread.detach();
}

QString QmlCpp::getAndroidDeviceStatus_qstr() {
	QString result = QString::number(connected_status);
	return result;
}
QString QmlCpp::imageurl() {
	switch (connected_status)
	{
	case true:{
		return "connect_on.png";
		break;
	}
	case false:{
		return "connect_off.png";
		break;
	}
	default: {
		return "undefined";
		break;
	}
	}
}
QString QmlCpp::text_status() {
    switch(connected_status)
    {
        case true:{
            return "已连接";
            break;
        }
        case false:{
            return "未连接";
            break;
        }
    }
}
