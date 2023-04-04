#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;
class Student // початок оголошення класу
{
	string name, lastname; // прізвище студента
	int s1, s2, s3; // бали
public:
	void Set(string name, string lastname, int s1, int s2, int s3)
	{
		this->name = name;
		this->lastname = lastname;
		this->s1 = s1;
		this->s2 = s2;
		this->s3 = s3;
	}
	string GetName()
	{
		return lastname;
	}
	void Print()
	{
		cout << "Студент(ка) " << name << " " << lastname << " має " << s1 << " балiв по математиці, "
			<< s2 << " балiв по фізиці, " << s3 << " балiв по інформатиці " << " Середній бал: " << serbal() << endl;
	}
	double serbal()
	{
		return (s1 + s2 + s3) / 3;
	}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int kilkist = 0;
	string str;
	ifstream fin("C:\\Lab3\\data.txt"); // створення потоку читання файлу
	if (fin)
	{
		while (!fin.eof()) 
		{
			getline(fin, str, '\n');
			kilkist++; 
		}
		
		Student* P = new Student[kilkist];
		fin.clear(); 
		fin.seekg(0); 
		for (int i = 0; i < kilkist; i++)
		{
			string name, lastname ;
			int s1, s2, s3;
			fin >> name >> lastname;
			fin >> s1 >> s2 >> s3; 
			P[i].Set(name, lastname, s1, s2, s3);
		}
		for (int i = 0; i < kilkist; i++)
			P[i].Print();
		// сортування за алфавітом
		for (int i = 0; i < kilkist - 1; i++)
			for (int j = i + 1; j < kilkist; j++)
				if (P[i].serbal() < P[j].serbal())
				{
					swap(P[i], P[j]); 
				}
		// вивід списку за алфавітом
		for (int i = 0; i < kilkist; i++)
			P[i].Print();
			for (int i = 0; i < kilkist - 1; i++)
				for (int j = i + 1; j < kilkist; j++)
					if (P[i].GetName() < P[j].GetName())
					{
						swap(P[i], P[j]);
					}
			for (int i = 0; i < kilkist; i++)
			{
				if (P[i].serbal() >= 4)
				P[i].Print();
			}
		fin.close(); // закриття потоку
		delete[]P; // звільнення динамічної пам’яті
	}
	else
		cout << "Unable to open file";
}
