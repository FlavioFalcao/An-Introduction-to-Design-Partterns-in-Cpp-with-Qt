#include "FilmList.h"

FilmList::FilmList()
{
}

const QString FilmList::toString(void) const
{
	QString str("");
	int listSize = this->size();
	for (int i = 0; i < listSize; ++i)
	{
		str += QString("%1%2").arg((*this)[i]->toString(true)).arg("\n");
	}
	return str;
}

Film * FilmList::findFilm(const QString & id) const
{
	int listSize = this->size();
	for (int i = 0; i < listSize; ++i)
	{
		if ((*this)[i]->getID() == id)
		{
			//qDebug() << "findFilm() found" << endl;
			return (*this)[i];
		}
	}
	return nullptr; // return nullptr if unscuccessful
}

const QString FilmList::getID(const QString & title) const
{
	int listSize = this->size();
	for (int i = 0; i < listSize; ++i)
	{
		if ((*this)[i]->getTitle() == title)
		{
			return (*this)[i]->getID();
		}
	}
	return QString("No such title.");
}

void FilmList::addFilm(Film * & film)
{
	this->append(film);
}


void FilmList::removeFilm(const QString & filmID)
{
	Film * pfilm;
	while (pfilm = findFilm(filmID))
	{
		//qDebug() << "removeFilm() removing" << endl;
		removeAll(pfilm);
	}
}
