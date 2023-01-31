#include <stdio.h>

int f_way1(int n) {
	// version ONE: using Function Recursion
	if (n <= 2)
		return n;
	return f_way1(n - 2) + f_way1(n - 3);
}

int f_way2(int n) {
	// version TWO: using Space Optimization
	int a = 0, b = 1, c = 2, d = 0;
	if (n <= 2)
		return n;
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
	for (int i = 0; i <= n; i++) {
		if (i <= 2)
			f[i] = i;
		else
			f[i] = f[i - 2] + f[i - 3];
	}
	return f[n];
}

void main() {
	int way1, way2, way3;
	for (int i = 0; i < 7; i++) {
		way1 = f_way1(i);
		way2 = f_way2(i);
		way3 = f_way3(i);
		printf("F(%d):\n", i);
		printf("Way One: %-4d  Way Two: %-4d  Way Three: %d\n", way1, way2, way3);
	}
}
