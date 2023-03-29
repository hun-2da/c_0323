#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//element *k;
typedef struct{
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	int rows;
	int cols;
	int terms;

} SparseMatrix;

element* matrix_transpose2(SparseMatrix a,element *p) {

	element *b = NULL;
	int bindex;

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (p->col == c) {
					b[i].row = p[i].col;
					b[i].col = p[i].row;
					b[i].value = p[i].value;
					bindex++;
				}
			}
		}
		return b;
	}
}

void martrix_print(SparseMatrix a, element *p) {

	printf("============\n");

	for (int i = 0; i < a.terms; i++) {

		printf("(%d, %d, %d) \n", p[i].row, p[i].col, p[i].value);

	}
	printf("============\n");
}
int main(void) {
	
	element* p = (element*)malloc(sizeof(element));
	//int* num[] = (int*)malloc(sizeof(int));


	SparseMatrix m = {6,6,7};
	int num[] = { 0,3,7,1,0,9,1,5,8,3,0,6,3,1,5,4,5,1,5,2,2 };

	for (int i = 0; i < m.terms; i++) {
		p[i].row = num[i];
		p[i].col = num[i+1];
		p[i].value = num[i+2];
	}
	element *result;
	result = matrix_transpose2(m,p);
	martrix_print(m,result);
	free(p);
	system("pause");
	return 0;
}