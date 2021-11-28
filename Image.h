#include "Pixel.h"
#include "lodepng.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Image{
	public:
		unsigned int width, height;
		vector <Pixel> pixels;
		Image():width(0),height(0){}
		Image(int width, int height, vector <Pixel> pixels):width(width),height(height),pixels(pixels){}
		Image(Image& img):width(img.width),height(img.height),pixels(img.pixels){}
		Image(string filename){
			filename+=".png";
			const char* filein = filename.c_str();
			vector <uchar> image;
			unsigned width, height, w=0, h=0;
			lodepng::decode(image, width, height, filein);
			for(unsigned long long i=0;i<width*height*4;i+=4,w++){
				Color color(image[i],image[i+1],image[i+2],image[i+3]);
				Point point(w/width,w%width+1);
				Pixel pixel(color,point);
				pixels.push_back(pixel);
			}
		}
		Image& operator = (Image&);

		void setPixel(Pixel pixel, unsigned x){
			pixels[x]=pixel;
		}

		void setPixel(Color color, unsigned x, unsigned y){
		Point point(x, y);
		Pixel pixel(color, point);
		pixels[y*width+x]=pixel;
		}

		void setPixel(Color color, Point point){
			
			Pixel pixel(color, point);
			pixels[pixel.getY()*width+pixel.getY()]=pixel;
		}
		
		void setPixel(Pixel pixel){
			pixels[pixel.getY()*width+pixel.getX()]=pixel;
		}
		
		Pixel getPixel(unsigned x){
			return pixels[x];
		}

		Pixel getPixel(unsigned x, unsigned y){
			return pixels[y*width+x];
		}

		void setColor(Color color){
			for(int i=0;i<pixels.size();i++){
				if(pixels[i].getColor().A>0){
				uchar medium_color = pixels[i].getColor().R/3+pixels[i].getColor().G/3+pixels[i].getColor().B/3;
				uchar r,g,b;
				uchar max = std::max(color.R,std::max(color.G,color.B));
				r=(color.R * medium_color)/max;
				g=(color.G * medium_color)/max;
				b=(color.B * medium_color)/max;
				Color col(r,g,b);
				pixels[i].setColor(col);
				}
    		}
		}

		void outputImage(string filename){
			filename+=".png";
			vector <uchar> image;
			unsigned width=pixels[pixels.size()-1].getY(), height=pixels[pixels.size()-1].getX();
			for(unsigned long long i=0;i<pixels.size();i++){
				image.push_back(pixels[i].getColor().R);
				image.push_back(pixels[i].getColor().G);
				image.push_back(pixels[i].getColor().B);
				image.push_back(pixels[i].getColor().A);
			}
			lodepng::encode(filename.c_str(), image, width, height);
		}
		
};
