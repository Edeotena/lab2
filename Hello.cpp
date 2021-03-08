#include <iostream>
#include <clocale>
#include <cstdlib>;
#include <ctime>
#include <chrono>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	unsigned long long N,K;
	bool nach = false;
	string sizeN;
	cout << "Введите размер массива: ";
	cin >> sizeN;
	try
	{
		N = stoll(sizeN);
		nach = true;
	}
	catch (const exception &e)
	{
		cout << "Недостаточно оперативной памяти для работы программы";
	}
	if (nach) {
		nach = false;
		int* pptr = (int*)malloc(N * sizeof(int));
		if (pptr != NULL)
		{
			for (unsigned long long i = 0; i < N; i++)
			{
				pptr[i] = rand( ) % 10;
			}
			cout << "Изначальный массив: " << endl;
			for (unsigned long long i = 0; i < N; i++)
			{
				cout << pptr[i] << " ";
			}
			auto start = std::chrono::high_resolution_clock::now();
			for (unsigned long long i = 0; i < N - 1; i++)
			{
				for (unsigned long long j = 0; j < N - i - 1; j++)
				{
					if (pptr[j] > pptr[j + 1])
					{
						int temp = pptr[j];
						pptr[j] = pptr[j + 1];
						pptr[j + 1] = temp;
					}
				}
			}
			auto finish = std::chrono::high_resolution_clock::now();
			cout << endl << "Отсортированный массив: " << endl;
			for (unsigned long long i = 0; i < N; i++)
			{
				cout << pptr[i] << " ";
			}
			cout << endl << "Время выполнения сортировки: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << " наносекунд";
			cout << endl;
			cout << "Введите сколько элементов добавить в массив: ";
			cin >> sizeN;
			try
			{
				K = stoll(sizeN);
				nach = true;
			}
			catch (const exception& e)
			{
				cout << "Недостаточно оперативной памяти для работы программы";
			}
			if (nach)
			{
				pptr = (int*)realloc(pptr, (N + K) * sizeof(int));
				if (pptr != NULL)
				{
					cout << endl << "Массив после добавления: " << endl;
					for (unsigned long long i = 0; i < N + K; i++)
					{
						pptr[i] = rand() % 10;
					}
					for (unsigned long long i = 0; i < N + K; i++)
					{
						cout << pptr[i] << " ";
					}
					auto start = std::chrono::high_resolution_clock::now();
					sort(pptr, pptr + N + K);
					auto finish = std::chrono::high_resolution_clock::now();
					cout << endl << "Отсортированный массив: " << endl;
					for (unsigned long long i = 0; i < N + K; i++)
					{
						cout << pptr[i] << " ";
					}
					cout << endl << "Время выполнения сортировки: " << chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << " наносекунд" << endl;
				}
				else
				{
					cout << "Ошибка выделения памяти при добавлении элементов в массив";
				}
			}
			delete[] pptr;
		}
		else
		{
			cout << "Ошибка выделения памяти при создании массива";
		}
	}
	return 0;
}
