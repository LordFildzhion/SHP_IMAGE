#include<iostream>
#include<cassert>
#include "Pixel.h"
using namespace std;
int main(){
	//----Pixel----//

	//Construcor point
	Point p;
	assert(p.x==0);
	assert(p.y==0);
	
	//Inclusion parameters
	p.x=5;
	assert(p.x==5);
	p.y=10;
	assert(p.y==10);
	
	//Constructor point with parameters
	Point p1(7,-7);
	assert(p1.x==7);
	assert(p1.y==-7);
	
	//Transmission data
	Point p2(p1);
	assert(p2.x==p1.x);
	assert(p2.y==p1.y);

	//Transmission parameters check
	p2.x=77; p2.y=12;
	assert(p1.x==7);
	assert(p1.y==-7);

	cout<<"Tests complete!"<<endl;
}