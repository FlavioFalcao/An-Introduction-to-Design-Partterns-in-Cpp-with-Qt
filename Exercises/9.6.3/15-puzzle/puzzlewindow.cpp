#include "puzzlewindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <cstdlib>
#include "puzzleview.h"
#include "puzzlemodel.h"

PuzzleWindow::PuzzleWindow(QWidget *parent) :
	QMainWindow(parent)
{
	// shuffle button
	QPushButton *shuffleButton = new QPushButton("Shuffle");
	shuffleButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	// quit button
	QPushButton *exitButton = new QPushButton("quit");
	exitButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	exitButton->connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));

	// control buttons
	QVBoxLayout *buttons = new QVBoxLayout;
	buttons->addStretch(2);
	buttons->addWidget(shuffleButton);
	buttons->addWidget(exitButton);

	// game view
	PuzzleView *pView = new PuzzleView(new PuzzleModel());

	// central layout
	QHBoxLayout *puzzle = new QHBoxLayout();
	puzzle->addWidget(pView);
	puzzle->addLayout(buttons);

	// central widget
	QWidget *cWidget = new QWidget();
	cWidget->setLayout(puzzle);

	this->setCentralWidget(cWidget);

	setWindowTitle("15 Puzzle");
}
