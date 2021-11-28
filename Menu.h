#include"Renderer.h"
class Menu{
    private:
    int v;
    string filename;
    Image image;
    public:
        Menu(int v, string filename):v(v),filename(filename){Image image(filename);this->image=image;}
        
        void setColor(Color color){
            image.setColor(color);
        }

        void blackWhite(string blackWhite){
            Color color(122,122,122);
            image.setColor(color);
            Renderer Renderer(image, blackWhite);
        }
        
};