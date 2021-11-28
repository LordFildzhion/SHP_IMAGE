#include"Image.h"
#include<ctime>
#include<cstdlib>
class Renderer{
    public:
        Renderer(Image& image, string ret){
            Image outImage(image.width, image.height, image.pixels);

            srand(time(NULL));
            Color color;
			for(int i=0;i<image.pixels.size();i++){
				uchar medium_color =255 - image.pixels[i].getColor().R/3;
                bool key=false;
                if(rand()%medium_color==0){
                    key=true;
                }
                if(ret=="black"){
                    if(key){
                        color.setColor(255,255,255,image.pixels[i].getColor().A);
                    }
                    else{
                        color.setColor(0,0,0,image.pixels[i].getColor().A);
                    }
                }
                else{
                    if(key){
                        color.setColor(0,0,0,image.pixels[i].getColor().A);
                    }
                    else{
                        color.setColor(255,255,255,image.pixels[i].getColor().A);
                    }
                }
                image.pixels[i].setColor(color);
			}
        }
};