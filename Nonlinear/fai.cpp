#include "fai.h"


double fai::getdata() {
	return data;
}

void fai::setdata(double & in) {
	data = in;
}

fai operator + (const fai & left, const fai &right) {
	return fai(left.data + right.data);
}

fai operator -(const fai & left, const fai &right) {
	return fai(left.data - right.data);
}

fai operator * (const fai & left, const fai &right) {
	return fai(left.data * right.data);
}

fai operator / (const fai & left, const fai &right) {
	return fai(left.data / right.data);
}