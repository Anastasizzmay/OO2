#include <iomanip>
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>

using namespace std;

void showMenu();
int writeNumbers();
string writeWord();



class cartoons
{
	protected:
		int rating;
		string name;
		string country;
	public:
		cartoons(int rating, string name, string country)
		{
			this->rating = rating;
			this->name = name;
			this->country = country;
		}
		virtual void show() {};
};
int mainMenu(cartoons** ptr);

class anime : public cartoons
{
	private:
		bool isManga;
		string subtitles;
	public:
		anime (int rating, string name, string country, bool isManga, string subtitles) : cartoons (rating, name, country)
		{
			/*this->rating = rating;
			this->name = name;
			this->country = country;*/
			this->isManga = isManga;
			this->subtitles = subtitles;
		}
		void show() {
			cout << "Название: " 
				<< this->name << endl
				<< "Страна производства: " 
				<< this->country << endl 
				<< "Рейтинг: " 
				<< this->rating << endl 
				<< "Основана ли на манге: " 
				<< this->isManga << endl 
				<< "Язык субтитров: " 
				<< this->subtitles << endl;
		};
};

class musical :public cartoons
{
private:
	string music;
	bool music_subtitles;
public:
	musical(int rating, string name, string country, string music, bool music_subtitles) : cartoons(rating, name, country)
	{
		this->music = music;
		this->music_subtitles = music_subtitles;
	}
	void show()
	{
		cout << "Название: "
			<< this->name << endl
			<< "Страна производства: "
			<< this->country << endl
			<< "Рейтинг: "
			<< this->rating << endl 
			<< "Название музыки: " 
			<< this->music << endl 
			<< "Наличие субтитров: " 
			<< this->music_subtitles << endl;
	}
};

class developing :public cartoons
{
private:
	int age;
	string topic;
public:
	developing(int rating, string name, string country, int age, string topic) : cartoons(rating, name, country)
	{
		this->age = age;
		this->topic = topic;
	}
		void show()
	{
		cout << "Название: "
			<< this->name << endl
			<< "Страна производства: "
			<< this->country << endl
			<< "Рейтинг: "
			<< this->rating << endl 
			<< "Возрастное ограничение: " 
			<< this->age << endl 
			<< "Тема: " 
			<< this->topic << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout << endl;
	cartoons* ptr[3]; // массив указателей на абстрактный базовый класс
	anime an( 9, "Тетрадь смерти", "Япония", true, "Русский"); // объект класса «Окружность»
	musical mu( 10, "Ла-ла-ленд", "США" , "Another Day of Sun", true); // объект класса «Прямоугольник»
	developing de( 10, "Даша-путешественица", "США", 2, "Английский язык"); // объект класса «Сфера»
	ptr[0] = &an; // инициализация массива указателей ptr
	ptr[1] = &mu;
	ptr[2] = &de;
	mainMenu(ptr);
	return 0;
}

void showMenu()
{
	cout << "\tНажмите 1 - если жанр мультика аниме \n\tНажмите 2 - если жанр мультика мюзикал \n\tНажмите 3 - если жанр мультика развивающий\n\tНажмите 4 - выход\n\tВаш выбор:> ";
}

int mainMenu(cartoons** ptr)
{
	int choice;
	while (true)
	{
		showMenu();
		choice = writeNumbers();
		switch (choice)
		{
		case 1:
		{
			string name, country;
			int rating;
			cout << endl << "Введите название мультика: ";
			name = writeWord();
			cout << endl << "Введите рейтинг мультика: ";
			rating = writeNumbers();
			cout << endl << "Введите страну производства мультика: ";
			country = writeWord();

			bool ch;
			cout << endl << "Если аниме не основано на манге, нажмите 0: ";
			ch = writeNumbers();
			string s;
			cout << endl << "Введи язык субтитров: " ;
			s = writeWord();
			cout << endl;
			cout << endl;
			ptr[0] = new anime(rating, name, country, ch, s);
			ptr[0]->show();
			break;
		}
		case 2:
		{
			string n, c;
			string name, country;
			int rating;
			cout << endl << "Введите название мультика: ";
			name = writeWord();
			cout << endl << "Введите рейтинг мультика: ";
			rating = writeNumbers();
			cout << endl << "Введите страну производства мультика: ";
			country = writeWord();

			bool ch;
			string m;
			cout << "Введите название композиции: ";
			m = writeWord();
			cout << "Если к музыке нет субтитров, нажмите 0: ";
			ch = writeNumbers();
			cout << endl;
			cout << endl;
			ptr[1] = new musical(rating, name, country, m, ch);
			ptr[1]->show();
			break;
		}
		case 3:
		{
			string n, c;
			string name, country;
			int rating;
			cout << endl << "Введите название мультика: ";
			name = writeWord();
			cout << endl << "Введите рейтинг мультика: ";
			rating = writeNumbers();
			cout << endl << "Введите страну производства мультика: " ;
			country = writeWord();

			string t;
			int a;
			cout << endl << "Введите тему мультика: ";
			t = writeWord();
			cout << endl << "Введите ограничение по возрасту: ";
			a = writeNumbers();
			cout << endl;
			cout << endl;
			ptr[2] = new developing(rating, name, country, a, t);
			ptr[2]->show();
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
	if (ptr[0] != NULL) delete ptr[0];
	if (ptr[1] != NULL) delete ptr[1];
	if (ptr[2] != NULL) delete ptr[2];
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