#include <vector>
#include <iostream>
#include "../include/matrix.h"

template <class T>
matrix<T>::matrix(){
	m = std::vector< std::vector<T> >();
	s = 0;
}

template <class T>
matrix<T>::matrix(int x, int y){
		std::vector<T> *v;
		for(int i = 0; i < x; i++){
			v = new std::vector<T>((0, y));
			m.push_back(*v);
		}
		s = x;
}

template <class T>
matrix<T> matrix<T>::copy(){
	matrix<T> ret;
	std::vector<T> *v;
	for(int i = 0; i < s; i++){
		v = new std::vector<T>();
		for(int j = 0; j < m[0].size(); j++){
			(*v).push_back(m[i][j]);
		}
		ret += (*v);
	}
	return ret;
}

//matrix<T>::matrix( matrix<T>matrix&& rv ){
//	m = std::move(rv.m);
//	s = rv.s;
//
//	rv.s = 0;
//}
//
//matrix<T>& matrix::operator=(matrix<T>matrix&& rv){
//	m = std::move(rv.m);
//	s = rv.s;
//	return (*this);
//}

template <class T>
matrix<T>& matrix<T>::operator+=(std::vector<T>& p){
	m.push_back(p);
	s++;
	return *this;
}

template <class T>
matrix<T>& matrix<T>::operator+=(line& l){
	std::vector<T> p00 = std::vector<T>();
	p00.push_back(l.p0[0]);
	p00.push_back(l.p0[1]);
	p00.push_back(l.p0[2]);
	p00.push_back(l.p0[3]);

	std::vector<T> p01 = std::vector<T>();
	p01.push_back(l.p1[0]);
	p01.push_back(l.p1[1]);
	p01.push_back(l.p1[2]);
	p01.push_back(l.p1[3]);

	m.push_back(p00);
	m.push_back(p01);
	s+=2;
	return *this;
}

template <class T>
matrix<T>& matrix<T>::operator+=(matrix<T>& mx){
	for(int i = 0; i < mx.size(); i++){
		(*this) += mx[i];
	}
	return *this;
}

template <class T>
void matrix<T>::ident(){
		for(int i = 0; i < s; i++){
			for(int j = 0; j < m[i].size(); j++){
				if( j == i )
					m[i][j] = 1;
				else
					m[i][j] = 0;
			}
		}	
}

template <class T>
matrix<T>& matrix<T>::operator*=(matrix<T>& m){
		return *this;
}

template <class T>
int matrix<T>::size(){
		return s;
}

template <class T>
std::vector<T>& matrix<T>::operator[](int i){
	return m[i];
}

template <class T>
void matrix<T>::draw(screen& scrn){
		for(int i = 0; i < s; i+=2){
			point p0 = point(m[i]);
			point p1 = point(m[i+1]);
			line l = line(p0, p1);
			l.draw(scrn);

		}
}

template <class T>
void matrix<T>::draw(screen& scrn, pixel& color){
		for(int i = 0; i < s; i+=2){
			point p0 = point(m[i]);
			point p1 = point(m[i+1]);
			line l = line(p0, p1);
			l.set_color(color);
			l.draw(scrn);

		}
}

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T>& m){
	//os << m.size() << "\n";
	for(int i = 0; i < m[0].size(); i++){
		os << "| ";
		for(int j = 0; j < m.size(); j++){
			os << m[j][i] << " ";
		}
		os << "|\n";
	}

	return os;
}

matrix<double> operator*(matrix<double>& m1, matrix<double>& m2){
	double sum = 0;
	matrix<double> m = matrix<double>();
	std::vector<double> *v;
	for(int i = 0; i < m2.size(); i++){
		v = new std::vector<double>();
		for(int j = 0; j < m2[0].size(); j++){
			for(int k = 0; k < m2[0].size(); k++){
				sum += m1[k][j] * m2[i][k];
			}
			(*v).push_back(sum);
			sum = 0;
		}
		m += (*v);
	}
	return m;
}

matrix<int> operator*(matrix<int>& m1, matrix<double>& m2){
	double sum = 0;
	matrix<int> m = matrix<int>();
	std::vector<int> *v;
	for(int i = 0; i < m2.size(); i++){
		v = new std::vector<int>();
		for(int j = 0; j < m2[0].size(); j++){
			for(int k = 0; k < m2[0].size(); k++){
				sum += m1[k][j] * m2[i][k];
			}
			(*v).push_back(sum);
			sum = 0;
		}
		m += (*v);
	}
	return m;
}

matrix<int> operator*(matrix<double>& m1, matrix<int>& m2){
	double sum = 0;
	matrix<int> m = matrix<int>();
	std::vector<int> *v;
	for(int i = 0; i < m2.size(); i++){
		v = new std::vector<int>();
		for(int j = 0; j < m2[0].size(); j++){
			for(int k = 0; k < m2[0].size(); k++){
				sum += m1[k][j] * m2[i][k];
			}
			(*v).push_back(sum);
			sum = 0;
		}
		m += (*v);
	}
	return m;
}

template class matrix<int>;
template class matrix<double>;
