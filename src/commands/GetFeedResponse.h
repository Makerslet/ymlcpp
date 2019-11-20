#ifndef GETFEEDRESPONSE_H
#define GETFEEDRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"
#include "common_and_base/common_structures/PlaylistDescription.h"

#include <QVariant>
#include <QVector>

namespace ymlcpp {
namespace server_access {

struct PlaylistWithTracks
{
    QString type;
    bool ready;
    PlaylistInfo description;
    QVector<uint> tracks;
};


class GetFeedResponse : public ServerResponse
{
public:
    GetFeedResponse();
    ~GetFeedResponse() override;

    QVector<PlaylistWithTracks> description() const;

private:
    void parseContent(const QVariant&) override;

private:
    QVector<PlaylistWithTracks> _playlists;
};

}
}

#endif // GETFEEDRESPONSE_H
