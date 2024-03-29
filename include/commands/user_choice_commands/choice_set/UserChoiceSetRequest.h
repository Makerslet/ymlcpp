#ifndef USERCHOICESETREQUEST_H
#define USERCHOICESETREQUEST_H

#include "../../common_and_base/base_requests_responses/ServerPostRequest.h"
#include "../../common_and_base/common_enums/AppRequestTypes.h"
#include "../../common_and_base/common_enums/UserChoice.h"

#include <QPair>
#include <QNetworkRequest>

namespace ymlcpp {
namespace server_access {

class UserChoiceSetRequest : public ServerPostRequest
{
public:
    UserChoiceSetRequest(const QString&,
                         const QString&,
                         UserChoiceType,
                         ContentType,
                         UserAction,
                         const QStringList&);

    QPair<QNetworkRequest, QByteArray> toNetworkRequest() const override;
    QSharedPointer<IServerResponse> createResponse(const QByteArray&) const override;

private:
    QNetworkRequest prepareRequest(int payloadLen) const;
    QByteArray preparePayload() const;

private:
    const QString _oauth;
    const QString _userId;

    const UserChoiceType _choiceType;
    const ContentType _choiceContent;
    const UserAction _action;

    const QStringList _ids;
    static const QString _templateUrl;
};

}
}

#endif // USERCHOICESETREQUEST_H
