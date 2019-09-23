#ifndef ARTISTDESCRIPTIONPARSER_H
#define ARTISTDESCRIPTIONPARSER_H

#include "../common_structures/ArtistDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class ArtistDescriptionParser
{
public:
    static ArtistDescription    parseArtistDescriptionJson(const QVariantHash&);
    static ArtistCover          parseArtistCoverJSon(const QVariantHash&);
    static ArtistCounts         parseArtistCountsJSon(const QVariantHash&);
    static ArtistRaitings       parseArtistRaitings(const QVariantHash&);
    static ArtistLink           parseArtistLink(const QVariantHash&);
};

}
}

#endif // ARTISTDESCRIPTIONPARSER_H
