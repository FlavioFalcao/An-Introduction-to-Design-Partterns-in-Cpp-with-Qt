#ifndef FILMLIST_H
#define FILMLIST_H
#include <QList>
#include <QString>
#include "Film.h"

class FilmList : public QList<Film*>
{
private:
	FilmList(const FilmList & fl);
	FilmList operator=(const FilmList & fl);

	// remove all deleted Film* off the list.
	void clearDeleted(void);

public:
	FilmList();

	const QString toString(void) const;
	const Film * const findFilm(const QString & id) const;
	const QString getID(const QString & title) const;
	void addFilm(Film * & film);
	void removeFilm(const QString & filmID);

};

#endif // FILMLIST_H
