#include <QCoreApplication>
#include "ClientCodeMock.h"

int main(int argc, char** argv) {

    QCoreApplication app(argc, argv);

    ClientCodeMock mock;

	return app.exec();
}
