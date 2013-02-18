#include "puzzlewindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <cstdlib>

PuzzleWindow::PuzzleWindow(QWidget *parent) :
	QMainWindow(parent)
{


	QHBoxLayout *hbl = new QHBoxLayout;
	QPushButton *exitButton = new QPushButton("Exit");
	hbl->addWidget(exitButton);
	hbl->addWidget(new QPushButton("second button"));
	exitButton->connect(exitButton, SIGNAL(clicked()), nullptr, exit(EXIT_FAILURE));
	qDebug() << "create widget";
	QWidget *widget = new QWidget;
	widget->setLayout(hbl);

	setCentralWidget(widget);

	qDebug() << "after setCentralWidget widget";

	setWindowTitle("15 Puzzle");
}
