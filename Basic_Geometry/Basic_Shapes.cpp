#include "Basic_Shapes.h"

using namespace PST;


INIT_FIELDS(PST::Basic_Shape, LV::Variable_Base)
ADD_FIELD("PST::Point", m_position)
FIELDS_END


INIT_FIELDS(PST::Circle, PST::Basic_Shape)
ADD_FIELD("float", m_radius)
FIELDS_END


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





INIT_FIELDS(PST::Triangle, PST::Basic_Shape)
ADD_FIELD("PST::Point", m_point_1)
ADD_FIELD("PST::Point", m_point_2)
ADD_FIELD("PST::Point", m_point_3)
FIELDS_END


void Triangle::M_calculate_geometrical_data()
{
    m_area = 0.5f
            * segment_length(m_point_1, m_point_2)
            * segment_length(m_point_1, m_point_3)
            * sin_between_vectors(m_point_2 - m_point_1, m_point_3 - m_point_1);

    m_perimeter = segment_length(m_point_1, m_point_2)
            + segment_length(m_point_2, m_point_3)
            + segment_length(m_point_3, m_point_1);
}



void Triangle::set_points(const Point& _1, const Point& _2, const Point& _3)
{
    m_point_1 = _1;
    m_point_2 = _2;
    m_point_3 = _3;

    M_calculate_geometrical_data();
}





INIT_FIELDS(PST::Square, PST::Basic_Shape)
ADD_FIELD("float", m_side_size)
FIELDS_END


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
