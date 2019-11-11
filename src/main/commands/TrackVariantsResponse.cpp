#include "TrackVariantsResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

namespace ymlcpp {
namespace server_access {

TrackVariantsResponse::TrackVariantsResponse() :
    ServerResponse (AppResponseType::TrackVariantsResponse)
{}

TrackVariantsResponse::~TrackVariantsResponse()
{}


QVector<TrackVariant> TrackVariantsResponse::trackVariants() const
{
    return _trackVariants;
}

void TrackVariantsResponse::parseContent(const QVariant& data)
{
    for(auto track : data.toList())
        parseTrackVariant(track.toHash());
}

void TrackVariantsResponse::parseTrackVariant(const QVariantHash& trackHash)
{
    TrackVariant variant;
    QString codec = trackHash["codec"].toString();

    if(codec == "mp3")
        variant.codec = TrackCodec::mp3;
    else if(codec == "aac")
        variant.codec = TrackCodec::aac;
    else
        variant.codec = TrackCodec::unknown;

    variant.bitrate = trackHash["bitrateInKbps"].toUInt();
    variant.gain = trackHash["gain"].toBool();
    variant.preview = trackHash["preview"].toBool();
    variant.trackXmlUrl = trackHash["downloadInfoUrl"].toUrl();

    _trackVariants.push_back(variant);
}

}
}
