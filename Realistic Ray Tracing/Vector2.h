#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include <cmath>
#include <iostream>

class Vector2{
public:
	Vector2(){}
	~Vector2(){}
	Vector2(float e1, float e2){
		e[0] = e1;
		e[2] = e2;
	}

	Vector2(const Vector2& v){
		if (this != &v){
			*this = v;
		}
	}

	float x() const { return e[0]; }
	float y() const { return e[1]; }

	const Vector2& operator+() const{
		return *this;
	}
	
	Vector2 operator-() const{
		return Vector2(-e[0], -e[1]);
	}

	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	float length() const {
		return std::sqrt(e[0] * e[0] + e[1] * e[1]);
	}

	float squaredLength() const{
		return (e[0] * e[0] + e[1] * e[1]);
	}

	void makeUnitVector(){
		*this = *this / (*this).length();
	}

	void setX(float _x){ e[0] = _x; }
	void setY(float _y){ e[1] = _y; }


	friend bool operator==(const Vector2& lhs, const Vector2& rhs);
	friend bool operator!=(const Vector2& lhs, const Vector2& rhs);

	friend std::istream& operator>>(std::istream& is, Vector2& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& v);

	friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
	friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

	friend Vector2 operator/(const Vector2& lhs, float scalar);
	friend Vector2 operator*(const Vector2& lhs, float scalar);
	friend Vector2 operator*(float scalar, const Vector2& rhs);

	Vector2& operator=(const Vector2& rhs){
		e[0] = rhs.x();
		e[1] = rhs.y();

		return *this;
	}

	Vector2& operator+=(const Vector2& rhs){
		*this = *this + rhs;

		return *this;
	}

	Vector2 operator-=(const Vector2& rhs){
		*this = *this - rhs;

		return *this;
	}

	Vector2& operator*=(const float rhs){
		*this = *this * rhs;

		return *this;
	}

	Vector2& operator/=(const float rhs){
		*this = *this / rhs;

		return *this;
	}

	friend Vector2 unitVector(const Vector2& vec){
		float length = vec.length();

		return vec / length;
	}

	friend float dot(const Vector2&lhs, const Vector2& rhs);
	
private:
	float e[2];
};

inline bool operator==(const Vector2& lhs, const Vector2& rhs){
	return (lhs.x() == rhs.x() && lhs.y() == rhs.y());
}

inline bool operator!=(const Vector2& lhs, const Vector2& rhs){
	return !(lhs == rhs);
}

inline std::istream& operator>>(std::istream& is, Vector2& v){
	float tmp;
	is >> tmp;
	v.setX(tmp);
	is >> tmp;
	v.setY(tmp);

	return is;
}

inline std::ostream& operator<<(std::ostream& os, const Vector2& v){
	os << "(" << v.x() << " " << v.y() << ")";

	return os;
}

inline Vector2 operator+(const Vector2& lhs, const Vector2& rhs){
	return Vector2(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}

inline Vector2 operator-(const Vector2& lhs, const Vector2& rhs){
	return Vector2(lhs.x() - rhs.x(), lhs.y() - rhs.y());
}

inline Vector2 operator/(const Vector2& lhs, float scalar){
	return Vector2(lhs.x() / scalar, lhs.y() / scalar);
}

inline Vector2 operator*(const Vector2& lhs, float scalar){
	return Vector2(lhs.x() * scalar, lhs.y() * scalar);
}

inline Vector2 operator/(float scalar, const Vector2& rhs){
	return Vector2(rhs.x() * scalar, rhs.y() * scalar);
}

#endif