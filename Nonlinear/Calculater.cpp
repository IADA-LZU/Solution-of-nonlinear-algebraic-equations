// Calculater.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <memory.h>
#include "Digit.h"
#include "function.h"
#include "basic_derivative.h"
#include "func_define.h"
#include "multi_calu.h"
#include "step.h"
#include "fai.h"
#include <vector>
#include <sstream>


using namespace std;



int main()
{
	string polynomial = "-3*x^(-3)-x^2+x+1";
	string first_der;
	string var = "3.66";
	vector<fai> coefficient, exponential;

	//��һ�ֻ��������󵼷�
	first_der = first_derivative(polynomial, coefficient, exponential);

	/*cout << "������ԭ������"; cin >> polynomial;
	  cout << "������ѡ��Ľӽ�ֵ��"; cin >> var;*/
	cout << "ԭ����Ϊ��" << polynomial << endl;
	cout << "һ�׵���Ϊ��" <<first_der << endl;
	cout << "x��ֵΪ��" << var << endl;

	long double ori_func = calcu(polynomial, var);
	long double fir_func = calcu(first_der, var);
	cout << fir_func << endl;

	long double result = ori_func / fir_func;
	cout <<"ԭ��������һ�׵����Ľ��Ϊ��" << result << endl << endl << endl;


	//�ڶ��ֲ�ֵ����
	/*cout << "������ԭ������"; cin >> polynomial;
	  cout << "������ѡ��Ľӽ�ֵ��"; cin >> a;*/
	string a = "3.66";
	long double steper = 0.001;
	string var_one = step(a, steper, '+');
	string var_two = step(a, steper, '-');

	long double func_val_one = calcu(polynomial, var_one);
	long double func_val_two = calcu(polynomial, var_two);
	cout << "�󵼴�a��ֵΪ" << a << endl;
	cout << "f(a + steper)Ϊ" << func_val_one << endl;
	cout << "f(a - steper)Ϊ" << func_val_two << endl;

	long double first_der_num = (func_val_one - func_val_two) / (2 * steper);
	cout << first_der_num << endl;

	system("pause");

	return 0;
}