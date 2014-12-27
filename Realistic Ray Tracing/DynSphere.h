#ifndef __DYN_SPHERE_H__
#define __DYN_SPHERE_H__

#include "Shape.h"
#include "Vector3.h"
#include "Ray.h"
#include "rgb.h"

class DynSphere : public Shape{
public :
	DynSphere(const Vector3& _ocenter, float _radius, const rgb& _color, float mintime, float maxtime);
	bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const;
	bool shadowHit(const Ray& r, float tmin, float tmax, float time) const;
	Vector3 getCenter(float time) const;

public:
	Vector3 ocenter;
	float mintime;
	float maxtime;
	float radius;
	rgb color;
};

#endif