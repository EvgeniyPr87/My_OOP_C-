#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//Шаблоны классов

//#define TWO_PARAM

class Point
{
	int x;
	int y;
	int z;

public:
	Point()
	{
		x = y = z = 0;
	}
	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

template<typename T> // вместо typename можно использовать class
class MyClass
{
	T value;
public:

	MyClass(T value)
	{
		this->value = value;
	}

	void DataTypeSize()
	{
		cout << sizeof(value) << endl;
}
};

#ifdef TWO_PARAM
// Передача в шаблон нескольких переменных разного типа
template<typename T1, typename T2>
class MyClass
{
	T1 value;
	T2 value;
public:

	MyClass(T1 value, T2 value)
	{
		this->value = value;
		this->value2 = value2;
	}

	void DataTypeSize()
	{
		cout << sizeof(value) << endl;
		cout << sizeof(value2) << endl;
	}
};

#endif // TWO_PARAM


void main() {
	setlocale(LC_ALL, "");
	int a = 5;
	double b = 4.3;
	MyClass<int>c(a);
	c.DataTypeSize();
	MyClass<double> M(b);
	M.DataTypeSize();
	// Передаем в шаблон пользовательский тип Point 
	Point K;
	MyClass<Point> D(K);
	D.DataTypeSize();
}