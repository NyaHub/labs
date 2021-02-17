#include <stdio.h>
#include <cmath>

int posled(int start, int down, int up, int (*callback)(int k, int i));
int add(int k, int i) { return k + (pow(i, 3) + 1); }
int mul(int k, int i) { return k * (i / (i - 3)); }

int main()
{
	int k = posled(0, 2, 5, &add) - posled(1, 5, 12, &mul);
	printf("%i\n", k);
	return 0;
}

int posled(int start, int down, int up, int (*callback)(int k, int i))
{
	int k = start;
	for (int i = down; i <= up; i++)
	{
		k = callback(k, i);
	}
	return k;
}
