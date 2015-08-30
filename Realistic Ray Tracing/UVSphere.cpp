#include "UVSphere.h"


UVSphere::UVSphere(const Vector3& _center, float _radius, Texture* _tex)
	:center(_center), radius(_radius), tex(_tex)
{
}


UVSphere::~UVSphere()
{
}


bool UVSphere::hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const{
	Vector3 tmp = r.origin() - center;

	double a = dot(r.direction(), r.direction());
	double b = 2 * dot(r.direction(), tmp);
	double c = dot(tmp, tmp) - radius*radius;

	double discriminant = b*b - 4 * a*c;
	if (discriminant > 0){
		discriminant = sqrt(discriminant);
		double t = (-b - discriminant) / (2.0 * a);

		if (t < tmin){
			t = (-b + discriminant) / (2.0 * a);
		}
		if (t < tmin || t > tmax)
			return false;

		record.t = t;
		record.hit_p = (r.origin() + t * r.direction());
		Vector3 n = record.normal = (record.hit_p - center) / radius;

		float twopi = 6.28318530718f;
		float theta = acos(n.z());
		float phi = atan2(n.y(), n.x());
		if (phi < 0.0f)
			phi += twopi;

		float one_over_2pi = 0.159154943092f;
		float one_over_pi = 2 * one_over_2pi;
		record.uv = Vector2(phi*one_over_2pi, (M_PI - theta) * one_over_pi);
		
		record.hit_tex = tex;
		return true;
	}
	return false;
}

bool UVSphere::shadowHit(const Ray& r, float tmin, float tmax, float time) const{
	Vector3 tmp = r.origin() - center;

	double a = dot(r.direction(), r.direction());
	double b = 2 * dot(r.direction(), tmp);
	double c = dot(tmp, tmp) - radius*radius;

	double discriminant = b*b - 4 * a*c;
	if (discriminant > 0){
		discriminant = sqrt(discriminant);
		double t = (-b - discriminant) / (2.0 * a);

		if (t < tmin){
			t = (-b + discriminant) / (2.0 * a);
		}
		if (t < tmin || t > tmax)
			return false;
		return true;
	}
	return false;
}