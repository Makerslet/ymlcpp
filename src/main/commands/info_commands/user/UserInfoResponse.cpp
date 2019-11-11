#include "UserInfoResponse.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>

namespace ymlcpp {
namespace server_access {

UserInfoResponse::UserInfoResponse() :
    ServerResponse (AppResponseType::UserInfoResponse)
{}

UserInfoResponse::~UserInfoResponse()
{}

void UserInfoResponse::parseContent(const QVariant& data)
{
    auto resultHashMap = data.toHash();

    auto accountIter = resultHashMap.find("account");
    if(accountIter != resultHashMap.end())
        parseAccount(accountIter.value().toHash());

    auto permissionsIter = resultHashMap.find("permissions");
    if(permissionsIter != resultHashMap.end())
        parsePermissions(permissionsIter.value().toHash());

    auto subscriptionIter = resultHashMap.find("subscription");
    if(subscriptionIter != resultHashMap.end())
        parseSubscription(subscriptionIter.value().toHash());

    auto plusIter = resultHashMap.find("plus");
    if(plusIter != resultHashMap.end())
        parsePlus(plusIter.value().toHash());

    _userInfo.subeditor = resultHashMap["subeditor"].toBool();
    _userInfo.subeditorLevel = resultHashMap["subeditorLevel"].toUInt();
    _userInfo.defaultEmail = resultHashMap["defaultEmail"].toString();

}

void UserInfoResponse::parseAccount(const QVariantHash& accHash)
{
    auto& account = _userInfo.account;
    account.createTime = accHash["now"].toDateTime().toLocalTime();
    account.uid = accHash["uid"].toUInt();
    account.login = accHash["login"].toString();
    account.region = accHash["region"].toUInt();
    account.fullName = accHash["fullName"].toString();
    account.secondName = accHash["secondName"].toString();
    account.firstName = accHash["firstName"].toString();
    account.displayName = accHash["displayName"].toString();
    account.serviceAvailable = accHash["serviceAvailable"].toBool();
    account.hostedUser = accHash["hostedUser"].toBool();
    account.registeredAt = accHash["registeredAt"].toDateTime().toLocalTime();
}

void UserInfoResponse::parsePermissions(const QVariantHash& permHash)
{
    auto& permissions = _userInfo.permissions;
    permissions.until = permHash["until"].toDateTime().toLocalTime();
    permissions.values = permHash["values"].toStringList();
    permissions.defaults = permHash["default"].toStringList();
}

void UserInfoResponse::parseSubscription(const QVariantHash& subscrptnHash)
{
    auto& subscription = _userInfo.subscription;
    subscription.canStartTrial = subscrptnHash["canStartTrial"].toBool();
    subscription.mcdonalds = subscrptnHash["mcdonalds"].toBool();
}

void UserInfoResponse::parsePlus(const QVariantHash& plusHash)
{
    auto& plus = _userInfo.plus;
    plus.hasPlus = plusHash["hasPlus"].toBool();
    plus.isTutorialCompleted = plusHash["isTutorialCompleted"].toBool();
}

UserInfo UserInfoResponse::userInfo() const
{
    return _userInfo;
}

}
}
