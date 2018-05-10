#include "../include/parser.h"

int main(int argc, char **argv){
	screen s = screen(500, 500);
	matrix<double> transform = matrix<double>(4, 4);
	transform.ident();
	std::vector< matrix<double> > world = std::vector< matrix<double> >();
	world.push_back(transform);
	matrix<int> edges = matrix<int>();
	polygon poly = polygon();

	my::vector view = my::vector(0, 0, 1, 1);
	point ambient_l = point(0, 0, 0, 1);
	point light_l = point(500, 500, 500, 1);
	pixel ambient_c = pixel(50, 50, 50);
	pixel light_c = pixel(0, 255, 255);
	double areflect[] = {0.1, 0.1, 0.1};
	double dreflect[] = {0.5, 0.5, 0.5};
	double sreflect[] = {0.5, 0.5, 0.5};

	struct light l;
	l.location = light_l;
	l.color = light_c;

	struct light ambient;
	ambient.location = ambient_l;
	ambient.color = ambient_c;

	if(argc > 0){
		std::cout << "reading script...";
		parse_file(argv[1], world, edges, poly, s, view, l, ambient, areflect, dreflect, sreflect);
	}
	else
		return 1;
}
