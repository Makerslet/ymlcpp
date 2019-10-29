#include "TracksInforesponse.h"
#include "../../common_and_base/parsers/TrackDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>


namespace ymlcpp {
namespace server_access {

TracksInfoResponse::TracksInfoResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::ContentInfoResponse)
{
    parseResponse(data);
}

TracksInfoResponse::~TracksInfoResponse()
{}

QList<TrackDescription> TracksInfoResponse::tracksDescription() const
{
    return _tracks;
}

ErrorInfo TracksInfoResponse::errorInfo() const
{
    return _errInfo;
}

void TracksInfoResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        for(auto track : resultFieldIter->toList())
            _tracks.push_back(
                        TrackDescriptionParser::parseTrackDescription(
                            track.toHash()));
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
    {
        // unknown error
        _respStatus = ResponseResult::Error;
    }
}

ResponseResult TracksInfoResponse::status() const
{
    return _respStatus;
}

void TracksInfoResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
