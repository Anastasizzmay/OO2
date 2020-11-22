#include <iomanip>
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>

using namespace std;

int writeNumbers();
string writeWord();

class Animation
{
protected:
	string genre;
public:
	Animation()
	{

	};
	Animation(string genre)
	{
		this->genre = genre;
	};
	 void show()
	{
		cout << "Жанр: " << this->genre << endl;
	};
};

class Director : virtual public Animation
{
protected:
	string name;
	string surname;
	string birthday;
	string sex;
public:
	Director()
	{

	};
	Director(string genre, string name, string surname, string birthday, string sex) :Animation(genre)
	{
		this->name = name;
		this->surname = surname;
		this->birthday = birthday;
		this->sex = sex;
	};
	void show() {
		cout << "Имя: " << this->name
			<< endl << "Фамилия: " << this->surname
			<< endl << "Дата рождения: " << this->birthday
			<< endl << "Пол: " << this->sex << endl;
	};
};

class Company : virtual public Animation
{
protected:
	string namec;
	string country;
public:
	Company()
	{

	};
	Company(string genre, string namec, string country) :Animation(genre)
	{
		this->namec = namec;
		this->country = country;
	};
	void show() {
		cout << "Название компании производителя: " << this->namec
			<< endl << "Страна: " << this->country
			<< endl;
	};
};

class Cartoon : public Director, public Company
{
protected:
	string namecar;
	int year;
	int age;
	int rating;
public:
	Cartoon()
	{

	};
	Cartoon(string genre, string name, string surname, string sex, string birthday, string country, string namec, string namecar, int age, int year, int rating) : Director(genre, name, surname, sex, birthday), Company(genre, country, namec), Animation(genre)
	{
		this->namecar = namecar;
		this->year = year;
		this->age = age;
		this->rating = rating;
	};
	void Cart_show()
	{
		Animation::show();
		Director::show();
		Company::show();
		cout << "Название мультипликационного произведения: " << this->namecar
			<< endl << "Год выпуска: " << this->year
			<< endl << "Возрастное ограничение: " << this->age
			<< endl << "Рейтинг: " << this->rating
			<< endl;
	};
};

int main()
{
	Cartoon* cartoon = NULL;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	string genre, namecar, name, surname, sex, birthday, country, namec;
	int age, year, rating;
	cout << "Введите название мультика: ";
	namecar = writeWord();
	cout << endl;
	cout << "Введите жанр: ";
	genre = writeWord();
	cout << endl;
	cout << "Введите возрастное ограничение: ";
	age = writeNumbers();
	cout << endl;
	cout << "Введите год выпуска: ";
	year = writeNumbers();
	cout << endl;
	cout << "Введите рейтинг: ";
	rating = writeNumbers();
	cout << endl;
	cout << "Введите название студии: ";
	namec = writeWord();
	cout << endl;
	cout << "Введите страну производства: ";
	country = writeWord();
	cout << endl;
	cout << "Введите имя режиссера: ";
	name = writeWord();
	cout << endl;
	cout << "Введите фамилию режиссера: ";
	surname = writeWord();
	cout << endl;
	cout << "Введите пол режиссера: ";
	sex = writeWord();
	cout << endl;
	cout << "Введите дату рождения режиссера: ";
	cin >> birthday;
	cout << endl;
	cartoon = new Cartoon(genre, name, surname, birthday, sex, namec, country, namecar, age, year, rating);
	cartoon->Cart_show();
	delete cartoon;
	return 0;
}

int writeNumbers()
{
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

string writeWord()
{
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}