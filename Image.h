#include "Pixel.h"
#include "lodepng.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Image{
	private:
		unsigned int width, height;
		vector <Pixel> pixels;
	public:
		Image():width(0),height(0){}
		Image(int width, int height, vector <Pixel> pixels):width(width),height(height),pixels(pixels){}
		Image(const Image& img):width(img.width),height(img.height),pixels(img.pixels){}

		void inputImage(string filename="1"){
			filename+=".png";
			const char* filein = filename.c_str();
			vector <uchar> image;
			unsigned width, height, w=0, h=0;
			unsigned error = lodepng::decode(image, width, height, filein);
			for(unsigned long long i=0;i<=width*height*4;i+=4,w++){
				Color color(image[i],image[i+1],image[i+2],image[i+3]);
				if(w==width&&h!=height-1){
					h++;
					w=0;
				}
				Point point(h,w);
				Pixel pixel(color,point);
				pixels.push_back(pixel);
			}
		}

		void SetPixel(Pixel pixel, unsigned x, unsigned y){
			pixels[x*y]=pixel;
		}

		Pixel getPixel(unsigned x, unsigned y){
			return pixels[x*y];
		}

		vector <Pixel> getPixels(){
			return pixels;
		}

		void outputImage(vector <Pixel> pixels, string filename="2"){
			filename+=".png";
			vector <uchar> image;
			unsigned width=pixels[pixels.size()-1].getY(), height=pixels[pixels.size()-1].getX();
			for(unsigned long long i=0;i<pixels.size();i++){
				image.push_back(pixels[i].getColor().R);
				image.push_back(pixels[i].getColor().G);
				image.push_back(pixels[i].getColor().B);
				image.push_back(pixels[i].getColor().A);
			}
			unsigned error = lodepng::encode(filename.c_str(), image, width, height);
		}
		
};
