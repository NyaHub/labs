#include <stdio.h>

int main()
{
	int n = 0;

	do
	{
		printf("Enter num: ");
		scanf("%i", &n);
	} while (!((n >= 1) and (n <= 8)));

	switch (n)
	{
	case 1:
		printf("Автомобиль\n");
		break;
	case 2:
		printf("Компьютер\n");
		break;
	case 3:
		printf("Холодильник\n");
		break;
	case 5:
		printf("Стиральная машина\n");
		break;
	case 4:
		printf("телевизор\n");
		break;
	case 6:
		printf("Видик\n");
		break;
	case 7:
		printf("дом кино\n");
		break;
	case 8:
		printf("кепка\n");
		break;
	default:
		printf("как ты сюда попал?\n");
	}
	return 0;
}
