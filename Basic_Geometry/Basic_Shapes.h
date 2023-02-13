#ifndef BASIC_SHAPES_H
#define BASIC_SHAPES_H

#include <Variable_Base.h>

#include "Basic_Geometry.h"


namespace PST
{

    constexpr float PI = 3.141592653589793;

    class Basic_Shape : public LV::Variable_Base
    {
    public:
        DECLARE_VARIABLE;

    private:
        Point m_position;

    protected:
        float m_area = 0.0f, m_perimeter = 0.0f;

    private:
        virtual void M_calculate_geometrical_data() = 0;

    public:
        inline void set_position(const Point& _position) { m_position = _position; }

    public:
        inline const Point& position() const { return m_position; }
        inline float area() const { return m_area; }
        inline float perimeter() const { return m_perimeter; }

    public:
        virtual void serialize(const std::string& _name, const std::string& _path) = 0;
        void deserialize(const std::string& _name, const std::string& _path);

    };


    class Circle : public Basic_Shape
    {
    public:
        DECLARE_VARIABLE;

    private:
        float m_radius = 0.0f;

    private:
        void M_calculate_geometrical_data() override;

    public:
        void set_radius(float _radius);

    public:
        void serialize(const std::string &_name, const std::string &_path) override;

    };


    class Triangle : public Basic_Shape
    {
    public:
        DECLARE_VARIABLE;

    private:
        Point m_point_1;
        Point m_point_2;
        Point m_point_3;

    private:
        void M_calculate_geometrical_data() override;

    public:
        void set_points(const Point& _1, const Point& _2, const Point& _3);

    public:
        void serialize(const std::string &_name, const std::string &_path) override;

    };


    class Square : public Basic_Shape
    {
    public:
        DECLARE_VARIABLE;

    private:
        float m_side_size = 0.0f;

    private:
        void M_calculate_geometrical_data() override;

    public:
        void set_side_size(float _side_size);

    public:
        void serialize(const std::string &_name, const std::string &_path) override;

    };

}

#endif // BASIC_SHAPES_H
