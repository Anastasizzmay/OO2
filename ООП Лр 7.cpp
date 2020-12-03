#include<iostream>
#include <conio.h>
#include <string>

using namespace std;
int getInt();
int getTime(int);
template<class T> class Date {
private:
	T year;
	T month;
	T day;
public:
	Date()
	{
		year = 0;
		month = 0;
		day = 0;
	};
	Date(T h, T m, T s)
	{
		year = h;
		month = m;
		day = s;
	}
	Date(const Date<T>& date)
	{
		year = date.year;
		month = date.month;
		day = date.day;
	}
	void changeYear(T ptr)
	{
		year = ptr;
	}
	void changeMonth(T ptr)
	{
		month = ptr;
	}
	void changeDay(T ptr)
	{
		day = ptr;
	}
	T getHour()
	{
		return year;
	}
	T getMinute()
	{
		return month;
	}
	T getSecond()
	{
		return day;
	}
	void NewYear();
	void show();
	void operator != (Date<T>& date)
	{
		int d, m, y;
		cout << "Введите год: " << endl;
		y = getInt();
		cout << "Введите месяц: " << endl;
		m = getTime(13);
		cout << "Введите день: " << endl;
		d = getTime(32);
		if (year != y)
		{
			cout << "Даты не равны" << endl;
		}
		if (month != m)
		{
			cout << "Даты не равны" << endl;
		}
		if (day != d)
		{
			cout << "Даты не равны" << endl;
		}
		else
		{
			cout << "Даты равны" << endl;
		}
		system("pause");
	}
	void operator - (Date<T>& date)
	{
		int d, m, y;
		cout << "Введите год: " << endl;
		y = getInt();
		cout << "Введите месяц: " << endl;
		m = getTime(13);
		cout << "Введите день: " << endl;
		d = getTime(32);
		if (year > y) 
		{
			y = year - y;
			if (day > d)
			{
				d = day - d;
			}
			else
			{
				if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
				{
					if (month == 2)
					{
						day += 28;
						month--;
					}
					else
					{
						day += 30;
						month--;
					}
				}

			}
			if (month > m)
			{
				m = month - m;
			}
			else
			{
				month += 12;
				m = month - m;
				y--;
			}

		}
		else
		{
			y = y - year;
			if (y == 0) 
			{
				if (month > m)
				{
					m = month - m;
				}
				else
				{
					m = m - month;
				}
				if (day > d && m != 0)
				{
					d = day - d;
				}
				else
				{
					if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
					{
						if (month == 2)
						{
							day += 28;
							month--;
						}
						else
						{
							day += 30;
							month--;
						}
					}

				}

			}
			if (d > day)
			{
				d = d - day;
			}
			else
			{
				if (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)
				{
					if (m == 2)
					{
						d += 28;
						m--;
					}
					else
					{
						d += 30;
						m--;
					}
				}

			}
			if (m > month)
			{
				m = m - month;
			}
			else
			{
				m += 12;
				m = m - month;
				y--;
			}
		}
		cout<< "Разница: " << d << "/" << m << "/" << y << endl;
		system("pause");
	}
};

template <class T> void Date<T>::NewYear()
{
	int mn, md = 0, d;
	mn = month;
	d = day;
	while (mn != 0)
	{
		if (mn == 2|| mn == 4 || mn == 6 || mn == 9 || mn == 11)
		{
			if (mn == 2)
			{
				d += 28;
				mn--;
			}
			else 
			{
				d += 30;
				mn--;
			}
		}
		else { d += 31; mn--; }
	}
	md = 365 - d + 31;
	cout << "Осталось " << md << " дней" << endl;
}

template <class T> void Date<T>::show()
{
	cout << day << "/" << month << "/" << year << endl;
}

int menuMain();
int menuChange(Date<int>&);

int main()
{
	Date<int> obj;
	setlocale(LC_ALL, "rus");
	while (true)
	{
		int chooseMenu1 = menuMain();
		if (chooseMenu1 == 0)
		{
			while (true)
			{
				int chooseMenu2 = menuChange(obj);
				if (chooseMenu2 == 0)
				{
					cout << "Введите год: ";
					int ptr = getInt();
					obj.changeYear(ptr);
					system("cls");
				}
				else
					if (chooseMenu2 == 1)
					{
						cout << "Введите месяц: ";
						int ptr = getTime(13);
						obj.changeMonth(ptr);
						system("cls");
					}
					else
						if (chooseMenu2 == 2)
						{
							cout << "Введите день: ";
							int ptr = getTime(32);
							obj.changeDay(ptr);
							system("cls");
						}
						else
							if (chooseMenu2 == 3) break;
			}
		}
		else
			if (chooseMenu1 == 1)
			{
				obj.show();
				system("pause");
			}
			else
				if (chooseMenu1 == 2)
				{
					obj.show();
					obj.NewYear();
					system("pause");
				}
				else
					if (chooseMenu1 == 3)
					{
						obj.operator - (obj);
					}
					else
						if (chooseMenu1 == 4)
						{
							obj.operator != (obj);
						}
						else
						if (chooseMenu1 == 5) break;
	}
	return 0;
}

int menuMain()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 6) % 6;

		if (choiceButton == 0) cout << "->Изменить дату" << endl;
		else cout << "Изменить дату" << endl;

		if (choiceButton == 1) cout << "->Посмотреть дату" << endl;
		else cout << "Посмотреть дату" << endl;

		if (choiceButton == 2) cout << "->Определить количество дней до Нового Года" << endl;
		else cout << "Определить количество дней до Нового Года" << endl;

		if (choiceButton == 3) cout << "->Определить разницу между датами" << endl;
		else cout << "Определить разницу между датами" << endl;

		if (choiceButton == 4) cout << "->Сравнить даты" << endl;
		else cout << "Сравнить даты" << endl;

		if (choiceButton == 5) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}
		system("cls");
	}
}

int menuChange(Date<int>& obj)
{
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Год: " << obj.getHour() << endl; }
		else cout << " Год: " << obj.getHour() << endl;

		if (choose_menu == 1) { cout << " -> Месяц: " << obj.getMinute() << endl; }
		else cout << " Месяц: " << obj.getMinute() << endl;

		if (choose_menu == 2) { cout << " -> День: " << obj.getSecond() << endl; }
		else cout << " День: " << obj.getSecond() << endl;

		if (choose_menu == 3) { cout << " -> Выйти в главное меню " << endl; }
		else cout << " Выйти в главное меню " << endl;


		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int getTime(int c) {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
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
				if (key == 13 && numbers.length() != 0 && stoi(numbers) < c) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
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
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}