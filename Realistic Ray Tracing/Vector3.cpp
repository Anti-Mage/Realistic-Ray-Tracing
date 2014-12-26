#include "Vector3.h"

std::istream& operator>>(std::istream& is, Vector3& t){
	float tmp;
	is >> tmp;
	t.setX(tmp);
	is >> tmp;
	t.setY(tmp);
	is >> tmp;
	t.setZ(tmp);

	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector3& t){
	os << '(' << t.x() << " " << t.y() << " " << t.z() << ')';

	return os;
}

float tripleProduct(const Vector3& v1, const Vector3& v2, const Vector3& v3){
	return dot((cross(v1, v2)), v3);
}
