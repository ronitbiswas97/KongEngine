#ifndef SVECTOR3_H
#define SVECTOR3_H

#include <ostream>

struct SVector3
{
	struct { float x, y, z; };

	SVector3();
	SVector3(float x);
	SVector3(float x, float y, float z);
	SVector3(const SVector3& copy);

	float& operator[](size_t index);
	const float& operator[](size_t index) const;

	SVector3& operator+=(const SVector3& right);
	SVector3& operator-=(const SVector3& right);
	SVector3& operator*=(const SVector3& right);
	SVector3& operator/=(const SVector3& right);

	friend SVector3 operator+(float left, const SVector3& right);
	friend SVector3 operator+(const SVector3& left, float right);
	friend SVector3 operator+(const SVector3& left, const SVector3& right);
	friend SVector3 operator-(float left, const SVector3& right);
	friend SVector3 operator-(const SVector3& left, float right);
	friend SVector3 operator-(const SVector3& left, const SVector3& right);
	friend SVector3 operator*(float left, const SVector3& right);
	friend SVector3 operator*(const SVector3& left, float right);
	friend SVector3 operator*(const SVector3& left, const SVector3& right);
	friend SVector3 operator/(float left, const SVector3& right);
	friend SVector3 operator/(const SVector3& left, float right);
	friend SVector3 operator/(const SVector3& left, const SVector3& right);

	friend bool operator==(const SVector3& left, const SVector3& right);
	friend bool operator!=(const SVector3& left, const SVector3& right);
	friend std::ostream& operator<<(std::ostream& ost, const SVector3& vector);

	static float Dot(const SVector3& left, const SVector3& right);
	static float Magnitud(const SVector3& vector);
	static SVector3 Normalize(const SVector3& vector);
	static float Distance(const SVector3& left, const SVector3& right);
	static SVector3 Projection(const SVector3& left, const SVector3& right);
	static SVector3 Cross(const SVector3& left, const SVector3& right);
};

#endif // !SVECTOR3_H
