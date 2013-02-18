#ifndef PUZZLEMODEL_H
#define PUZZLEMODEL_H
#include <QObject>
#include <QList>

class PuzzleModel : public QObject
{
	Q_OBJECT
private:
	QList<int> m_Positions;
	int m_Rows;
	int m_Cols;

public:
	explicit PuzzleModel(QObject *parent = 0);
	int value(int r, int c);
	bool slide(int tilenum);
	bool neighbouring(int r, int c);
	
signals:
	void grideChanged(void);

public slots:
	
};

#endif // PUZZLEMODEL_H
