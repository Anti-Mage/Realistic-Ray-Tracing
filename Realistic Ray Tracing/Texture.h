#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "Vector2.h"
#include "Vector3.h"
#include "rgb.h"

class Texture{
public :
	virtual rgb value(const Vector2&, const Vector3&) const = 0;
};

#endif