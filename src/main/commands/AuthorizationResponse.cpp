#include "AuthorizationResponse.h"

#include <QJsonObject>
#include <QJsonDocument>

namespace ymlcpp {
namespace server_access {

AuthorizationResponse::AuthorizationResponse(const QByteArray& data)
{
    parseResponse(data);
}

void AuthorizationResponse::parseResponse(const QByteArray& data)
{
    QJsonDocument document = QJsonDocument::fromJson(data);

    auto jsonObject = document.object();
    auto accessTokenIter = jsonObject.find("access_token");

    if(accessTokenIter != jsonObject.end())
    {
        _status = AuthorizationStatus::Succes;
        _oauthToken = accessTokenIter->toString();
    }
    else
    {
        // error and capatha handling later
    }
}

AuthorizationResponse::AuthorizationStatus AuthorizationResponse::status() const
{
    return _status;
}

QString AuthorizationResponse::oauthToken() const
{
    return _oauthToken;
}

QString AuthorizationResponse::errorDescriprion() const
{
    return  _errorDescription;
}

QUrl AuthorizationResponse::captchaUrl() const
{
    return _captchaUrl;
}

}
}
