#include "rightmenu.h"
#include "ui_rightmenu.h"

#include <QDebug>
#include <QPropertyAnimation>

/**
 * @brief Constructs a new RightMenu widget.
 * @param parent
 */
RightMenu::RightMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightMenu)
{
    ui->setupUi(this);

    connect(ui->chatroomWidget, SIGNAL(sendMessage(QString)), this, SIGNAL(askSendMessage(QString)));
    connect(this, SIGNAL(addMsg(QString)), ui->chatroomWidget, SLOT(addText(QString)));
}

/**
 * @brief Destroys the RightMenu
 */
RightMenu::~RightMenu()
{
    delete ui;
}





void RightMenu::on_pushButton_clicked()
{
    emit askDisconnection();
}
