#ifndef GETFEEDRESPONSE_H
#define GETFEEDRESPONSE_H

#include "common_and_base/base_requests_responses/IServerResponse.h"
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


class GetFeedResponse : public IServerResponse
{
public:
    GetFeedResponse(const QByteArray&);
    ~GetFeedResponse() override;

    ResponseResult status() const override;
    ErrorInfo errorInfo() const;
    QVector<PlaylistWithTracks> description() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QVector<PlaylistWithTracks> _playlists;
    ErrorInfo _errInfo;
};

}
}

#endif // GETFEEDRESPONSE_H
