#include "commands/user_choice_commands/choice_set/UserChoiceSetRequest.h"
#include "commands/user_choice_commands/choice_set/UserChoiceSetResponse.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

const QString UserChoiceSetRequest::_templateUrl("https://api.music.yandex.net/users/%1/%2/%3/%4");

UserChoiceSetRequest::UserChoiceSetRequest(const QString &oauth, const QString &userId,
                UserChoiceType choiceType, ContentType choiceContent,
                UserAction action, const QStringList& ids) :
    ServerPostRequest (AppRequestType::UserChoiceSetRequest),
    _oauth(oauth),
    _userId(userId),
    _choiceType(choiceType),
    _choiceContent(choiceContent),
    _action(action),
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
    auto response = QSharedPointer<UserChoiceSetResponse>::create();
    response->parseResponse(payload);
    return response.dynamicCast<IServerResponse>();
}

QNetworkRequest UserChoiceSetRequest::prepareRequest(int payloadLen) const
{
    QString choiceTypeStr = UserChoiceConvertor::userChoiceTypeToString(_choiceType);
    QString choiceContentStr = UserChoiceConvertor::userChoiceContentToString(_choiceContent);
    QString actionStr = UserChoiceConvertor::userActionToString(_action);

    QUrl actualUrl(_templateUrl.arg(_userId).arg(choiceTypeStr).arg(choiceContentStr).arg(actionStr));
    QNetworkRequest request(actualUrl);

    QString authValue = QString("OAuth %1").arg(_oauth);
    request.setRawHeader("Authorization", authValue.toUtf8());
    //request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
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
