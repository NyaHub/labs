#include <iostream>
#include <string>

using namespace std;

int main(){

	float z;// tut musor
	float *z1 = &z;// tut ssilka na musor
	printf("Zadanie 1: z=%2.2f, *z1=%i\n\n", z, z1);

	*z1 *= 2;
	printf("Zadanie 2: z=%2.2f, *z1=%i\n\n", z, z1);

	srand(z);// a pochemu net?
	int *arr;
	int arrSize;
	cout << "Zadanie 3:" << endl;
	cout << "Enter array size: "; cin >> arrSize;
	arr = (int *) calloc(arrSize, sizeof(int));
	if(!arr){
		printf("Allocation filure!\n");
	}
	int a, b;
	cout << "Enter a: "; cin >> a;
	cout << "Enter b: "; cin >> b;
	int s;
	for(int i = 0; i < arrSize; i++){
		arr[i] = rand() % (b - a) + a;
		s += arr[i];
	}
	printf("Sum: %i; Avg: %2.2f.\n", s, (float) s/arrSize);

	return 0;
}
