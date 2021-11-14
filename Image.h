#include "Pixel.h"
#include "lodepng.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define RED "red"
#define ORANGE "orange"
#define YELLOW "yellow"
#define GREEN "green"
#define LIGHTBLUE "light blue"
#define BLUE "blue"
#define MAGENTA "magenta"
#define NEGATIVE "negative"
#define GREY "grey"

using namespace std;
class Image{
	private:
		unsigned int width, height;
		vector <Pixel> pixels;
	public:
		Image():width(0),height(0){}
		Image(int width, int height, vector <Pixel> pixels):width(width),height(height),pixels(pixels){}
		Image(const Image& img):width(img.width),height(img.height),pixels(img.pixels){}

		Image(string filename="1"){
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

		void setPixel(Pixel pixel, unsigned x){
			pixels[x]=pixel;
		}

		void setPixel(Pixel pixel, unsigned x, unsigned y){
			pixels[y*width+x]=pixel;
		}

		Pixel getPixel(unsigned x){
			return pixels[x];
		}

		Pixel getPixel(unsigned x, unsigned y){
			return pixels[y*width+x];
		}

		vector <Pixel> getPixels(){
			return pixels;
		}

		void setColor(string color){
			for(int i=0;i<pixels.size();i++){
        		if(pixels[i].getColor().A>0){
					uchar medium_color = (pixels[i].getColor().R+pixels[i].getColor().G+pixels[i].getColor().B)/3;
					Color col;
					if(color==RED)
						col.setColor(medium_color,0,0);
					else if(color==ORANGE)
						col.setColor(medium_color,medium_color/2,0);
					else if(color==YELLOW)
						col.setColor(medium_color,medium_color,0);
					else if(color==GREEN)
						col.setColor(0,medium_color,0);
					else if(color==LIGHTBLUE)
						col.setColor(0,medium_color,medium_color);
					else if(color==BLUE)
						col.setColor(0,0,medium_color);
					else if(color==MAGENTA)
						col.setColor(medium_color,0,medium_color);
					else if(color==NEGATIVE)
						col.setColor(255-medium_color,255-medium_color,255-medium_color);
					else if(color==GREY)
						col.setColor(medium_color,medium_color,medium_color);
					else{
						printf("Color Incorrectly entered");
					}
					pixels[i].setColor(col);
				}
    		}
		}

		void outputImage(string filename="2"){
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
