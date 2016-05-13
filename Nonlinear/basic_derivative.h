#ifndef BASIC_DERIVATIVE
#define BASIC_DERIVATIVE

#include "fai.h"
#include <vector>
#include <sstream>

string first_derivative(const string &polynomial, vector<fai> &coefficient, vector<fai> &exponential) {
	int sign = 1, exponential_sign = 0;
	double numb = 0, one = 1;
	fai temp(numb);
	char judge = '0';
	string first_derivative, numbber;

	for (auto c : polynomial) {
		if (c == '-' || c == '+') {
			if (c == '-') {
				if (numb != 0) {
					temp.setdata(numb);
					exponential.push_back(temp);
					numb = 0;
				}
				if (judge == 'x') {
					temp.setdata(one);
					exponential.push_back(temp);
				}
				sign = -1;
			}
			else {
				if (judge == 'x') {
					temp.setdata(one);
					exponential.push_back(temp);
				}
				if (numb != 0) {
					temp.setdata(numb);
					exponential.push_back(temp);
					numb = 0;
				}
			}
		}
		else if (isdigit(c))
			numb = c - '0' + numb * 10;
		else if (c == '*') {
			if (sign == -1) {
				numb *= sign;
				temp.setdata(numb);
				coefficient.push_back(temp);
				numb = 0;
				sign = 1;
			}
			else {
				temp.setdata(numb);
				coefficient.push_back(temp);
				numb = 0;
			}
		}
		else if (c == '^')
			exponential_sign = 1;
		else if (c == ')') {
			if (exponential_sign == 1) {
				if (sign == -1) {
					numb *= sign;
					sign = 1;
				}
				temp.setdata(numb);
				exponential.push_back(temp);
				numb = 0;
				exponential_sign = 0;
			}
			else {
				if (sign == -1) {
					numb *= sign;
					sign = 1;
				}
				temp.setdata(numb);
				coefficient.push_back(temp);
				numb = 0;
			}
		}

		if (c == 'x' && judge != '*') {
			if (sign == -1)
				one *= sign;
			temp.setdata(one);
			coefficient.push_back(temp);
			one = 1;
			sign = 1;
		}

		judge = c;
	}
	if (numb != 0) {
		temp.setdata(numb);
		coefficient.push_back(temp);
		numb = 0;
		temp.setdata(numb);
		exponential.push_back(temp);
	}

	for (int i = 0; i < (int)coefficient.size(); ++i) {
		numb = coefficient[i].getdata() * exponential[i].getdata();
		coefficient[i].setdata(numb);
		if (exponential[i].getdata() != 0) {
			numb = exponential[i].getdata() - 1;
			exponential[i].setdata(numb);
		}
		stringstream str;
		str << coefficient[i].getdata();
		str >> numbber;
		if (coefficient[i].getdata() < 0)
			numbber = "(" + numbber + ")";
		first_derivative = first_derivative + "+" + numbber + "*x^";
		str.clear();
		str << exponential[i].getdata();
		str >> numbber;
		if (exponential[i].getdata() < 0)
			numbber = "(" + numbber + ")";
		first_derivative = first_derivative + numbber;
	}

	return first_derivative;
}



#endif // !FIRST_DE