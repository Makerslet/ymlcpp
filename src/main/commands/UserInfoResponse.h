#ifndef USERINFORESPONSE_H
#define USERINFORESPONSE_H

#include "headers/IServerResponse.h"

#include <QDateTime>

namespace ymlcpp {
namespace server_access {

struct UserInfo {
    QDateTime   createTime;
    QString     uid;
    QString     login;
    uint        region;
    QString     fullName;
    QString     secondName;
    QString     firstName;
    QString     displayName;
    bool        serviceAvailable;
    bool        hostedUser;
    QDateTime   registerTime;
};

class UserInfoResponse : public IServerResponse
{
public:
    UserInfoResponse(const QByteArray&);
    ~UserInfoResponse() override;

    ResponseResult status() const override;
    UserInfo userInfo() const;

private:
    void parseResponse(const QByteArray&) override;

private:
    ResponseResult _respStatus;
    UserInfo _userInfo;
};

}
}

#endif // USERINFORESPONSE_H
