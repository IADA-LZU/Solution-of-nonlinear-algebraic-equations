#ifndef FAI_H
#define FAI_H

#include <iostream>

class fai
{
public:
	fai(double in) : data(in) {}

	double getdata();
	void setdata(double &);

	friend fai operator+ (const fai &, const fai &);
	friend fai operator- (const fai &, const fai &);
	friend fai operator* (const fai &, const fai &);
	friend fai operator/ (const fai &, const fai &);

private:
	long double data;

};

#endif