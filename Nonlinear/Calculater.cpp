// Calculater.cpp : 定义控制台应用程序的入口点。

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

	//第一种基本函数求导法
	first_der = first_derivative(polynomial, coefficient, exponential);

	/*cout << "请输入原函数："; cin >> polynomial;
	  cout << "请输入选择的接近值："; cin >> var;*/
	cout << "原函数为：" << polynomial << endl;
	cout << "一阶导数为：" <<first_der << endl;
	cout << "x的值为：" << var << endl;

	long double ori_func = calcu(polynomial, var);
	long double fir_func = calcu(first_der, var);
	cout << fir_func << endl;

	long double result = ori_func / fir_func;
	cout <<"原函数除以一阶导数的结果为：" << result << endl << endl << endl;


	//第二种插值法求导
	/*cout << "请输入原函数："; cin >> polynomial;
	  cout << "请输入选择的接近值："; cin >> a;*/
	string a = "3.66";
	long double steper = 0.001;
	string var_one = step(a, steper, '+');
	string var_two = step(a, steper, '-');

	long double func_val_one = calcu(polynomial, var_one);
	long double func_val_two = calcu(polynomial, var_two);
	cout << "求导处a的值为" << a << endl;
	cout << "f(a + steper)为" << func_val_one << endl;
	cout << "f(a - steper)为" << func_val_two << endl;

	long double first_der_num = (func_val_one - func_val_two) / (2 * steper);
	cout << first_der_num << endl;

	system("pause");

	return 0;
}