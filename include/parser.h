#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <vector>
#include "matrix.h"
#include "polygon.h"

void parse_file ( const char * filename, 
		  std::vector< matrix<double> >& world, 
		  matrix<int>& edges,
		  polygon& polygons,
		  screen& s,
		  my::vector view,
		  light l,
		  light ambient,
		  double areflect[],
		  double dreflect[],
		  double sreflect[]);

#endif
