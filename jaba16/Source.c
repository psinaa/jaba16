#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#define N 100

double* massive(double* ptr_array, int n);
int print_massive(double* ptr_array, int n);
double* izm_massive(double* ptr_array, int n, double* new_mas);
int delete_k(double* ptr_array, int size);
double* insert(double* ptr_array, int size, int index, int num);
double tri_massiva(double* ptr_arraya, double* ptr_arrayb, double* ptr_arrayc, double* ptr_arrayd, int size);

main()
{
	setlocale(LC_ALL, "rus");
	double* ptr_array, * new_mas, * ptr_arraya, * ptr_arrayb, * ptr_arrayc, * ptr_arrayd;
	double element;
	int size, menu = 10, menu1 = 10, menu2 = 10;
	printf("Введите размер массива: ");
	scanf("%d", &size);
	ptr_array = (double*)malloc(size * sizeof(double));
	ptr_arraya = (double*)malloc(size * sizeof(double));
	ptr_arrayb = (double*)malloc(size * sizeof(double));
	ptr_arrayc = (double*)malloc(size * sizeof(double));
	ptr_arrayd = (double*)malloc(size * sizeof(double));
	new_mas = (double*)malloc(size * sizeof(double));
	massive(ptr_array, size);
	srand(time(NULL));
	while (menu != 0)
	{
		printf("1-1 задание \n2-2 задание\n3-дз\n0-выход\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			while (menu1 != 0)
			{
				printf("1-вывод массива\n2-вывод измененного массива\n3-удалить массивы\n0-выход\n");
				scanf("%d", &menu1);
				switch (menu1)
				{
				case 1:
					print_massive(ptr_array, size);
					break;
				case 2:
					izm_massive(ptr_array, size, new_mas);
					break;
				case 3:
					free(ptr_array);
					free(new_mas);
					break;
				}
			}
		case 2:
			while (menu2 != 0)
			{
				printf("1-удаление всех отрицательных элементов\n2-вставить -999 после каждого положительного\n0-выход\n");
				scanf("%d", &menu2);
				switch (menu2)
				{
				case 1:
					delete_k(ptr_array, size);
					break;
				case 2:
					insert(ptr_array, size, 5, -999);
					break;
				}
			}
		case 3:
			tri_massiva(ptr_arraya, ptr_arrayb, ptr_arrayc, ptr_arrayd, size);
		}
	}
}

double* massive(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(ptr_array + i) = -1 + rand() % 3;
	}
	return ptr_array;
}

int print_massive(double* ptr_array, int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = %lf\n", i + 1, *(ptr_array + i));
	}
	return ptr_array;
}

double* izm_massive(double* ptr_array, int n, double* new_mas)
{
	for (int i = 0; i < n; i++)
	{
		*(new_mas + i) = *(ptr_array + i) * (-1);
	}
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = %lf\n", i + 1, *(new_mas + i));
	}
}
int delete_k(double* ptr_array, int size)
{
	int n = size;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] < 0)
		{
			for (int m = i; m < size - 1; m++)
				ptr_array[m] = ptr_array[m + 1];
			size--;
			i--;
		}
	}
	for (int i = 0; i < size; i++)
		printf("A[%d]=%lf\n", i, ptr_array[i]);
	return size;
}
double* insert(double* ptr_array, int size, int index, int num)
{
	for (int i = size; i >= 0; i--)
	{
		if (ptr_array[i] > 0)
		{
			size++;
			for (int k = size; k >= i + 1; k--)
				ptr_array[k] = ptr_array[k - 1];
			ptr_array[i + 1] = num;
		}
	}
	for (int i = 0; i < size; i++)
		printf("A[%d]=%lf\n", i, ptr_array[i]);
}
double tri_massiva(double* ptr_arraya, double* ptr_arrayb, double* ptr_arrayc, double* ptr_arrayd, int size)
{
	int n = size;
	for (int i = 0; i <= n; i++)
	{
		ptr_arraya[i] = rand();
		ptr_arrayb[i] = rand();
		ptr_arrayc[i] = rand();
	}
	for (int i = 0; i <= n; i++)
	{
		double max;
		if (ptr_arraya[i] > ptr_arrayb[i] && ptr_arraya[i] > ptr_arrayc[i])
			max = ptr_arraya[i];
		else if (ptr_arrayb[i] > ptr_arraya[i] && ptr_arrayb[i] > ptr_arrayc[i])
			max = ptr_arrayb[i];
		else if (ptr_arrayc[i] > ptr_arraya[i] && ptr_arrayc[i] > ptr_arrayb[i])
			max = ptr_arrayc[i];
		ptr_arrayd[i] = max;
	}
	for (int i = 0; i < n; i++)
		printf("a[%d]=%lf\tb[%d]=%lf\tb[%d]=%lf\tb[%d]=%lf\n", i, ptr_arraya[i], i, ptr_arrayb[i], i, ptr_arrayc[i], i, ptr_arrayd[i]);
}