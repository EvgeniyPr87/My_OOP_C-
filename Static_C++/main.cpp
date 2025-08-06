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

	static int Count;// объявление статического поля 

public:


	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		Count++; // реализация логики в конструкторе класса
		id = Count;//при создании яблока счетчик увеличивается на 1 и эта единица присваивается
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
	cout << Apple::get_Count();//статическое поле позволяет обратиться непосредственно к нашему классу
	cout << endl;
	cout << "ID" << " " << apple2.get_id() << endl;

	// в статических метадах работа с нестатическими полями запрещена
	// статические методы работают только со статическими полями
	//статический метод виден всему классу и экземплярам класса
	// не статические методы можно вызывать только экземплярам класса

#endif // STATIC_COUNT

}