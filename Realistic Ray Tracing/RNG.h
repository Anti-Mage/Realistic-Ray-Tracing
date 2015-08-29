#ifndef __RNG_H__
#define __RNG_H__

class RNG{
public:
	RNG(unsigned long long _seed = 7564231ULL){
		seed = _seed;
		mult = 62089911ULL;
		llong_max = 4294967295ULL;
		float_max = 4294967295.0f;
	}
	float operator()();

private:
	unsigned long long seed;
	unsigned long long mult;
	unsigned long long llong_max;
	float float_max;
};

inline float RNG::operator()(){
	seed = mult * seed;
	return float(seed % llong_max) / float_max;
}

#define m 0x100000000LL  
#define c 0xB16  
#define a 0x5DEECE66DLL  

static unsigned long long seed = 1;

static double drand48(void)
{
	seed = (a * seed + c) & 0xFFFFFFFFFFFFLL;
	unsigned int x = (unsigned int)(seed >> 16);
	return  ((double)x / (double)m);

}

static void srand48(unsigned int i)
{
	seed = (((long long int)i) << 16) | rand();
}

#endif