//Абстрактные классы-класс в котором присутствует хотя-бы одна чисто вирт.функция
//Чисто вертуальные функции- пустая функция без реализации.
//Создание экземпляров абстрактных классов невозможно

#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//#define WEAPON

#ifdef WEAPON
class Weapon //Абстрактный класс
{
public:
	virtual void  Shoot() = 0; //Это функция чисто виртуальная

	void InFo() //  В абстрактном классе могут реализовываться и обычные функции
	{
		cout << "Info()" << endl;
	}
};
//!!!в абстрактном классе могут быть функции, методы, которые  могут иметь полную реализацию

class Gun :public Weapon
{
public:
	void Shoot()override
	{
		cout << "BAng!BAng!BAng!" << endl;
	}
};
class Bazooka : public Weapon
{
public:
	void Shoot()override
	{
		cout << "BadaBub!!!" << endl;
	}
};
class Knife : public Weapon
{
public:
	void Shoot()override
	{
		cout << "Vgihhh" << endl;
	}
};
class Player
{
public:
	void Shoot(Weapon* weapon) //создаем метод для игрока и передаем  в него указатель
		// на элемент класса Weapon
	{
		weapon->Shoot();
	}
};
#endif // WEAPON


// Абстрактный базовый класс Shape
class Shape {
public:
    std::string name;

    Shape(const std::string& n) : name(n) {
        std::cout << "Shape constructor: " << name << std::endl;
    }

    // Чисто виртуальная функция для расчета площади
    // Каждый производный класс ОБЯЗАН реализовать ее
    virtual double calculateArea() const = 0;

    // Чисто виртуальная функция для рисования
    virtual void draw() const = 0;

    // Обычная виртуальная функция (с реализацией)
    virtual void displayInfo() const {
        std::cout << "This is a " << name << " shape." << std::endl;
    }

    // Виртуальный деструктор - очень важен для полиморфного удаления
    virtual ~Shape() {
        std::cout << "Shape destructor: " << name << std::endl;
    }
};

// Производный класс Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(const std::string& n, double r) : Shape(n), radius(r) {
        std::cout << "Circle constructor: " << name << std::endl;
    }

    // Реализация чисто виртуальной функции calculateArea()
    double calculateArea() const override {
        return 3.14159 * radius * radius;
    }

    // Реализация чисто виртуальной функции draw()
    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }

    // Переопределение displayInfo() (необязательно, но полезно)
    void displayInfo() const override {
        Shape::displayInfo(); // Вызов базовой реализации
        std::cout << "It has a radius of " << radius << "." << std::endl;
    }

    ~Circle() {
        std::cout << "Circle destructor: " << name << std::endl;
    }
};

// Производный класс Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(const std::string& n, double w, double h) : Shape(n), width(w), height(h) {
        std::cout << "Rectangle constructor: " << name << std::endl;
    }

    // Реализация чисто виртуальной функции calculateArea()
    double calculateArea() const override {
        return width * height;
    }

    // Реализация чисто виртуальной функции draw()
    void draw() const override {
        std::cout << "Drawing a rectangle with width " << width << " and height " << height << std::endl;
    }

    ~Rectangle() {
        std::cout << "Rectangle destructor: " << name << std::endl;
    }
};


void main(){
	setlocale(LC_ALL, " ");
	
#ifdef WEAPON
	Knife knife;// создаем экземпляр класса нож
	Gun gun;
	Player player1;// создаем игрока
	player1.Shoot(&knife);// вызываем метод shoot для игрока и передаем ему ссылку на созданный нож
	player1.Shoot(&gun);
	gun.InFo();
	knife.InFo();
#endif // WEAPON

    // Shape s; // Ошибка: нельзя создать объект абстрактного класса

    Shape* shapes[2]; // Массив указателей на базовый абстрактный класс

    shapes[0] = new Circle("My Circle", 5.0);
    shapes[1] = new Rectangle("My Rectangle", 4.0, 6.0);

    std::cout << "\n--- Displaying Shapes Info ---" << std::endl;
    for (int i = 0; i < 2; ++i) {
        shapes[i]->displayInfo();
        shapes[i]->draw();
        std::cout << "Area: " << shapes[i]->calculateArea() << std::endl;
        std::cout << "--------------------" << std::endl;
    }

    std::cout << "\n--- Cleaning up ---" << std::endl;
    // Полиморфное удаление: благодаря виртуальному деструктору Shape
    for (int i = 0; i < 2; ++i) {
        delete shapes[i];
    }

}