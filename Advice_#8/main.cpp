// #8 Проектируйте свои классы так, чтобы их было сложно использовать неправильно
// #3 Предпочитайте удаление фунций закрытым и неопределенным

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;// стандартный поток ошибок

//функция проверяет является ли год високосным
bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}



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
	int get_year()const { return year; }

	bool is_valid()const
	{
		//return year >= 0;
		return year >= 1900 && year <= 2025;
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
	Year(char) = delete;
	Year(bool) = delete;
	~Year() {};
};
	std::ostream& operator<<(std::ostream& os, const Year& obj) {
		return os << obj.get_year();
	}
	class Day
	{
		int day;

	public:
		int get_day()const { return day; }
		//функция проверяет вхождение в диапазон даты
		bool is_valid(Month month, int year)const
		{
			int maxDays = 31;// количество дней по умолчанию

			switch (month) {
			case Month::Feb:maxDays = isLeapYear(year) ? 29 : 28; break;
			case Month::Apr:
			case Month::Jun:
			case Month::Sep:
			case Month::Nov:maxDays = 30; break;
			default: break;
			}
			return day > 0 && day <= maxDays;
		}
	public:

		explicit Day(int d) :day(d) {}
		Day(char) = delete;
		Day(bool) = delete;

		~Day() {};
	};
	std::ostream& operator<<(std::ostream& os, const Day& obj) {
		return os << obj.get_day();
	}

class Date
{
	Day day;
	Month month;
	Year year;

public:
	class InvalidDay : public std::runtime_error
	{
	public:
		InvalidDay(const std::string& message="Invalid day value"): std::runtime_error(message){}
	};

	Date(Day d, Month m, Year y)
		:day(d)
		,month(m)
		,year(y)
	{

	}
	Date(Date&) = delete; //запрещаем копирование
	Date& operator=(Date&) = delete; // запрещаем оператор присвоения

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
		Date d3(Day(32), Month::Feb, Year(1991));
		d3.print();
		Date d4(Day(12),Month::Dec,Year(2025));
		d4.print();
		Date d5(Day(22), Month::Apr, Year(1987));
		d5.print();

	}
	/*catch (const Day::InvalidDay&) {
		cerr << "Error" << endl;
	}*/
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