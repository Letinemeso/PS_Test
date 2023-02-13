#include "Basic_Shapes.h"

using namespace PST;


INIT_FIELDS(PST::Basic_Shape, LV::Variable_Base)
ADD_FIELD(PST::Point, m_position)
FIELDS_END


void Basic_Shape::deserialize(const std::string &_name, const std::string &_path)
{
    LV::MDL_Reader mdl_manager;
    mdl_manager.parse_file(_path);
    LV::MDL_Variable_Stub stub = mdl_manager.get_stub(_name);
    assign_values(stub);

    M_calculate_geometrical_data();
}





INIT_FIELDS(PST::Circle, PST::Basic_Shape)
ADD_FIELD(float, m_radius)
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



void Circle::serialize(const std::string &_name, const std::string &_path)
{
    LV::MDL_Reader mdl_manager;

    LDS::Vector<std::string> temp;
    LV::MDL_Variable_Stub stub;
    stub.name = _name;

    temp.push(std::to_string(position().x));
    temp.push(std::to_string(position().y));
    stub.fields.emplace("m_position", temp);
    temp.clear();

    temp.push(std::to_string(m_radius));
    stub.fields.emplace("m_radius", temp);
    temp.clear();

    mdl_manager.add_stub(stub);
    mdl_manager.save_to_file(_path);
}





INIT_FIELDS(PST::Triangle, PST::Basic_Shape)
ADD_FIELD(PST::Point, m_point_1)
ADD_FIELD(PST::Point, m_point_2)
ADD_FIELD(PST::Point, m_point_3)
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



void Triangle::serialize(const std::string &_name, const std::string &_path)
{
    LV::MDL_Reader mdl_manager;

    LDS::Vector<std::string> temp;
    LV::MDL_Variable_Stub stub;
    stub.name = _name;

    temp.push(std::to_string(position().x));
    temp.push(std::to_string(position().y));
    stub.fields.emplace("m_position", temp);
    temp.clear();

    temp.push(std::to_string(m_point_1.x));
    temp.push(std::to_string(m_point_1.y));
    stub.fields.emplace("m_point_1", temp);
    temp.clear();

    temp.push(std::to_string(m_point_2.x));
    temp.push(std::to_string(m_point_2.y));
    stub.fields.emplace("m_point_2", temp);
    temp.clear();

    temp.push(std::to_string(m_point_3.x));
    temp.push(std::to_string(m_point_3.y));
    stub.fields.emplace("m_point_3", temp);
    temp.clear();

    mdl_manager.add_stub(stub);
    mdl_manager.save_to_file(_path);
}





INIT_FIELDS(PST::Square, PST::Basic_Shape)
ADD_FIELD(float, m_side_size)
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



void Square::serialize(const std::string &_name, const std::string &_path)
{
    LV::MDL_Reader mdl_manager;

    LDS::Vector<std::string> temp;
    LV::MDL_Variable_Stub stub;
    stub.name = _name;

    temp.push(std::to_string(position().x));
    temp.push(std::to_string(position().y));
    stub.fields.emplace("m_position", temp);
    temp.clear();

    temp.push(std::to_string(m_side_size));
    stub.fields.emplace("m_side_size", temp);
    temp.clear();

    mdl_manager.add_stub(stub);
    mdl_manager.save_to_file(_path);
}
