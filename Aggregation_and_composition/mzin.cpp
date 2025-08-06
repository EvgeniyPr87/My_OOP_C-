#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class Human
{
public:
	void Think()
	{
		brain.Think();
	}

private:
	class Brain  // это реализация компазиции
		// Brain  виден только классу Human и без него не существует
		// этот класс вложен в основной в Human
	{
	public:
		void Think()
		{
			cout << "Я думаю!" << endl;
		}
	};
	Brain brain;
};

void main()
{
	setlocale(LC_ALL, "");
	 
	Human human;
	human.Think();

}