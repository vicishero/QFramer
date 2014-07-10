#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"QFramer/fmainwindow.h"
#include"centerwindow.h"
#include"settingmenu.h"
#include"lockmenu.h"
#include"functionpages/rightfloatwindow.h"
#include <QResizeEvent>
#include <QMouseEvent>
#include <QHideEvent>
class MainWindow : public FMainWindow
{
    Q_OBJECT
private:
    void initData();
    void initUI();
    void initConnect();
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent * event);
    void hideEvent(QHideEvent * event);
    void showEvent(QHideEvent * event);
    void mouseDoubleClickEvent(QMouseEvent *event);
public:
    static MainWindow* instance;
    CenterWindow* centerWindow;
    SettingMenu* settingmenu;
    LockMenu* lockMenu;
    RightFloatWindow* rightfloatWindow;
public:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow* getInstance();
    RightFloatWindow* getRightFloatWindow();
signals:

public slots:


};

#endif // MAINWINDOW_H
