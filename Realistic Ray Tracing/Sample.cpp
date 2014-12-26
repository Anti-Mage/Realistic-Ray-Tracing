#include "Sample.h"
#include "Vector2.h"
#include <math.h>
#include <stdlib.h>
#include "RNG.h"


void random(Vector2* samples, int num_sample){
	for (int i = 0; i < num_sample; ++i){
		samples[i].setX(drand48());
		samples[i].setY(drand48());
	}
}

void jitter(Vector2* samples, int num_sample){
	int sqrt_samples = (int)(std::sqrt(num_sample));

	for (int i = 0; i < sqrt_samples; ++i){
		for (int j = 0; j < sqrt_samples; ++j){
			float x = ((double)i + drand48()) / (double)sqrt_samples;
			float y = ((double)j + drand48()) / (double)sqrt_samples;
			(samples[i * sqrt_samples + j]).setX(x);
			(samples[i * sqrt_samples + j]).setY(y);
		}
	}
}

void nrooks(Vector2* samples, int num_sample){

}
