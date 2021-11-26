#include"Renderer.h"
using namespace std;
int main(){
    string inf, outf, ret;
    cout<<"Filename for input in program & black|white & filename for output from program"<<endl;
    cin>>inf>>ret>>outf;
    Image image(inf);
    image.setColor("grey");
    Renderer renderer(image, ret);
    image.outputImage(outf);
}