#include "AuthorizationResponse.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QMap>

namespace ymlcpp {
namespace server_access {

const AuthorizationResponse::ErrorsMap AuthorizationResponse::_errors {
    {"authorizatio_pending",           AuthorizationError::AuthorizationPending},
    {"bad_verification_code",          AuthorizationError::BadVerificationCode},
    {"invalid_client",                 AuthorizationError::InvalidClient},
    {"invalid_grant",                  AuthorizationError::InvalidGrant},
    {"invalid_request",                AuthorizationError::InvalidRequest},
    {"invalid_scope",                  AuthorizationError::InvalidScope},
    {"unauthorized_client",            AuthorizationError::UnauthorizedClient},
    {"unsupported_grant_type",         AuthorizationError::UnsupportedGrantType},
    {"Basic auth required",            AuthorizationError::BasicAuthRequired},
    {"Malformed Authorization header", AuthorizationError::MalformedAuthorization}
};

const AuthorizationResponse::FieldsMap AuthorizationResponse::_fields {
    {ResponseFields::AccessToken, "access_token"},
    {ResponseFields::TokenType, "token_type"},
    {ResponseFields::Error, "error"},
    {ResponseFields::ErrorDescription, "error_description"}
};

AuthorizationResponse::AuthorizationResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::AuthorizationResponse)
{
    parseResponse(data);
}

void AuthorizationResponse::parseResponse(const QByteArray& data)
{
    QJsonDocument document = QJsonDocument::fromJson(data);

    auto jsonObject = document.object();

    if(jsonObject.find(_fields[ResponseFields::Error]) != jsonObject.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(jsonObject);
    }
    else if(jsonObject.find(_fields[ResponseFields::AccessToken]) != jsonObject.end())
    {
        _respStatus = ResponseResult::Succes;
        _oauthToken = jsonObject.find(_fields[ResponseFields::AccessToken]).value().toString();
    }
    else
    {
        _respStatus = ResponseResult::Error;
        _error = AuthorizationError::RequiredFillCaptcha;
        // TODO: implement captcha handler later
    }
}

void AuthorizationResponse::parseError(const QJsonObject& object)
{
    auto errorStr = object.find(_fields[ResponseFields::Error]).value().toString();
    auto errorDescriptionIter = object.find(_fields[ResponseFields::ErrorDescription]);

    _error = _errors.contains(errorStr) ? _errors[errorStr] : AuthorizationError::UnknownError;
    _errorDescription = errorDescriptionIter != object.end() ? errorDescriptionIter.value().toString() : "";
}

ResponseResult AuthorizationResponse::status() const
{
    return _respStatus;
}


QString AuthorizationResponse::oauthToken() const
{
    return _oauthToken;
}

AuthorizationResponse::AuthorizationError AuthorizationResponse::error() const
{
    return _error;
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
