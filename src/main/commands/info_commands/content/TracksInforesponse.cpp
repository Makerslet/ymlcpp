#include "TracksInforesponse.h"
#include <QDebug>


namespace ymlcpp {
namespace server_access {

TracksInfoResponse::TracksInfoResponse(const QByteArray& data) :
    IServerResponse (AppResponseType::ContentInfoResponse)
{
    qDebug() << data;
}

TracksInfoResponse::~TracksInfoResponse()
{}

void TracksInfoResponse::parseResponse(const QByteArray& data)
{

}

ResponseResult TracksInfoResponse::status() const
{
    return _respResult;
}

}
}
