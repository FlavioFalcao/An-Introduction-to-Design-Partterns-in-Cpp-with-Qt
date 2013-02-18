#ifndef TILE_H
#define TILE_H
#include <QPushButton>

class Tile : public QPushButton
{
	Q_OBJECT
private:
	int m_Number;

public:
	explicit Tile(int tileNumber, QWidget *parent = 0);

signals:
	
public slots:
	
};

#endif // TILE_H
