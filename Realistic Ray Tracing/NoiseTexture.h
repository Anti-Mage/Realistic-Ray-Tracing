#ifndef __NOISE_TEXTURE_H__
#define __NOISE_TEXTURE_H__

#include <math.h>
#include "Texture.h"
#include "rgb.h"
#include "SolidNoise.h"

class NoiseTexture : public Texture{
public:
	NoiseTexture(float _scale = 1.0f){
		scale = _scale;
		c0 = rgb(0.8, 0.0, 0.0);
		c1 = rgb(0.0, 0.0, 0.8);
	}

	NoiseTexture(const rgb& _c0, const rgb& _c1, float _scale = 1.0f) :c0(_c0), c1(_c1), scale(_scale){}

	virtual rgb value(const Vector2& uv, const Vector3& p) const;

	float scale;
	rgb c0, c1;
	SolidNoise solid_noise;
};

#endif