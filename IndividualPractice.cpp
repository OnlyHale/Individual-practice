/*********************************************************************************
*Project Name : Practica_Individual												 *
*File Name : Practica_Individual.cpp											 *
*Language : CPP, MSVS ver 2015 and above										 *
*Programmers : Ратников Роман Олегович, группа : М3О - 110Б - 20				 *
*Modified By :																	 *
*Created : 30 / 05 / 2021														 *
*Last Revision : 24 / 06 / 2021													 *
*Comment : Практика																 *
*********************************************************************************/
#include <iostream>
#include <math.h>
using namespace std;
//Функция для метода бисекции
double Function(double x)
{
	double e = 2.7182;
	double Function;
	Function = pow(e, x) - 1 / sqrt(x);
	return Function;
}
//Функция для метода простой итерации
double Function2(double x)
{
	double e = 2.7182;
	double Function2;
	Function2 = pow(e, -2 * x);
	return Function2;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	double fa; //Значение 1 функции в а
	double fc; //Значение 1 функции в с
	double Eps; //Точность для метода бисекции
	double a = 0.3; //Левая граница отрезка
	double b = 0.8; //Праввая граница отрезка
	double Bufer; //Переменная для хранения значения
	//Для корректности границ
	if (a > b)
	{
		Bufer = b;
		b = a;
		a = Bufer;
	}
	double c; //Середина отрезка
	double value; //Приближённое значение
	int i = 0;
	cout << " Введите точность:";
	cin >> Eps;
	if (Eps <= 0)
	{
		cout << " Ошибка.Eps должен быть больше 0.";
		return 1;
	}
	cout << "\n Eps = " << Eps << endl; // Эхо - печать
	double Diff = b - a; //Длина промежутка
	cout << fixed; //Корректность печати
	cout << "\n\tМетод бисекции" << endl;
	//Шапка таблицы
	cout << " Итерация""\t\tc" << "\t\tFunction(a)" << "\t\tFunction(c)" << "\
t\tDiff" << endl;
	while (Diff > Eps)
	{
		c = (b + a) / 2;
		if (c > 0)
			fc = Function(c);
		else
		{
			cout << " Некорректные данные" << endl;
			return 2;
		}
		if (a > 0)
			fa = Function(a);
		else
		{
			cout << " Некорректные данные" << endl;
			return 3;
		}
		cout << "\t " << i + 1 << "\t\t" << c << "\t" << fa << "\t\t" << fc << "\t\t" << Diff <<
			endl;
		if (fc * fa < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}
		i++;
		Diff = b - a;
	}
	//Вычисление и печать последней строки таблицы
	c = (b + a) / 2;
	if (c > 0)
		fc = Function(c);
	else
	{
		cout << " Некорректные данные" << endl;
		return 2;
	}

	if (a > 0)
		fa = Function(a);
	else
	{
		cout << " Некорректные данные" << endl;
		return 3;
	}
	cout << "\t " << i + 1 << "\t\t" << c << "\t" << fa << "\t\t" << fc << "\t\t"
		<< Diff << endl;
	value = c;
	cout << "\t\t" << "Длина промежутка(разность)= " << Diff << "\n\t"
		<< "Приближённое значение : = " << value << ".Принадлежит отрезку ["<<a<<"; "<<b<<"]"<<endl;
		double Eps2;
	cout << "\nВведите точность для метода простой итерации:";
	cin >> Eps2;
	if (Eps2 <= 0)
	{
		cout << " Ошибка.Eps2 должен быть больше 0.";
		return 4;
	}
	cout << "\n Eps2 = " << Eps2 << endl; //Эхо-печать
	i = 0;
	Diff = value - Function2(value);
	if (Diff < 0)
	{
		Diff = -Diff;
	}
	cout << "\n\tМетод простой итерации" << endl;
	//Шапка таблицы
	cout << "\t\tk" << "\t\tX k" << "\t\t\tX k+1" << "\t\t\tDiff" << endl;
	while (Diff > Eps2)
	{
		cout << "\t\t" << i + 1 << "\t\t" << value << "\t\t" << Function2(value)
			<< "\t\t" << Diff << endl;
		value = Function2(value);
		Diff = value - Function2(value);
		if (Diff < 0)
		{
			Diff = -Diff;
		}
		i++;
	}
	//Печать последней строки таблицы
	cout << "\t\t" << i + 1 << "\t\t" << value << "\t\t" << Function2(value) <<
		"\t\t" << Diff << endl;
	cout << "\n После " << i + 1 << " итераций с точностью " << Eps2 << " найден искомый корень : " << Function2(value) << endl;
		return 0;
}