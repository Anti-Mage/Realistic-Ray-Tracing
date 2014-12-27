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
	Image(int width, int height);					//����դ��ʼ��ΪĬ����ɫ
	Image(int width, int height, const rgb& background);	//����դ��ʼ��Ϊbachground��ɫ
	~Image();

	bool set(int x, int y, const rgb& color);
	void gammaCorret(float gamma);
	void writePPM(std::ostream& out);
	void readPPM(const std::string& file_name);
	int width(){ return nx; }
	int height() { return ny; }

private:
	rgb** raster;	//��դ����
	int nx;			//��դ�Ŀ��
	int ny;			//��դ�ĳ���
};

#endif