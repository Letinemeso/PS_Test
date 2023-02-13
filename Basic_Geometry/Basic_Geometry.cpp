#include "Basic_Geometry.h"

#include <cmath>

using namespace PST;


bool PST::hasIntersection(const Line& _1, const Line& _2)
{
    Point vec1 = _1.end - _1.begin;
    Point vec2 = _2.end - _2.begin;

    if(floats_are_equal(vec1.x, 0.0f) && floats_are_equal(vec2.x, 0.0f))
        return floats_are_equal(_1.begin.x, _2.begin.x);
    if(floats_are_equal(vec1.x, 0.0f))
        return number_is_in_bounds(_1.begin.x, _2.begin.x, _2.end.x);
    if(floats_are_equal(vec2.x, 0.0f))
        return number_is_in_bounds(_2.begin.x, _1.begin.x, _1.end.x);

    float k1 = vec1.y / vec1.x;
    float b1 = _1.end.y - k1 * _1.end.x;

    float k2 = vec2.y / vec2.x;
    float b2 = _2.end.y - k2 * _2.end.x;

    if(floats_are_equal(k1, 0.0f) && floats_are_equal(k2, 0.0f))
        return (number_is_in_bounds(_1.begin.x, _2.begin.x, _2.end.x) || number_is_in_bounds(_1.end.x, _2.begin.x, _2.end.x)) && floats_are_equal(_1.begin.y, _2.begin.y);

    //  intersection point
    float x_x = (b2 - b1) / (k1 - k2);
    float x_y = k1 * x_x + b1;

    return number_is_in_bounds(x_y, _1.begin.y, _1.end.y) && number_is_in_bounds(x_y, _2.begin.y, _2.end.y);
}



bool PST::floats_are_equal(float _1, float _2, float _precision)
{
    return fabs(_1 - _2) <= _precision;
}

bool PST::number_is_in_bounds(float _num, float _bound_1, float _bound_2)
{
    float max = 0.0f;
    float min = 0.0f;

    if( _bound_1 >= _bound_2)
    {
        max = _bound_1;
        min = _bound_2;
    }
    else
    {
        max = _bound_2;
        min = _bound_1;
    }

    return _num <= max && _num >= min;
}


float PST::vector_length(const Point& _vec)
{
    auto sqr = [](float _num)->float { return _num * _num; };
    return sqrt(sqr(_vec.x) + sqr(_vec.y));
}

float PST::segment_length(const Point& _begin, const Point& _end)
{
    return vector_length(_end - _begin);
}

float PST::cos_between_vectors(const Point& _vec1, const Point& _vec2)
{
    float length_1 = vector_length(_vec1),
            length_2 = vector_length(_vec2);

    if(length_1 == 0 || length_2 == 0)
        return 0.0f;

    float divident = _vec1.x * _vec2.x + _vec1.y * _vec2.y;
    float divider = length_1 * length_2;
    return divident / divider;
}

float PST::sin_between_vectors(const Point& _vec1, const Point& _vec2)
{
    auto sqr = [](float _num)->float { return _num * _num; };
    return sqrt(1 - sqr(cos_between_vectors(_vec1, _vec2)));
}




















































