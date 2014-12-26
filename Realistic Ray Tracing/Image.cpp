#include "Image.h"


Image::Image()
{
}


Image::~Image()
{
}

Image::Image(int width, int height){
	nx = width;
	ny = height;

	raster = new rgb*[nx];			//给光栅分配内存
	for (int i = 0; i < nx; ++i){
		raster[i] = new rgb[ny];
	}
}

Image::Image(int width, int height, const rgb& background){
	nx = width;
	ny = height;

	raster = new rgb*[nx];			//给光栅分配内存
	for (int i = 0; i < nx; ++i){
		raster[i] = new rgb[ny];
		for (int j = 0; j < ny; ++j)
			raster[i][j] = background;
	}
}

bool Image::set(int x, int y, const rgb& color){
	if (x < 0 || x >= nx) return false;
	if (y < 0 || y >= ny) return false;

	raster[x][y] = color;
	return true;
}

void Image::gammaCorret(float gamma){
	rgb tmp;
	float power = 1.0f / gamma;
	for (int i = 0; i < nx; ++i){
		for (int j = 0; j < ny; ++j){
			tmp = raster[i][j];
			raster[i][j] = rgb(pow(tmp.r(), power), pow(tmp.g(), power), pow(tmp.b(), power));
		}
	}
}

void Image::writePPM(std::ostream& out){
	out << "P6\n";
	out << nx << ' ' << ny << '\n';
	out << "255\n";

	int i, j;
	unsigned int ired, igreen, iblue;
	unsigned char red, green, blue;

	for (i = ny - 1; i >= 0; --i){
		for (j = 0; j < nx; ++j){
			ired = (unsigned int)(256 * raster[j][i].r());
			igreen = (unsigned int)(256 * raster[j][i].g());
			iblue = (unsigned int)(256 * raster[j][i].b());

			if (ired > 255) ired = 255;
			if (igreen > 255) igreen = 255;
			if (iblue > 255) iblue = 255;

			red = (unsigned char)ired;
			green = (unsigned char)igreen;
			blue = (unsigned char)iblue;

			out.put(red);
			out.put(green);
			out.put(blue);
		}
	}
}

void Image::readPPM(const std::string& file_name){
	std::ifstream in;
	in.open(file_name.c_str());

	if (!in.is_open()){
		std::cerr << "ERROR -- Could't open file \'" << file_name << "\'.\n";
		exit(-1);
	}

	char ch, type;
	char red, green, blue;
	int i, j, cols, rows;
	int num;

	in.get(ch);
	in.get(type);
	in >> cols >> rows >> num;

	nx = cols;
	ny = rows;

	raster = new rgb*[nx];
	for (i = 0; i < nx; ++i){
		raster[i] = new rgb[ny];
	}
	in.get(ch);

	for (i = ny - 1; i >= 0; --i){
		for (j = 0; j < nx; ++j){
			in.get(red);
			in.get(green);
			in.get(blue);

			raster[j][i] = rgb((float)((unsigned char)red) / 255.0f, (float)((unsigned char)green) / 255.0f, (float)((unsigned char)blue) / 255.0f);
		}
	}
}
