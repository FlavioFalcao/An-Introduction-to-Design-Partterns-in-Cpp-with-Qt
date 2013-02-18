#include <QApplication>
#include "puzzlewindow.h"
// experiment
#include <QButtonGroup>
#include <QPushButton>
#include <QDebug>
//

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	PuzzleWindow pWin;
	pWin.show();

	return app.exec();
}
