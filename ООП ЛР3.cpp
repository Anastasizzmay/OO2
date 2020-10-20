#include <iomanip>
#include <iostream>

void showMenu();
int mainMenu();

using namespace std;

class Matrix;

class vectorr
{
private:
	int numberOfElements;
	int* vect;
public:
	void show();
	void fill();
	~vectorr();
	vectorr(int);
	vectorr(const vectorr&);
	friend void MatrMultiply(int n, Matrix& arr, vectorr& vect, vectorr& rec);
};

class Matrix
{
private:
	int n;
	int** arr;
public:
	~Matrix(); //Диструктор
	Matrix(int);
	Matrix(const Matrix&);
	void shown();
	void filll();
	friend void MatrMultiply(int n, Matrix& arr, vectorr& vect, vectorr& rec);
};

vectorr::vectorr(int number) :numberOfElements (number)
{
	vect = new int[number];
}

vectorr::vectorr(const vectorr& external)
{
	numberOfElements = external.numberOfElements;
	vect = new int[numberOfElements];
	for (int i = 0; i < numberOfElements; i++)
		vect[i] = external.vect[i];
}

void MatrMultiply(int n, Matrix& matrix, vectorr& vektor, vectorr& rec)
{
	for (int i = 0; i < n; i++)
	{
		float temp = 0;
		for (int j = 0; j < n; j++)
		{
			temp += matrix.arr[i][j] * vektor.vect[j];
		}
	    rec.vect[i] = temp;
	}
}

void Matrix::filll()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j] ;
		}
	}
}

void vectorr::fill()
{
	for (int i = 0; i < numberOfElements; i++)
		cin >> vect[i];
}

void vectorr::show()
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << setw(4) << vect[i];
	}
}

int main()
{
	setlocale(0, "");
	cout << endl;
	mainMenu();
	return 0;
}


void showMenu()
{
	cout << "\t1) Показать матрицу\n\t2) Показать вектор\n\t3) Умножение матрицы на вектор\n\t4) Выход\n\tВаш выбор:> ";
}
int mainMenu()
{
	int t, choice;
	cout << endl << "\t Введите размер матрицы";
	cin >> t;
	Matrix f(t);
	cout << "\tВведите элементы матрицы: ";
	f.filll();
	cout << endl << "\tВведите кол-во координат вектора: ";
	int temp;
	cin >> temp;
	vectorr vect(temp);
	cout << "\tВведите элементы вектора: ";
	vect.fill();
	while (true)
	{
		showMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << endl << "\t";
			f.shown();
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl << "\t";
			vect.show();
			cout << endl;
			break;
		}
		case 3:
		{
			vectorr rec(temp);
			MatrMultiply(t, f, vect, rec);
			cout << endl << "\t";
			rec.show();
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

Matrix::~Matrix()
{
	for (int z = 0; z < n; z++)
		delete[] arr[z];
	delete[] arr;
}

vectorr::~vectorr()
{
	delete[] vect;
}

void Matrix::shown()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix::Matrix(int number) :n(number)
{
	arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
}

Matrix::Matrix(const Matrix& external)
{
	n = external.n;
	arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = external.arr[i];
}