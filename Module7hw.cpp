#pragma once
#include "IntArray.h";
#include <iostream>

int main()
{
	int temp = 0;

	//Создание контейнера с отрицательным размером
	try
	{
		IntArray arr1(-1);
	}
	catch (bad_length& bl1)
	{
		cout << bl1.what() << endl << endl;
	}

	//Обращение к элементу за пределами контейнера
	IntArray arr2(5);
	for (int i{ 0 }; i < 5; i++)
		arr2[i] = i + 1;
	try
	{
		temp = arr2[-2];
	}
	catch (bad_range& br2)
	{
		cout << br2.what() << endl << endl;
	}

	//Попытка вставить элемент за пределами контейнера
	//(элемента с индексом "5" не существует)
	IntArray arr3(5);
	for (int i{ 0 }; i < 5; i++)
		arr3[i] = i + 1;
	try
	{
		arr3.insertAfter(7, 5);
	}
	catch (bad_range& br3)
	{
		cout << br3.what() << endl << endl;
	}

	//Попытка создать контейнер комически большого размера
	try
	{
		IntArray arr4(10000000000000000000);
	}
	catch (bad_alloc& ba4)
	{
		cout << ba4.what() << endl << endl;
	}
	catch (bad_length& bl4)
	{
		cout << bl4.what() << endl << endl;
	}

	//Попытка создать контейнер размера int
	//если не хватит памяти, то поймается исключение bad_alloc
	try
	{
		IntArray arr5(2147483647);
		cout << "Container created successfully" << endl;
	}
	catch (bad_alloc& ba5)
	{
		cout << ba5.what() << endl << endl;
	}
	catch (bad_length& bl5)
	{
		cout << bl5.what() << endl << endl;
	}
}
