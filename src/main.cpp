#include "mainwindow.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("iDescriptor");
    // QCoreApplication::setOrganizationDomain("iDescriptor.com");
    QCoreApplication::setApplicationName("iDescriptor");
    // QCoreApplication::setApplicationVersion(IDESCRIPTOR_VERSION);

    QApplication::setStyle(QStyleFactory::create("macOS"));

    MainWindow *w = MainWindow::sharedInstance();
    w->show();
    return a.exec();
}
