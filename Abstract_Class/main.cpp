//Абстрактные классы-класс в котором присутствует хотя-бы одна чисто вирт.функция
//Чисто вертуальные функции- пустая функция без реализации.
//Создание экземпляров абстрактных классов невозможно

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

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
class Knife: public Weapon
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
	void Shoot(Weapon *weapon) //создаем метод для игрока и передаем  в него указатель
		// на элемент класса Weapon
	{
		weapon->Shoot();
	}
};

void main(){
	setlocale(LC_ALL, " ");
	//Player player1{};
	Knife knife;// создаем экземпляр класса нож
	Gun gun;
	Player player1;// создаем игрока
	player1.Shoot(&knife);// вызываем метод shoot для игрока и передаем ему ссылку на созданный нож
	player1.Shoot(&gun);
	gun.InFo();
	knife.InFo();

}