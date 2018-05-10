#include "../include/my.h"
#include <cmath>

//std::vector<double> my::view = my::vector(0, 0, 1, 1);

my::vector::vector() : std::vector<double>(){
}

my::vector::vector(double a, double b, double c, double d) : std::vector<double>(){
	(*this).push_back(a);
	(*this).push_back(b);
	(*this).push_back(c);
	(*this).push_back(d);
}

my::vector::vector(int a, int b, int c, int d) : std::vector<double>(){
	(*this).push_back(a);
	(*this).push_back(b);
	(*this).push_back(c);
	(*this).push_back(d);
}

my::vector::vector(std::vector<double>& v1, std::vector<double>& v2) : std::vector<double>(){
	(*this).push_back(v2[0] - v1[0]);
	(*this).push_back(v2[1] - v1[1]);
	(*this).push_back(v2[2] - v1[2]);
	(*this).push_back(1);
}

my::vector::vector(std::vector<int>& v1, std::vector<int>& v2) : std::vector<double>(){
	(*this).push_back(v2[0] - v1[0]);
	(*this).push_back(v2[1] - v1[1]);
	(*this).push_back(v2[2] - v1[2]);
	(*this).push_back(1);
}

double my::vector::dot(std::vector<double>& v){
	return (v[0] * (*this)[0]) + (v[1] * (*this)[1]) + (v[2] * (*this)[2]);
}

my::vector my::vector::cross(std::vector<double>& v){
	my::vector ret = my::vector();
	ret.push_back( ((*this)[1] * v[2]) - ((*this)[2] * v[1]) );
	ret.push_back( ((*this)[2] * v[0]) - ((*this)[0] * v[2]) );
	ret.push_back( ((*this)[0] * v[1]) - ((*this)[1] * v[0]) );
	ret.push_back(1.0);

	return ret;
}

void my::vector::normalize(){
	double mag = sqrt(pow((*this)[0], 2) + pow((*this)[1], 2) + pow((*this)[2], 2));

	(*this)[0] = (*this)[0] / mag;
	(*this)[1] = (*this)[1] / mag;
	(*this)[2] = (*this)[2] / mag;
}

my::vector operator*(double d, my::vector v){
	my::vector ret = my::vector(d * v[0], d * v[1], d * v[2], 1.0);
	return ret;
}

my::vector operator-(my::vector v1, my::vector v2){
	my::vector ret = my::vector(v1[0]-v2[0], v1[1]-v2[1], v1[2]-v2[2], 1.0);
	return ret;
}
