#include "ServerPostRequest.h"


namespace ymlcpp {
namespace server_access {

ServerPostRequest::ServerPostRequest(AppRequestType appReqType) :
    _appReqType(appReqType)
{

}

ServerPostRequest::~ServerPostRequest()
{

}

ServerRequestType ServerPostRequest::serverRequestType() const
{
    return _serverReqType;
}

AppRequestType ServerPostRequest::appRequestType() const
{
    return _appReqType;
}


QByteArray ServerPostRequest::toApiFormat(const QHash<QString, QString>& data) const
{
    QByteArray result;

    for(auto it = data.begin(); it != data.end(); ++it)
        result.append(QString("%1=%2&").arg(it.key()).arg(it.value()));

    result.remove(result.length() - 1, 1);

    return result;
}

QByteArray ServerPostRequest::toApiFormat(const QString& base, const QStringList& ids) const
{
    QByteArray result;

    for(auto id : ids)
        result.append(QString("%1=%2&").arg(base).arg(id));

    result.remove(result.length() - 1, 1);

    return result;
}

QByteArray ServerPostRequest::toApiFormat(const QString& base, const QString& addInfo, const QStringList& ids) const
{
    QByteArray result;

    for(auto id : ids)
        result.append(QString("%1=True&%2=%3&").arg(addInfo).arg(base).arg(id));

    result.remove(result.length() - 1, 1);

    return result;
}

}
}
