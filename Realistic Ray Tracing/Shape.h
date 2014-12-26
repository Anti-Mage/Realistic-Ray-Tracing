#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "Ray.h"
#include "Vector3.h"
#include "rgb.h"

class Ray;
class rgb;

struct HitRecord{
	float t;
	Vector3 normal;
	rgb color;
};

class Shape{
public:
	virtual bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const = 0;
	virtual bool shadowHit(const Ray& r, float tmin, float tmax, float time) const = 0;
};

#endif