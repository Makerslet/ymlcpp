#ifndef TRACKDESCRIPTIONPARSER_H
#define TRACKDESCRIPTIONPARSER_H

#include "../common_structures/TrackDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class TrackDescriptionParser
{
public:
    static TrackDescription parseTrackDescription(const QVariantHash&);
    static MajorDescription parseMajorDescription(const QVariantHash&);
    static NormalizationDescription parseNormalizationDescription(const QVariantHash&);
};

}
}
#endif // TRACKDESCRIPTIONPARSER_H
