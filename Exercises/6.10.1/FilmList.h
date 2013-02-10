#ifndef FILMLIST_H
#define FILMLIST_H

#include <QList>
#include "Film.h"

class FilmList : public QList<Film*>
{
public:
	FilmList();
};

#endif // FILMLIST_H
