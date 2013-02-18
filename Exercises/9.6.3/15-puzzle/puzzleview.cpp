#include "puzzleview.h"

PuzzleView::PuzzleView(PuzzleModel *pm, QWidget *parent) :
	QWidget(parent), m_Model(pm), \
	m_Buttons(new QButtonGroup), \
	m_Layout(new QGridLayout)
{
	const int tileN = 15;

	// create buttons
	Tile *newTile;
	for (int i = 0;  i < tileN; ++i)
	{
		newTile = new Tile(i); // parent set by layout
		newTile->setText(QString("%1").arg(i+1));
		newTile->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		m_Buttons->addButton(newTile, i); // this is crashing
	}

	// connect click() signal
	for (int i = 0; i < tileN; ++i)
	{
		//		connect(m_Buttons->button(i), SIGNAL(clicked()), \
		//				m_Model, SIGNAL(gridChanged() ) );
	}

	int i = 0;
	for (int j = 0; j < 4; ++j)
	{
		for (int k =0; k < 4; ++k)
		{
			m_Layout->addWidget(m_Buttons->button(i), j, k);
			++i;
			if ( i >= tileN)
				 break;
		}
	}

	m_Buttons->connect(m_Buttons, SIGNAL(m_Buttons->buttonClicked(0)), m_Model, SIGNAL(grideChanged()));


	setLayout(m_Layout);
}

void PuzzleView::refresh(void)
{
	srand(time(0));
}

void PuzzleView::tryToSlide(QAbstractButton * button)
{
	button = button; //TODO imeplementation

}
//qDebug() << endl << "Hello!" << endl;
