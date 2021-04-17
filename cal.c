#include<stdio.h> // include io library
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

int months[] = {31, 28, 31, 30, 31, 30, 
				31, 31, 30, 31, 30, 31};
char *monthsText[] = {"January","February","March","April","May","June","July",
					"August","September","October","November","December"};
char *match_month[] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};

/*The function takes a year and return if it is leap year */
int isLeapYear(int year){
	//return 1 if leap year, 0 otherwise
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
		return 1;
	}
	else{
		return 0;
	}
}

/*The function takes a day and return what day of the week it is */
int findWeekDay (int day, int month, int year){
	//return 0 if Sun, 1 if Mon, 2 if Tue, 3 if Wed, 4 if Thu, 5 if Fri, 6 if Sat

	if (isLeapYear(year) == 1){
		months[1] = 29;
	}
	// find the number of leap year up to but not including that year
	int result = day;
	for (int i = 1753; i < year; i++){
		if (isLeapYear(i) == 1){
			result += 366;
		}
		else{
			result += 365;
		}
	}

	for (int i = 0; i < month - 1; i++){
		result += months[i];
	}

	months[1] = 28;
	return result % 7;
}

/*The function takes a string and print the string in center align*/
void centerPrint(int n, char str[]){
	//n is the size of the printed string
	int stringLength = strlen(str);

	int leftAlign = (n - stringLength) / 2;
	int rightAlign = n - leftAlign - stringLength;
	char result[1000];
	int idx = 0;

	for (int i = 0; i < leftAlign; i++){
		result[idx] = ' ';
		idx++;
	}
	for (int i = 0; i < stringLength; i++){
		result[idx] = str[i];
		idx++;
	}
	for (int i = 0; i < rightAlign; i++){
		result[idx] = ' ';
		idx++;
	}
	result[idx] = '\0';
	printf("%s", result);
}

/*The function takes a month of a given year and print out the month*/
void printMonth(int month, int year){
	char date[100];
	sprintf(date, "%s %d",monthsText[month - 1], year);
	centerPrint(20, date);
	printf("\n");
	printf("Su Mo Tu We Th Fr Sa\n");
	int current = findWeekDay(1, month, year);
	int currentDay = 1;

	for (int i = 0; i < current; i++){
		printf("   ");
	}

	while (currentDay <= months[month - 1]){
		printf("%2d ", currentDay);
		if (current == 6){
			printf("\n");
		}
		current = (current + 1) % 7;
		currentDay++;
	}
	if (current != 0){
		printf("\n");
	}
	printf("\n");
}

/*The function takes 2 strings and concatenate them*/
char* stringCat(char str1[], char str2[]){
	static char result[100];
	int idx = 0;
	for (int i = 0; i < strlen(str1); i++){
		result[idx] = str1[i];
		idx++;
	}
	for (int i = 0; i < strlen(str2); i++){
		result[idx] = str2[i];
		idx++;
	}
	result[idx] = '\0';
	return result;
}

/*The function prints a line in the year calendar*/
void monthLines(int *d1, int *d2, int *d3, int m1, int m2, int m3, int year){
	int temp1 = *d1;
	int temp2 = *d2;
	int temp3 = *d3;
	int current1 = findWeekDay(temp1, m1, year);
	int current2 = findWeekDay(temp2, m2, year);
	int current3 = findWeekDay(temp3, m3, year);

	if (isLeapYear(year) == 1){
		months[1] = 29;
	}

	for (int i = 0; i < current1; i++){
		printf("   ");
	}

	while (*d1 <= months[m1 - 1]){
		printf("%2d ", *d1);
		current1 = (current1 + 1) % 7;
		int temp = *d1;
		temp++;
		*d1 = temp;
		if (current1 == 0){
			break;
		}
	}

	while (current1 != 0){
		printf("   ");
		current1 = (current1 + 1) % 7;
	}

	printf(" ");

	for (int i = 0; i < current2; i++){
		printf("   ");
	}

	while (*d2 <= months[m2 - 1]){
		printf("%2d ", *d2);
		current2 = (current2 + 1) % 7;
		int temp = *d2;
		temp++;
		*d2 = temp;
		if (current2 == 0){
			break;
		}
	}

	while (current2 != 0){
		printf("   ");
		current2 = (current2 + 1) % 7;
	}

	printf(" ");

	for (int i = 0; i < current3; i++){
		printf("   ");
	}

	while (*d3 <= months[m3 - 1]){
		printf("%2d ", *d3);
		current3 = (current3 + 1) % 7;
		int temp = *d3;
		temp++;
		*d3 = temp;
		if (current3 == 0){
			break;
		}
	}

	printf("\n");

	months[1] = 28;
}

/*The function takes 3 months of a year and print them*/
void printThreeMonth(int m1, int m2, int m3, int year){
	if (isLeapYear(year) == 1){
		months[1] = 29;
	}
	centerPrint(20, monthsText[m1 - 1]);
	printf("  ");
	centerPrint(20, monthsText[m2 - 1]);
	printf("  ");
	centerPrint(20, monthsText[m3 - 1]);
	printf("\n");
	printf("%s  %s  %s\n", "Su Mo Tu We Th Fr Sa", "Su Mo Tu We Th Fr Sa", 
		"Su Mo Tu We Th Fr Sa");

	int d1 = 1;
	int d2 = 1;
	int d3 = 1;

	while (d1 <= months[m1 - 1] || d2 <= months[m2 - 1] || d3 <= months[m3 - 1]){
		monthLines(&d1, &d2, &d3, m1, m2, m3, year);
	}
	printf("\n");
	months[1] = 28;
}

/*The function takes a year and print the year*/
void printYear(int year){
	char y[10];
	sprintf(y, "%d", year);
	centerPrint(64, y);
	printf("\n");
	printThreeMonth(1,2,3, year);
	printThreeMonth(4,5,6, year);
	printThreeMonth(7,8,9, year);
	printThreeMonth(10,11,12, year);
}

/*The function takes a string and return the month it represent. Return -1 if not valid*/
int checkMonth (char *month){
	if (atoi(month) > 0)
		return atoi(month);
	char * match[100];
	strncpy(match, month, 3);

	for (int i = 0; i < 12; i++){
		if (strcasecmp(match, match_month[i]) == 0)
			return i + 1;
	}
	return -1;
}

/*The function calculate current month and year*/
void printcurrent(int *current_month, int *current_year){
	time_t timenow;
	struct tm *current;
	time(&timenow);
	
	current = localtime(&timenow);

	*current_month = current->tm_mon+1;
	*current_year = current->tm_year+1900; 
}

/*Reading input*/
int main(int argc, char *argv[]){
	int current_month = -1;
	int current_year = -1;

	printcurrent(&current_month, &current_year);
	if (argc == 1){
		printMonth(current_month, current_year);
	}
	else if (argc == 2){
		if (1753 >= atoi(argv[1]) || atoi(argv[1]) > 9999){
			printf("not in the range 1753...9999\n");
			return 0;
		}
		printYear(atoi(argv[1]));
	}
	else if (argc == 3){
		if (strcasecmp(argv[1], "-m") == 0 && checkMonth(argv[2]) > 0
			&& checkMonth(argv[2]) <= 12){
			printMonth(checkMonth(argv[2]), current_year);
		}
		else if (checkMonth(argv[1]) > 0 && checkMonth(argv[1]) < 13
			&& atoi(argv[2]) > 1754 && atoi(argv[2]) < 9999){
			printMonth(checkMonth(argv[1]), atoi(argv[2]));
		}
		else{
			printf("%d\n", checkMonth(argv[2]));
			printf("Invalid input\n");
		}
	}
	else if (argc == 4){
		if (strcasecmp(argv[1], "-m") == 0 && checkMonth(argv[2]) > 0
			&& checkMonth(argv[2]) <= 12 && atoi(argv[3]) > 1754 
			&& atoi(argv[3]) < 9999){
			printMonth(checkMonth(argv[2]), atoi(argv[3]));
		}
		else{
			printf("%s\n", "Invalid input.");
		}
	}
	else{
		printf("Invalid input\n");
	}
}