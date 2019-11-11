#include "TrackDownloadResponse.h"

namespace ymlcpp {
namespace server_access {

TrackDownloadResponse::TrackDownloadResponse() :
    ServerResponse (AppResponseType::TrackDownloadResponse)
{}

TrackDownloadResponse::~TrackDownloadResponse()
{}

void TrackDownloadResponse::parseResponse(const QByteArray& data)
{
    QString isHtmlError = QString(data.left(6));
    if(!isHtmlError.contains("<html>"))
    {
        _result = data;
        _respStatus = ResponseResult::Succes;
    }
    else
        _respStatus = ResponseResult::Error;

}

void TrackDownloadResponse::parseContent(const QVariant&)
{}

QByteArray TrackDownloadResponse::binaryTrack() const
{
    return _result;
}

}
}
