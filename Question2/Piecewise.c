#include <stdio.h>

int f_way1(int n) {
	// version ONE: using Function Recursion
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	return f_way1(n - 2) + f_way1(n - 3);
}

int f_way2(int n) {
	// version TWO: using Space Optimization
	int a = 0, b = 1, c = 2, d = 0;
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	if (n == 2)
		return c;

	for (int i = 3; i <= n; i++) {
		d = a + b;
		a = b;
		b = c;
		c = d;
	}
	return d;
}

int f_way3(int n) {
	// version THREE: using Dynamic Programming 
	int* f = (int*)malloc(sizeof(int) * (n + 1));
	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 2] + f[i - 3];
	}

	return f[n];
}

void main() {
	for (int i = 0; i < 11; i++) {
		printf("F(%d):\n", i);
		printf("Way One: %-4d  Way Two: %-4d  Way Three: %d\n", f_way1(i), f_way2(i), f_way3(i));
	}
}