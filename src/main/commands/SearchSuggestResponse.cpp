#include "SearchSuggestResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

namespace ymlcpp {
namespace server_access {

SearchSuggestResponse::SearchSuggestResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::SearchSuggestResponse)
{
    parseResponse(data);
}

SearchSuggestResponse::~SearchSuggestResponse(){}

ResponseResult SearchSuggestResponse::status() const
{
    return _respStatus;
}

void SearchSuggestResponse::parseResponse(const QByteArray& data)
{
    QFile file("SearchSuggestResponse.json");
    file.open(QIODevice::ReadWrite);
    file.write(data);
    file.close();
    qDebug() << "result written";
}

ErrorInfo SearchSuggestResponse::errorInfo() const
{
    return _errInfo;
}

void SearchSuggestResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

SearchSuggestResult SearchSuggestResponse::description() const
{
    return _result;
}


}
}
