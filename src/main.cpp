#include <QDir>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextCodec>
#include <QQmlContext>
#include "qmlcpp.h"
#include <QIcon>
#include <Windows.h>
int main(int argc, char *argv[])
{
    //设置中文编码
    AllocConsole();
    ShowWindow(GetConsoleWindow(), SW_HIDE);    //隐藏自己创建的控制台
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/toolbox.png"));
    QQmlApplicationEngine engine;
    QmlCpp qmlCpp;
    engine.rootContext()->setContextProperty("qmlCpp",&qmlCpp);
    engine.addImportPath(QCoreApplication::applicationDirPath() + QDir::separator() + QLatin1String("..") +
                         QDir::separator() + QLatin1String("lib") + QDir::separator() + QLatin1String("qml"));
    engine.addImportPath(QCoreApplication::applicationDirPath() + QDir::separator() + QLatin1String("qml"));
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
