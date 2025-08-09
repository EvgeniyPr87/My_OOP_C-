#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;

//#define CLASS_HUMAN

#ifdef CLASS_HUMAN
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
#endif // CLASS_HUMAN


void main()
{
	setlocale(LC_ALL, "");
	 
#ifdef CLASS_HUMAN
	Human human;
	human.Think();
#endif // CLASS_HUMAN


}