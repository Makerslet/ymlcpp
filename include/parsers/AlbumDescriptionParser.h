#ifndef ALBUMDESCRIPTIONPARSER_H
#define ALBUMDESCRIPTIONPARSER_H

#include "commands/common_and_base/common_structures/AlbumDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class AlbumDescriptionParser
{
public:
    static AlbumDescription     parseAlbumDescription(const QVariantHash&);
    static BuyAlbumDescription  parseBuyAlbumDescription(const QVariantHash&);
    static LabelDescription     parseLabelDescription(const QVariantHash&);
    static BestDescription      parseBestDescription(const QVariantHash&);
};

}
}

#endif // ALBUMDESCRIPTIONPARSER_H
