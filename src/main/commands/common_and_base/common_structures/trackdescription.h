#ifndef TRACKDESCRIPTION_H
#define TRACKDESCRIPTION_H

#include "ArtistDescription.h"
#include "AlbumDescription.h"

#include <QString>

namespace ymlcpp {
namespace server_access {

struct MajorDescription
{
    uint id;
    QString name;
};

struct NormalizationDescription
{
    double gain;
    uint peak;
};

struct TrackDescription
{
    QString id;
    QString realId;
    QString title;
    MajorDescription major;
    bool available;
    bool availableForPremiumUsers;
    bool availableFullWithoutPermission;
    uint durationMs;
    QString storageDir;
    uint fileSize;
    NormalizationDescription normalization;
    uint previewDurationMs;
    QList<ArtistDescription> artists;
    QList<AlbumDescription> albums;
    QString coverUri;
    QString ogImage;
    bool lyricsAvailable;
    QString type;
};

}
}

#endif // TRACKDESCRIPTION_H
