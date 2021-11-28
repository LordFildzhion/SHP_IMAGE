#include"Menu.h"
using namespace std;
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    Image image(a);
    Color col(GREY);
    image.setColor(col);
    image.outputImage(c);
}