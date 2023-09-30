#include <stdlib.h>
#include <stdio.h>

// malloc для указателя выделяет минимум 24(32 байта, 8 адресов), слeдующий 40(64 байла, 16 адресов), след 57(80 байт, 20 адресов)
int main()
{
	int *one;
	int **two;
	int **three;
	int **four;

	one = (int *)malloc(20);
	two = (int **)malloc(10);
	three = (int **)malloc(10);
	four = (int **)malloc(10);

	two[0] = (int *)malloc(24*sizeof(int)); // 8 байт
	two[1] = (int *)malloc(24*sizeof(int)); // 8 байт
	// printf("%d", sizeof(int));
	// two[2] = (int *)malloc(10);
	// two[3] = (int *)malloc(10);
	// two[0][0] = (int)malloc(1);
	// two[0][1] = (int)malloc(1);
	// two[0][2] = (int)malloc(1);
	// two[0][3] = (int)malloc(1);
	// two[0][4] = (int)malloc(1);
	// two[0][5] = (int)malloc(1);
	// two[0][6] = (int)malloc(1);
	// two[0][7] = (int)malloc(1);
	// two[0][8] = (int)malloc(1);
	// two[0][9] = (int)malloc(1);

	// two[0][0] = 1;
	// two[0][1] = 1;
	// two[0][2] = 1;
	// two[0][3] = 1;
	// two[0][4] = 1;
	// two[0][5] = 1;
	// two[0][6] = 1;
	// two[0][5] = 1;
	// two[0][7] = 1;
	// two[0][8] = 1;
	// two[0][9] = 1;

	// two[1][0] = 2;
	// two[1][1] = 2;
	// two[1][2] = 2;
	// two[1][3] = 2;
	// two[1][4] = 2;
	// two[1][5] = 2;
	// two[1][6] = 2;
	// two[1][5] = 2;
	// two[1][7] = 2;
	// two[1][8] = 2;
	// two[1][9] = 2;



	// 2wo[0][6] = 1;

	// two[0][7] = 1;
	// two[0][8] = 1;
	// two[0][9] = 1;

	// free(two[3]);
	// free(two[2]);
	// free(two[1]);

	// printf("%p\n", &two[0]);
	// printf("%p\n", &two[1]);
	// printf("%p\n", &two[2]);
	// printf("%p\n", &two[3]);
	printf("\n");
	printf("%p\n", &two);
	printf("%.2d: %p,%d %p,%d\n",  0, &two[0][0], two[0][0], &two[1][0], two[1][0]);
	printf("%.2d: %p,%d %p,%d\n",  1, &two[0][1], two[0][1], &two[1][1], two[1][1]);
	printf("%.2d: %p,%d %p,%d\n",  2, &two[0][2], two[0][2], &two[1][2], two[1][2]);
	printf("%.2d: %p,%d %p,%d\n",  3, &two[0][3], two[0][3], &two[1][3], two[1][3]);
	printf("%.2d: %p,%d %p,%d\n",  4, &two[0][4], two[0][4], &two[1][4], two[1][4]);
	printf("%.2d: %p,%d %p,%d\n",  5, &two[0][5], two[0][5], &two[1][5], two[1][5]);
	printf("%.2d: %p,%d %p,%d\n",  6, &two[0][6], two[0][6], &two[1][6], two[1][6]);
	printf("%.2d: %p,%d %p,%d\n",  7, &two[0][7], two[0][7], &two[1][7], two[1][7]);
	printf("%.2d: %p,%d %p,%d\n",  8, &two[0][8], two[0][8], &two[1][8], two[1][8]);
	printf("%.2d: %p,%d %p,%d\n",  9, &two[0][9], two[0][9], &two[1][9], two[1][9]);
	// printf("%p %p\n", &two[0][7], &two[1][7]);
	// printf("%p %p\n", &two[0][7], &two[1][7]);
	// printf("%p\n", &three);
	// printf("%p\n", &four);
	free(two[0]);
	free(two);
	free(one);
	return 0;
}
