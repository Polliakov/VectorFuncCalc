#include <iostream>
#include <string>

#include "Function1.cpp"
#include "Function2.cpp"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");

	int vectorSize;

	cout << "Введите размер вектора: ";
	cin >> vectorSize;

	FunctionContainer** vectorFunction = new FunctionContainer*[vectorSize];

	double* inputVector = new double[vectorSize];
	cout << "\nВведите вектор a: " << endl;
	for (int i = 0; i < vectorSize; i++) {
		cout << "Элемент " << i + 1 << ": ";
		cin >> inputVector[i];
	}

	int x;

	cout << "\nВведите аргумент x: ";
	cin >> x;


	cout << "\nВыбор функций и ввод аргументов:" << endl;
	cout << "Функция 1: a*cos(b*x)+c" << endl;
	cout << "Функция 2: a*x^b" << endl;
	for (int i = 0; i < vectorSize; i++) {
		int functionType;
		double b;
		double c;

		cout << "Тип " << i + 1 << "-й функции: ";
		cin >> functionType;

		switch (functionType) {
		case 1:
			cout << "Аргументы b c: ";
			cin >> b >> c;

			vectorFunction[i] = new Function1(inputVector[i], x, b, c);
			break;
		case 2:
			cout << "Аргумент b: ";
			cin >> b;

			vectorFunction[i] = new Function2(inputVector[i], x, b);
			break;
		default:
			cout << "Функции нет в списке" << endl;
			i--;
			break;
		}
	}
	delete[] inputVector;

	cout << "\nРезультирующий вектор:" << endl;
	for (int i = 0; i < vectorSize; i++) {
		cout << vectorFunction[i]->invoke() << " ";
	}

	system("pause > nul");
	return 0;
}