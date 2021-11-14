#include"Image.h"
using namespace std;
int main(){
    string filenameIn, color;
    cout<<"Input name of file for in (without \".png\") and color"<<endl;
    cin>>filenameIn>>color;
    Image image(filenameIn);
    image.setColor(color);
    image.outputImage();
}