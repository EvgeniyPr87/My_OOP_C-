#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;

#define PERSON_TAKE_PARAMETRS const std::string& ferst_name, const std::string& last_name, int age
#define PERSON_GIVE_PARAMETRS ferst_name,  last_name,  age


class Person
{
	std::string ferst_name;
	std::string last_name;
	int age;
public:
	//					get_Metods:

	const std::string& get_ferst_name()const { return ferst_name; }
	
	const std::string& get_last_name()const { return last_name; }
	
	int get_age()const { return age; }
	

	//					set_Metos:

	void set_ferst_name(std::string ferst_name) { this->ferst_name = ferst_name; }

	void set_last_name(std::string last_name) { this->last_name = last_name; }

	void set_age(int age) { this->age = age; }
	

	//					Constructors:
	Person(PERSON_TAKE_PARAMETRS)
		:ferst_name(ferst_name)
		,last_name(last_name)
		,age(age)
	{
#ifdef DEBUG
		cout << "Constructor Person\n";
#endif // DEBUG

	}
	//					Destructor:
	virtual~Person()=default;

	//					Metods:

	virtual void displayInfo()const { cout << last_name << " " << ferst_name << " " << age << endl; }
	

 };

#define LIBRARYUSER_TAKE_PARAMETRS int userID,std::vector<std::string> booksBorrowed
#define LIBRARYUSER_GIVE_PARAMETRS userID, booksBorrowed

class LibraryUser :public Person
{

	int userID;
	std::vector<std::string&> booksBorrowed;

public:
	//					 get_Metods:

	int get_userID()const { return userID; }
	

	//					Constructors:

	LibraryUser(PERSON_TAKE_PARAMETRS, LIBRARYUSER_TAKE_PARAMETRS) :Person(PERSON_GIVE_PARAMETRS)
		,userID(userID)
		,booksBorrowed(booksBorrowed)
	{
#ifdef DEBUG
		cout << "Constructor LibraryUser\n";
#endif // DEBUG

	}
};

void main()
{
	setlocale(LC_ALL, " ");

	Person person("Andry", "Mixen", 25);
	person.displayInfo();
}