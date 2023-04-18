#include <iostream>
#include <cmath>
#define PI 3.14

using namespace std;
class Cilinder {
private:
    double radius; // Радіус циліндра
    double height; // Висота циліндра

public:
    // Конструктор без параметра
    Cilinder() : radius(0), height(0) {}

    // Конструктор з параметрами
    Cilinder(double r, double h) : radius(r), height(h) {}

    // Методи для отримання значення радіуса і висоти
    double getRadius() const {
        return radius;
    }

    double getHeight() const {
        return height;
    }

    // Методи для присвоювання значення радіуса і висоти
    void setRadius(double r) {
        radius = r;
    }

    void setHeight(double h) {
        height = h;
    }

    // Перевантаження операції виводу
    friend ostream& operator<<(ostream& os, const Cilinder& cilinder) {
        os << "Радіус: " << cilinder.radius << ", Висота: " << cilinder.height << ", Об'єм: " << cilinder.getVolume();
        return os;
    }

    // Перевантаження операції додавання
    Cilinder operator+(const Cilinder& other) const {
        double maxRadius = max(radius, other.radius);
        double sumVolume = getVolume() + other.getVolume();
        return Cilinder(maxRadius, sumVolume / maxRadius);
    }

    // Перевантаження операції інкремента (++), збільшує радіус і висоту на одиницю
    Cilinder& operator++() {
        ++radius;
        ++height;
        return *this;
    }

    // Метод для обчислення об'єму циліндра
    double getVolume() const {
        return PI * radius * radius * height;
    }
};

int main() {
    setlocale(0, "Ukr");
    Cilinder c1; // Створення циліндра зі значеннями за замовчуванням (0, 0)
    cout << "Циліндр 1: " << c1 << endl;

    Cilinder c2(3, 5); // Створення циліндра зі значеннями радіуса=3 та висоти=5
    cout << "Циліндр 2: " << c2 << endl;

    c1.setRadius(2); // Задання нового значення радіуса для циліндра 1
    c1.setHeight(4); // Задання нового значення висоти для циліндра 1
    cout << "Циліндр 1 (після зміни): " << c1 << endl;
    cout << "Об'єм циліндра 1: " << c1.getVolume() << endl;
    cout << "Об'єм циліндра 2: " << c2.getVolume() << endl;

    Cilinder c3 = c1 + c2; // Додавання двох циліндрів
    cout << "Циліндр 3 (після додавання): " << c3 << endl;

    ++c1; // Збільшення радіуса і висоти циліндра 1 на одиницю
    cout << "Циліндр 1 (після збільшення): " << c1 << endl;

    return 0;
}
