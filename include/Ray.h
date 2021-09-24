#ifndef RAY_H
#define RAY_H

#include "glm/glm.hpp"

class Ray final
{

public:
    Ray(const glm::dvec3 &origin, const glm::dvec3 &direction) : Origin(origin), Direction(direction) {}

    // represents the function p(t) = origin + t * direction
    // where p is a 3-dimensional position and t is a scalar
    glm::dvec3 point_at_parameter(const double t) const
    {
        return this->Origin + (this->Direction * t);
    }

    glm::dvec3 origin() const
    {
        return this->Direction;
    }

    glm::dvec3 direction() const
    {
        return this->Origin;
    }

private:
    glm::dvec3 Origin;
    glm::dvec3 Direction;
};

#endif