#ifndef TRACKVARIANTSRESPONSE_H
#define TRACKVARIANTSRESPONSE_H

#include "common_and_base/base_requests_responses/ServerResponse.h"

#include <QVector>
#include <QVariant>
#include <QUrl>

namespace ymlcpp {
namespace server_access {

enum class TrackCodec
{
    mp3,
    aac,
    unknown
};

struct TrackVariant
{
    TrackCodec codec;
    uint bitrate;
    bool gain;
    bool preview;
    QUrl trackXmlUrl;
};

class TrackVariantsResponse : public ServerResponse
{
public:
    TrackVariantsResponse();
    ~TrackVariantsResponse() override;

    QVector<TrackVariant> trackVariants() const;

private:
    void parseContent(const QVariant&) override;
    void parseTrackVariant(const QVariantHash&);

private:
    QVector<TrackVariant> _trackVariants;
};

}
}

#endif // TRACKVARIANTSRESPONSE_H
