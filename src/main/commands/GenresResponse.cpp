#include "GenresResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include <QDebug>

namespace ymlcpp {
namespace server_access {


GenresResponse::GenresResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::GenresResponse)
{
    qDebug() << QString(data);
    parseResponse(data);
}

GenresResponse::~GenresResponse()
{
}

ResponseResult GenresResponse::status() const
{
    return  _respStatus;
}

GenreDescription GenresResponse::genreDescription() const
{
    return _genreDescription;
}

ErrorInfo GenresResponse::errorInfo() const
{
    return _errInfo;
}

void GenresResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        //parseResult(resultFieldIter.value().toList());
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

void GenresResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
