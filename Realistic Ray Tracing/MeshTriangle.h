#ifndef __MESH_TRIANGLE_H__
#define __MESH_TRIANGLE_H__

#include "Shape.h"

class Mesh;
class Texture;

class MeshTriangleUV : public Shape
{
public:
	MeshTriangleUV();
	MeshTriangleUV(Mesh* _mesh, int p0, int p1, int p2, int index);
	~MeshTriangleUV();
	bool hit(const Ray& r, float tmin, float tmax, float time, HitRecord& rec) const;
	bool shadowHit(const Ray& r, float tmin, float tmax, float time) const;

public:
	int p[3];
	Mesh* mesh_ptr;
};

#endif