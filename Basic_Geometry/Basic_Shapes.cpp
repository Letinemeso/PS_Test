#include "Basic_Shapes.h"

using namespace PST;


void Circle::M_calculate_geometrical_data()
{
    m_area = PI * m_radius * m_radius;
    m_perimeter = 2 * PI * m_radius;
}



void Circle::set_radius(float _radius)
{
    m_radius = _radius;
    M_calculate_geometrical_data();
}





void Triangle::M_calculate_geometrical_data()
{
    m_area = 0.5f
            * segment_length(m_points[0], m_points[1])
            * segment_length(m_points[0], m_points[2])
            * sin_between_vectors(m_points[1] - m_points[0], m_points[2] - m_points[0]);

    m_perimeter = segment_length(m_points[0], m_points[1])
            + segment_length(m_points[1], m_points[2])
            + segment_length(m_points[2], m_points[0]);
}



void Triangle::set_points(const Point& _1, const Point& _2, const Point& _3)
{
    m_points[0] = _1;
    m_points[1] = _2;
    m_points[2] = _3;

    M_calculate_geometrical_data();
}





void Square::M_calculate_geometrical_data()
{
    m_area = m_side_size * m_side_size;

    m_perimeter = m_side_size * 4.0f;
}



void Square::set_side_size(float _side_size)
{
    m_side_size = _side_size;
    M_calculate_geometrical_data();
}
