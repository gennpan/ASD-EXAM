#include <iostream>


class point 
{                               //generalmente di default i primi sono private
    public:
        point(double X, double Y) { x=X; y=Y; } //costruttore classe base
        void setx(double);
        void sety(double);
        double getx() {return x; }
        double gety() {return y; }
    
    private:
        double x, y;
};

void point::setx(double X) { x=X; }
void point::sety(double Y) { y=Y; }


//DEFINISCO UNA NUOVA CLASSE POINT3D
class point3d : public point        //public indica il tipo di ereditarietà
{
    public:
        point3d(double X, double Y, double Z):point(X,Y) { z=Z; } //costruttore classe derivata che richiama quello della classe base
        double getz() { return z; }
        void setz(double Z) { z=Z; }

    private:
        double z;
};



int main()
{
    
}