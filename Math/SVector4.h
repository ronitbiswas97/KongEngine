#ifndef SVECTOR4_H
#define SVECTOR4_H

struct SVector4
{
    struct { float x, y, z, w; };
    SVector4();
    SVector4(float x, float y, float z, float w);
    SVector4(const SVector4& v);

    float& operator[](size_t index);
    const float& operator[](size_t index) const;
    friend SVector4 operator+(const SVector4& left, float right);
    friend SVector4 operator+(float left, const SVector4& right);
    friend SVector4 operator+(const SVector4& left, const SVector4& right);
    friend SVector4 operator-(const SVector4& left, float right);
    friend SVector4 operator-(float left, const SVector4& right);
    friend SVector4 operator-(const SVector4& left, const SVector4& right);
    friend SVector4 operator*(const SVector4& left, float right);
    friend SVector4 operator*(float left, const SVector4& right);
    friend SVector4 operator*(const SVector4& left, const SVector4& right);
    friend SVector4 operator/(const SVector4& left, float a);
    friend SVector4 operator/(float left, const SVector4& right);
    friend SVector4 operator/(const SVector4& left, const SVector4& right);
    friend bool operator==(const SVector4& left, const SVector4& right);
    friend bool operator!=(const SVector4& left, const SVector4& right);
    friend std::ostream& operator<<(std::ostream& ost, const SVector4& v);

    static float Dot(const SVector4& left, const SVector4& right);
    static float Magnitud(const SVector4& left);
    static SVector4 Normalize(const SVector4& right);
    static float Distance(const SVector4& left, const SVector4& right);

private:
    static const size_t m_length = 4;
};
#endif
