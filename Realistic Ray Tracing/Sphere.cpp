#include "Sphere.h"


Sphere::Sphere(const Vector3& _center, float _radius, const rgb& _color) :center(_center), radius(_radius), color(_color)
{
}

bool Sphere::hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const{
	Vector3 tmp = r.origin() - center;

	double a = dot(r.direction(), r.direction());
	double b = 2 * dot(r.direction(), tmp);
	double c = dot(tmp, tmp) - radius * radius;

	double discriminant = b * b - 4 * a * c;

	if (discriminant > 0){
		discriminant = std::sqrt(discriminant);
		double t = (-b - discriminant) / (2 * a);
		if (t < tmin)
			t = (-b + discriminant) / (2 * a);
		if (t < tmin || t > tmax)
			return false;

		record.t = (float)t;
		record.normal = unitVector(r.origin() + t * r.direction() - center);
		//record.color = color;
		return true;
	}
	return false;
}
bool Sphere::shadowHit(const Ray& r, float tmin, float tmax, float time) const{
	Vector3 tmp = r.origin() - center;

	double a = dot(r.direction(), r.direction());
	double b = 2 * dot(r.direction(), tmp);
	double c = dot(tmp, tmp) - radius * radius;

	double discriminant = b * b - 4 * a * c;

	if (discriminant > 0){
		discriminant = std::sqrt(discriminant);
		double t = (-b - discriminant) / (2 * a);
		if (t < tmin)
			t = (-b + discriminant) / (2 * a);
		if (t < tmin || t > tmax)
			return false;

		return true;
	}
	return false;
}
