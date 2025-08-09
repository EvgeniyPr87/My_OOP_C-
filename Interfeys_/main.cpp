#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#define TEORY

#ifdef TEORY
//		Интерфейсы - это публичные методы, с помощью которых, можно взаимодействовать 
// с какой-либо сущностью. 
//		Интерфейс- Набор абстрактных методов (часто чисто виртуальных функций),
// которые определяют контракт, которому должны соответствовать классы, реализующие этот интерфейс.
//.		Интерфейс определяет что класс должен делать, но не как он это делает.
//		Классы, реализующие интерфейс, должны предоставить конкретные реализации для всех методов,
// объявленных в интерфейсе.

//					Как реализовать интерфейс в C++:

//			Определите абстрактный класс(интерфейс) :

//	*Создайте класс, который будет служить интерфейсом.
//	*Объявите все методы интерфейса как virtual и = 0 (чисто виртуальные).
//	*Сделайте деструктор виртуальным(virtual ~InterfaceName() = default;) - это важно для 
//       равильного удаления объектов через указатели на базовый класс(интерфейс).
//	*Абстрактный класс может содержать и другие члены, но они не являются частью интерфейса.
//	*Реализуйте интерфейс в конкретных классах :

//*Создайте классы, которые будут реализовывать интерфейс.
//*Наследуйте эти классы от абстрактного класса(интерфейса).
//*Реализуйте все чисто виртуальные функции, объявленные в интерфейсе.
//*Используйте ключевое слово override для гарантии, что вы действительно 
//    переопределяете виртуальную функцию из базового класса.
//*Эти классы могут добавлять свои собственные члены(данные и методы) в дополнение 
// к реализации интерфейса.  
#endif // TEORY

//Интерфейс Shape (абстрактный класс):
class Shape {
public:
	//  чисто виртуальная функция расчета площади:
	virtual double getArea()const = 0;

	//	чисто виртуальная функция для расчета периметра:
	virtual double getPerimeter()const = 0;

	//	чисто виртуальная функция для рисования фигуры:
	virtual void draw()const = 0;

	//	виртуальный деструктор:
	virtual ~Shape() = default;
};

// Класс Circle, реализующий интерфейс Shape:
class Circle : public Shape {
	double radius;

public:
	Circle(double radius) : radius(radius) {}

	//	реализация getArea():
	double getArea()const override {
		return 3.14 * radius * radius;
	}

	//	реализация getPerimeter():
	double getPerimeter()const override {
		return 2 * 3.14 * radius;
	}

	//	реализация draw():
	void draw()const override {
		cout << "Drawing a circle with radius " << radius << endl;
	}
};

// Класс Rectangle, реализующий интерфейс Shape:
class Rectangle :public Shape {
	double width;
	double height;

public:
	Rectangle(double width, double height):width(width), height(height){}

	// реализация getArea():
	double getArea()const override {
		return width * height;
	}

	//	реализация getPerimeter():
	double getPerimeter()const override {
		return 2 * (width + height);
	}

	//	реализация draw():
	void draw()const override {
		cout << "Drawing a rectangle with " << width << " and height " << height << endl;
	}
};


void main() {

	setlocale(LC_ALL, "");

	//!!! Нельзя создать обьект абстрактного класса.
	//В данном случае создать обькт Shape- невозможно!!!

	Shape* circle = new Circle(5.0);
	Shape* rectangle = new Rectangle(4.0, 6.0);

	cout << "Circle Area: " << circle->getArea() << endl;
	cout << "Rectangle Area: " << rectangle->getArea() << endl;

	cout << "Rectangle perimetr:  " << rectangle->getPerimeter() << endl;

	circle->draw();
	rectangle->draw();
}