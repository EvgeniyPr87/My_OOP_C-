#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Human
{
public:
	string Name;
	int Age;
	int Weight;

	Human(string Name)
	{
		this->Name = Name;
		this->Age = 0;
		this->Weight = 0;
	}
	Human(string Name, int Age):Human(Name) //деллегирование 
	{
		this->Age = Age;
	}
	Human(string Name, int Age, int Weight):Human(Name,Age) //деллегирование
	{
		this->Weight = Weight;
	}

};
void main() {
	setlocale(LC_ALL, " ");


}