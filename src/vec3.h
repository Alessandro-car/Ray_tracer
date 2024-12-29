#ifndef VEC3_H
#define VEC3_H

typedef struct {
	double e[3];
} vec3;

typedef vec3 point3;

vec3 vec3_create(double e0, double e1, double e2);

vec3 vec3_zero(void);

double x(const vec3 *v);

double y(const vec3 *v);

double z(const vec3 *v);

double vec3_get(const vec3 *v, int i);

void vec3_set(vec3* v, int i, double value);

vec3 vec3_negate(const vec3 *v);

vec3 vec3_add(const vec3* u, const vec3 *v);

void vec3_add_assign(vec3 *u, const vec3 *v);

vec3 vec3_subtract(const vec3 *u, const vec3 *v);

vec3 vec3_multiply(const vec3 *u, const vec3 *v);

vec3 vec3_multiply_scalar(const vec3 *v, double t);

void vec3_multiply_assign(vec3 *v, double t);

vec3 vec3_divide(const vec3 *v, double t);

void vec3_divide_assign(vec3 *v, double t);

double vec3_length_squared(const vec3* v);

double vec3_length(const vec3 *v);

double vec3_dot(const vec3* u, const vec3* v);

vec3 vec3_cross(const vec3* u, const vec3 *v);

vec3 vec3_unit_vector(const vec3 *v);

void vec3_print(const vec3* v);

#define VEC3_NEG(v) vec3_negate(&(v))
#define VEC3_ADD(u, v) vec3_add(&(u), &(v))
#define VEC3_ADD_ASSIGN(u, v) vec3_add_assign(&(u), &(v))
#define VEC3_SUB(u, v) vec3_subtract(&(u), &(v))
#define VEC3_MUL(u, v) _Generic((v), \
												double: vec3_multiply_scalar(&(u), v)) \
												vec3: vec3_multiply(&(u), &(v)))
#define VEC3_DIV(u, t) vec3_divide(&(u), (t))
#define VEC3_MUL_ASSIGN(u, t) vec3_multiply_assign(&(u), (t))
#define VEC3_DIV_ASSIGN(u, t) vec3_divide_assign(&(u), (t))

#endif
