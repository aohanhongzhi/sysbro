#include <DApplication>
#include <DWidgetUtil>
#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.loadTranslator();
    a.setOrganizationName("deepin");
    a.setApplicationVersion(DApplication::buildVersion("1.0"));
    a.setApplicationAcknowledgementPage("https://github.com/rekols");
    a.setProductIcon(QIcon(":/images/icon.svg"));
    a.setProductName(DApplication::translate("Main", "应用开机启动管理"));
//    a.setApplicationDescription(DApplication::translate("Main", "应用开机启动管理"));

    if (!a.setSingleInstance("sysbro-startup-apps")) {
        return 0;
    }

    MainWindow w;
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();

}
