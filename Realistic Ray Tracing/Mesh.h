#ifndef __MESH_H__
#define __MESH_H__

#include "Vertex.h"
#include "Shape.h"
#include "Texture.h"

class Mesh{
public:
	Mesh(){}
	~Mesh(){}
	Texture* getTexture() const{ return tex; }

public:
	Texture*	tex;
	Vector3*	verts;
	VertexUV*	vertUVs;
	VertexN*	vertNs;
	VertexUVN*	vertUVNs;
};

#endif