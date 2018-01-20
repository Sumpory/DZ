#pragma once

#include "Matr.h" //����������� ������������� ����� 

template <typename type>

class Vector : public Matrix<type> //���������� ������ ������ � �������������
{
public:
	void scalar(Vector<type> matr1, Vector<type> matr2);	//��������� ������������
	void vectmult(Vector<type> matr1, Vector<type> matr2);	//��������� ������������
};

template <typename type>
Vector<type> operator ^ (Vector<type> operand1, Vector<type> operand2) //���������� ���������� ������������
{
	Vector<type> a;
	a.scalar(operand1, operand2);
	return (a);
}

template <typename type>
Vector<type> operator * (Vector<type> operand1, Vector<type> operand2) //���������� ���������� ������������
{
	Vector<type> a;
	a.vectmult(operand1, operand2);
	return (a);
}

template <typename type>
void Vector<type>::scalar(Vector<type> matr1, Vector<type> matr2) //��������� ������������
{
	if (matr1.length == matr2.length && matr1.column == matr2.column) // ���������� ������ ��� ��������� ��� �������
	{
		del();
		length = 1;
		column = 1;
		add();
		matr[0][0] = 0;
		for (int i = 0; i < matr1.column; i++)
		{
			matr[0][0] += matr1.matr[0][i] * matr2.matr[0][i];
		}
	}
	else
	{
		cout << "�������� �����������\n";
	}
}

template <typename type>
void Vector<type>::vectmult(Vector<type> matr1, Vector<type> matr2) //��������� ������������
{
	if (matr1.length == 1 && matr2.length == 1 && matr1.column == 3 && matr2.column == 3) //������� ����������
	{
		del();
		length = 1;
		column = 3;
		add();
		matr[0][0] = matr1.matr[0][1] * matr2.matr[0][2] - matr2.matr[0][1] * matr1.matr[0][2];
		matr[0][1] = matr2.matr[0][0] * matr1.matr[0][2] - matr1.matr[0][0] * matr2.matr[0][2];
		matr[0][2] = matr1.matr[0][0] * matr2.matr[0][1] - matr2.matr[0][0] * matr1.matr[0][1];
	}
	else
	{
		cout << "�������� ����������� �������" << endl;
	}
}