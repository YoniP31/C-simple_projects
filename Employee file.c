/*
A. Write a function that creats a binary file of Employee lists.
   The function receives as parameters the string that contains the file name,
   the function needs to organize the input data and save it in the file.
B. Write a function that gets the file name and a salary threshold, the
   function should organize the additional salary, if the new salary is
   higher than the threshold remove the employee's data, else, save new data.
C. Write a function that displays the contents of the binary file.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct employee {
	int code;
	char name[15];
	float salary;
}Employee;

Employee list;

void printFile(char* filename) {
	FILE* file;
	file = fopen(filename, "rb");
	if (!file) {
		printf("file is not open\n");
		return;
	}
	printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
	while (fread(&list, sizeof(struct employee), 1, file) != NULL) {
		printf("%-10d%-13s%7.2f\n", list.code, list.name, list.salary);
	}
	fclose(file);
}

void updateSalary(char* filename, int threshold) {
	FILE* file;
	FILE* temp_file;
	float raise;
	file = fopen(filename, "rb+");
	if (!file) {
		printf("file is not open\n");
		return;
	}
	temp_file = fopen("tmp.bin", "wb+");
	if (!temp_file) {
		printf("file is not open\n");
		return;
	}
	while (!feof(file)) {
		fread(&list, sizeof(struct employee), 1, file);
		printf("Enter Employee's %s raise amount: ", list.name);
		scanf("%f", &raise);
		if ((raise + list.salary) < threshold) {
			list.salary += raise;
			printf("%.2f\n", list.salary);
			//copying to a new file with the change (raise)
			fwrite(&list, sizeof(struct employee), 1, temp_file);
		}
		else {
			printf("IF did not accure\n");
		}
	}
	fclose(file);
	fclose(temp_file);
	remove(filename);
	rename("tmp.bin", filename);

}

void binary_file(char* title) {
	FILE* file;
	char c;
	file = fopen(title, "wb+");
	if (!file) {
		printf("file is not open\n");
		return;
	}
	else {
		printf("Enter employee's code, name, and salary.\n");
		printf("Enter EOF to end input.\n");
		printf("? ");
		scanf("%d%s%f", &list.code, list.name, &list.salary);
		while (!feof(stdin)) {
			fwrite(&list, sizeof(struct employee), 1, file);
			//fprintf(file, "%d %s %.2f\n", list.code, list.name, list.salary);
			printf("? ");
			c = getchar();
			scanf("%d%s%f", &list.code, list.name, &list.salary);
		}
		fclose(file);
	}
}

void main() {
	char filename[20];
	int threshold;
	printf("Enter file name: ");
	scanf("%s", &filename);
	binary_file(filename);
	printf("Enter salary threshold: ");
	scanf("%d", &threshold);
	updateSalary(filename, threshold);
	printFile(filename);
}