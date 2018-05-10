#ifndef __MY_H__
#define __MY_H__

#include <vector>

namespace my{
	class vector : public std::vector<double>{
		//std::vector doesnt implement dot or cross, but still using its memory management

		public:

		vector();

		vector(double, double, double, double);

		vector(int, int, int, int);

		vector(std::vector<double>& v1, std::vector<double>& v2);

		vector(std::vector<int>& v1, std::vector<int>& v2);

		double dot(std::vector<double>& v);	

		my::vector cross(std::vector<double>& v);

		void normalize();

	};
}

my::vector operator*(double d, my::vector v);

my::vector operator-(my::vector v1, my::vector v2);

#endif
