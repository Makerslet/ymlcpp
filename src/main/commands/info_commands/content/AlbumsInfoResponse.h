#ifndef ALBUMSINFORESPONSE_H
#define ALBUMSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/IServerResponse.h"
#include "../../common_and_base/common_structures/AlbumDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {


class AlbumsInfoResponse : public IServerResponse
{
public:
    AlbumsInfoResponse(const QByteArray&);
    ~AlbumsInfoResponse() override;

    ResponseResult status() const override;
    QList<AlbumDescription> albumsDescription() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseContent(const QVariantHash&);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QList<AlbumDescription> _albums;
    ErrorInfo _errInfo;
};

}
}

#endif // ALBUMSINFORESPONSE_H
