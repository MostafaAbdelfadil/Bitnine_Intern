#include <stdio.h>

enum TypeTag {
	ADD, //Addition (+) Node
	SUB, //Subtraction (-) Node
	MUL, //Multiblication (*) Node
	DIV, //Division (/) Node
	NUM, //Number Node
	FIB  //Fibunacci Calculator Node
};

typedef struct Node {
	enum TypeTag type;
	struct Node* left;
	struct Node* right;
	int value;
};

// Node creation
struct Node* makeFunc(enum TypeTag type) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->type = type;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

//Node of type NUM creation
struct Node* makeValue(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->type = NUM;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = value;

	return newNode;
}

//Fibunacci Calculation
int fibonacci(int n) {
	int* fib = (int*)malloc(sizeof(int) * (n + 1));
	//fib[0] = 0;
	//fib[1] = 1;
	for (int i = 0; i <= n; i++) {
		if (i <= 1)
			fib[i] = i;
		else
			fib[i] = fib[i - 1] + fib[i - 2];
	}
	int a = fib[n];
	return a;
}

//Process any Node
int calc(struct Node* node) {
	if (node->type == ADD)
		return calc(node->left) + calc(node->right);
	else if (node->type == SUB)
		return calc(node->left) - calc(node->right);
	else if (node->type == MUL)
		return calc(node->left) * calc(node->right);
	else if (node->type == DIV)
		return calc(node->left) / calc(node->right);
	if (node->type == FIB)
		return fibonacci(calc(node->left));
	else
		return node->value;
}



void main() {
	//Testcase in the PDF
	struct Node* add = makeFunc(ADD);
	add->left = makeValue(10);
	add->right = makeValue(6);
	struct Node* mul = makeFunc(MUL);
	mul->left = makeValue(5);
	mul->right = makeValue(4);
	struct Node* sub = makeFunc(SUB);
	sub->left = makeValue(calc(add));
	sub->right = makeValue(calc(mul));
	struct Node* fibo = makeFunc(FIB);
	fibo->left = makeValue(abs(calc(sub)) - 1);
	fibo->value = fibonacci(calc(fibo->left));

	//Desired output
	printf("add : %d\n", calc(add));
	printf("mul : %d\n", calc(mul));
	printf("sub : %d\n", calc(sub));
	printf("fibo : %d\n", calc(fibo));
}
