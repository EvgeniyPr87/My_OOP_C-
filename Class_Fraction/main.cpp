#include<iostream>
#include<string>
#include<cmath>
#include<numeric>
#include<algorithm>
#include<sstream>
#include<stdexcept>
using std::cout;
using std::cin;
using std::endl;
// + - * / += -= == ++ -- > < >= <=
//#define OLD_STYLE
class Fraction;
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction& left, const Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);


class Fraction
{
	int integer;//целая часть
	int numerator;//числитель
	int denominator;//знаменатель

public:
							//Getters:
	int get_integer()const { return integer;}
	int get_numerator()const { return numerator;}
	int get_denominator()const { return denominator;}

							//Setters:
							
	void set_integer(int integer) { this->integer = integer; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) {
		if (denominator == 0) {
			throw std::invalid_argument("Denominator cannot be zero!");
	}
		this->denominator = denominator;
	}
							// Constructors:
	Fraction():integer(0),numerator(0),denominator(1){}
	explicit Fraction(int integer): integer(integer),numerator(0)
		,denominator(1){}
	Fraction(int numerator, int denominator) :integer(0), numerator(numerator) {
		if (denominator == 0) {
			throw std::invalid_argument("Denominator cannot be zero!");
}
		this->denominator = denominator;
	}
		
	Fraction(int integer, int numerator, int denominator) :integer(integer), numerator(numerator) {
		if (denominator == 0) {
			throw std::invalid_argument("Denominator cannot be zero!");
		}
		this->denominator = denominator;
	}
		

	// Copy Constructor:
	Fraction(const Fraction& other): integer(other.integer),numerator(other.numerator)
		,denominator(other.denominator){}
	
	
~Fraction(){}

								// Operators:
//Assignment operator:
Fraction& operator =(const Fraction& other) {
	if (this != &other) {
		integer = other.integer;
		numerator = other.numerator;
		denominator = other.denominator;
	}
	return *this;
}
//Operator *=
	Fraction& operator*= (const Fraction & other) {return *this = *this * other;}
	
//Operator /=
	Fraction& operator /=(const Fraction& other) {return *this = *this / other;}

//Operator +=
	Fraction& operator+=(const Fraction& other) {return *this = *this + other;}

//Operator -=
	Fraction& operator-= (const Fraction& other){return *this = *this - other;}


	// Incriment/Decriment:
	//Operator ++
	Fraction& operator++() { integer++; return *this; }//Prefics
	Fraction& operator ++(int) { Fraction old = *this; integer++; return old; } //Postfix

	//Operator --
	Fraction& operator--() { integer--; return *this; }//Prefics
	Fraction& operator--(int) { Fraction old = *this; integer--; return old; }//Postfix

	//Type-cast operators:
	explicit operator int()const { return integer + numerator / denominator;}
	explicit operator double()const { return integer + (double)numerator / denominator; }


								// Metods:
// метод переводит дробь в неправильную
Fraction& to_improper() {
	if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be zero!");
	}
	int sign = 1;
	if (integer < 0 || numerator < 0) {
		sign = -1;
	}
	integer = std::abs(integer);
	numerator = std::abs(numerator);

	numerator += integer * denominator;
	numerator *= sign;
	integer = 0;
	return *this;
}

//метод переводит дробь в правильную
Fraction& to_proper() {
	if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be zero!");
	}
	//определяем знак дроби
	int sign = 1;
	if (integer < 0 || numerator < 0) {
		sign = -1;
	}
	//абсолютное значение
	integer = std::abs(integer);
	numerator = std::abs(numerator);

	integer += numerator / denominator;
	numerator %= denominator;

	// возвращаем знак
	integer *= sign;
	numerator *= sign;

	return *this;
}
#ifdef OLD_STYLE
Fraction& reduction() {
	int more, less, rest;
	if (numerator < denominator) {
		less = numerator;
		more = denominator;
	}
	else
	{
		more = numerator;
		less = denominator;
	}
	do {
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

#endif // OLD_STYLE

Fraction& reduction() {
	if (denominator == 0) {
		throw std::invalid_argument("Denominator cannot be zero!");
	}
	//получаем абсолютное значение
	int num = std::abs(numerator);
	int den = std::abs(denominator);

	//вычисляем НОД
	int gcd = std::gcd(num, den);

	//сокращаем дробь
	numerator /= gcd;
	denominator /= gcd;

	return *this;
}

Fraction inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	if (inverted.numerator == 0)
	{
		throw std::invalid_argument("Cannot invert a fraction with a zero numerator.");
	}
	std::swap(inverted.numerator, inverted.denominator);
	return inverted;
}

};


							// Operators out:

// operator *
Fraction operator *( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduction();
}

Fraction operator /( const Fraction& left,const Fraction& right)
{
	return (left * right.inverted()).to_proper(); 
}

Fraction operator+( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),

		left.get_denominator() * right.get_denominator()
	).to_proper().reduction();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduction();
}

//Comparison operators(операторы сравнения):

bool operator ==(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();

	return 
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}

bool operator !=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left,Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator <<(std::ostream& os, const Fraction& obj) {
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
#ifdef OLD_STYLE
std::istream& operator >>(std::istream& cin, Fraction& obj) {
	const int SIZE = 32;
	char sz_input[SIZE] = {};
	cin.getline(sz_input, SIZE);
	const char delimeters[] = { '(','/',')',' ','.',',',0 };
	int numbers[3] = {};
	int n = 0;
	for (char* pch = strtok(sz_input, delimeters); pch && n < 3; pch = strtok(NULL, delimeters))
		numbers[n++] = atoi(pch);
	switch (n)
	{
	case 1:obj = Fraction(numbers[0]); break;
	case 2:obj = Fraction(numbers[0], numbers[1]); break;
	case 3:obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	return cin;
}
#endif // OLD_STYLE

std::istream& operator>>(std::istream& is, Fraction obj) {
	std::string input;
	std::getline(is, input);

	std::stringstream ss(input);
	int integerPart = 0;
	int numeratorPart = 0;
	int denominatorPart = 1;

	char slash;

	if (ss >> integerPart) {
		if (ss >> numeratorPart >> slash >> denominatorPart) {
			if (denominatorPart == 0) {
				throw std::invalid_argument("Denominator cannot be zero!");
			}
			else {
				numeratorPart = 0;
				denominatorPart = 1;
			}
		}else {
			ss.clear();
			ss.seekg(0);
			if (ss >> numeratorPart >> slash >> denominatorPart) {
				integerPart = 0;
				if (denominatorPart == 0) {
					throw std::invalid_argument("Denominator cannot be zero!");
				}
			}
			else {
				obj = Fraction();
				return is;
			}
		}
	}
	obj = Fraction(integerPart, numeratorPart, denominatorPart);
	return is;
}


void main() {
	setlocale(LC_ALL, "");
	Fraction fraction1(2,9);
	//cout << "Введите дробь: "; cin >> fraction1;
	//cout << fraction1;
	Fraction fraction2(1, 2, 3);
	Fraction fraction3 = fraction1 * fraction2;
	cout << fraction3 << endl;
	Fraction fr = fraction1 / fraction2;
	cout << fr<<endl;
	fr *= fraction1;
	cout << fr << endl;
	++fraction2;
	cout << fraction2 << endl;
	fraction2++;
	cout << fraction2 << endl;
	--fraction2;
	cout << fraction2 << endl;
	fraction2--;
	cout << fraction2 << endl;
	int x = static_cast<int> (fraction2);
	cout << x << endl;
	double y = static_cast<double>(fraction2);
	cout << y << endl;
	Fraction fr3 = fraction1 + fraction1;
	cout << fr3 << endl;


	
}