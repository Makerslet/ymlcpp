#include "TrackVariantsResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>

#include <QDebug>

namespace ymlcpp {
namespace server_access {

TrackVariantsResponse::TrackVariantsResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::TrackVariantsResponse)
{
    parseResponse(data);
}

TrackVariantsResponse::~TrackVariantsResponse()
{

}

ResponseResult TrackVariantsResponse::status() const
{
    return _respStatus;
}

QVector<TrackVariant> TrackVariantsResponse::trackVariants() const
{
    return _trackVariants;
}

ErrorInfo TrackVariantsResponse::errorInfo() const
{
    return _errInfo;
}

void TrackVariantsResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Succes;
        parseResult(resultFieldIter.value().toList());
    }
    else if(errorFieldIter != rootHash.end())
    {
        _respStatus = ResponseResult::Error;
        parseError(errorFieldIter.value().toHash());
    }
    else
        _respStatus = ResponseResult::Error;
}

void TrackVariantsResponse::parseResult(const QVariantList& resultList)
{
    for(auto track : resultList)
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

void TrackVariantsResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

}
}
