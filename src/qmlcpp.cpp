#include "qmlcpp.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
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



