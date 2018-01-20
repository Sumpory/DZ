#pragma once

#include <iostream>

using namespace std; // Использование пространства имён std

template <typename type> // Шаблоны

class Matrix // Обьявление класса
{
public:				// Спецификатор доступа
	type ** matr;	// Динамический массив type
	int length = 0; // Строки
	int column = 0; // Столбцы
	void add();		// Добавление матрицы
	void del();		// Удаление матрицы
	void in();		// Заполнение матрицы
	void out();		// Вывод матрицы
	void sum(Matrix<type> matr1, Matrix<type> matr2);	// Сумма матриц
	void mult(Matrix<type> matr1, Matrix<type> matr2);	// Умножение матриц
};

template <typename type> // Обьявление шаблонов перед каждой функцией, в кторой они используются.
Matrix<type> operator + (Matrix<type> operand1, Matrix<type> operand2) //перегрузка оператора +
{
	Matrix<type> a; //создание переменной для вызова функции
	a.sum(operand1, operand2);
	return (a);
}

template <typename type>
Matrix<type> operator * (Matrix<type> operand1, Matrix<type> operand2) //перегрузка оператора *
{
	Matrix<type> a;
	a.mult(operand1, operand2);
	return (a);
}

template <typename type>
istream & operator >> (istream &operand1, Matrix<type> &operand2) //перегрузка cin. & - ссылка
{
	operand2.in();
	return (operand1);
}

template <typename type>
ostream & operator << (ostream &operand1, Matrix<type> &operand2) //перегрузка cout
{
	operand2.out();
	return (operand1);
}

template <typename type>
void Matrix<type>::add() //добавление строк и столбцов матрицы
{
	matr = new type * [length];
	for (int i = 0; i < length; i++)
	{
		matr[i] = new type [column];
	}
}

template <typename type>
void Matrix<type>::del() //удаление строк, столбцов и их размерностей
{
	for (int i = 0; i < length; i++)
	{
		delete[] matr[i];
	}
	delete[] matr;
	length = 0;
	column = 0;
}

template <typename type>
void Matrix<type>::in() //ввод матрицы
{
	del();
	cout << "Введите размерности\n";
	cin >> length >> column;
	add();
	cout << "Введите элементы\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> matr[i][j];
		}
	}
}

template <typename type>
void Matrix<type>::out() //вывод матрицы
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename type>
void Matrix<type>::sum(Matrix<type> matr1, Matrix<type> matr2) //суммирование двух матриц
{
	if (matr1.length == matr2.length && matr1.column == matr2.column) //условие выполнения
	{
		del();
		length = matr1.length;
		column = matr1.column;
		add();
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < column; j++)
			{
				matr[i][j] = matr1.matr[i][j] + matr2.matr[i][j];
			}
		}
	}
	else
	{
		cout << "Неверные размерности" << endl;
	}
}

template <typename type>
void Matrix<type>::mult(Matrix<type> matr1, Matrix<type> matr2) //перемножение матриц
{
	if (matr1.length == matr2.column) //условие выполнения
	{
		del();
		length = matr1.length;
		column = matr2.column;
		add();
		for (int i = 0; i < length; i++)
		{
			
			for (int j = 0; j < column; j++)
			{
				matr[i][j] = 0;
				for (int k = 0; k < matr1.column; k++)
				{
					matr[i][j] += matr1.matr[i][k] * matr2.matr[k][j];
				}
			}
		}
	}
	else
	{
		cout << "Неверные размерности" << endl;
	}
}