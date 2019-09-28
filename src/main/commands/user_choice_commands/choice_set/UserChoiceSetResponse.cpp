#include "UserChoiceSetResponse.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>

namespace ymlcpp {
namespace server_access {


UserChoiceSetResponse::UserChoiceSetResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::UserChoiceSetResponse)
{
    parseResponse(data);
}

void UserChoiceSetResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
        _respStatus = ResponseResult::Succes;
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
}

ResponseResult UserChoiceSetResponse::status() const
{
    return _respStatus;
}

void UserChoiceSetResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}


}
}
