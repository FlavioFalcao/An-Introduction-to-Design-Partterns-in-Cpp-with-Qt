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

const Film * const FilmList::findFilm(const QString & id) const
{
	int listSize = this->size();
	for (int i = 0; i < listSize; ++i)
	{
		if ((*this)[i]->getID() == id)
		{
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
	unsigned listSize = this->size();
	for (int i = 0; i < static_cast<int>(listSize); ++i)
	{
		if ((*this)[i]->getID() == filmID)
		{
			delete (*this)[i];
			(*this)[i] = nullptr;
		}
	}
	this->clearDeleted();
}

void FilmList::clearDeleted(void)
{
	while (this->removeOne(nullptr)) {}
}
