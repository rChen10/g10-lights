#include <vector>
#include <iostream>

#include "line.h"


#ifndef __MATRIX_H__
#define __MATRIX_H__

template <class T>
class matrix{
	public:
	std::vector< std::vector<T> > m;
	int s;
	
	matrix();

	matrix(int x, int y);

	matrix<T> copy();
	
	//matrix(matrix&& lv);

	//matrix& operator=(matrix&& lv);

	matrix<T>& operator+=(std::vector<T>& p);

	matrix<T>& operator+=(line& l);

	matrix<T>& operator+=(matrix<T>& mx);

	void ident();

	matrix<T>& operator*=(matrix<T>& m);

	int size();

	std::vector<T>& operator[](int i);

	void draw(screen& scrn);

	void draw(screen& scrn, pixel& color);
	
};

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T>& m);

matrix<double> operator*(matrix<double>& m1, matrix<double>& m2);

matrix<int> operator*(matrix<int>& m1, matrix<double>& m2);

matrix<int> operator*(matrix<double>& m1, matrix<int>& m2);
#endif
