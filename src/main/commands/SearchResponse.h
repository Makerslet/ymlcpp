#ifndef SEARCHRESPONSE_H
#define SEARCHRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"
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

class SearchResponse : public  ServerResponse
{
public:
    SearchResponse();
    ~SearchResponse() override;

    SearchResult description() const;

private:
    void parseContent(const QVariant&) override;
    void parseTracks(const QVariantHash&);
    void parseAlbums(const QVariantHash&);
    void parsePlaylists(const QVariantHash&);
    void parseArtists(const QVariantHash&);

private:
    SearchResult _result;
};

}
}

#endif // SEARCHRESPONSE_H
