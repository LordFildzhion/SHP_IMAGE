#include"Image.h"
#include<ctime>
#include<cstdlib>
class Renderer{
    private:

    public:
        Renderer(Image& image, string ret){
            Image outImage(image.width, image.height, image.pixels);

            srand(time(NULL));
            Color color;
			for(int i=0;i<image.pixels.size();i++){
				uchar medium_color = image.pixels[i].getColor().R/3+image.pixels[i].getColor().G/3+image.pixels[i].getColor().B/3;
                bool key=false;
                if(medium_color==255){
                    key=true;
                }
                else if(medium_color==0){

                }
                else if(medium_color>=204){
                    if(1 + rand()%2==1){
                        key=true;
                    }
                }
                else if(medium_color>=153){
                    if(1 + rand()%3==1){
                        key=true;
                    }
                }
                else if(medium_color>=102){
                    if(1 + rand()%4==1){
                        key=true;
                    }
                }
                else if(medium_color>=51){
                    if(1 + rand()%5==1){
                        key=true;
                    }
                }
                else{
                    if(1 + rand()%6==1){
                        key=true;
                    }
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