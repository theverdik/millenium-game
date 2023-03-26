#ifndef MATHUTIL_H
#define MATHUTIL_H

#include <raylib.h>

// non-ptr

float   math_vec2_dot(Vector2 v1, Vector2 v2);
Vector2 math_vec2_scale(Vector2 v, float a);
Vector2 math_vec2_mul(Vector2 v1, Vector2 v2);
Vector2 math_vec2_norm(Vector2 v);

// ptr

float   math_ptr_vec2_dot(Vector2 *v1, Vector2 *v2);
void    math_ptr_vec2_scale(Vector2 *v, float a);
Vector2 math_ptr_vec2_mul(Vector2 *v1, Vector2 *v2);
void    math_ptr_vec2_norm(Vector2 *v);

#endif // MATHUTIL_H
