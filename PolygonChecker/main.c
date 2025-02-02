#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			if (strcmp(result, "Scalene triangle") == 0 || strcmp(result, "Scalene triangle") == 0 || strcmp(result, "Scalene triangle") == 0) {
				printangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}
			break;

		case 2:
			printf("Rectangle selected.\n");
			RectFunction();
			break;

		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		int tmp = scanf_s("%d", &triangleSides[i]);
		if (tmp != 1) {
			printf("Please enter a valid integer.\n");
			exit(1);
		}
	}
	return triangleSides;
}




int RectFunction()
{
	int p1[2], p2[2], p3[2], p4[2];
	char confirmInp;
	int whileState = 1;
	int whilestate2 = 1;

	while (whileState)
	{
		printf("What is your first point's X axis(upper left)?\n");
		if (scanf_s("%d", &p1[0]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}
		printf("What is your first point's Y axis(upper left)?\n");
		if (scanf_s("%d", &p1[1]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}

		printf("What is your second point's X axis(upper right)?\n");
		if (scanf_s("%d", &p2[0]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}		
		printf("What is your second point's Y axis(upper right)?\n");
		if (scanf_s("%d", &p2[1]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}

		printf("What is your third point's X axis(lower left)?\n");
		if (scanf_s("%d", &p3[0]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}		
		printf("What is your third point's Y axis(lower left)?\n");
		if (scanf_s("%d", &p3[1]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}

		printf("What is your fourth point's X axis(lower right)?\n");
		if (scanf_s("%d", &p4[0]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}		
		printf("What is your fourth point's Y axis(lower right)?\n");
		if (scanf_s("%d", &p4[1]) != 1) {
			printf("Please enter a valid number\n");
			exit(1);
		}
		printf("Are these your coordinates?\n");
		printf("Upper Left: (%d, %d)\n", p1[0], p1[1]);
		printf("Upper Right: (%d, %d)\n", p2[0], p2[1]);
		printf("Lower Left: (%d, %d)\n", p3[0], p3[1]);
		printf("Lower Right: (%d, %d)\n", p4[0], p4[1]);
		printf("Confirm (y/n): ");

		while (getchar() != '\n');
		while (whilestate2)
		{
			scanf_s("%c", &confirmInp, 1);
			if (confirmInp == 'y' || confirmInp == 'Y') {
				whilestate2 = 0;
				whileState = 0;
			}
			else if (confirmInp == 'n' || confirmInp == 'N') {
				printf("Please re-enter the coordinates.\n");
				whilestate2 = 0;
			}
			else {
				printf("Invalid input, please enter 'y' or 'n'.\n");
			}
		}
		
	}




	int Upp_X_Diff = abs(p1[0] - p2[0]);
	int Upp_Y_Diff = abs(p1[1] - p3[1]);
	int Low_X_Diff = abs(p3[0] - p4[0]);
	int Low_Y_Diff = abs(p2[1] - p4[1]);

	int area = Upp_X_Diff * Upp_Y_Diff;
	int peri = 2 * (Upp_X_Diff + Upp_Y_Diff);
	int peri2 = Upp_X_Diff + Upp_Y_Diff + Low_X_Diff + Low_Y_Diff;
	if (Upp_X_Diff == Low_X_Diff && Upp_Y_Diff == Low_Y_Diff)
	{
		printf("This shape matches a rectangle\n");
		printf("The Perimeter is : %d\n", peri);
		printf("The Area is : %d\n", area);

	}

	else
	{
		printf("This shape does not match a rectangle\n");
		printf("The Perimeter is :%d\n", peri2);
	}
	return 0;
}