#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QDate>
#include <QStringList>
#include <QDebug>

class Film  // abstract base class
{
private:
	QString m_FilmID;
	QString m_Title;
	QString m_Director;
	QString m_FilmLength;
	QDate m_ReleaseDate;

public:
	Film(QString id, QString title, QString dir, QString length, QDate relDate);
	Film(QStringList & propList);

	virtual const QString toString(bool labeled, QString sepChar) const = 0;
};

class Educational : public Film
{
public:	// enum member
	enum GradeLevel {Grade1, Grade2};

private:
	QString m_Subject;
	GradeLevel m_GradeLevel;

public:
	Educational(QString id, QString title, QString dir,
				QString length, QDate relDate, GradeLevel glv);
	Educational(QStringList & propList);
};

class Entertainment : public Film
{
public:
	enum FilmTypes {Action, Comedy, SciFi};
	enum MPAARatings {G, PG, PG13};

private:
	FilmTypes m_Type;
	MPAARatings m_Rating;

public:
	Entertainment(QString id, QString title, QString dir,
				  QString length, QDate relDate,
				  FilmTypes fty,  MPAARatings rtng);
	Entertainment(QStringList & propList);

};

#endif // FILM_H
