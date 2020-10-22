#include <iomanip>
#include <iostream>
#include<Windows.h>

void showMenu();
int mainMenu();

using namespace std;

class cartoons
{
private:
	int rating;
	string name;
	string country;
public:
	cartoons() {};
	cartoons(int rating, string name, string country);
	void show();
};

class anime :public cartoons
{
private:
	bool isManga;
	string subtitles;
public:
	anime(int rating, string name, string country, bool isManga, string subtitles);
	void show();
};

class musical :public cartoons
{
private:
	string music;
	bool music_subtitles;
public:
	musical(int rating, string name, string country, string music, bool music_subtitles);
	void show();
};

class developing :public cartoons
{
private:
	int age;
	string topic;
public:
	developing(int rating, string name, string country, int age, string topic);
	void show();
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout << endl;
	mainMenu();
	return 0;
}

void showMenu()
{
	cout << "\t Нажмите 1 - если жанр мультика аниме \n\tНажмите 2 - если жанр мультика мюзикал \n\tНажмите 3 - если жанр мультика развивающий\n\tНажмите 4 - выход\n\tВаш выбор:> ";
}

int mainMenu()
{
	anime* Manga = NULL;
	musical* Music = NULL;
	developing* Dev = NULL;

	int choice;
	while (true)
	{
		showMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string name, country;
			int rating;
			cout << "Введите название мультика" << endl;
			cin >> name;
			cout << "Введите рейтинг мультика" << endl;
			cin >> rating;
			cout << "Введите страну производства мультика" << endl;
			cin >> country;

			bool ch;
			cout << "Если аниме основано на манге, нажмите 1" << endl;
			cin >> ch;
			string s;
			cout << "Введи язык субтитров: " << endl;
			cin >> s;
			Manga = new anime(rating, name, country, ch, s);
			Manga->show();
			break;
		}
		case 2:
		{
			string n, c;
			string name, country;
			int rating;
			cout << "Введите название мультика" << endl;
			cin >> name;
			cout << "Введите рейтинг мультика" << endl;
			cin >> rating;
			cout << "Введите страну производства мультика" << endl;
			cin >> country;

			bool ch;
			string m;
			cout << "Введите название композиции: " << endl;
			cin >> m;
			cout << "Если к музыке есть субтитры, нажмите 1" << endl;
			cin >> ch;
			Music = new musical(rating, name, country, m, ch);
			Music->show();
			break;
		}
		case 3:
		{
			string n, c;
			string name, country;
			int rating;
			cout << "Введите название мультика" << endl;
			cin >> name;
			cout << "Введите рейтинг мультика" << endl;
			cin >> rating;
			cout << "Введите страну производства мультика" << endl;
			cin >> country;

			string t;
			int a;
			cout << "Введите тему мультика: " << endl;
			cin >> t;
			cout << "Введите ограничение по возрасту: " << endl;
			cin >> a;
			Dev = new developing(rating, name, country, a, t);
			Dev->show();
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
	if (Manga != NULL) delete Manga;
	if (Music != NULL) delete Music;
	if (Dev != NULL) delete Dev;
}

cartoons::cartoons(int rating, string name, string country)
{
	this->rating = rating;
	this->name = name;
	this->country = country;
}

anime::anime(int rating, string name, string country, bool isManga, string subtitles)
{
	this->cartoons::cartoons(rating, name, country);
	this->isManga = isManga;
	this->subtitles = subtitles;
}

musical::musical(int rating, string name, string country, string music, bool music_subtitles)
{
	this->cartoons::cartoons(rating, name, country);
	this->music = music;
	this->music_subtitles = music_subtitles;
}

developing::developing(int rating, string name, string country, int age, string topic)
{
	this->cartoons::cartoons(rating, name, country);
	this->age = age;
	this->topic = topic;
}

void cartoons::show()
{
	cout << "Название: " << this->name << endl << "Страна производства: " << this->country << endl << "Рейтинг: " << this->rating << endl;;
}
void anime::show()
{
	cartoons::show();
	cout << "Основана ли на манге: " << this->isManga << endl << "Язык субтитров: " << this->subtitles << endl;
}

void musical::show()
{
	cout << "Название музыки: " << this->music << endl << "Наличие субтитров: " << this->music_subtitles << endl;
	cartoons::show();
}

void developing::show()
{
	cout << "Возрастное ограничение: " << this->age << endl << "Тема: " << this->topic << endl;
	cartoons::show();
}