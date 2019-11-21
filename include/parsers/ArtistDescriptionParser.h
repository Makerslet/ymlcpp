#ifndef ARTISTDESCRIPTIONPARSER_H
#define ARTISTDESCRIPTIONPARSER_H

#include "commands/common_and_base/common_structures/ArtistDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class ArtistDescriptionParser
{
public:
    static ArtistDescription    parseArtistDescription(const QVariantHash&);
    static ArtistCover          parseArtistCover(const QVariantHash&);
    static ArtistCounts         parseArtistCounts(const QVariantHash&);
    static ArtistRaitings       parseArtistRaitings(const QVariantHash&);
    static ArtistLink           parseArtistLink(const QVariantHash&);
};

}
}

#endif // ARTISTDESCRIPTIONPARSER_H
