#include <iostream>
#include <windows.h>
#include <string>


using namespace std;

class Human 
{
	string name, lastName, phone;
	int code, age;
public:
	Human();
	Human(string name, string lastName, string phone, int code, int age);
	void set_name(string name) { this->name=name; }
	void set_lastName(string lastName) { this->lastName = lastName; }
	void set_phone(string phone) { this->phone= phone; }
	void set_code(int code) { this->code = code; }
	void set_age(int age) { this->age = age; }
	string get_name() { return name; }
	string get_lastName() { return lastName; }
	string get_phone() { return phone; }
	int get_code() { return code; }
	int get_age() { return age; }
	void print();
};

Human::Human()
{
	name = "����";
	lastName = "��������";
	phone = "(+38)-099-999-99-99";
	code = 111111;
	age = 18;
}

Human::Human(string name, string lastName, string phone, int code, int age)
{
	this->name = name;
	this->lastName = lastName;
	this->phone = phone;
	this->code = code;
	this->age = age;
}

void Human::print()
{
	cout << "��'�: " << name << "\n�������: " << lastName << "\n����� ��������: " << phone;
	cout << "\n���������������� ���: "<< code << "\n³�: " << age << endl;
 }

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Human a;
	Human b("������", "�������", "(+38)-088-888-88-88", 222222, 19); 
	a.print();
	b.print();
};
