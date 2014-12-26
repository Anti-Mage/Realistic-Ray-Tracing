#ifndef __RGB_H__
#define __RGB_H__

#include <iostream>

class rgb
{
public:
	//constructor and destructor
	rgb() :_r(0), _g(0),_b(0){}
	rgb(float red, float green, float blue) :_r(red), _g(green), _b(blue){}
	rgb(const rgb& original){ *this = original; }
	~rgb(){}

public:
	void setRed(float red){ _r = red; }
	void setGreen(float green){ _g = green; }
	void setBlue(float blue){ _b = blue; }

public:
	rgb& operator=(const rgb& rhs);
	rgb& operator+=(const rgb& rhs);
	rgb& operator*=(const rgb& rhs);
	rgb& operator/=(const rgb& rhs);
	rgb& operator*=(float rhs); 
	rgb& operator/=(float rhs);
	
	
	rgb operator+()const { return *this; }
	rgb operator-()const{ return rgb(-_r, -_g, -_b); }

	float r() const { return _r; }
	float g() const { return _g; }
	float b() const { return _b; }

	void clamp();

	friend std::ostream& operator<<(std::ostream& out, const rgb& rhs);
	friend rgb operator*(const rgb& c, float f);
	friend rgb operator*(float f, const rgb& c);
	friend rgb operator/(const rgb& c, float f);
	friend rgb operator*(const rgb& lhs, const rgb& rhs);
	friend rgb operator/(const rgb& lhs, const rgb& rhs);
	friend rgb operator+(const rgb& lhs, const rgb& rhs);
	friend rgb operator-(const rgb& lhs, const rgb& rhs);
private:
	float _r;
	float _g;
	float _b;
};

inline rgb& rgb::operator=(const rgb& rhs){
	_r = rhs.r();
	_g = rhs.g();
	_b = rhs.b();

	return *this;
}

inline rgb& rgb::operator+=(const rgb& rhs){
	*this = *this + rhs;

	return *this;
}

inline rgb& rgb::operator*=(float f){
	*this = *this * f;

	return *this;
}

inline rgb& rgb::operator/=(float f){
	*this = *this / f;

	return *this;
}

inline rgb& rgb::operator*=(const rgb& rhs){
	*this = *this * rhs;

	return *this;
}

inline rgb& rgb::operator/=(const rgb& rhs){
	*this = *this / rhs;

	return *this;
}

inline void rgb::clamp(){
	if (_r > 1.0f) _r = 1.0f;
	if (_g > 1.0f) _g = 1.0f;
	if (_b > 1.0f) _b = 1.0f;

	if (_r < 0.0f) _r = 0.0f;
	if (_g < 0.0f) _g = 0.0f;
	if (_b < 0.0f) _b = 0.0f;
}

inline std::ostream& operator<<(std::ostream& out, const rgb& rhs){
	out << rhs.r() << ' ' << rhs.g() << ' ' << rhs.b() << ' ';

	return out;
}

inline rgb operator*(const rgb& c, float f){
	return rgb(c.r() * f, c.g() * f, c.b() * f);
}

inline rgb operator*(float f, const rgb& c){
	return rgb(c.r() * f, c.g() * f, c.b() * f);
}
inline rgb operator/(const rgb& c, float f){
	return rgb(c.r() / f, c.g() / f, c.b() / f);
}

inline rgb operator*(const rgb& lhs, const rgb& rhs){
	return rgb(lhs.r() * rhs.r(), lhs.g() * rhs.g(), lhs.b() * rhs.b());
}

inline rgb operator/(const rgb& lhs, const rgb& rhs){
	return rgb(lhs.r() / rhs.r(), lhs.g() / rhs.g(), lhs.b() / rhs.b());
}

inline rgb operator+(const rgb& lhs, const rgb& rhs){
	return rgb(lhs.r() + rhs.r(), lhs.g() + rhs.g(), lhs.b() + rhs.b());
}

inline rgb operator-(const rgb& lhs, const rgb& rhs){
	return rgb(lhs.r() - rhs.r(), lhs.g() - rhs.g(), lhs.b() - rhs.b());
}


#endif