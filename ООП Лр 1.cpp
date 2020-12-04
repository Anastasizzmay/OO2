#include<Windows.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите символ (строчную или прописную букву алфавита)" << endl;
	char lit;
	cin >> lit;
	int k;
	k = (int)lit;
	cout << k << " " << lit << endl; 
	cout << lit <<  " " << k << " " << hex << k << " " << oct << endl;
}