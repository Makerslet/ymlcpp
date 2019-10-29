#ifndef SEARCHRESPONSE_H
#define SEARCHRESPONSE_H

#include "common_and_base/base_requests_responses/IServerResponse.h"
#include "common_and_base/common_structures/TrackDescription.h"
#include "common_and_base/common_structures/AlbumDescription.h"
#include "common_and_base/common_structures/ArtistDescription.h"
#include "common_and_base/common_structures/PlaylistDescription.h"

#include <QVariant>
#include <QVector>

namespace ymlcpp {
namespace server_access {

struct SearchResult
{
    void* best; // будет вариативное поле для лучшего результата
    QVector<TrackDescription> tracks;
    QVector<AlbumDescription> albums;
    QVector<PlaylistInfo> playlists;
    QVector<ArtistDescription> artists;
};

class SearchResponse : public  IServerResponse
{
public:
    SearchResponse(const QByteArray&);
    ~SearchResponse() override;

    ResponseResult status() const override;
    ErrorInfo errorInfo() const;
    SearchResult description() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseTracks(const QVariantHash&);
    void parseAlbums(const QVariantHash&);
    void parsePlaylists(const QVariantHash&);
    void parseArtists(const QVariantHash&);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    SearchResult _result;
    ErrorInfo _errInfo;
};

}
}

#endif // SEARCHRESPONSE_H
