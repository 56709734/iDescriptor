#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ZDownloader.h"
#include "ZUpdater.h"
#include "devicemanagerwidget.h"
#include "iDescriptor.h"
#include "libirecovery.h"
#include "ztabwidget.h"
#include <QLabel>
#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow *sharedInstance();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ZUpdater *m_updater = nullptr;
public slots:
    void updateNoDevicesConnected();

private:
    void createMenus();

    Ui::MainWindow *ui;
    ZTabWidget *m_ZTabWidget;
    DeviceManagerWidget *m_deviceManager;
    QStackedWidget *m_mainStackedWidget;
    QLabel *m_connectedDeviceCountLabel;
};
#endif // MAINWINDOW_H
