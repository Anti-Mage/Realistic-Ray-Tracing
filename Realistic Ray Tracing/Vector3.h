#ifndef _VECTOR3_H__
#define _VECTOR3_H__

#include <cmath>
#include <iostream>

class Vector3
{
public:
	Vector3(){}
	~Vector3(){}
	Vector3(float e0, float e1, float e2);
	Vector3(const Vector3& v){ *this = v; }

	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }

	const Vector3& operator+() const;
	Vector3 operator-() const;

	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	float length() const;
	float squaredLength() const;

	void makeUnitVector();

	void setX(float _x){ e[0] = _x; }
	void setY(float _y){ e[1] = _y; }
	void setZ(float _z){ e[2] = _z; }
	float minComponent() const;
	float maxComponent() const;
	float maxAbsComponent() const;
	float minAbsComponent() const;
	int indexOfMinComponent() const;
	int indexOfMaxComponent() const;
	int indexOfAbsMinComponent() const;
	int indexOfAbsMaxComponent() const;
	
	friend bool operator==(const Vector3& lhs, const Vector3& rhs);
	friend bool operator!=(const Vector3& lhs, const Vector3& rhs);

	friend std::istream& operator>>(std::istream& is, Vector3& t);
	friend std::ostream& operator<<(std::ostream& os, const Vector3& t);

	friend Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
	friend Vector3 operator-(const Vector3& lhs, const Vector3& rhs);

	friend Vector3 operator/(const Vector3& lhs, float scalar);
	friend Vector3 operator*(const Vector3& lhs, float scalar);
	friend Vector3 operator*(float scalar, const Vector3& rhs);

	Vector3& operator=(const Vector3& rhs);
	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator-=(const Vector3& rhs);
	Vector3& operator*=(const float t);
	Vector3& operator/=(const float t);

	friend Vector3 unitVector(const Vector3& v);
	friend Vector3 minVec(const Vector3& lhs, const Vector3& rhs);
	friend Vector3 maxVec(const Vector3& lhs, const Vector3& rhs);
	friend Vector3 cross(const Vector3& lhs, const Vector3& rhs);
	friend float dot(const Vector3& lhs, const Vector3& rhs);
	friend float tripleProduct(const Vector3& v1, const Vector3& v2, const Vector3& v3);
private:
	float e[3];
};

inline Vector3::Vector3(float e0, float e1, float e2) {
	e[0] = e0;
	e[1] = e1;
	e[2] = e2;
}

inline const Vector3& Vector3::operator+() const{
	return *this;
}

inline Vector3 Vector3::operator-() const{
	return Vector3(-e[0], -e[1], -e[2]);
}

inline float Vector3::length() const{
	return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

inline float Vector3::squaredLength() const{
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

inline void Vector3::makeUnitVector(){
	*this = *this / (*this).length();
}

inline float Vector3::minComponent() const{
	float tmp = e[0];
	if (e[1] < tmp) tmp = e[1];
	if (e[2] < tmp) tmp = e[2];

	return tmp;
}

inline float Vector3::maxComponent() const{
	float tmp = e[0];
	if (e[1] > tmp) tmp = e[1];
	if (e[2] > tmp) tmp = e[2];

	return tmp;
}

inline float Vector3::minAbsComponent() const{
	float tmp = std::fabs(e[0]);
	if (std::fabs(e[1]) < tmp) tmp = std::fabs(e[1]);
	if (std::fabs(e[2]) < tmp) tmp = std::fabs(e[2]);

	return tmp;
}

inline float Vector3::maxAbsComponent() const{
	float tmp = std::fabs(e[0]);
	if (std::fabs(e[1]) > tmp) tmp = std::fabs(e[1]);
	if (std::fabs(e[2]) > tmp) tmp = std::fabs(e[2]);

	return tmp;
}

inline int Vector3::indexOfMinComponent() const{
	float tmp = e[0];
	int index = 0;
	if (e[1] < tmp) {
		tmp = e[1]; index = 1;
	}
	if (e[2] < tmp) index = 2;

	return index;
}

inline int Vector3::indexOfMaxComponent() const{
	float tmp = e[0];
	int index = 0;
	if (e[1] > tmp) {
		tmp = e[1]; index = 1;
	}
	if (e[2] > tmp) index = 2;

	return index;
}

inline int Vector3::indexOfAbsMinComponent() const{
	float tmp = std::fabs(e[0]);
	int index = 0;
	if (std::fabs(e[1]) < tmp) {
		tmp = std::fabs(e[1]); index = 1;
	}
	if (std::fabs(e[2]) < tmp) index = 2;

	return index;
}

inline bool operator==(const Vector3& lhs, const Vector3& rhs){
	if (lhs.x() == rhs.x() && lhs.y() == rhs.y() && lhs.z() == rhs.z())
		return true;
	return false;
}

inline bool operator!=(const Vector3& lhs, const Vector3& rhs){
	return !(lhs == rhs);
}

inline Vector3 operator*(const Vector3& lhs, float scalar){
	return Vector3(lhs.x() * scalar, lhs.y() * scalar, lhs.z() * scalar);
}

inline Vector3 operator*(float scalar, const Vector3& rhs){
	return Vector3(rhs.x() * scalar, rhs.y() * scalar, rhs.z() * scalar);
}

inline Vector3 operator/(const Vector3& lhs, float scalar){
	return Vector3(lhs.x() / scalar, lhs.y() / scalar, lhs.z() / scalar);
}

inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs){
	return Vector3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs){
	return Vector3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

inline Vector3& Vector3::operator=(const Vector3& rhs){
	setX(rhs.x());
	setY(rhs.y());
	setZ(rhs.z());

	return *this;
}

inline Vector3& Vector3::operator+=(const Vector3& rhs){
	*this = *this + rhs;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& rhs){
	*this = *this - rhs;
	return *this;
}

inline Vector3& Vector3::operator*=(float t){
	*this = *this * t;
	return *this;
}

inline Vector3& Vector3::operator/=(float t){
	*this = *this / t;
	return *this;
}

inline float dot(const Vector3& lhs, const Vector3& rhs){
	return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

inline Vector3 cross(const Vector3& lhs, const Vector3& rhs){
	Vector3 tmp;
	tmp.setX(lhs.y() * rhs.z() - lhs.z() * rhs.y());
	tmp.setY(lhs.z() * rhs.x() - lhs.x() * rhs.z());
	tmp.setZ(lhs.x() * rhs.y() - lhs.y() * rhs.x());

	return tmp;
}

inline Vector3 unitVector(const Vector3& v){
	float length = v.length();
	return v / length;
}

inline Vector3 minVec(const Vector3& lhs, const Vector3& rhs){
	Vector3 tmp(lhs);
	if (rhs.x() < lhs.x()) tmp.setX(rhs.x());
	if (rhs.y() < lhs.y()) tmp.setY(rhs.y());
	if (rhs.z() < lhs.z()) tmp.setZ(rhs.z());

	return tmp;
}

inline Vector3 maxVec(const Vector3& lhs, const Vector3& rhs){
	Vector3 tmp(lhs);
	if (rhs.x() > lhs.x()) tmp.setX(rhs.x());
	if (rhs.y() > lhs.y()) tmp.setY(rhs.y());
	if (rhs.z() > lhs.z()) tmp.setZ(rhs.z());

	return tmp;
}

#endif