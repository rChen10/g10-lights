#ifndef __POLYGON_H__
#define __POLYGON_H_

#include <iostream>
#include <fstream>
#include <cmath>

#include "matrix.h"
#include "my.h"

struct light{
	point location;
	pixel color;
};

class polygon : public matrix<int>{
	public:
	
	double areflect[3];
	double dreflect[3];
	double sreflect[3];

	polygon();

	polygon(matrix<double>&);

	polygon(matrix<int>&);

	polygon& operator+=(line l);

	polygon& operator+=(std::vector<int>& p);

	polygon& operator+=(std::vector<double>& p);

	polygon& operator+=(line& l);

	polygon& operator+=(matrix<int>& mx);

	void ident();

	int size();

	std::vector<int>& operator[](int i);

	void draw(screen& scrn, std::vector< light > lights, my::vector view);

	void draw(screen& scrn, pixel& color);

	void set_areflect(double aref[]);

	void set_dreflect(double dref[]);

	void set_sreflect(double sref[]);
};


#define PI atan(1)*4
//helper
static double convert(double theta){
	return theta * PI / 180;
}

matrix<double> create_translate(std::vector<double> p);

matrix<double> create_scale(std::vector<double> a);

matrix<double> create_rotateZ(double theta);

matrix<double> create_rotateX(double theta);

matrix<double> create_rotateY(double theta);



matrix<int> make_curve(matrix<int>& coefs, int step);

matrix<int> make_circle(double r, std::vector<double>& pc, int step);

matrix<int> generate_curve_coefs(matrix<double>& a, int type);


matrix<int> create_sphere(std::vector<double>& pc, double r, int step);

matrix<int> generate_sphere(std::vector<double>& pc, double r, int step);

matrix<int> create_torus(std::vector<double>& pc, double r, double R, int step);

matrix<int> generate_torus(std::vector<double>& pc, double r, double R, int step);

matrix<int> create_box(std::vector<double>& pc, double w, double h, double d);



void fill_poly(point t, point m, point b, screen& s, pixel p);
#endif
