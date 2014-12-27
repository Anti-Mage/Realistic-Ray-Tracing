#include "MarbleTexture.h"

rgb MarbleTexture::value(const Vector2& uv, const Vector3& p) const{
	float tmp = scale * noise.turbulence(freq * p, octaves);
	float t = 2.0f * std::fabs(std::sin(freq * p.x() + tmp));

	if (t < 1.0f){
		return (c1 * t + (1.0 - t)*c2);
	}
	else{
		t -= 1.0f;
		return (c0 * t + (1.0f - t) * c1);
	}
}