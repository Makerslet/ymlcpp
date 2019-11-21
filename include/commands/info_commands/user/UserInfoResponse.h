#ifndef USERINFORESPONSE_H
#define USERINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/ServerResponse.h"

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

class UserInfoResponse : public ServerResponse
{
public:
    UserInfoResponse();
    ~UserInfoResponse() override;

    UserInfo userInfo() const;

private:
    void parseContent(const QVariant&) override;
    void parseAccount(const QVariantHash&);
    void parsePermissions(const QVariantHash&);
    void parseSubscription(const QVariantHash&);
    void parsePlus(const QVariantHash&);

private:
    UserInfo _userInfo;
};

}
}

#endif // USERINFORESPONSE_H
