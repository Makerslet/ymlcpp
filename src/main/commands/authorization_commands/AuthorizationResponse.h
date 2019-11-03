#ifndef AUTHORIZATIONRESPONSE_H
#define AUTHORIZATIONRESPONSE_H

#include "../common_and_base/base_requests_responses/ServerResponse.h"

#include <QByteArray>
#include <QJsonObject>
#include <QUrl>

namespace ymlcpp {
namespace server_access {


class AuthorizationResponse : public ServerResponse
{
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
        RequiredFillCaptcha,
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
    AuthorizationResponse();


    QString oauthToken() const;

    AuthorizationError error() const;
    QString errorDescriprion() const;

    QUrl captchaUrl() const;
    void parseResponse(const QByteArray&) override;

private:
    void parseError(const QVariantHash&) override;
    void parseContent(const QVariant&) override;

private:
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
