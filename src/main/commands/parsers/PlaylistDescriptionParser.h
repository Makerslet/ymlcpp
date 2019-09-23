#ifndef PLAYLISTDESCRIPTIONPARSER_H
#define PLAYLISTDESCRIPTIONPARSER_H

#include "../common_structures/PlaylistDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class PlaylistDescriptionParser
{
public:
    static PlaylistDescription parsePlaylistDescription(const QVariantHash&);
    static PlaylistInfo parsePlaylistInfo(const QVariantHash&);
    static PlaylistOwner parsePlaylistOwner(const QVariantHash&);
    static PlaylistCover parsePlaylistCover(const QVariantHash&);
};

}
}

#endif // PLAYLISTDESCRIPTIONPARSER_H
