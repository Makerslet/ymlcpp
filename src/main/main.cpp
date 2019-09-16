#include <QCoreApplication>
#include "ServerAccessManager.h"
#include "commands/AuthorizationRequest.h"

int main(int argc, char** argv) {

    QCoreApplication app(argc, argv);


    ymlcpp::server_access::ServerAccessManager sam;
    auto reqPointer = QSharedPointer<ymlcpp::server_access::AuthorizationRequest>::create(
                "yamustest@yandex.ru", "123456789a");


    sam.sendRequest(reqPointer);


	return app.exec();
}
