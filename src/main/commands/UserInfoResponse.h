#ifndef USERINFORESPONSE_H
#define USERINFORESPONSE_H

#include "headers/IServerResponse.h"

#include <QDateTime>

namespace ymlcpp {
namespace server_access {

struct UserInfo {
    QDateTime   _createTime;
    QString     _uid;
    QString     _login;
    uint        _region;
    QString     _fullName;
    QString     _secondName;
    QString     _firstName;
    QString     _displayName;
    bool        _serviceAvailable;
    bool        _hostedUser;
    QDateTime   _registerTime;
};

class UserInfoResponse : public IServerResponse
{
public:
    UserInfoResponse(const QByteArray&);
    ~UserInfoResponse() override;

private:
    void parseResponse(const QByteArray&) override;
};

}
}

#endif // USERINFORESPONSE_H
