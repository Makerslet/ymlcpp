#include "AlbumsInfoResponse.h"
#include "../../common_and_base/common_enums/AppResponseTypes.h"
#include "../../common_and_base/parsers/AlbumDescriptionParser.h"

#include <QJsonDocument>
#include <QJsonObject>

namespace ymlcpp {
namespace server_access {

AlbumsInfoResponse::AlbumsInfoResponse(const QByteArray& data) :
    IServerResponse(AppResponseType::ContentInfoResponse)
{
    parseResponse(data);
}

AlbumsInfoResponse::~AlbumsInfoResponse()
{}

void AlbumsInfoResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    auto jsonObject = jsonDoc.object();

    auto rootHash = jsonObject.toVariantHash();
    auto resultFieldIter = rootHash.find("result");
    auto errorFieldIter = rootHash.find("error");

    if(resultFieldIter != rootHash.end())
    {
        for(auto album : resultFieldIter->toList())
            _albums.push_back(
                        AlbumDescriptionParser::parseAlbumDescription(album.toHash()));
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

void AlbumsInfoResponse::parseError(const QVariantHash& errHash)
{
    _errInfo.name = errHash["name"].toString();
    _errInfo.message = errHash["message"].toString();
}

ResponseResult AlbumsInfoResponse::status() const
{
    return _respStatus;
}

QList<AlbumDescription> AlbumsInfoResponse::albumsDescription() const
{
    return _albums;
}

ErrorInfo AlbumsInfoResponse::errorInfo() const
{
    return _errInfo;
}

}
}
