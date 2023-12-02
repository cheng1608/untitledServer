#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QtNetwork>
#include <QString>
#include <QByteArray>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCryptographicHash>



class HttpServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);
    void incomingConnection(qintptr socketDescriptor) override;
    bool updateCoins(QString account,int coins);


    bool checkLogin(QString account,QString password);


private slots:
    void handleRequest();

private:
    int getCoinValue(QString account);
};

#endif // HTTPSERVER_H
