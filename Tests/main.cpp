#define ASSERT(condition) { if(!condition) {int* a = nullptr ; *a = 0; } } do{}while(false)

#define TEST_CASE_TRUE(func) ASSERT(func())
#define TEST_CASE_TRUE_1ARG(func, arg1) ASSERT(func(arg1))
#define TEST_CASE_TRUE_2ARG(func, arg1, arg2) ASSERT(func(arg1, arg2))
#define TEST_CASE_TRUE_3ARG(func, arg1, arg2, arg3) ASSERT(func(arg1, arg2, arg3))

#define TEST_CASE_FALSE(func) ASSERT(!func())
#define TEST_CASE_FALSE_1ARG(func, arg1) ASSERT(!func(arg1))
#define TEST_CASE_FALSE_2ARG(func, arg1, arg2) ASSERT(!func(arg1, arg2))
#define TEST_CASE_FALSE_3ARG(func, arg1, arg2, arg3) ASSERT(!func(arg1, arg2, arg3))

#include <vector>


#include <Basic_Geometry.h>

#include <Basic_Shapes.h>


bool circle_geometrical_data_test(float _radius, float _expected_area, float _expected_perimeter)
{
    PST::Circle circle;
    circle.set_radius(_radius);
    return PST::floats_are_equal(circle.perimeter(), _expected_perimeter, 0.001f) && PST::floats_are_equal(circle.area(), _expected_area);
}

bool triangle_geometrical_data_test(std::vector<PST::Point> _points, float _expected_area, float _expected_perimeter)
{
    PST::Triangle triangle;
    triangle.set_points(_points[0], _points[1], _points[2]);
    return PST::floats_are_equal(triangle.perimeter(), _expected_perimeter, 0.001f) && PST::floats_are_equal(triangle.area(), _expected_area);
}

bool square_geometrical_data_test(float _side_size, float _expected_area, float _expected_perimeter)
{
    PST::Square square;
    square.set_side_size(_side_size);
    return PST::floats_are_equal(square.perimeter(), _expected_perimeter, 0.001f) && PST::floats_are_equal(square.area(), _expected_area);
}


int main()
{
    TEST_CASE_FALSE_2ARG(PST::hasIntersection, PST::Line({1, 15}, {7, 15}), PST::Line({4, 3}, {6, 7})); //  just no intersection
    TEST_CASE_TRUE_2ARG(PST::hasIntersection, PST::Line({1, 1}, {4, 4}), PST::Line({4, 1}, {1, 4}));    //  just intersection
    TEST_CASE_FALSE_2ARG(PST::hasIntersection, PST::Line({2, 1}, {4, 3}), PST::Line({1, 2}, {3, 4}));   //  parallel, not vertical nor horizontal
    TEST_CASE_TRUE_2ARG(PST::hasIntersection, PST::Line({1, 5}, {7, 5}), PST::Line({3, 2}, {3, 8}));    //  vertical and horisontal perpendicular intersection
    TEST_CASE_FALSE_2ARG(PST::hasIntersection, PST::Line({1, 5}, {7, 5}), PST::Line({13, 2}, {13, 8})); //  vertical and horisontal perpendicular, no intersection
    TEST_CASE_FALSE_2ARG(PST::hasIntersection, PST::Line({2, 1}, {2, 4}), PST::Line({3, 1}, {3, 4}));   //  vertical parallel
    TEST_CASE_TRUE_2ARG(PST::hasIntersection, PST::Line({2, 1}, {2, 4}), PST::Line({2, 1}, {2, 4}));    //  vertical same line
    TEST_CASE_TRUE_2ARG(PST::hasIntersection, PST::Line({2, 1}, {2, 4}), PST::Line({2, 2}, {2, 3}));    //  vertical partially same line
    TEST_CASE_FALSE_2ARG(PST::hasIntersection, PST::Line({1, 1}, {4, 1}), PST::Line({1, 2}, {4, 2}));   //  horisontal parallel
    TEST_CASE_TRUE_2ARG(PST::hasIntersection, PST::Line({1, 2}, {4, 2}), PST::Line({1, 2}, {4, 2}));    //  horisontal same line
    TEST_CASE_FALSE_2ARG(PST::hasIntersection, PST::Line({1, 1}, {2, 1}), PST::Line({3, 1}, {4, 1}));   //  horisontal same line with interval
    TEST_CASE_TRUE_2ARG(PST::hasIntersection, PST::Line({1, 1}, {2, 1}), PST::Line({2, 1}, {4, 1}));    //  horisontal with 1 common point

    TEST_CASE_TRUE_3ARG(circle_geometrical_data_test, 3.0f, 28.274333882f, 18.849555922f);
    TEST_CASE_TRUE_3ARG(circle_geometrical_data_test, 28.274333882f, 2511.508411077f, 177.652879218f);

    TEST_CASE_TRUE_3ARG(triangle_geometrical_data_test, std::vector<PST::Point>({ PST::Point(0.0f, 0.0f), PST::Point(5.0f, 0.0f), PST::Point(0.0f, 5.0f) }), 12.5f, 17.0710678f);
    TEST_CASE_TRUE_3ARG(triangle_geometrical_data_test, std::vector<PST::Point>({ PST::Point(-1.0f, 2.0f), PST::Point(3.0f, -2.0f), PST::Point(10.0f, 3.0f) }), 24.0f, 25.3045405f);

    TEST_CASE_TRUE_3ARG(square_geometrical_data_test, 3.0f, 9.0f, 12.0f);
    TEST_CASE_TRUE_3ARG(square_geometrical_data_test, 12.0f, 144.0f, 48.0f);

    return 0;
}
