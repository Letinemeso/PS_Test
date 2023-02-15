#include <vector>

#include "gtest/gtest.h"

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


class ValidIntersectionTest : public testing::TestWithParam<std::pair<PST::Line, PST::Line>>
{
};
TEST_P(ValidIntersectionTest, ValidTest)
{
    ASSERT_TRUE(PST::hasIntersection(GetParam().first, GetParam().second));
}

class InvalidIntersectionTest : public testing::TestWithParam<std::pair<PST::Line, PST::Line>>
{
};
TEST_P(InvalidIntersectionTest, InvalidTest)
{
    ASSERT_FALSE(PST::hasIntersection(GetParam().first, GetParam().second));
}

class ValidCircleTest : public testing::TestWithParam<std::pair<float, std::pair<float, float>>>
{
};
TEST_P(ValidCircleTest, ValidAreaTest)
{
    PST::Circle circle;
    circle.set_radius(GetParam().first);
    ASSERT_TRUE(PST::floats_are_equal(circle.area(), GetParam().second.first));
}
TEST_P(ValidCircleTest, ValidPerimeterTest)
{
    PST::Circle circle;
    circle.set_radius(GetParam().first);
    ASSERT_TRUE(PST::floats_are_equal(circle.perimeter(), GetParam().second.second));
}

class ValidSquareTest : public testing::TestWithParam<std::pair<float, std::pair<float, float>>>
{
};
TEST_P(ValidSquareTest, ValidAreaTest)
{
    PST::Square square;
    square.set_side_size(GetParam().first);
    ASSERT_TRUE(PST::floats_are_equal(square.area(), GetParam().second.first));
}
TEST_P(ValidSquareTest, ValidPerimeterTest)
{
    PST::Square square;
    square.set_side_size(GetParam().first);
    ASSERT_TRUE(PST::floats_are_equal(square.perimeter(), GetParam().second.second));
}

class ValidTriangleTest : public testing::TestWithParam<std::pair<std::vector<PST::Point>, std::pair<float, float>>>
{
};
TEST_P(ValidTriangleTest, ValidAreaTest)
{
    PST::Triangle triangle;
    triangle.set_points(GetParam().first[0], GetParam().first[1], GetParam().first[2]);
    ASSERT_TRUE(PST::floats_are_equal(triangle.area(), GetParam().second.first));
}
TEST_P(ValidTriangleTest, ValidPerimeterTest)
{
    PST::Triangle triangle;
    triangle.set_points(GetParam().first[0], GetParam().first[1], GetParam().first[2]);
    ASSERT_TRUE(PST::floats_are_equal(triangle.perimeter(), GetParam().second.second));
}

class ValidSerializationTest : public testing::Test
{
};

TEST_F(ValidSerializationTest, SerializationTest)
{
    LV::Type_Manager::register_type("float", {
                                        [](const std::string& _val)
                                        {
                                            if(_val == ".")
                                            return false;

                                            unsigned int dots_count = 0;
                                            unsigned int i=0;
                                            if(_val[0] == '+' || _val[0] == '-')
                                            ++i;
                                            for(; i<_val.size(); ++i)
                                            {
                                                if(_val[i] == '.')
                                                {
                                                    ++dots_count;
                                                    continue;
                                                }
                                                if(_val[i] < '0' || _val[i] > '9')
                                                return false;
                                            }

                                            if(dots_count > 1)
                                            return false;

                                            return true;
                                        },
                                        [](void* _variable_vptr, const LDS::Vector<std::string>& _values_as_string) { *((float*)_variable_vptr) = std::stof(_values_as_string[0]); }
                                    });
    LV::Type_Manager::register_type("PST::Point", {
                                        [](const std::string& _val)
                                        {
                                            if(_val == ".")
                                            return false;

                                            unsigned int dots_count = 0;
                                            unsigned int i=0;
                                            if(_val[0] == '+' || _val[0] == '-')
                                            ++i;
                                            for(; i<_val.size(); ++i)
                                            {
                                                if(_val[i] == '.')
                                                {
                                                    ++dots_count;
                                                    continue;
                                                }
                                                if(_val[i] < '0' || _val[i] > '9')
                                                return false;
                                            }

                                            if(dots_count > 1)
                                            return false;

                                            return true;
                                        },
                                        [](void* _variable_vptr, const LDS::Vector<std::string>& _values_as_string)
                                        {
                                            ((PST::Point*)_variable_vptr)->x = std::stof(_values_as_string[0]);
                                            ((PST::Point*)_variable_vptr)->y = std::stof(_values_as_string[1]);
                                        }
                                    });

    PST::Circle circle;
    circle.set_radius(3.0f);
    circle.serialize("circle", "./circle");

    PST::Triangle triangle;
    std::vector<PST::Point> _points({ PST::Point(0.0f, 0.0f), PST::Point(5.0f, 0.0f), PST::Point(0.0f, 5.0f) });
    triangle.set_points(_points[0], _points[1], _points[2]);
    triangle.serialize("triangle", "./triangle");

    PST::Square square;
    square.set_side_size(12.0f);
    square.serialize("square", "./square");


    PST::Circle circle_2;
    circle_2.deserialize("circle", "./circle");
    ASSERT_TRUE(PST::floats_are_equal(circle_2.area(), 28.274333882f));
    ASSERT_TRUE(PST::floats_are_equal(circle_2.perimeter(), 18.849555922f));

    PST::Triangle triangle_2;
    triangle_2.set_points(_points[0], _points[1], _points[2]);
    triangle_2.deserialize("triangle", "./triangle");
    ASSERT_TRUE(PST::floats_are_equal(triangle_2.area(), 12.5f));
    ASSERT_TRUE(PST::floats_are_equal(triangle_2.perimeter(), 17.0710678f));

    PST::Square square_2;
    square_2.deserialize("square", "./square");
    ASSERT_TRUE(PST::floats_are_equal(square_2.area(), 144.0f));
    ASSERT_TRUE(PST::floats_are_equal(square_2.perimeter(), 48.0f));
}



INSTANTIATE_TEST_SUITE_P(
        ValidIntersectionTest,
        ValidIntersectionTest,
        testing::Values(
                std::pair<PST::Line, PST::Line>(PST::Line({1, 1}, {4, 4}), PST::Line({4, 1}, {1, 4})), //  just intersection
                std::pair<PST::Line, PST::Line>(PST::Line({1, 5}, {7, 5}), PST::Line({3, 2}, {3, 8})), //  vertical and horisontal perpendicular intersection
                std::pair<PST::Line, PST::Line>(PST::Line({2, 1}, {2, 4}), PST::Line({2, 1}, {2, 4})), //  vertical same line
                std::pair<PST::Line, PST::Line>(PST::Line({2, 1}, {2, 4}), PST::Line({2, 2}, {2, 3})), //  vertical partially same line
                std::pair<PST::Line, PST::Line>(PST::Line({1, 2}, {4, 2}), PST::Line({1, 2}, {4, 2})), //  horisontal same line
                std::pair<PST::Line, PST::Line>(PST::Line({1, 1}, {2, 1}), PST::Line({2, 1}, {4, 1}))  //  horisontal with 1 common point
            )
        );

INSTANTIATE_TEST_SUITE_P(
        InvalidIntersectionTest,
        InvalidIntersectionTest,
        testing::Values(
                std::pair<PST::Line, PST::Line>(PST::Line({1, 15}, {7, 15}), PST::Line({4, 3}, {6, 7})  ), //  just no intersection
                std::pair<PST::Line, PST::Line>(PST::Line({2, 1}, {4, 3}),   PST::Line({1, 2}, {3, 4})  ), //  parallel, not vertical nor horizontal
                std::pair<PST::Line, PST::Line>(PST::Line({1, 5}, {7, 5}),   PST::Line({13, 2}, {13, 8})), //  vertical and horisontal perpendicular, no intersection
                std::pair<PST::Line, PST::Line>(PST::Line({2, 1}, {2, 4}),   PST::Line({3, 1}, {3, 4})  ), //  vertical parallel
                std::pair<PST::Line, PST::Line>(PST::Line({1, 1}, {4, 1}),   PST::Line({1, 2}, {4, 2})  ), //  horisontal parallel
                std::pair<PST::Line, PST::Line>(PST::Line({1, 1}, {2, 1}),   PST::Line({3, 1}, {4, 1})  )  //  horisontal same line with interval
            )
        );


INSTANTIATE_TEST_SUITE_P(
        ValidCircleTest,
        ValidCircleTest,
        testing::Values(
                std::pair<float, std::pair<float, float>>(3.0f, {28.274333882f, 18.849555922f}),
                std::pair<float, std::pair<float, float>>(28.274333882f, {2511.508411077f, 177.652879218f})
            )
        );

INSTANTIATE_TEST_SUITE_P(
        ValidSquareTest,
        ValidSquareTest,
        testing::Values(
                std::pair<float, std::pair<float, float>>(3.0f, {9.0f, 12.0f}),
                std::pair<float, std::pair<float, float>>(12.0f, {144.0f, 48.0f})
            )
        );

INSTANTIATE_TEST_SUITE_P(
        ValidTriangleTest,
        ValidTriangleTest,
        testing::Values(
                std::pair<std::vector<PST::Point>, std::pair<float, float>>({ PST::Point(0.0f, 0.0f), PST::Point(5.0f, 0.0f), PST::Point(0.0f, 5.0f) }, {12.5f, 17.0710678f}),
                std::pair<std::vector<PST::Point>, std::pair<float, float>>({ PST::Point(-1.0f, 2.0f), PST::Point(3.0f, -2.0f), PST::Point(10.0f, 3.0f) }, {24.0f, 25.3045405f})
            )
        );






int main()
{
    testing::InitGoogleTest();

    bool tests_passed = RUN_ALL_TESTS() == 0;

    if(!tests_passed)
        return 1;

    return 0;
}
