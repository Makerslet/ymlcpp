#ifndef SERVERACCESSOR_H
#define SERVERACCESSOR_H

#include <QNetworkRequest>
#include <QNetworkAccessManager>

namespace ymlcpp {
namespace server_access {

class ServerAccessor : public QObject
{
    Q_OBJECT
public:
    ServerAccessor(QObject* parent = nullptr);
    ~ServerAccessor();

    ServerAccessor(const ServerAccessor&) = delete;
    ServerAccessor& operator=(const ServerAccessor&) = delete;

    void sendRequest(const QNetworkRequest&);
    void sendRequest(const QPair<QNetworkRequest, QByteArray> &);

signals:
    void responseReceived(QNetworkReply*);
    void errorHapenned(QNetworkReply*, const QList<QSslError>&);

private:
    QNetworkAccessManager* _networkAccessManager;
};

}
}

#endif // SERVERACCESSOR_H
