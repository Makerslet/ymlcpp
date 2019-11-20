#include "TracksInforesponse.h"
#include "../../common_and_base/parsers/TrackDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>


namespace ymlcpp {
namespace server_access {

TracksInfoResponse::TracksInfoResponse() :
    ServerResponse (AppResponseType::ContentInfoResponse)
{}

TracksInfoResponse::~TracksInfoResponse()
{}

QList<TrackDescription> TracksInfoResponse::tracksDescription() const
{
    return _tracks;
}


void TracksInfoResponse::parseContent(const QVariant& data)
{
    for(auto track : data.toList())
        _tracks.push_back(TrackDescriptionParser::parseTrackDescription(
                        track.toHash()));
}

}
}
