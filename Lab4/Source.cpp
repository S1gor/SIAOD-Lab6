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
		if (flag)	break;
	}
}

int getNextStep(int step)
{
	const float factor = 1.247;
	step /= factor;

	return step < 1 ? 1 : step;
}

void combSort(int* mas, int size, int& steps)
{
	int step = size;

	bool flag = true;
	while (step != 1 || flag)
	{
		step = getNextStep(step);
		flag = false;
		for (int i = 0; i < size - step; i++)
		{
			if (mas[i] > mas[i + step])
			{
				swap(mas[i], mas[i + step]);
				flag = true;
			}
			steps++;
		}
	}
}

int selectSort()
{
	int choice;
	printf("Choose: 1 - bubble sort, 2 - combSort;\nChoice:");
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
		combSort(mas, size, steps);
		break;
	}
	
	print(mas, size, "After sorting:\t");
	printf("\nSteps: %d\n", steps);

	return 0;
}