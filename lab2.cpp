#include <iostream>
#include <cmath>
#define PI 3.14

using namespace std;

class Cilindr
{
private:
    int R, H;
public:
    Cilindr()
    {
        R = 0, H = 0;
    }
    Cilindr(int R, int H)
    {
        this->R = R;
        this->H = H;
    }
    void set_Cil(int R, int H)
    {
        this->R = R;
        this->H = H;
    }
    int get_CilR() { return R; }
    int get_CilH() { return H; }
    double Obm()
    {
        return PI * R * R * H;
    }
    friend void frd(Cilindr a, Cilindr b);
};
void print_val(Cilindr a)
{
    cout << "Rad: " << a.get_CilR() << endl;
    cout << "Vis: " << a.get_CilH() << endl;
    cout << "Obm: " << a.Obm() << endl;
}
void frd(Cilindr a, Cilindr b)
{
    cout << "Obm3: " << a.Obm() + b.Obm() << endl;
    if (a.R > b.R) cout << "Rad3: " << a.R << endl;
    else cout << "Rad3: " << b.R << endl;
}
int main()
{
    Cilindr a(4, 9);
    print_val(a);
    Cilindr b(6, 8);
    print_val(b);
    frd(a, b);
}
