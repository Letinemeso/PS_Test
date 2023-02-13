#include <iostream>

#include <Basic_Geometry.h>

int main()
{

//    PST::Line line1{{3, 3}, {5, 9}};
//    PST::Line line2{{1, 6}, {9, 5}};

//    PST::Line line1{{1, 5}, {7, 5}};
//    PST::Line line2{{3, 2}, {3, 8}};

    PST::Line line1{{1, 5}, {7, 5}};
    PST::Line line2{{4, 3}, {6, 7}};

    std::cout << PST::hasIntersection(line1, line2) << "\n";

    return 0;
}
