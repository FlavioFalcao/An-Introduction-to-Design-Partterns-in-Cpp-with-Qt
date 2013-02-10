#include "Film.h"
//================================================
// Film class implementation
//================================================

// ctor
Film::Film(QString id, QString title, QString dir, QString length, QDate relDate)
	: m_FilmID(id), m_Title(title), m_Director(dir), m_FilmLength(length), m_ReleaseDate(relDate)
{}

// ctor
Film::Film(QStringList & propList)
{
	if (propList.empty()) // check for empty list
		return;
	int listSize = propList.size();
	if (listSize < 5)
		return;	// incorrect list size. no handle yet (TODO)
	m_FilmID = propList.takeFirst();
	m_Title = propList.takeFirst();
	m_Director = propList.takeFirst();
	m_FilmLength = propList.takeFirst();
	m_ReleaseDate = QDate::fromString(propList.takeFirst());
}

const QString Film::toString(bool labeled, QString sepChar) const
{

}

//================================================


//================================================
// Educational class implementation
//================================================

// ctor
Educational::Educational(QString id, QString title, QString dir,
						 QString length, QDate relDate, GradeLevel glv)
	: Film(id, title, dir, length, relDate), m_GradeLevel(glv)
{}

// ctor
Educational::Educational(QStringList &  propList)
	: Film(propList), m_GradeLevel(static_cast<GradeLevel>(propList.takeFirst().toInt()))
{}

//================================================


//================================================
//  Entertainment class implementation
//================================================


// ctor
Entertainment::Entertainment(QString id, QString title, QString dir,
							 QString length, QDate relDate, FilmTypes fty, MPAARatings rtng)
	: Film(id, title, dir, length, relDate), m_Type(fty), m_Rating(rtng)
{}

// ctor
Entertainment::Entertainment(QStringList &propList)
	: Film(propList), m_Type(static_cast<FilmTypes>(propList.takeFirst().toInt())),
	  m_Rating(static_cast<MPAARatings>(propList.takeFirst().toInt()))
{}

