#ifndef __UVSPHERE_H__
#define __UVSPHERE_H__

#include "Shape.h"
#include "Vector3.h"
#include "Ray.h"
#include "Texture.h"

class UVSphere : public Shape
{
public:
	UVSphere(const Vector3& _center, float _radius, Texture* tex);
	BBox bounddingBox() const;
	bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& record) const;
	bool shadowHit(const Ray& r, float tmin, float tmax, float time) const;
	~UVSphere();

public:
	Vector3 center;
	float radius;
	Texture* tex;
};

#endif