#ifndef TRACKVARIANTSRESPONSE_H
#define TRACKVARIANTSRESPONSE_H

#include "common_and_base/base_requests_responses/IServerResponse.h"

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

class TrackVariantsResponse : public IServerResponse
{
public:
    TrackVariantsResponse(const QByteArray&);
    ~TrackVariantsResponse() override;

    ResponseResult status() const override;
    QVector<TrackVariant> trackVariants() const;
    ErrorInfo errorInfo() const;

private:
    void parseResponse(const QByteArray&) override;
    void parseResult(const QVariantList &);
    void parseTrackVariant(const QVariantHash&);
    void parseError(const QVariantHash&);

private:
    ResponseResult _respStatus;
    QVector<TrackVariant> _trackVariants;
    ErrorInfo _errInfo;
};

}
}

#endif // TRACKVARIANTSRESPONSE_H
