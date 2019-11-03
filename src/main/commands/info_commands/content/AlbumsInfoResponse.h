#ifndef ALBUMSINFORESPONSE_H
#define ALBUMSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/ServerResponse.h"
#include "../../common_and_base/common_structures/AlbumDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {


class AlbumsInfoResponse : public ServerResponse
{
public:
    AlbumsInfoResponse();
    ~AlbumsInfoResponse() override;

    QList<AlbumDescription> albumsDescription() const;

private:
    void parseContent(const QVariant&) override;

private:
    QList<AlbumDescription> _albums;
};

}
}

#endif // ALBUMSINFORESPONSE_H
