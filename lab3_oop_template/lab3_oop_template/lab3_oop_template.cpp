#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

template<class X> class vector
{
	X *mas;
	int n;
public:
	vector(int number)
	{
		n = number;
		mas = new X[n];
	}
	vector()
	{}
	template <class X>
	vector<X> operator=(vector <X> m)
	{
		return mas = m.mas;
	}
	X& operator[](int index)
	{
		return mas[index];
	}
	int GetLength()
	{
		return n;
	}
	template <class X>
	friend ostream& operator<<(ostream& out, vector<X>& a);
};
template<class Y> class matrix
{
	int n;
	Y* mas;
public:
	matrix(int number)
	{
		n = number;
		mas = new Y[n];
	}
	matrix()
	{
	}
	Y& operator[](int index)
	{
		if (index<0 || index>n - 1)
		{
			exit(1);
		}
		return mas[index];
	}
	template<class Y>
	matrix<Y> operator=(matrix<Y> m)
	{
		return mas = m.mas;
	}
	template<class Y>
	matrix<Y> operator+(matrix<Y> m)
	{
		int N = m.n;
		int M = m.mas[0].GetLength();
		matrix<Y> temp;
		temp = m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < M; j++)
				temp[i][j] += (*this)[i][j];
		return temp;
	}
	template<class Y>
	friend ostream& operator<<(ostream& out, matrix<Y>& a);
};
template<class Y>
ostream& operator<<(ostream& out, matrix<Y>& a)
{
	for (int i = 0; i < a.n; i++)
		out << " " << a.mas[i];
	out << endl;
	return out;
}
template <class X>
ostream& operator<<(ostream& out, vector<X>& a)
{
	for (int i = 0; i < a.n; i++)
		out << " " << a.mas[i];
	out << endl;
	return out;
}
void input()
{
	int w, h;
	cout << "������� ����������� �������(2 �����, ������, �������)" << endl;
	cin >> w;
	cin >> h;
	matrix<vector<int>> matr(w);
	matrix<vector<int>> matr2(w);
	matrix<vector<int>> sum(w);
	cout << "������� ������ �������" << endl;
	for (int i = 0; i < w; i++)
	{
		cout << "������� ������" << endl;
		vector<int> vec(h);
		for (int j = 0; j < h; j++)
			cin >> vec[j];
		matr[i] = vec;
	}
	cout << "������ �������:" << endl;
	cout << matr << endl;

	cout << "������� ������ �������" << endl;
	for (int i = 0; i < w; i++)
	{
		cout << "������� ������" << endl;
		vector<int> vec(h);
		for (int j = 0; j < h; j++)
			cin >> vec[j];
		matr2[i] = vec;
	}
	cout << "������ �������:" << endl;
	cout << matr2;
	cout << "Sum:" << endl;
	sum = matr + matr2;
	cout << sum;
}
void input2()
{
	int w, h;
	cout << "������� ����������� �������(2 �����,������, �������)" << endl;
	cin >> w;
	cin >> h;
	matrix<vector<string>> matr(w);
	matrix<vector<string>> matr2(w);
	matrix<vector<string>> sum(w);
	cout << "������� ������ �������" << endl;
	for (int i = 0; i < w; i++)
	{
		cout << "������� ������" << endl;
		vector<string> vec(h);
		for (int j = 0; j < h; j++)
			cin >> vec[j];
		matr[i] = vec;
	}
	cout << "������ �������:" << endl;
	cout << matr << endl;

	cout << "������� ������ �������" << endl;
	for (int i = 0; i < w; i++)
	{
		cout << "������� ������" << endl;
		vector<string> vec(h);
		for (int j = 0; j < h; j++)
			cin >> vec[j];
		matr2[i] = vec;
	}
	cout << "������ �������:" << endl;
	cout << matr2;
	cout << "Sum:" << endl;
	sum = matr + matr2;
	cout << sum;
}
void input3()
{
	int w, h;
	cout << "������� ����������� �������(2 �����,������, �������)" << endl;
	cin >> w;
	cin >> h;
	matrix<vector<double>> matr(w);
	matrix<vector<double>> matr2(w);
	matrix<vector<double>> sum(w);
	cout << "������� ������ �������" << endl;
	for (int i = 0; i < w; i++)
	{
		cout << "������� ������" << endl;
		vector<double> vec(h);
		for (int j = 0; j < h; j++)
			cin >> vec[j];
		matr[i] = vec;
	}
	cout << "������ �������:" << endl;
	cout << matr << endl;

	cout << "������� ������ �������" << endl;
	for (int i = 0; i < w; i++)
	{
		cout << "������� ������" << endl;
		vector<double> vec(h);
		for (int j = 0; j < h; j++)
			cin >> vec[j];
		matr2[i] = vec;
	}
	cout << "������ �������:" << endl;
	cout << matr2;
	cout << "Sum:" << endl;
	sum = matr + matr2;
	cout << sum;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int vvod;
	cout << "������� 1 ��� ������ � ������� ���� integer, ������� 2 ��� ������ �� �������� " << endl;
	cout << "��� ������� 3 ��� ������ � ������� ���� double" << endl;
	cin >> vvod;
	if (vvod==1)
		input();
	if (vvod == 2)
		input2();
	if (vvod == 3)
		input3();
	if (vvod > 3)
		cout << "�� �� ����� 1, 2 ��� 3" << endl;
	char a;
	cin >> a;
	return 0;
}
/*
int w, h;
cout << "������� ����������� �������(2 �����)" << endl;
cin >> w;
cin >> h;
matrix<vector<int>> matr(w);
matrix<vector<int>> matr2(w);
matrix<vector<int>> sum(w);
cout <<"������� ������ �������" << endl;
for (int i = 0; i < w; i++)
{
cout << "������� ������" << endl;
vector<int> vec(h);
for (int j = 0; j < h; j++)
cin >> vec[j];
matr[i] = vec;
}
cout << "������ �������:" << endl;
cout << matr << endl;

cout << "������� ������ �������" << endl;
for (int i = 0; i < w; i++)
{
cout << "������� ������" << endl;
vector<int> vec(h);
for (int j = 0; j < h; j++)
cin >> vec[j];
matr2[i] = vec;
}
cout << "������ �������:" << endl;
cout << matr2;
cout << "Sum:" << endl;
sum = matr + matr2;
cout << sum;
*/