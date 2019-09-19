#include <QCoreApplication>
#include "ClientCodeMock.h"

int main(int argc, char** argv) {

    QCoreApplication app(argc, argv);

    ymlcpp::server_access::ClientCodeMock mock;

	return app.exec();
}
