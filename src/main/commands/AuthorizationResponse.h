#ifndef AUTHORIZATIONRESPONSE_H
#define AUTHORIZATIONRESPONSE_H

#include "headers/IServerResponse.h"

#include <QByteArray>
#include <QJsonObject>
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

    enum class AuthorizationError {
        AuthorizationPending,
        BadVerificationCode,
        InvalidClient,
        InvalidGrant,
        InvalidRequest,
        InvalidScope,
        UnauthorizedClient,
        UnsupportedGrantType,
        BasicAuthRequired,
        MalformedAuthorization,
        UnknownError
    };

    enum class ResponseFields {
        AccessToken,
        TokenType,
        Error,
        ErrorDescription
    };

    using ErrorsMap = QMap<QString, AuthorizationError>;
    using FieldsMap = QMap<ResponseFields, QString>;

public:
    AuthorizationResponse(const QByteArray&);

    AuthorizationStatus status() const;
    QString oauthToken() const;

    AuthorizationError error() const;
    QString errorDescriprion() const;

    QUrl captchaUrl() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseError(const QJsonObject&);

private:
    AuthorizationStatus _status;
    QString _oauthToken;

    AuthorizationError _error;
    QString _errorDescription;

    QUrl _captchaUrl;

    const static ErrorsMap _errors;
    const static FieldsMap _fields;
};

}
}

#endif // AUTHORIZATIONRESPONSE_H
