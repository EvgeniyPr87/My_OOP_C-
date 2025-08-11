// Создаем класс Array,который может хранить массивы элементов различных типов(int, double, string )
#include<iostream>
#include<string>
#include<vector>
using std::cout;
using std::cin;
using std::endl;

#define INFO

template<typename T>
class Array
{
	std::vector<T> data;
	size_t size;
#ifdef INFO
	//size_t это тип данных для хранения размеров объектов в памяти.
//является беззнаковым целочисленным типом
//size_t гарантированно достаточно велик, чтобы хранить размер любого объекта,
// который может быть создан в системе. Использование int или других типов 
// может привести к переполнению, если размер объекта превысит максимальное значение,
// которое может хранить int.  
#endif // INFO
public:
	Array(size_t size):data(size),size(size){}

	T& operator[](size_t index) {
		if (index >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return data[index];
	}

		const T& operator[](size_t index)const {
			if (index >= size) {
				throw std::out_of_range("Index out of bounds");
			}
			return data[index];
		}
		
		size_t getSize()const {
			return size;
		}
};

void main() {
	setlocale(LC_ALL, "");

	//массив целых чисел:
	Array<int>intArray(10);
	for (size_t i = 0; i < intArray.getSize(); i++) {
		intArray[i] = i * 2;
	}
	cout << "Integer Array: ";
	for (size_t i = 0; i < intArray.getSize(); i++) {
		cout << intArray[i] << " ";
	}
	cout << endl;

	//массив строк:
	Array<std::string>stringArray(5);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";

	cout << "String Array: ";
	for (size_t i = 0; i < 5; i++) {
		cout << stringArray[i] << " ";
	}

	
}