#include <iostream>

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(int* mas, int size, int& steps)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - 1 - i; j++)
			if (mas[j] > mas[j + 1])
			{
				swap(mas[j], mas[j + 1]);
				steps++;
			}
}

void selectionSort(int* mas, int size, int& steps)
{
	int min_idx;
	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < size; j++)
			if (mas[j] < mas[min_idx])
				min_idx = j;

		if (min_idx != i)
		{
			swap(mas[min_idx], mas[i]);
			steps++;
		}
	}
}

int selectSort()
{
	int choice;
	printf("Choose: 1 - bubble sort, 2 - selection sort.\nChoice:");
	do {
		scanf_s("%d", &choice);
	} while (choice > 2 || choice < 1);
	printf("\n");
	return choice;
}

void print(int* mas, int size, const char* message)
{
	printf("%s", message);
	for (int i = 0; i < size; i++)
		printf("%d ", mas[i]);
}

int main()
{
	const int size = 8;
	int mas[size] = { 8,7,6,5,4,3,2,1 };
	int steps = 0;

	print(mas, size, "Before sorting:\t");
	printf("\n\n");

	switch (selectSort())
	{
	case 1:
		bubbleSort(mas, size, steps);
		break;
	case 2:
		selectionSort(mas, size, steps);
		break;
	}
	
	print(mas, size, "After sorting:\t");
	printf("\nSteps: %d\n", steps);

	return 0;
}