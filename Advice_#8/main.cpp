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


class Mounth
{
	int mounth;

public:
	static Mounth Jan() { return Mounth(1); }
	static Mounth Feb() { return Mounth(2); }
	static Mounth Mar() { return Mounth(3); }
	static Mounth Apr() { return Mounth(4); }
	static Mounth May() { return Mounth(5); }
	static Mounth Jun() { return Mounth(6); }
	static Mounth Jul() { return Mounth(7); }
	static Mounth Aug() { return Mounth(8); }
	static Mounth Sep() { return Mounth(9); }
	static Mounth Oct() { return Mounth(10);}
	static Mounth Nov() { return Mounth(11);}
	static Mounth Dec() { return Mounth(12);}
	bool is_valid()const
	{
		return mounth >= 1 && mounth <= 12;
}
	class InvalidMounth : public std::runtime_error {
	public:
		InvalidMounth(const std::string& msg="Invalid Month value") : std::runtime_error(msg){}
	};

	explicit Mounth(int m) : mounth(m) {
		if (!is_valid()) {
			throw InvalidMounth();
		}
	}

~Mounth() {};

friend std::ostream& operator<<(std::ostream& os, const Mounth& m) {
	return os << m.mounth;
}
};
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
	Mounth mounth;
	Year year;

public:
	Date(Day d, Mounth m, Year y)
		:day(d)
		,mounth(m)
		,year(y)
	{

	}
	~Date() {};

	void print()const {
		cout << day << "/" << mounth << "/" << year << endl;
	}
};



void main(){
	setlocale(LC_ALL, " ");
	try
	{
		
		Date d1(Day(30), Mounth(12), Year(1987));
		d1.print();
	}
	catch (const Day::InvalidDay&) {
		cerr << "Error" << endl;
	}
	catch (const Mounth::InvalidMounth& ) {
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
	{

	}
	
}