#ifndef ARTISTSINFORESPONSE_H
#define ARTISTSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/IServerResponse.h"
#include "../../common_and_base/common_structures/ArtistDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {


class ArtistsInfoResponse : public IServerResponse
{
public:
    ArtistsInfoResponse(const QByteArray&);
    ~ArtistsInfoResponse() override;

    ResponseResult status() const override;
    QList<ArtistDescription> artistsDescription() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QList<ArtistDescription> _artists;
    ErrorInfo _errInfo;
};

}
}

#endif // ARTISTSINFORESPONSE_H
