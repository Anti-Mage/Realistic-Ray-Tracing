#ifndef __IMAGE_TEXTURE_H__
#define __IMAGE_TEXTURE_H__

#include "Texture.h"

class Image;

class ImageTexture : public Texture{
public:
	ImageTexture(char* file_name);
	virtual rgb value(const Vector2& uv, const Vector3& p) const;

	Image* image;
};

#endif