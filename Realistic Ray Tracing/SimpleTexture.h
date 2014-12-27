#ifndef __SIMPLE_TEXTURE_H__
#define __SIMPLE_TEXTURE_H__

#include "Texture.h"

class SimpleTexture : public Texture{
public:
	SimpleTexture(rgb c) :color(c){}
	virtual rgb value(const Vector2&, const Vector3&) const{
		return color;
	}

	rgb color;
};

#endif