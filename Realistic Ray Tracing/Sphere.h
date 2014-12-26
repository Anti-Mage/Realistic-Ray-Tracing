#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Shape.h"
#include "Vector3.h"
#include "Ray.h"
#include "rgb.h"

class Sphere : public Shape
{
public:
	Sphere(const Vector3& _center, float _radius, const rgb& _color);
	//BBox boundingBox() const;	
	bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const;
	bool shadowHit(const Ray& r, float tmin, float tmax, float time) const;

private:
	Vector3 center;
	float radius;
	rgb color;
};

#endif