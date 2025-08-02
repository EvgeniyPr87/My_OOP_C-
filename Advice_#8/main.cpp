// #8 Проектируйте свои классы так, чтобы их было сложно использовать неправильно
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;// стандартный поток ошибок

class Day
{
	int day;
public:
	//функция проверяет вхождение в диапазон даты
	bool is_valid()const
	{
		return day > 0 && day < 32;
	}
public:
	//класс неверный день
	class InvalidDay {};
	// в конструкторе проверяем является дата верной
	explicit Day(int d):day(d) 
	{
		if (!is_valid())
		{
			throw InvalidDay();
		}
	}
	~Day() {};
	friend std::ostream& operator<<(std::ostream& os, const Day& d) {
		return os << d.day;
	}
};

enum  class Month
{
	Jan=1, Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec
};
std::ostream& operator<<(std::ostream& os, Month obj) {
	switch (obj) {
	case Month::Jan: return os << "January";
	case Month::Feb: return os << "February";
	case Month::Mar: return os << "March";
	case Month::Apr: return os << "April";
	case Month::May: return os << "May";
	case Month::Jun: return os << "June";
	case Month::Jul: return os << "July";
	case Month::Aug: return os << "August";
	case Month::Sep: return os << "September";
	case Month::Oct: return os << "October";
	case Month::Nov: return os << "November";
	case Month::Dec: return os << "December";
	default:return os << "Invalid Month";
	}
}

class Year
{
	int year;

public:
	bool is_valid()const
	{
		return year >= 0;
	}
	class InvalidYear : public std::runtime_error {
	public:
		InvalidYear(const std::string& msg = "Invalid Year value") : std::runtime_error(msg){}
	};
	explicit Year(int y):year(y){ 
		if (!is_valid()) {
			throw InvalidYear();
	}
	}
	~Year() {};
	friend std::ostream& operator<<(std::ostream& os, const Year& y) {
		return os << y.year;
	}
};

class Date
{
	Day day;
	Month month;
	Year year;

public:
	Date(Day d, Month m, Year y)
		:day(d)
		,month(m)
		,year(y)
	{

	}
	~Date() {};

	void print()const {
		cout << day << "/" << month << "/" << year << endl;
	}
};

void main(){
	setlocale(LC_ALL, " ");
	try
	{
		Date d1(Day(30), Month::Feb, Year(1987));
		d1.print();
		Date d2(Day(11), Month::Mar, Year(1987));
		d2.print();
	}
	catch (const Day::InvalidDay&) {
		cerr << "Error" << endl;
	}
	catch (const Year::InvalidYear&) {
		cerr << "Error" << endl;
	}
	catch (const std::exception& ) {
		cerr << "Error" << endl;
	}
	
	catch (...) {
		cerr << "Error" << endl;
	}
	
	
}