#include <cmath>
#include <cassert>
#include "SVector2.h"

SVector2::SVector2(): x{ 0 },y{ 0 }
{

}

SVector2::SVector2(float x, float y)
{
    this->x=x;
    this->y=y;
}

SVector2::SVector2(const SVector2& v): x{ v.x },y{ v.y }
{

}

float& SVector2::operator[](size_t index)
{
    assert(index >= 0 && index < m_length);
    return *(&x + index);
}

const float& SVector2::operator[](size_t index) const
{
    assert(index >= 0 && index < m_length);
    return *(&x + index);
}

SVector2& SVector2::operator=(const SVector2& v)
{
    x = v.x;
    y = v.y;
    return *this;
}

SVector2 operator+(const SVector2 & left, float right)
{
    return SVector2
    (
        left.x + right,
        left.y + right
    );
}

SVector2 operator+(float left, const SVector2& right)
{
    return SVector2
    (
        left + right.x,
        left + right.y
    );
}

SVector2 operator+(const SVector2& left, const SVector2& right)
{
    return SVector2
    (
        left.x + right.x,
        left.y + right.y
    );
}

SVector2 operator-(const SVector2 & left, float right)
{
    return SVector2
    (
        left.x - right,
        left.y - right
    );
}

SVector2 operator-(float left, const SVector2& right)
{
    return SVector2
    (
        left - right.x,
        left - right.y
    );
}

SVector2 operator-(const SVector2& left, const SVector2& right)
{
    return SVector2
    (
        left.x - right.x,
        left.y - right.y
    );
}

SVector2 operator*(const SVector2 & left, float right)
{
    return SVector2
    (
        left.x * right,
        left.y * right
    );
}

SVector2 operator*(float left, const SVector2& right)
{
    return SVector2
    (
        left * right.x,
        left * right.y
    );
}

SVector2 operator*(const SVector2& left, const SVector2& right)
{
    return SVector2
    (
        left.x * right.x,
        left.y * right.y
    );
}

SVector2 operator/(const SVector2 & left, float right)
{
    return SVector2
    (
        left.x / right,
        left.y / right
    );
}

SVector2 operator/(float left, const SVector2& right)
{
    return SVector2
    (
        left / right.x,
        left / right.y
    );
}

SVector2 operator/(const SVector2& left, const SVector2& right)
{
    return SVector2
    (
        left.x / right.x,
        left.y / right.y
    );
}

bool operator==(const SVector2& left, const SVector2& right)
{
    return (left.x == right.x && left.y == right.y);
}

bool operator!=(const SVector2& left, const SVector2& right)
{
    return !(left == right);
}

float SVector2::Dot(const SVector2& left, const SVector2& right)
{
    SVector2 temp(left * right);
    return (temp.x + temp.y);
}

float SVector2::Magnitud(const SVector2 & v)
{
    float x{ v.x * v.x };
    float y{ v.y * v.y };
    return sqrtf(x + y);
}
SVector2 SVector2::Normalize(const SVector2& v)
{
    float x{ v.x * v.x };
    float y{ v.y * v.y };
    float magnitud{ sqrtf(x + y) };
    return SVector2(x / magnitud, y / magnitud);
}

float SVector2::Distance(const SVector2& left, const SVector2& right)
{
    float x((left.x - right.x) * (left.x - right.x));
    float y((left.y - right.y) * (left.y - right.y));
    return sqrtf(x + y);
}
