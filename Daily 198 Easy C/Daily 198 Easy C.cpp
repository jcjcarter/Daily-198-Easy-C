// Daily 198 Easy C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int count_letters(char *word, int *count, int add) {
	int i = 0;
	while (strlen(word) > i) {
		if (word[i] >= 'a' && word[i] <= 'z')
			count[word[i] - 'a'] += add;
		else if (word[i] >= 'A' && word[i] <= 'Z')
			count[word[i] - 'A'] += add;
		i++;
	}
	return 0;
}

int summation(int *arr, int len) {
	int sum;
	int i;
	for (i = 0; i<len; i++)
		sum += arr[i];
	return sum;
}

int print_leftover(int *letters, int side) {
	int i;
	printf("LEFTOVER FROM %s: ", (side + 1) ? "RIGHT" : "LEFT");
	for (i = 0; i<26; i++)
		if (letters[i] * side>0)
			printf("%c * %i, ", i + 'a', letters[i] * side);
	putchar('\n');
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc<3) {
		fprintf(stderr, "Invalid Arguments!");
		return -1;
	}

	int letter_count[26] = { 0 };
	count_letters(argv[1], letter_count, 1);
	count_letters(argv[2], letter_count, -1);

	print_leftover(letter_count, 1);
	print_leftover(letter_count, -1);

	int sum = summation(letter_count, 26);
	if (sum>0)
		printf("\"%s\" (left) WINS. \"%s\" (right) LOSES.", argv[1], argv[2]);
	else if (sum<0)
		printf("\"%s\" (right) WINS. \"%s\" (left) LOSES.", argv[2], argv[1]);
	else
		printf("\"%s\" (left) TIES WITH \"%s\" (right).", argv[1], argv[2]);
	putchar('\n');
	return 0;
}