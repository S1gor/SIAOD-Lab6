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
	{
		bool flag = true;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				swap(mas[j], mas[j + 1]);
				flag = false;
			}
			steps++;
		}
		if (flag)
			break;
	}
}

void selectionSort(int* mas, int size, int& steps)
{
	int min_idx;
	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (mas[j] < mas[min_idx])
				min_idx = j;
			steps++;
		}
		if (min_idx != i)
			swap(mas[min_idx], mas[i]);
	}
}

void ñombSort(int* mas, int size, int& steps)
{
	const float factor = 1.247;
	float step = size - 1;

	while (step > 1)
	{
		for (int i = 0; i + step < size; i++)
		{
			if (mas[i] > mas[int(i + step)])
				swap(mas[i], mas[int(i + step)]);
			steps++;
		}
		step /= factor;
	}
}

int selectSort()
{
	int choice;
	printf("Choose: 1 - bubble sort, 2 - selection sort , 3 - combSort;\nChoice:");
	do {
		scanf_s("%d", &choice);
	} while (choice > 3 || choice < 1);
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
	//int mas[size] = { 2,3,4,5,6,1,7,8 };
	//int mas[size] = { 1,2,3,4,8,7,6,5 };
	//int mas[size] = { 8,7,6,5,1,2,3,4 };
	//int mas[size] = { 8,7,6,5,4,3,2,1 };
	int mas[size] = { 1,2,3,4,5,6,7,8 };
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
	case 3:
		ñombSort(mas, size, steps);
		break;
	}
	
	print(mas, size, "After sorting:\t");
	printf("\nSteps: %d\n", steps);

	return 0;
}