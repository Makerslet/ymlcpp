#ifndef AUTHORIZATIONRESPONSE_H
#define AUTHORIZATIONRESPONSE_H

#include "headers/IServerResponse.h"

#include <QByteArray>
#include <QUrl>

namespace ymlcpp {
namespace server_access {


class AuthorizationResponse : public IServerResponse
{
    enum class AuthorizationStatus {
        Succes,
        CaptchaRequired,
        Error
    };

public:
    AuthorizationResponse(const QByteArray&);

    AuthorizationStatus status() const;
    QString oauthToken() const;
    QString errorDescriprion() const;
    QUrl captchaUrl() const;

private:
    void parseResponse(const QByteArray&) override;

private:
    AuthorizationStatus _status;
    QString _oauthToken;
    QString _errorDescription;
    QUrl _captchaUrl;
};

}
}

#endif // AUTHORIZATIONRESPONSE_H
