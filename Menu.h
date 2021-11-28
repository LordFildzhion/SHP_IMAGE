#include"Renderer.h"
class Menu{
    private:
    int v;
    string filename;
    Image image;
    public:
        Menu(int v, string filename):v(v),filename(filename){Image image(filename);this->image=image;}
        
        void setColor(string color){
            image.setColor(color);
        }

        void blackWhite(string blackWhite){
            image.setColor("grey");
            Renderer Renderer(image, blackWhite);
        }
        
};