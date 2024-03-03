
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
void frequent(int array[], int n);
void random(int array[], int n);
void show(int array[], int n);
void sort(int array[], int n);
void frequent(int arr[], int n)
{
	int max_count = 1, res = arr[0], curr_count = 1;   //  res - Зберігає найменше число, яке набільше разів трапляється
	for (int i = 1; i < n; i++)                       //  max_count - Зберігає максимальну кількість чисел            curr_count - Рахує поточну кількість елементів
	{
		if (arr[i] == arr[i - 1])
			curr_count++;
		else 
		{
			if (curr_count > max_count)
			{
				max_count = curr_count;
				res = arr[i - 1];
			}
			curr_count = 1;
		}
	}                        //якщо найменший елемент останній, то змінна зберігає його
	if (curr_count > max_count)
	{
		max_count = curr_count;
		res = arr[n - 1];
	}
	cout << res << " - Елемент, який зустрічається найчастіше - " << max_count << " раза(ів)"<<endl;
}
void random(int array[], int n)
{
	srand(time(NULL));
	for (int i = 0;i < n;i++)
	{
		array[i] = rand() % 20; //заповнення масиву випадковими числами
	}
}
void sort(int array[],int n)
{
	int min;  // ініціалізація додаткової змінної для переставлення елементів місцями
	for (int i = 0; i <= n - 1;i++)
	{
		for (int j = 0; j <= n - 2;j++)
		{
			if (array[j] > array[j + 1])
			{
				min = array[j + 1];
				array[j + 1] = array[j];
				array[j] = min;
			}
		}
	}
}
void show(int array[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << setw(3) << array[i];
	}
	cout << endl;
}
int main()
{
	SetConsoleOutputCP(1251);
	cout << "Виконва : Терещенко Богдан ІС-03" << endl;
	int n = 0; //   Розмірність масиву
	cout << "Введіть кількість елементів масиву:\n"; cin >> n;
	int *array = new int[n];    //Масив з випадковими числами
	random(array, n);          //Ззаповнення масиву випадковими числами
	show(array, n);           //Вивід масиву
	sort(array, n);          //Сортування масиву методом бульбашки
	show(array, n);         //Виведення масиву
	frequent(array, n);    //Функція для виведення найменшого елементу, який зустрічався начастіше
	delete[] array;
	system("pause");
}
