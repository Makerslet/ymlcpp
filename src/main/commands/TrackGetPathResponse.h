#ifndef TRACKGETPATHRESPONSE_H
#define TRACKGETPATHRESPONSE_H

#include "headers/IServerResponse.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

struct PathDescription
{
    QString host;
    QString path;
    QString ts;
    QString s;
    int region;
};

class TrackGetPathResponse : public IServerResponse
{
public:
    TrackGetPathResponse(const QByteArray& data);
    ~TrackGetPathResponse() override;

    ResponseResult status() const override;
    PathDescription pathDescription() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseXml(const QByteArray&);

private:
    ResponseResult _respStatus;
    PathDescription _pathDescription;
    ErrorInfo _errInfo;

};

}
}

#endif // TRACKGETPATHRESPONSE_H
