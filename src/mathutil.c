#include <math.h>

#include "mathutil.h"

// non-ptr

float math_vec2_dot(Vector2 v1, Vector2 v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

Vector2 math_vec2_mul(Vector2 v1, Vector2 v2)
{
	return (Vector2) {v1.x * v2.x, v1.y * v2.y};
}

Vector2 math_vec2_scale(Vector2 v, float a)
{
	return (Vector2) {v.x * a, v.y * a};
}

Vector2 math_norm_vec2(Vector2 v)
{
	float ilength = 1 / sqrt(v.x * v.x + v.y * v.y);
	return (Vector2) {v.x * ilength, v.y * ilength};
}

// ptr

float math_ptr_vec2_dot(Vector2 *v1, Vector2 *v2)
{
	return v1->x * v2->x + v1->y * v2->y;
}

Vector2 math_ptr_vec2_mul(Vector2 *v1, Vector2 *v2)
{
	return (Vector2) {v1->x * v2->x, v1->y * v2->y};
}

void math_ptr_vec2_scale(Vector2 *v, float a)
{
	v->x *= a;
	v->y *= a;
}

void math_ptr_norm_vec2(Vector2 *v)
{
	float ilength = 1 / sqrt(v->x * v->x + v->y * v->y);
	v->x *= ilength;
	v->y *= ilength;
}
