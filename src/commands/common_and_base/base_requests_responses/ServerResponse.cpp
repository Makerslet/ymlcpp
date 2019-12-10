#include "commands/common_and_base/base_requests_responses/ServerResponse.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

ServerResponse::ServerResponse(AppResponseType rType) :
    _respType(rType)
{
}

ServerResponse::~ServerResponse(){}

AppResponseType ServerResponse::appResponseType() const
{
    return  _respType;
}

ResponseResult ServerResponse::status() const
{
    return _respStatus;
}

ErrorInfo ServerResponse::errInfo() const
{
    return _errInfo;
}

void ServerResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        parseContent(resultFieldIter.value());
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

void ServerResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
