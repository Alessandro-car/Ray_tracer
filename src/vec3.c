#include "vec3.h"

#include <math.h>
#include <stdio.h>

vec3 vec3_create(double e0, double e1, double e2) {
	vec3 v = {{e0, e1, e2}};
	return v;
}

vec3 vec3_zero(void) {
	return vec3_create(0, 0, 0);
}

double x(const vec3 *v) {
	return v->e[0];
}

double y(const vec3 *v) {
	return v->e[1];
}

double z(const vec3 *v) {
	return v->e[2];
}

double vec3_get(const vec3 *v, int i) {
	return v->e[i];
}

void vec3_set(vec3* v, int i, double value) {
	v->e[i] = value;
}

vec3 vec3_negate(const vec3 *v) {
	return vec3_create(-v->e[0], -v->e[1], -v->e[2]);
}

vec3 vec3_add(const vec3* u, const vec3 *v) {
	return vec3_create(
		u->e[0] + v->e[0],
		u->e[1] + v->e[1],
		u->e[2] + v->e[2]
	);
}

void vec3_add_assign(vec3 *u, const vec3 *v) {
	u->e[0] += v->e[0];
	u->e[0] += v->e[0];
	u->e[0] += v->e[0];
}

vec3 vec3_subtract(const vec3 *u, const vec3 *v) {
	return vec3_create(
		u->e[0] - v->e[0],
		u->e[1] - v->e[1],
		u->e[2] - v->e[2]
	);
}

vec3 vec3_multiply(const vec3 *u, const vec3 *v) {
	return vec3_create(
		u->e[0] * v->e[0],
		u->e[1] * v->e[1],
		u->e[2] * v->e[2]
	);
}

vec3 vec3_multiply_scalar(const vec3 *v, double t) {
	return vec3_create(
		v->e[0] * t,
		v->e[1] * t,
		v->e[2] * t
	);
}

void vec3_multiply_assign(vec3 *v, double t) {
	v->e[0] *= t;
	v->e[1] *= t;
	v->e[2] *= t;
}

vec3 vec3_divide(const vec3 *v, double t) {
	return vec3_multiply_scalar(v, 1.0 / t);
}

void vec3_divide_assign(vec3 *v, double t) {
	vec3_multiply_assign(v, 1.0 / t);
}

double vec3_length_squared(const vec3* v) {
	return v->e[0] * v->e[0] +
				 v->e[1] * v->e[1] +
				 v->e[2] * v->e[2];
}

double vec3_length(const vec3 *v) {
	return sqrt(vec3_length_squared(v));
}

double vec3_dot(const vec3* u, const vec3* v) {
	return u->e[0] * v->e[0] +
				 u->e[1] * v->e[1] +
				 u->e[2] * v->e[2];
}

vec3 vec3_cross(const vec3* u, const vec3 *v) {
	return vec3_create(
		u->e[1] * v->e[2] - u->e[2] * v->e[1],
		u->e[2] * v->e[0] - u->e[0] * v->e[2],
		u->e[0] * v->e[1] - u->e[1] * v->e[0]
	);
}

vec3 vec3_unit_vector(const vec3 *v) {
	return vec3_divide(v, vec3_length(v));
}

void vec3_print(const vec3* v) {
	printf("%f %f %f", v->e[0], v->e[1], v->e[2]);
}
