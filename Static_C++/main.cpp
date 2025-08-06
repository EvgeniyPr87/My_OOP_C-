#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define STATIC_COUNT

#ifdef STATIC_COUNT
class Apple
{
	int weight;
	string color;
	int id;

	static int Count;// объ€вление статического пол€ 

public:


	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++; // реализаци€ логики в конструкторе класса
		id = Count;//при создании €блока счетчик увеличиваетс€ на 1 и эта единица присваиваетс€
		//закрытому полю id
		//простейший генератор id
	}
	int get_id()const
	{
		return id;
	}
	static int get_Count()
	{
		return Count;
	}
	static void ChangetColor(Apple& apple, string color) // обратитьс€ статическим методом к 
		// кщнкретному объекту через ссыдку на объект
	{
		apple.color = color;
	}
};

int Apple::Count = 0; //инициализируют статическое поле вне класса таким синтаксисом
#endif // STATIC_COUNT

void main(){
	setlocale(LC_ALL," ");

#ifdef STATIC_COUNT
	Apple apple1(150, "red");
	cout << apple1.get_Count() << endl;
	Apple apple2(100, "green");
	cout << apple2.get_Count() << endl;
	Apple apple3(120, "yellow");
	cout << Apple::get_Count();//статическое поле позвол€ет обратитьс€ непосредственно к нашему классу
	cout << endl;
	cout << "ID" << " " << apple2.get_id() << endl;

	apple1.ChangetColor(apple1, "Green");
	

	// в статических метадах работа с нестатическими пол€ми запрещена
	// статические методы работают только со статическими пол€ми
	//статический метод виден всему классу и экземпл€рам класса
	// не статические методы можно вызывать только экземпл€рам класса

#endif // STATIC_COUNT

}