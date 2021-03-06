// lab 9.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void getCount() {
	char str[1000];
	int counter;
	int numeralCounter = 0;
	int curLetterCounter = 0;
	int lowLetterCounter = 0;
	printf("input the string: ");
	scanf("%s", &str);

	for (counter = 0; counter < strlen(str); counter++) {
		if ((str[counter] >= '0') && (str[counter] <= '9')) {
			numeralCounter++;
		}
		if ((str[counter] >= 'A') && (str[counter] <= 'Z')) {
			curLetterCounter++;
		}
		if ((str[counter] >= 'a') && (str[counter] <= 'z')) {
			lowLetterCounter++;
		}
	}
	printf("there is %d numeral in the string;\n", numeralCounter);
	printf("there is %d cursive letters in the string;\n", curLetterCounter);
	printf("there is %d lowcursive letters in the string\n", lowLetterCounter);
}

float getMonthCost() {
	float timeTalk;
	float subscriptionFee;
	float minuteCost;

	printf("enter the talk time: ");
	scanf("%f", &timeTalk);
	printf("enter the subscription fee: ");
	scanf("%f", &subscriptionFee);
	printf("enter the minute cost: ");
	scanf("%f", &minuteCost);

	if (minuteCost < (subscriptionFee / 499)) {
		printf("incorrect info\n");
		exit(1);
	}
	if (timeTalk <= 499) {
		return subscriptionFee;
	}
	else {
		return subscriptionFee + (timeTalk - 499) * minuteCost;
	}
}

char* getIntInStr() {
	char *str[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char* res = (char*)malloc(5*sizeof(char));
	int num;

	printf("please, input the numeral here: ");
	scanf("%d", &num);
	strcpy(res, str[num]);

	return res;
}

int main()
{
	int functionChoice;
	printf("1. Count numeral, cursive and lowcursive letters in the string\n");
	printf("2. Telephone subscription fee\n");
	printf("3. Get numeral into string\n");
	printf("	Wich function do you want to play? ");
	scanf("%d", &functionChoice);

	switch (functionChoice) {
		case 1: {
			getCount();
			break;
		}
		case 2: {
			printf("you need to pay %.2f rubles;\n", getMonthCost());
			break;
		}
		case 3: {
			printf("%s\n", getIntInStr());
			break;
		}
		default:
			printf("illegal symbols!");
			break;
	}
    return 0;
}

