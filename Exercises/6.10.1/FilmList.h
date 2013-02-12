#ifndef FILMLIST_H
#define FILMLIST_H
#include <QList>
#include <QString>
#include "Film.h"
#include <QDebug>

class FilmList : public QList<Film*>
{
private:
	FilmList(const FilmList & fl);
	FilmList operator=(const FilmList & fl);

public:
	FilmList();

	const QString toString(void) const;
	Film * findFilm(const QString & id) const;
	const QString getID(const QString & title) const;
	void addFilm(Film * & film);
	void removeFilm(const QString & filmID);

};

#endif // FILMLIST_H
