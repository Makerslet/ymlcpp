#ifndef TRACKGETPATHRESPONSE_H
#define TRACKGETPATHRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"
#include "common_and_base/common_structures/TrackPathDescription.h"

#include <QVariant>

namespace ymlcpp {
namespace server_access {

class TrackGetPathResponse : public ServerResponse
{
public:
    TrackGetPathResponse();
    ~TrackGetPathResponse() override;

    TrackPathDescription pathDescription() const;
    void parseResponse(const QByteArray&) override;

private:
    void parseContent(const QVariant&) override;
    void parseXml(const QByteArray&);

private:
    TrackPathDescription _pathDescription;
};

}
}

#endif // TRACKGETPATHRESPONSE_H
