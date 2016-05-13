#ifndef STEP
#define STEP

string step(string &var, long double &steper, char sign) {
	string step_str;
	long double var_n;
	stringstream sst;
	sst << var;
	sst >> var_n;
	sst.clear();
	if (sign == '+')
		sst << (var_n + steper);
	else
		sst << (var_n - steper);

	sst >> step_str;
	return step_str;
}

#endif // !STEP

