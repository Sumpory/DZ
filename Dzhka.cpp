

#include "stdafx.h"
#include <iostream> // Системные каталоги
#include "Matr.h" // Подключение заголовков
#include "Vector.h"

using namespace std; 

int main()
{
	setlocale(LC_ALL, "");
	Matrix<int> matr, matr1, matr2; // Объявление переменных
	Vector<int> vector, vector1, vector2;
	
	cout << "Выберите тип вычисления\n1)Умножение матрицы на матрицу\n2)Сумма матриц\n3)Векторное произведение (\n4)Скалярное произведение векторов\nИли нажмите 0 для выхода\n";
	unsigned short V = 1;
	while (V != 0) // Возможность выбора другой операции, пока не вписан 0
	{
		cin >> V;
		switch (V)
		{
		case 1: // Умножение матриц (векторов)
		{
			cout << "Первая матрица" << endl;
			cin >> matr1;
			cout << "Вторая матрица" << endl;
			cin >> matr2;
			matr = matr1 * matr2;
			cout << matr;
			break;
		}

		case 2: // Сумма матриц (векторов)
		{
			cout << "Первая матрица" << endl;
			cin >> matr1;
			cout << "Вторая матрица" << endl;
			cin >> matr2;
			matr = matr1 + matr2;
			cout << matr;
			break;
		}

		case 3: // Векторное произведение
		{
			cout << "Первый вектор" << endl;
			cin >> vector1;
			cout << "Второй вектор" << endl;
			cin >> vector2;
			vector = vector1 * vector2;
			cout << vector;
			break;
		}

		case 4: // Скалярное произведение векторов
		{
			cout << "Первый вектор" << endl;
			cin >> vector1;
			cout << "Второй вектор" << endl;
			cin >> vector2;
			vector = vector1 ^ vector2;
			cout << vector;
			break;
		}

		default:
		{
			break;
		}
		}

	}
	//system("pause");
	return 0;
}