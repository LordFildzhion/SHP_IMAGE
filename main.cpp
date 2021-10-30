#include"Image.h"
using namespace std;
int main(){
    Image image;
    string filenameIn, filenameOut;
    cout<<"Input name of file for in (without \".png\")"<<endl;
    cin>>filenameIn;
    image.inputImage(filenameIn);
    vector <Pixel> pixels=image.getPixels();
    cout<<"Input name of file for out (without \".png\")"<<endl;
    cin>>filenameOut;
    image.outputImage(pixels, filenameOut);
}