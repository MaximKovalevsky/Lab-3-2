// Lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


class Complex
{
	private:
		double z1;
		double z2;

	public:
		Complex() //базовый конструктор
		{
			z1 = 0;
			z2 = 0;
		}
		Complex(const Complex& other) //конструктор копирования
		{
			z1 = other.z1;
			z2 = other.z2;
		}
		Complex& operator=(Complex other) //оператор присваивания копированием
		{
			swap(z1, other.z1);
			swap(z2, other.z2);
			return *this;
		}
		friend Complex operator+(Complex other1, const Complex& other2) //оператор +
		{
			Complex temp = other1;
			temp += other2;
			return temp;
		}
		Complex& operator+=(Complex other) //оператор +=
		{
			z1 += other.z1;
			z2 += other.z2;
			return *this;
		}
		Complex operator*(Complex &other) //оператор *
		{
			double a, b;
			if (other.z2 < 0)
			{
				a = z1 * other.z1 - z2 * other.z2;
				b = z1 * other.z2 + other.z1 * z2;
			}
			else
			{
				a = z1 * other.z1 + z2 * other.z2;
				b = z1 * other.z2 + other.z1 * z2;
			}
			z1 = a;
			z2 = b;
			return *this;
		}
		Complex& operator*=(Complex other) //оператор *=
		{
			z1 *= other.z1;
			z2 *= other.z2;
			return *this;
		}
		friend ostream& operator<<(ostream& out, const Complex& other) //оператор вывода
		{
			if (other.z2 < 0)
				out << other.z1 << "+i(" << other.z2 << ")\n";
			else
				out << other.z1 << "+i" << other.z2 << "\n";
			return out;
		}
		friend istream& operator>>(istream& in, Complex& other) //оператор ввода
		{
			std::cout << "Введите действительную часть комплексного числа" << '\n';
			in >> other.z1;
			std::cout << "Введите мнимую часть комплексного числа" << '\n';
			in >> other.z2;
			return in;
		}
		Complex& operator++() //префиксный инкремент
		{
			this->z1 += 1;
			return *this;
		}
		Complex& operator++(int) //постфиксный инкремент
		{
			Complex temp = *this;
			this->z1 += 1;
			return temp;
		}
		~Complex() //деструктор
		{

		}



};

int main()
{
	setlocale(LC_ALL, "rus");
	Complex z1;
	cin >> z1;
	cout << "\n";
	cout << "Итоговое комплексное число: " << z1 << "\n";
	Complex z2;
	Complex z3;
	Complex z4;
	cin >> z2;
	cout << "\n";
	cout << "Итоговое комплексное число: " << z2 << "\n";
	cout << "Копируем второе число в первое: ";
	cout << (z1 = z2);//конструктор копирования на примере
	cout << "Сложим два комплексных числа: " << z1 + z2;//оператор +
	cout << "Произведем операцию += для числа z1: " << (z1 += z2);//оператор +=(после это действия обновляется z1)
	cout << "Перемножим два комплексных числа: " << z1 * z2;//оператор *
	cout << "Произведем операцию *= для числа z1: " << (z1 *= z2);//оператор *=
	cout << "++z =  " << ++z1;


}