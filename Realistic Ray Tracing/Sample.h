#ifndef __SAMPLE_H__
#define __SAMPLE_H__
#include <cmath>
class Vector2;

//2D sampling
void random(Vector2* samples, int num_samples);
void jitter(Vector2* samples, int num_samples);
void nrooks(Vector2* samples, int num_samples);
void multiJitter(Vector2* samples, int num_sample);
void shuffle(Vector2* samples, int num_sample);

void boxFilter(Vector2* sample, int num_sample);
void tentFilter(Vector2* sample, int num_sample);
void cubicSplineFilter(Vector2* sample, int num_sample);

//1D sampling
void random(float* samples, int num_sample);
void jitter(float* samples, int num_sample);
void shuffle(float* samples, int num_sample);

inline float solve(float r){
	float u = r;
	for (int i = 0; i < 5; ++i){
		u = (11.0f * r + u * u * (6.0f + u * (8.0f - 9.0f * u))) / (4.0f + 12.0f * u * (1.0f + u * (1.0 - u)));
	}
	return u;
}

inline float cubicFilter(float x){
	if (x < 1.0f / 24.0f){
		return std::pow(24 * x, 0.25f) - 2.0;
	}
	else if (x < 0.5f){
		return solve(24.0f * (x - 1.0f / 24.0f) / 11.0f) - 1.0f;
	}
	else if (x < 23.0f / 24.0f){
		return 1.0f - solve(24.0f * (23.0f / 24.0f - x) / 11.0f);
	}
	else{
		return 2.0f - std::pow(24.0f * (1.0 - x), 0.25f);
	}
}
#endif