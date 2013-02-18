#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H
#include <QWidget>
#include <QGridLayout>
#include <QButtonGroup>
#include <QString>
#include "puzzlemodel.h"
#include "tile.h"
#include <cstdlib>
#include <ctime>
// debug
#include <QDebug>
//

class PuzzleView : public QWidget
{
	Q_OBJECT
private:
	PuzzleModel *m_Model;
	QGridLayout *m_Layout;
	QButtonGroup *m_Buttons;
public:
	explicit PuzzleView(PuzzleModel *pm,  QWidget *parent = 0);
	void refresh(void);
	void tryToSlide(QAbstractButton * button);
	
};

#endif // PUZZLEVIEW_H
