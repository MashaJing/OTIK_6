#include <iostream>
#include <fstream>
#include <ctime>
#include "SoloveiStrassen.h"

using namespace std;

int main()
{
	int rounds;
	//int num;
	int beg;
	int end;

	SoloveiStrassen tester;
	ifstream Input;
	char filename[100];
	bool enterfile = false;

	while (!enterfile)//���� �� ������� ��� ������������� �����
	{
		cout << "Enter the file name: ";
		cin >> filename;
		Input.open(filename);
		if (Input.is_open()) enterfile = true;
		else if (filename[0] == '0') return 0;
		else cout << "This one does not exist! Try again or enter 0 to exit.\n\n";

	}



	try
	{
		Input >> rounds; //��������� ���������� �������� �� �����
		if (Input.eof()) throw exception("The file is empty!");
		
		Input >> beg;
		Input >> end;//��������� ������� ���������, � ������� ����� ����� ������� �����

		Input.close();

		if (beg > end)
		{
			int p = end;
			end = beg;
			beg = p;
		}
		unsigned int start_time = clock(); // ��������� �����
   
		
		for (int j = beg; j <= end; j++)
		{
			for (int i = 0; i < rounds; i++)
			{
				if (tester.Is_simple(j) == false)
				{
					break;
				}
				else if (i == rounds - 1)
				{
					cout << "Number " << j << " is prime with probability of " << 1.0 - pow(0.5, rounds) << endl;
					cout << i + 1 << " iterations" << endl;
					unsigned int end_time = clock(); // �������� �����
					unsigned int search_time = end_time - start_time; // ������� �����
					
					cout << "Time elapse: "<< search_time << endl;
					return 0;
				}
			}
			continue;

		}

		unsigned int end_time = clock(); // �������� �����
		unsigned int search_time = end_time - start_time; // ������� �����
		cout << "Time elapse: " << search_time << endl;
		cout << "No prime numbers in this interval!" << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
		return 0;
	
}