#ifndef SERVERRESPONSE_H
#define SERVERRESPONSE_H

#include "IServerResponse.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class ServerResponse : public IServerResponse
{
public:
    ServerResponse(AppResponseType);
    ~ServerResponse() override;
    AppResponseType appResponseType() const override;
    ResponseResult status() const override;
    ErrorInfo errInfo() const override;
    void parseResponse(const QByteArray&) override;

protected:
    virtual void parseError(const QVariantHash&);
    virtual void parseContent(const QVariant&) = 0;

protected:
    AppResponseType _respType;
    ResponseResult _respStatus;
    ErrorInfo _errInfo;
};

}
}

#endif // SERVERRESPONSE_H
