#include<iostream>
#include<cassert>
#include "Pixel.h"
using namespace std;
int main(){
	//----Color----//

	//Constructor color
	Color c;
	assert(c.R==0);
	assert(c.G==0);
	assert(c.B==0);
	assert(c.A==0);

	//Inclusion parameters
	c.R=5;
	assert(c.R==5);
	c.G=10;
	assert(c.G==10);
	c.B=15;
	assert(c.B==15);
	c.A=20;
	assert(c.A==20);

	//Constructor color with parameters
	Color c1(255,254,253,0);
	assert(c1.R==255);
	assert(c1.G==254);
	assert(c1.B==253);
	assert(c1.A==0);

	//Constructor color with parameters but without A
	Color c2(1, 2, 3);
	assert(c2.R==1);
	assert(c2.G==2);
	assert(c2.B==3);
	assert(c2.A==255);

    //Transmission data
    Color c3(c1);
    assert(c3.R==255);
	assert(c3.G==254);
	assert(c3.B==253);
	assert(c3.A==0);

    //Transmission parameters check
    c1.setColor(BLACK);
    assert(c1.R==0);
	assert(c1.G==0);
	assert(c1.B==0);
	assert(c1.A==255);
	
	
    
    cout<<"Tests complete!"<<endl;
}
