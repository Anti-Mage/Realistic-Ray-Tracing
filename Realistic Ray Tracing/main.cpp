#pragma warning(disable:4244)
#pragma warning(disable:4305)

#include <vector>
#include <iostream>
#include <fstream>
#include "Vector3.h"
#include "rgb.h"
#include "Image.h"
#include "Shape.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Vector2.h"
#include "Sample.h"
#include "SimpleTexture.h"
#include "MarbleTexture.h"
#include "NoiseTexture.h"
#include "DynSphere.h"

using namespace std;


int main(){

	
	HitRecord rec;
	bool is_a_hit;
	float tmax;
	Vector3 dir(0, 0, -1);

	vector<Shape*> shapes;
	shapes.push_back(new Sphere(Vector3(250, 250, -1000), 150, rgb(0.2f, 0.2f, 0.8f)));
	shapes.push_back(new Triangle(Vector3(300, 600, -800), Vector3(0, 100, -1000), Vector3(450, 20, -1000), rgb(0.8f, 0.2f, 0.2f)));

	Image img(500, 500);

	for (int i = 0; i < 500; ++i){
		for (int j = 0; j < 500; ++j){
			tmax = 100000.0f;
			is_a_hit = false;
			Ray r(Vector3(i, j, 0.0f), dir);

			for (int k = 0; k < static_cast<int>(shapes.size()); ++k){
				if (shapes[k]->hit(r, 0.00001f, tmax, 0, rec)){
					tmax = rec.t;
					is_a_hit = true;
				}
			}
			if (is_a_hit){
				img.set(i, j, rgb(0,0,0));
			}
			else{
				img.set(i, j, rgb(0.2f, 0.2f, 0.2f));
			}
		}
	}
	ofstream os("1.ppm");
	img.writePPM(os);

	return 0;
}