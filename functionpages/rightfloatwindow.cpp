#include "rightfloatwindow.h"
#include "QFramer/futil.h"
#include "mainwindow/mainwindow.h"
#include <QGraphicsDropShadowEffect>

RightFloatWindow::RightFloatWindow(QWidget *parent) :
    FMovableWidget(parent)
{
    initData();
    initUI();
    initConnect();

}

void RightFloatWindow::initData()
{
    cwidth = 200;
}

void RightFloatWindow::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::ToolTip);
    setObjectName(QString("RightFloatWindow"));
    QString qss = getQssFromFile(QString(":/qss/skin/qss/main.qss"));
    setStyleSheet(qss);
}

void RightFloatWindow::initConnect()
{

}

void RightFloatWindow::showEvent(QShowEvent *event)
{
    move(MainWindow::getInstance()->x()+ MainWindow::getInstance()->width() + 2,\
         MainWindow::getInstance()->y());
    resize(cwidth, MainWindow::getInstance()->height());
    MainWindow::getInstance()->settingmenu->\
            getActionMaps()["Show rightBar"]->setText(tr("Hide rightBar"));
    QWidget::showEvent(event);
}

void RightFloatWindow::hideEvent(QHideEvent *event)
{
    MainWindow::getInstance()->settingmenu->\
            getActionMaps()["Show rightBar"]->setText(tr("Show rightBar"));
}

void RightFloatWindow::mouseMoveEvent(QMouseEvent *event)
{
    move(x() + width(), y());
    FMovableWidget::mouseMoveEvent(event);
}

