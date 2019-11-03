#ifndef TRACKGETPATHRESPONSE_H
#define TRACKGETPATHRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"

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

class TrackGetPathResponse : public ServerResponse
{
public:
    TrackGetPathResponse();
    ~TrackGetPathResponse() override;

    PathDescription pathDescription() const;
    void parseResponse(const QByteArray&) override;

private:
    void parseContent(const QVariant&) override;
    void parseXml(const QByteArray&);

private:
    PathDescription _pathDescription;
};

}
}

#endif // TRACKGETPATHRESPONSE_H
