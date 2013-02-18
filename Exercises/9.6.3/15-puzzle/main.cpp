#include <QApplication>
#include "puzzlewindow.h"


int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	PuzzleWindow pWin;
	pWin.show();

	return app.exec();
}
