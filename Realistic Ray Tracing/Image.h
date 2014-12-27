#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <cmath>
#include <string>
#include <fstream>
#include "rgb.h"

class Image
{
public:
	Image();
	Image(int width, int height);					//将光栅初始化为默认颜色
	Image(int width, int height, const rgb& background);	//将光栅初始化为bachground颜色
	~Image();

	bool set(int x, int y, const rgb& color);
	void gammaCorret(float gamma);
	void writePPM(std::ostream& out);
	void readPPM(const std::string& file_name);
	int width(){ return nx; }
	int height() { return ny; }

private:
	rgb** raster;	//光栅矩阵
	int nx;			//光栅的宽度
	int ny;			//光栅的长度
};

#endif