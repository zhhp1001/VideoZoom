#include "VideoZoom.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoZoom w;
	w.show();
	return a.exec();
}
