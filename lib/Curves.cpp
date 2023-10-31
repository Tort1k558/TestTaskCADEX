#include "Curves.h"

#include<cmath>


Vec3::Vec3(float x, float y, float z):
	x(x), y(y), z(z)
{
}

Circle::Circle(float radius) 
    : m_radius(radius)
{
    if (m_radius <= 0.0f)
    {
        m_radius = 1.0f;
    }
}

Vec3 Circle::calculatePoint(float t) const
{
    float x = m_radius * std::cos(t);
    float y = m_radius * std::sin(t);
    float z = 0.0;
    return Vec3(x, y, z);
}

Vec3 Circle::calculateDerivative(float t) const
{
    float dx = -m_radius * std::sin(t);
    float dy = m_radius * std::cos(t);
    float dz = 0.0;
    return Vec3(dx, dy, dz);
}

float Circle::getRadius() const
{
    return m_radius;
}

Ellipse::Ellipse(float radiusX, float radiusY) : 
    m_radiusX(radiusX), m_radiusY(radiusY)
{
    if (m_radiusX <= 0.0f)
    {
        m_radiusX = 1.0f;
    }
    if (m_radiusY <= 0.0f)
    {
        m_radiusY = 1.0f;
    }
}

Vec3 Ellipse::calculatePoint(float t) const
{
    float x = m_radiusX * std::cos(t);
    float y = m_radiusY * std::sin(t);
    float z = 0.0f;
    return Vec3(x, y, z);
}

Vec3 Ellipse::calculateDerivative(float t) const
{
    float dx = -m_radiusX * std::sin(t);
    float dy = m_radiusY * std::cos(t);
    float dz = 0.0f;
    return Vec3(dx, dy, dz);
}

Helix::Helix(float radius, float step) :
    m_radius(radius), m_step(step)
{
    if (m_radius <= 0.0f)
    {
        m_radius = 1.0f;
    }
    if (m_step <= 0.0f)
    {
        m_step = 0.1f;
    }
}

Vec3 Helix::calculatePoint(float t) const
{
    float x = m_radius * std::cos(t);
    float y = m_radius * std::sin(t);
    float z = m_step * t / (2.0f * PI);
    return Vec3(x, y, z);
}

Vec3 Helix::calculateDerivative(float t) const
{
    float dx = -m_radius * std::sin(t);
    float dy = m_radius * std::cos(t);
    float dz = m_step / (2.0f * PI);
    return Vec3(dx, dy, dz);
}
