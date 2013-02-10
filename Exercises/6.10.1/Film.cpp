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
	if (labeled)
		return QString("%2%1%3%1%4%1%5%1%6")
				.arg(sepChar)
				.arg("Film ID: " + m_FilmID)
				.arg("Film title: " + m_Title)
				.arg("Director: " + m_Director)
				.arg("Length: " + m_FilmLength)
				.arg("Release date: " + m_ReleaseDate.toString());
	else
		return QString("%2%1%3%1%4%1%5%").arg(sepChar)
				.arg(m_FilmID).arg(m_Title).arg(m_Director)
				.arg(m_FilmLength).arg(m_ReleaseDate.toString());
}

//================================================


//================================================
// Educational class implementation
//================================================

// ctor
Educational::Educational(QString id, QString title, QString dir,
						 QString length, QDate relDate,  QString subject, GradeLevel glv)
	: Film(id, title, dir, length, relDate),m_Subject(subject), m_GradeLevel(glv)
{}

// ctor
Educational::Educational(QStringList &  propList)
	: Film(propList), m_Subject(propList.takeFirst())
	, m_GradeLevel(static_cast<GradeLevel>(propList.takeFirst().toInt()))
{}

const QString Educational::toString(bool labeled, QString sepChar) const
{
	if (labeled)
		return Film::toString(labeled, sepChar) \
				+ 	QString("%1%2%1%3").arg(sepChar) \
				.arg("Subject: " + m_Subject) \
				.arg("Grade level: " + getGradeLevel()); //?
	else
		return Film::toString(labeled, sepChar) \
				+ 	QString("%1%2%1%3").arg(sepChar) \
				.arg(m_Subject) \
				.arg(getGradeLevel()); //?
}

const QString Educational::getGradeLevel(void) const
{
	switch(m_GradeLevel)
	{
	case Grade1:
		return "Grade1";
	case Grade2:
		return "Grade2";
	default:
		return "?";
	}
}

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

const QString Entertainment::toString(bool labeled, QString sepChar) const
{
	if (labeled)
		return Film::toString(labeled, sepChar) \
				+ 	QString("%1%2%1%3").arg(sepChar) \
				.arg("Film type: " + getType()) \
				.arg("Rating: " + getRating()); //?
	else
		return Film::toString(labeled, sepChar) \
				+ 	QString("%1%2%1%3").arg(sepChar) \
				.arg(getType()) \
				.arg(getRating()); //?
}

const QString Entertainment::getType(void) const
{
	switch(m_Type)
	{
	case Action:
		return "Action";
	case Comedy:
		return "Comedy";
	case SciFi:
		return "SciFi";
	default:
		return "Unknown";
	}
}

const QString Entertainment::getRating(void) const
{
	switch(m_Rating)
	{
	case G:
		return "G";
	case PG:
		return "PG";
	case PG13:
		return "PG-13";
	default:
		return "?";
	}
}

//================================================
