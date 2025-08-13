#include<iostream>
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class List
{
public:
	List();
	~List();
	//Methods:
	void push_back(T data); //поместить в конец списка
	int get_size()const { return Size; }
	
//пререгружаем оператор []
	T& operator[](const int index);


private:
	// в private секции класса List создаем вложенный класс Node(узел)
	// Node(узел) не должен быть доступен напрямую, только через class List
	// чтобы класс Node имел возможность работать с различными типами данных делаем его шаблонным
	template<typename T>
	class Node
	{
	public:
		//Поля:
		Node* pNext;//указатель на следующий элемент
		
		T data;//второе поле- поле с данными

		// Constructor:
		//в конструкторе,чтобы при созд. поля не содержали мусора, устанавливаем значения по умолчанию
		//Node* PNext = nullptr - по умолчанию
		//T data=T() шаблонный тип принимает по умолчанию значение шаблонного типа
		//В конструктор передаем данные и указатель на следующий Node  (* PNext)
		Node(T data=T(), Node *PNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

	};
	int Size;//поле для подсчета элементов
	//создаем указатель на элемент класса Node в классе List
	Node<T> *head; // и чтобы иметь возможность создать его шаблонным типом, делаем List шаблонным
	//<T> элемент шаблонного типа  T
};

// При вынесении конструкторов и деструктора за класс нужно указывать что класс явл. шаблонным
template<typename T>
List<T>::List()
{
	//инициализируем поля в конструкторе начальными значениями
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {}

//вынесенная реализация методов:
template<typename T>
void List<T>::push_back(T data)
{
	// проверяем есть ли созданные элементы списка
	
	if (head == nullptr)
	{
		head = new Node<T>(data);//если нету, создаем первый элемент
	}
	else
	{
		//если есть элементы, перебираем список и в конце добавляем элемент
		//текущему элементу current присваиваем адресс нашего head (this->head)
		Node<T>* current = this->head;
		//проходим циклом по адресам, пока значение адреса следующего элемента не равно nullptr
		while (current->pNext != nullptr)
		{
			//присваиваем полю current значение адресса следующего элемента
			current = current->pNext;
		}
		// когда крайний элемент найден создается новый элемент
		current->pNext = new Node<T>(data);
	}
	Size++;// количество элементов увеличивается на 1
}



template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


void main() {
	setlocale(LC_ALL, "");
	List<int>lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);
	cout << lst.get_size() << endl;
	cout << lst[2] << endl;

	int NumberS;
	cin >> NumberS;
	for (int i = 0; i < NumberS; i++)
	{
		lst.push_back(rand() % 10); 
	}

	
	for (int i = 0; i < lst.get_size(); i++)
	{
		cout << lst[i] << endl;
	}

}