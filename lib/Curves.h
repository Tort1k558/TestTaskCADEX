#pragma once

#ifdef _WIN32
#define EXTERN __declspec(dllexport)
#else
#define EXTERN __attribute__((visibility("default")))
#endif

EXTERN const float PI = 3.14159265f;

struct EXTERN Vec3
{
    Vec3(float x, float y, float z);
    float x = 0.0f, y = 0.0f, z = 0.0f;
};


class EXTERN Curve
{
public:
    virtual Vec3 calculatePoint(float t) const = 0;
    virtual Vec3 calculateDerivative(float t) const = 0;
    virtual ~Curve() {}
};

class EXTERN Circle : public Curve
{
public:
    Circle(float radius);

    Vec3 calculatePoint(float t) const final;
    Vec3 calculateDerivative(float t) const final;

    float getRadius() const;
private:
    float m_radius;
};

class EXTERN Ellipse : public Curve
{
public:
    Ellipse(float radiusX, float radiusY);

    Vec3 calculatePoint(float t) const final;
    Vec3 calculateDerivative(float t) const final;
private:
    float m_radiusX;
    float m_radiusY;
};

class EXTERN Helix : public Curve
{
public:
    Helix(float radius, float step);

    Vec3 calculatePoint(float t) const final;
    Vec3 calculateDerivative(float t) const final;
private:
    float m_radius;
    float m_step;
};