#include <iostream>

using namespace std;
class Ship {
protected:
    int length;
    int displacement;
public:
    Ship(int l, int d) : length(l), displacement(d) {}
     ~Ship() {}
    int getLength() const { return length; }
    void setLength(int l) { length = l; }
    int getDisplacement() const { return displacement; }
    void setDisplacement(int d) { displacement = d; }
};

class Steamship : public Ship {
private:
    int maxSpeed;
public:
    Steamship(int l, int d, int s) : Ship(l, d), maxSpeed(s) {}
    ~Steamship() {}
    int getMaxSpeed() const { return maxSpeed; }
    void setMaxSpeed(int s) { maxSpeed = s; }
};

class Sailboat : public Ship {
private:
    int sailArea;
public:
    Sailboat(int l, int d, int a) : Ship(l, d), sailArea(a) {}
    ~Sailboat() {}
    int getSailArea() const { return sailArea; }
    void setSailArea(int a) { sailArea = a; }
};

class Yacht : public Sailboat {
private:
    int cabins;
public:
    Yacht(int l, int d, int a, int c) : Sailboat(l, d, a), cabins(c) {}
    ~Yacht() {}
    int getCabins() const { return cabins; }
    void setCabins(int c) { cabins = c; }
};

int main() {
    Ship ship1(100, 5000);
    Steamship steamship1(120, 7000, 30);
    Sailboat sailboat1(80, 2000, 100);
    Yacht yacht1(60, 1000, 50, 2); 


    cout << "Ship 1: length = " << ship1.getLength() << ", displacement = " << ship1.getDisplacement() << endl;
    cout << "Steamship 1: length = " << steamship1.getLength() << ", displacement = " << steamship1.getDisplacement() << ", max speed = " << steamship1.getMaxSpeed() << endl;
    cout << "Sailboat 1: length = " << sailboat1.getLength() << ", displacement = " << sailboat1.getDisplacement() << ", sail area = " << sailboat1.getSailArea() << endl;
    cout << "Yacht 1: length = " << yacht1.getLength() << ", displacement = " << yacht1.getDisplacement() << ", sail area = " << yacht1.getSailArea() << ", cabins = " << yacht1.getCabins() << endl;

    ship1.setLength(150);
    steamship1.setMaxSpeed(40);
    sailboat1.setSailArea(120);
    yacht1.setCabins(3);

    cout << "Ship 1: length = " << ship1.getLength() << ", displacement = " << ship1.getDisplacement() << endl;
    cout << "Steamship 1: length = " << steamship1.getLength() << ", displacement = " << steamship1.getDisplacement() << ", max speed = " << steamship1.getMaxSpeed() << endl;
    cout << "Sailboat 1: length = " << sailboat1.getLength() << ", displacement = " << sailboat1.getDisplacement() << ", sail area = " << sailboat1.getSailArea() << endl;
    cout << "Yacht 1: length = " << yacht1.getLength() << ", displacement = " << yacht1.getDisplacement() << ", sail area = " << yacht1.getSailArea() << ", cabins = " << yacht1.getCabins() << endl;


    return 0;
}