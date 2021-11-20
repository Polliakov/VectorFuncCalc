#include <iostream>
#include <string>

#include "Function1.cpp"
#include "Function2.cpp"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");

	int vectorSize;

	cout << "������� ������ �������: ";
	cin >> vectorSize;

	FunctionContainer** vectorFunction = new FunctionContainer*[vectorSize];

	double* inputVector = new double[vectorSize];
	cout << "\n������� ������ a: " << endl;
	for (int i = 0; i < vectorSize; i++) {
		cout << "������� " << i + 1 << ": ";
		cin >> inputVector[i];
	}

	int x;

	cout << "\n������� �������� x: ";
	cin >> x;


	cout << "\n����� ������� � ���� ����������:" << endl;
	cout << "������� 1: a*cos(b*x)+c" << endl;
	cout << "������� 2: a*x^b" << endl;
	for (int i = 0; i < vectorSize; i++) {
		int functionType;
		double b;
		double c;

		cout << "��� " << i + 1 << "-� �������: ";
		cin >> functionType;

		switch (functionType) {
		case 1:
			cout << "��������� b c: ";
			cin >> b >> c;

			vectorFunction[i] = new Function1(inputVector[i], x, b, c);
			break;
		case 2:
			cout << "�������� b: ";
			cin >> b;

			vectorFunction[i] = new Function2(inputVector[i], x, b);
			break;
		default:
			cout << "������� ��� � ������" << endl;
			i--;
			break;
		}
	}
	delete[] inputVector;

	cout << "\n�������������� ������:" << endl;
	for (int i = 0; i < vectorSize; i++) {
		cout << vectorFunction[i]->invoke() << " ";
	}

	system("pause > nul");
	return 0;
}