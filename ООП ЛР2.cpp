#include <iostream>
#include <iomanip>

void showMenu();
int mainMenu();
int prov (int);

using namespace std;

class mass
{
private:
	int numberOfElements;
	int* mas;
public:
	mass(int);
	mass(const mass&);
	mass merge(mass);
	mass intersect(mass);
	mass operator | (mass external);
	mass operator &(mass external);
	void bubbleSort();
	void show();
	void fill();
	~mass();
};

int main()
{
	setlocale(0, "");
	cout << endl;
	mainMenu();
	return 0;
}

mass::mass(int number) :numberOfElements(number)
{
	mas = new int[number];
}

mass::mass(const mass& external)
{
	numberOfElements = external.numberOfElements;
	mas = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
		mas[i] = external.mas[i];
}

void mass::fill()
{
	for (int i = 0; i < numberOfElements; i++)
		cin >> mas[i];
}

void mass::show()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << setw(4) << mas[i];
	}
}

void mass::bubbleSort()
{
	for (int i = 0; i < numberOfElements - 1; i++)
		for (int j = i; j < numberOfElements; j++)
		{
			if (mas[i] > mas[j]) swap(mas[i], mas[j]);
		}
}

mass mass::merge(mass external)
{
	this->bubbleSort();
	external.bubbleSort();
	mass temp(numberOfElements + external.numberOfElements);
	for (int i = 0; i < numberOfElements; i++)
		temp.mas[i] = mas[i];
	bool isUnique;
	int counter = numberOfElements;
	for (int i = numberOfElements; i < temp.numberOfElements; i++)
	{
		isUnique = true;
		for (int j = 0; j < numberOfElements; j++)
			if (external.mas[i - numberOfElements] == mas[j]) isUnique = false;
		if (isUnique)
		{
			temp.mas[counter] = external.mas[i - numberOfElements];
			counter++;
		}
	}
	temp.numberOfElements = counter;
	temp.bubbleSort();
	return mass(temp);
}

mass mass::operator | (mass external)
{
	mass temp(numberOfElements + external.numberOfElements);
	for (int i = 0; i < numberOfElements; i++)
		temp.mas[i] = mas[i];
	bool isUnique;
	int counter = numberOfElements;
	for (int i = numberOfElements; i < temp.numberOfElements; i++)
	{
		isUnique = true;
		for (int j = 0; j < numberOfElements; j++)
			if (external.mas[i - numberOfElements] == mas[j]) isUnique = false;
		if (isUnique)
		{
			temp.mas[counter] = external.mas[i - numberOfElements];
			counter++;
		}
	}
	temp.numberOfElements = counter;
	temp.bubbleSort();
	return mass(temp);
}

mass mass::intersect(mass external)
{
	this->bubbleSort();
	external.bubbleSort();
	bool isintersection = false;
	int size = (numberOfElements > external.numberOfElements) ? numberOfElements : external.numberOfElements;
	mass temp(size);
	size = 0;
	for (int i = 0; i < numberOfElements; i++)
		for (int j = 0; j < external.numberOfElements; j++)
			if (mas[i] == external.mas[j])
			{
				temp.mas[size] = mas[i];
				size++;
				isintersection = true;
			}
	if (!isintersection)
		cout << endl << "\tПересечения нет!" << endl;
	temp.numberOfElements = size;
	return mass(temp);
}

mass mass::operator & (mass external)
{
	bool isintersection = false;
	int size = (numberOfElements > external.numberOfElements) ? numberOfElements : external.numberOfElements;
	mass temp(size);
	size = 0;
	for (int i = 0; i < numberOfElements; i++)
		for (int j = 0; j < external.numberOfElements; j++)
			if (mas[i] == external.mas[j])
			{
				temp.mas[size] = mas[i];
				size++;
				isintersection = true;
			}
	if (!isintersection)
		cout << endl << "\tПересечения нет!" << endl;
	temp.numberOfElements = size;
	temp.bubbleSort();
	return mass(temp);
}

void showMenu()
{
	cout << "\t1) Показать массивы\n\t2) Пересечь массивы\n\t3) Объединить массивы\n\t4) Выход\n\tВаш выбор:> ";
}

int mainMenu()
{
	int temp, choice;
	cout << endl << "\tСколько элементов в первом массиве: ";
	cin >> temp;
	prov (temp);
	mass first(temp);
	cout << "\tВведите элементы массива: ";
	first.fill();
	cout << endl << "\tСколько элементов во втором массиве: ";
	cin >> temp;
	prov (temp);
	mass second(temp);
	cout << "\tВведите элементы массива: ";
	second.fill();
	while (true)
	{
		showMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << endl << "\t";
			first.show();
			cout << endl << "\t";
			second.show();
			cout << endl;
			break;
		}
		case 2:
		{
			mass third = first & second;
			third.show();
			cout << endl;
			break;
		}
		case 3:
		{
			mass third = first | second;
			third.show();
			cout << endl;
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
}

mass::~mass()
{
	delete[] mas;
}

int prov (int k)
{
	while (!(cin >> k) || (cin.peek() != '\n')) //проверяет, чтобы следующий символ в потоке был концом файла или концом строки без извлечения символа из потока и повреждения последующего действительного ввода.
	{
		cin.clear();
		while (cin.get() != '\n'); //заставляет систему ожидать ввода пользователем любого символа, который она считывает, и программа завершается.
		cout << "Input error! Retry input" << endl;
	}
	if (k < 0)
	{
		cin.clear();
		while (cin.get() != '\n'); //заставляет систему ожидать ввода пользователем любого символа, который она считывает, и программа завершается.
		cout << "Input error! Retry input" << endl;
	}
	
	return k;
}
