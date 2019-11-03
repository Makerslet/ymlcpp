#ifndef ARTISTSINFORESPONSE_H
#define ARTISTSINFORESPONSE_H

#include "../../common_and_base/base_requests_responses/ServerResponse.h"
#include "../../common_and_base/common_structures/ArtistDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {


class ArtistsInfoResponse : public ServerResponse
{
public:
    ArtistsInfoResponse();
    ~ArtistsInfoResponse() override;

    QList<ArtistDescription> artistsDescription() const;

private:
    void parseContent(const QVariant&) override;

private:
    QList<ArtistDescription> _artists;
};

}
}

#endif // ARTISTSINFORESPONSE_H
