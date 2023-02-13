#ifndef BASIC_GEOMETRY_H
#define BASIC_GEOMETRY_H


namespace PST
{

    struct Point
    {
        float x = 0.0f, y = 0.0f;

        Point() { }
        Point(float _x, float _y) : x(_x), y(_y) {  }
        inline Point operator+(const Point& _other) const { return {x + _other.x, y + _other.y}; }
        inline Point operator-(const Point& _other) const { return *this + Point(-_other.x, -_other.y); }
    };


    struct Line
    {
        Point begin, end;
    };

    bool hasIntersection(const Line& _1, const Line& _2);

    bool floats_are_equal(float _1, float _2, float _precision = 0.0001f);
    bool number_is_in_bounds(float _num, float _bound_1, float _bound_2);

    float vector_length(const Point& _vec);
    float segment_length(const Point& _begin, const Point& _end);
    float cos_between_vectors(const Point& _vec1, const Point& _vec2);
    float sin_between_vectors(const Point& _vec1, const Point& _vec2);

}


#endif // BASIC_GEOMETRY_H
