#include "color.h"

#include <stdio.h>

void write_color(FILE* out, const color pixel_color) {
	double r = x(&pixel_color);
	double g = y(&pixel_color);
	double b = z(&pixel_color);

	int rbyte = (int)255.999 * r;
	int gbyte = (int)255.999 * g;
	int bbyte = (int)255.999 * b;


	fprintf(out, "%d %d %d\n", rbyte, gbyte, bbyte);
}

