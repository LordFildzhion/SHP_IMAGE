#include<iostream>
#include<cassert>
#include "Pixel.h"
using namespace std;
int main(){
    //----Pixel----//

	//Constructor pixel
	Pixel pix;
	assert(pix.getColor().R==0);
	assert(pix.getColor().G==0);
	assert(pix.getColor().B==0);
	assert(pix.getColor().A==0);
	assert(pix.getX()==0);
	assert(pix.getY()==0);

	//Inclusion parameters
	pix.setColor(WHITE);
	pix.setPos(50,100);
	assert(pix.getColor().R==255);
	assert(pix.getColor().G==255);
	assert(pix.getColor().B==255);
	assert(pix.getColor().A==255);
	assert(pix.getX()==50);
	assert(pix.getY()==100);

	//Constructor pixel with parameters
	Color col(WHITE);
	Point pos(50,100);
	Pixel pix1(col,pos);
	assert(pix1.getColor().R==255);
	assert(pix1.getColor().G==255);
	assert(pix1.getColor().B==255);
	assert(pix1.getColor().A==255);
	assert(pix1.getX()==50);
	assert(pix1.getY()==100);

	//Transmission data
	Pixel pix2(pix);
	assert(pix2.getColor().R==255);
	assert(pix2.getColor().G==255);
	assert(pix2.getColor().B==255);
	assert(pix2.getColor().A==255);
	assert(pix2.getX()==50);
	assert(pix2.getY()==100);

	//Transmission parameters check
	pix2.setColor(BLACK);
	pix2.setPos(0,0);
	assert(pix.getColor().R==255);
	assert(pix.getColor().G==255);
	assert(pix.getColor().B==255);
	assert(pix.getColor().A==255);
	assert(pix.getX()==50);
	assert(pix.getY()==100);

	cout<<"Tests complete!"<<endl;
}
