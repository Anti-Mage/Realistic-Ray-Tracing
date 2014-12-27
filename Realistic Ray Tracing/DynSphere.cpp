#include "DynSphere.h"

DynSphere::DynSphere(const Vector3& _ocenter, float _radius, const rgb& _color, float min_time, float max_time)
:ocenter(_ocenter), radius(_radius), color(_color),mintime(min_time),maxtime(max_time){

}

bool DynSphere::hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const{
	Vector3 new_center = getCenter(time); 
	Vector3 tmp = r.origin() - new_center;

	double a = dot(r.direction(), r.direction());
	double b = 2 * dot(r.direction(), tmp);
	double c = dot(tmp, tmp) - radius * radius;

	double discriminant = b*b - 4 * a*c;

	if (discriminant > 0){
		discriminant = std::sqrt(discriminant);
		double t = (-b - discriminant) / (2 * a);
		if (t < tmin)
			t = (-b + discriminant) / (2 * a);
		if (t < tmin || t > tmax)
			return false;

		record.t = t;
		record.normal = unitVector(r.origin() + t * r.direction() - new_center);
		//record.color = color;
		return true;
	}

	return false;
}

bool DynSphere::shadowHit(const Ray& r, float tmin, float tmax, float time) const{
	Vector3 new_center = getCenter(time);
	Vector3 tmp = r.origin() - new_center;

	double a = dot(r.direction(), r.direction());
	double b = 2 * dot(r.direction(), tmp);
	double c = dot(tmp, tmp) - radius * radius;

	double discriminant = b*b - 4 * a*c;

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

Vector3 DynSphere::getCenter(float time) const{
	float realtime = time * maxtime + (1.0 - time) * mintime;
	return Vector3(ocenter.x() + realtime, ocenter.y() + realtime, ocenter.z() + realtime);
}