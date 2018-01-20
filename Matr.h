#pragma once

#include <iostream>

using namespace std; // ������������� ������������ ��� std

template <typename type> // �������

class Matrix // ���������� ������
{
public:				// ������������ �������
	type ** matr;	// ������������ ������ type
	int length = 0; // ������
	int column = 0; // �������
	void add();		// ���������� �������
	void del();		// �������� �������
	void in();		// ���������� �������
	void out();		// ����� �������
	void sum(Matrix<type> matr1, Matrix<type> matr2);	// ����� ������
	void mult(Matrix<type> matr1, Matrix<type> matr2);	// ��������� ������
};

template <typename type> // ���������� �������� ����� ������ ��������, � ������ ��� ������������.
Matrix<type> operator + (Matrix<type> operand1, Matrix<type> operand2) //���������� ��������� +
{
	Matrix<type> a; //�������� ���������� ��� ������ �������
	a.sum(operand1, operand2);
	return (a);
}

template <typename type>
Matrix<type> operator * (Matrix<type> operand1, Matrix<type> operand2) //���������� ��������� *
{
	Matrix<type> a;
	a.mult(operand1, operand2);
	return (a);
}

template <typename type>
istream & operator >> (istream &operand1, Matrix<type> &operand2) //���������� cin. & - ������
{
	operand2.in();
	return (operand1);
}

template <typename type>
ostream & operator << (ostream &operand1, Matrix<type> &operand2) //���������� cout
{
	operand2.out();
	return (operand1);
}

template <typename type>
void Matrix<type>::add() //���������� ����� � �������� �������
{
	matr = new type * [length];
	for (int i = 0; i < length; i++)
	{
		matr[i] = new type [column];
	}
}

template <typename type>
void Matrix<type>::del() //�������� �����, �������� � �� ������������
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
void Matrix<type>::in() //���� �������
{
	del();
	cout << "������� �����������\n";
	cin >> length >> column;
	add();
	cout << "������� ��������\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> matr[i][j];
		}
	}
}

template <typename type>
void Matrix<type>::out() //����� �������
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
void Matrix<type>::sum(Matrix<type> matr1, Matrix<type> matr2) //������������ ���� ������
{
	if (matr1.length == matr2.length && matr1.column == matr2.column) //������� ����������
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
		cout << "�������� �����������" << endl;
	}
}

template <typename type>
void Matrix<type>::mult(Matrix<type> matr1, Matrix<type> matr2) //������������ ������
{
	if (matr1.length == matr2.column) //������� ����������
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
		cout << "�������� �����������" << endl;
	}
}