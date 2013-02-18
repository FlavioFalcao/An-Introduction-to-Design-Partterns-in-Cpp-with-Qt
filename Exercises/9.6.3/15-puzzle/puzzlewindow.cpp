#include "puzzlewindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

PuzzleWindow::PuzzleWindow(QWidget *parent) :
	QMainWindow(parent)
{
	QPushButton exitButton("Exit");
	//exitButton.connect(&exitButton, SIGNAL(clicked()), nullptr, SLOT(exit()));
	QHBoxLayout hbl;
	QPushButton button2("second button");
	hbl.addWidget(&exitButton);
	hbl.addWidget(&button2);

	qDebug() << "create widget";
	QWidget widget;
	widget.setLayout(&hbl);

	setCentralWidget(&widget);

	qDebug() << "after setCentralWidget widget";

	setWindowTitle("15 Puzzle");
}
