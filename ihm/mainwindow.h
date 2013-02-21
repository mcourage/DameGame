#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Threads/incomingconnectionthread.h"

#ifdef __cplusplus
extern "C" {
#include "../DameGame/include/client.h"
#include "../DameGame/include/structures.h"
}
#endif

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void serverConnection(QString host, int port, QString pseudo);
    void serverDisconnection();

    void on_actionQuit_triggered();
    void on_showHidePushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool _rightMenuHidden;

    //Client attributes
    int _socket_descriptor;     // descriptor of socket
    sockaddr_in _local_addr;    // local adress of the client
    hostent *_ptr_host; 		// information about host machine
    servent *_ptr_service;      // information about a service

    player _player;// the player

    //Thread for listen incoming connection
    IncomingConnectionThread * _incomingConnection;

};

#endif // MAINWINDOW_H
