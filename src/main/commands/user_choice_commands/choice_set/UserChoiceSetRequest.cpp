#include "UserChoiceSetRequest.h"
#include "UserChoiceSetResponse.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

const QString UserChoiceSetRequest::_templateUrl("https://api.music.yandex.net/users/%1/%2/%3/action");

UserChoiceSetRequest::UserChoiceSetRequest(const QString &login, const QString &oauth,
                UserChoiceType choiceType, UserChoiceContent choiceContent, const QStringList& ids) :
    ServerPostRequest (AppRequestType::UserChoiceSetRequest),
    _oauth(oauth),
    _login(login),
    _choiceType(choiceType),
    _choiceContent(choiceContent),
    _ids(ids)
{

}


QPair<QNetworkRequest, QByteArray> UserChoiceSetRequest::toNetworkRequest() const
{
    auto payload = preparePayload();
    auto request = prepareRequest(payload.length());
    return qMakePair(request, payload);
}


QSharedPointer<IServerResponse> UserChoiceSetRequest::createResponse(const QByteArray& payload) const
{
    return QSharedPointer<UserChoiceSetResponse>::create(payload);
}

QNetworkRequest UserChoiceSetRequest::prepareRequest(int payloadLen) const
{
    QString choiceTypeStr = UserChoiceConvertor::userChoiceTypeToString(_choiceType);
    QString choiceContentStr = UserChoiceConvertor::userChoiceContentToString(_choiceContent);

    QUrl actualUrl(_templateUrl.arg(_login).arg(choiceTypeStr).arg(choiceContentStr));
    QNetworkRequest request(actualUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader, payloadLen);
    return  request;
}

QByteArray UserChoiceSetRequest::preparePayload() const
{
    QString contentId = QString("%1-ids").arg(
                UserChoiceConvertor::userChoiceContentToStringSingle(_choiceContent));

    return toApiFormat(contentId, _ids);
}


}
}
