#include "UserInfoResponse.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>

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
    auto jsonDoc = QJsonDocument::fromBinaryData(data);

    auto rootHashMap = jsonDoc.object().toVariantHash();
    auto resultFieldIter = rootHashMap.find("result");
    if(resultFieldIter != rootHashMap.end())
    {
        _respStatus = ResponseResult::Succes;

        auto resultHashMap = resultFieldIter->toHash();
        auto accountFieldIter = resultHashMap.find("account");
        if(accountFieldIter == resultHashMap.end())
            return;

        auto accountHashMap = accountFieldIter->toHash();
        _userInfo.createTime = accountHashMap["now"].toDateTime().toLocalTime();
        _userInfo.uid = accountHashMap["uid"].toString();
        _userInfo.login = accountHashMap["login"].toString();
        _userInfo.region = accountHashMap["region"].toUInt();
        _userInfo.fullName = accountHashMap["fullName"].toString();
        _userInfo.secondName = accountHashMap["secondName"].toString();
        _userInfo.firstName = accountHashMap["firstName"].toString();
        _userInfo.displayName = accountHashMap["displayName"].toString();
        _userInfo.serviceAvailable = accountHashMap["serviceAvailable"].toBool();
        _userInfo.hostedUser = accountHashMap["hostedUser"].toBool();
        _userInfo.registerTime = accountHashMap["registeredAt"].toDateTime().toLocalTime();
    }
    else
        _respStatus = ResponseResult::Error;
}

ResponseResult UserInfoResponse::status() const
{
    return _respStatus;
}

UserInfo UserInfoResponse::userInfo() const
{
    return _userInfo;
}

}
}
