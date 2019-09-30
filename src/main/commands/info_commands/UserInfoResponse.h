#ifndef USERINFORESPONSE_H
#define USERINFORESPONSE_H

#include "../common_and_base/base_requests_responses/IServerResponse.h"

#include <QDateTime>
#include <QVariant>

namespace ymlcpp {
namespace server_access {

struct Account
{
    QDateTime   createTime;
    uint        uid;
    QString     login;
    uint        region;
    QString     fullName;
    QString     secondName;
    QString     firstName;
    QString     displayName;
    bool        serviceAvailable;
    bool        hostedUser;
    QDateTime   registeredAt;
};

struct Permissions
{
    QDateTime   until;
    QStringList values;
    QStringList defaults;
};

struct Subscription
{
    bool canStartTrial;
    bool mcdonalds;
};

struct Plus
{
    bool hasPlus;
    bool isTutorialCompleted;
};

struct UserInfo {
    Account         account;
    Permissions     permissions;
    Subscription    subscription;
    Plus    plus;
    bool    subeditor;
    uint    subeditorLevel;
    QString defaultEmail;
};

class UserInfoResponse : public IServerResponse
{
public:
    UserInfoResponse(const QByteArray&);
    ~UserInfoResponse() override;

    ResponseResult status() const override;
    UserInfo userInfo() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseAccount(const QVariantHash&);
    void parsePermissions(const QVariantHash&);
    void parseSubscription(const QVariantHash&);
    void parsePlus(const QVariantHash&);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    UserInfo _userInfo;
    ErrorInfo _errInfo;
};

}
}

#endif // USERINFORESPONSE_H
