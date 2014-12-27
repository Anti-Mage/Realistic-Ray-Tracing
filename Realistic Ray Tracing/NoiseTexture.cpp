#include "NoiseTexture.h"

rgb NoiseTexture::value(const Vector2& rgb, const Vector3& p) const{
	float t = (1.0f + solid_noise.noise(p * scale)) / 2.0f;

	return t * c0 + (1 - t) * c1;
}