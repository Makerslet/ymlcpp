#include "UserInfoResponse.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>

#include <QDebug>

namespace ymlcpp {
namespace server_access {

UserInfoResponse::UserInfoResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserInfoResponse)
{
    parseResponse(data);
}

UserInfoResponse::~UserInfoResponse()
{
}

void UserInfoResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        auto resultHashMap = resultFieldIter.value().toHash();

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
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
    {
        // unknown error
        _respStatus = ResponseResult::Error;
    }
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

void UserInfoResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

ResponseResult UserInfoResponse::status() const
{
    return _respStatus;
}

UserInfo UserInfoResponse::userInfo() const
{
    return _userInfo;
}

ErrorInfo UserInfoResponse::errorInfo() const
{
    return _errInfo;
}

}
}
