#include "color.h"
#include "vec3.h"

#include <stdio.h>

int main() {

	int image_height = 256;
	int image_width = 256;

	printf("P3\n%d %d\n255\n", image_width, image_height);

	for (int j = 0; j < image_height; ++j) {
		fprintf(stderr, "\rScanlines remaining: %d ", (image_height - j));
		fflush(stderr);
		for (int i = 0; i < image_width; ++i) {
			color pixel_color = vec3_create((double)i / (image_width - 1), (double)j / (image_height - 1), 0.0);
			write_color(stdout, pixel_color);
		}
	}

	fprintf(stderr, "\rDone. 						\n");
}
