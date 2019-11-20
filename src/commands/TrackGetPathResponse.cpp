#include "TrackGetPathResponse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QXmlStreamReader>

namespace ymlcpp {
namespace server_access {

TrackGetPathResponse::TrackGetPathResponse() :
    ServerResponse (AppResponseType::TrackPathResponse)
{
}

TrackGetPathResponse::~TrackGetPathResponse()
{
}

TrackPathDescription TrackGetPathResponse::pathDescription() const
{
    return _pathDescription;
}

void TrackGetPathResponse::parseXml(const QByteArray& rawXml)
{
    QXmlStreamReader xml(rawXml);

    while(!xml.atEnd() && !xml.hasError()){
        xml.readNext();
        if(xml.isStartElement() && xml.name() == "host"){
            xml.readNext();
            _pathDescription.host = xml.text().toString();
            continue;
        }
        else if(xml.isStartElement() && xml.name() == "path"){
            xml.readNext();
            _pathDescription.path = xml.text().toString();
            continue;
        }
        else if(xml.isStartElement() && xml.name() == "ts"){
            xml.readNext();
            _pathDescription.ts = xml.text().toString();
            continue;
        }
        else if(xml.isStartElement() && xml.name() == "region"){
            xml.readNext();
            _pathDescription.region = xml.text().toInt();
            continue;
        }
        else if(xml.isStartElement() && xml.name() == "s"){
            xml.readNext();
            _pathDescription.s = xml.text().toString();
            continue;
        }
    }
}

void TrackGetPathResponse::parseResponse(const QByteArray& data)
{
    auto jsonDoc = QJsonDocument::fromJson(data);
    if(data.contains("html"))
        _respStatus = ResponseResult::Error;
    else
    {
        _respStatus = ResponseResult::Succes;
        parseXml(data);
    }
}

void TrackGetPathResponse::parseContent(const QVariant& data)
{}

}
}
