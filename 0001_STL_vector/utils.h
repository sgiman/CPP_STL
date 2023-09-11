//****************************** 
// utils.h
// �++ | Visual Studio 2022 
//****************************** 
// Writing by sgiman @ 2022-2023

#pragma once

#include <iostream>
#include <cmath>
#include <ctime>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

/*------------------
	   MyDate
-------------------*/
// For current Date
struct tm newtime;
__time32_t aclock;

void MyDate()
{
	// Time
	cout << "**************************************************************\n";
	time_t current_time;
	current_time = time(NULL);
	cout << current_time;
	cout << " seconds has passed since 00:00:00 GMT, Jan 1, 1970\n";

	// Current Date
	char buffer[32];
	errno_t errNum;
	_time32(&aclock);
	_localtime32_s(&newtime, &aclock);
	errNum = asctime_s(buffer, 32, &newtime);
	printf("Current date and time: %s", buffer);
	cout << "**************************************************************\n";
}

/*----------------------------- 
	 ��������� ���. ������ 
------------------------------*/
void FillArray(int* const arr, const int size, const int max)
{
	srand(time(NULL));							// �c�������� ������� ��� rand() 
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % max;					// 1..max
	}
}

/*----------------------------- 
      ������� ���. ������ 
------------------------------*/
void ShowArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "  " << arr[i] << "\t";
	}
	cout << endl;
}

/*----------------------------- 
  ���������� ����� ��������� 
------------------------------*/
template <typename T> 
class SmartPointer
{
public:
	SmartPointer(T *ptr)	// �����������
	{
		this->ptr = ptr;	// ��������� �������� ����� (���������)
		cout << "=== Constructor (smart pointer) ===" << endl;

	}
	~SmartPointer()			// ����������
	{
		delete ptr;			// ���������� ������ (��� ������ �� ������� ��������� {} - �������/�����)
		cout << "=== Destructor (clear memory) ===" << endl;
	}

	T& operator *()			// cc���� (�����) ��� ��������� (��� ������� �����)
	{
		return *ptr;		// ������� ������ �� ��������� 
	}

private:
	T* ptr;		// ���������� ���������
};
