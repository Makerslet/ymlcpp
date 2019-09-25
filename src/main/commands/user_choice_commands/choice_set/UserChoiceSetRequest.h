#ifndef USERCHOICESETREQUEST_H
#define USERCHOICESETREQUEST_H

#include "../../common_and_base/base_requests_responses/ServerPostRequest.h"
#include "../../common_and_base/common_enums/AppRequestTypes.h"
#include "../../common_and_base/common_enums/UserChoice.h"

#include <QPair>
#include <QNetworkRequest>
#include <QMap>

namespace ymlcpp {
namespace server_access {

class UserChoiceSetRequest : public ServerPostRequest
{
public:
    UserChoiceSetRequest(const QString& login,
                         const QString& oauth,
                         UserChoiceType,
                         UserChoiceContent,
                         const QStringList&);

    QPair<QNetworkRequest, QByteArray> toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QNetworkRequest prepareRequest(int payloadLen) const;
    QByteArray preparePayload() const;

private:
    const QString _oauth;
    const QString _login;

    const UserChoiceType _choiceType;
    const UserChoiceContent _choiceContent;

    const QStringList _ids;
    static const QString _templateUrl;
};

}
}

#endif // USERCHOICESETREQUEST_H
