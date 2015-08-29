#pragma warning(disable:4244)

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
	for (int i = 0; i < num_sample; ++i){
		samples[i].setX(((double)i + drand48()) / (double)num_sample);
		samples[i].setY(((double)i + drand48()) / (double)num_sample);
	}

	for (int i = num_sample - 2; i >= 0; --i){
		int target = int(drand48() * (double)i);
		float tmp = samples[i + 1].x();
		samples[i + 1].setX(samples[target].x());
		samples[target].setX(tmp);
	}
}

//assume num_samples is a perfect square
void multiJitter(Vector2* samples, int num_samples){
	int sqrt_samples = static_cast<int>(sqrt(num_samples));
	float subcell_width = 1.0f / (float(num_samples));

	for (int i = 0; i < sqrt_samples; ++i){
		for (int j = 0; j < sqrt_samples; ++j){
			samples[i*sqrt_samples + j].setX(i*sqrt_samples*subcell_width + j*subcell_width + drand48()*subcell_width);
			samples[i*sqrt_samples + j].setY(j*sqrt_samples*subcell_width + i*subcell_width + drand48()*subcell_width);
		}
	}

	for (int i = 0; i < sqrt_samples; ++i){
		for (int j = 0; j < sqrt_samples; ++j){
			int k = j + int(drand48() * (sqrt_samples - j - 1));
			float t = samples[i*sqrt_samples + j].x();
			samples[i*sqrt_samples + j].setX(samples[k*sqrt_samples + k].x());
			samples[i*sqrt_samples + k].setX(t);

			k = j + int(drand48() * (sqrt_samples - j - 1));
			t = samples[i*sqrt_samples + j].y();
			samples[j*sqrt_samples + i].setY(samples[k*sqrt_samples + i].y());
			samples[k*sqrt_samples + i].setY(t);
		}
	}
}

void shuffle(Vector2* samples, int num_samples){
	for (int i = num_samples - 2; i >= 0; --i){
		int target = int(drand48() * (double)i);
		Vector2 tmp = samples[i + 1];
		samples[i + 1] = samples[target];
		samples[i + 1] = tmp;
	}
}

void boxFilter(Vector2* samples, int num_samples){
	for (int i = 0; i < num_samples; ++i){
		samples[i].setX(samples[i].x() - 0.5f);
		samples[i].setY(samples[i].y() - 0.5f);
	}
}

void tentFilter(Vector2* samples, int num_samples){
	for (int i = 0; i < num_samples; ++i){
		float x = samples[i].x();
		float y = samples[i].y();

		if (x < 0.5f)
			samples[i].setX((float)std::sqrt(2.0 * (double)x) - 1.0f);
		else
			samples[i].setX(1.0f - (float)std::sqrt(2.0 - 2.0 * (double)x));

		if (y < 0.5f)
			samples[i].setY((float)std::sqrt(2.0 * (double)y) - 1.0f);
		else
			samples[i].setY(1.0f - (float)std::sqrt(2.0 - 2.0 * (double)y));
	}
}

void cubicSplineFilter(Vector2* samples, int num_samples){
	for (int i = 0; i < num_samples; ++i){
		float x = samples[i].x();
		float y = samples[i].y();

		samples[i].setX(cubicFilter(x));
		samples[i].setY(cubicFilter(y));
	}
}

void random(float* samples, int num_samples){
	for (int i = 0; i < num_samples; i++){
		samples[i] = (float)drand48();
	}
}

void jitter(float* samples, int num_samples){
	for (int i = 0; i < num_samples; ++i){
		samples[i] = ((double)i + drand48()) / (double)num_samples;
	}
}

void shuffle(float* samples, int num_samples){
	for (int i = num_samples - 2; i >= 0; --i){
		int target = int(drand48() * (double)i);
		float tmp = samples[i + 1];
		samples[i + 1] = samples[target];
		samples[target] = tmp;
	}
}
