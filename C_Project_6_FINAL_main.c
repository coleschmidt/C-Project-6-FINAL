#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//declared value for an array to fill the the scanf values
	int array[100000], divisible[100000], digits[100000];
	
	//course number interger as for the project requirement
	int course_num = 1101;
	
	//values for artithmic. Both equal to zero for operation to add up
	int sum = 0, div_sum = 0, dig_sum = 0;
	float avg = 0, div_avg = 0, dig_avg = 0;
	
	//empty values to be declared by user input
	int num, count, lower_limit = 1, upper_limit = 20;

	int div_count = 0, digit_count = 0; 
	
	//to demonstrate %s, a string will be used for my name
	char first_name[20] = "cole", last_name[20] = "schmidt";
	
	//to enhance the algorithm beyond 8, it has been generalized for user input
	//printf and scanf statement to ask user for what values to submit and how big the array they want to be
	printf("How many numbers do you want in array?\n");
	scanf("%d", &count);
	
	printf("\nInput the necessary numbers for array: \n");

	//the for loop that'll ask user for each of the values to input and add the operands to the sum
	for (num = 0; num < count; num++){
		scanf("\n %d", &array[num]);
    	sum += array[num];
	}

	//operation that'll caluclate the average based on the values inputted
	avg = (float)sum / count;

	//as for the requirement of the project, the checked numbers must be within a range
	//this is an algorithm that asks the user what the numbers they want the range to be within
	//as for an ongoing execution bug that stalls the program.
	printf("What two numbers do you want for the lower and upper limit?\n");
	printf("It can be any number as long it's an interger between 1 to 350\n");
	scanf("%d\n", &lower_limit);
	scanf("%d\n" , &upper_limit);

	//as for another project reuqirement the range must be within 1 to 350.
	//this algorithim is supposed to ask the user to resummit the numbers if it doesn't fall under 1 to 350. 
	//this is the likely suspect that is triggering the execution bug as it keeps asking for 
	/*while (lower_limit < 1 || lower_limit > 350){
		printf("You resumit the lower_limit\n");
		printf("It's not within the limit of 1 to 350\n");
		scanf("%d\n", &lower_limit);
	}

	while (upper_limit < 1 || upper_limit > 350){
		printf("You resumit the upper_limit\n");
		printf("It's not within the limit of 1 to 350\n");
		scanf("%d\n" , &upper_limit);
	}*/

	//this is the alogirthm that checks the array for the following conditions
	//due to the execution error involving the range, their conditions has been temporarily set aside
	for (num = 0; num < count; ++num)
	{
		if ((array[num] % 7) == 0 && array[num] >= lower_limit && array[num] <= upper_limit){
			divisible[div_count] = array[num];
			div_count++;
		}
		if ((array[num]) % 10 == 7 && array[num] >= lower_limit && array[num] <= upper_limit)
		{
			digits[digit_count] = array[num];
			digit_count++;
		}
	}

	for (num = 0; num < div_count; ++num)
	{
		div_sum += divisible[num];
	}

	for (num = 0; num < digit_count; ++num)
	{
		dig_sum += digits[num];
	}
	
	div_avg = (float)div_sum / div_count;
	dig_avg = (float)dig_sum / digit_count;

	//the required print statements that'll output the values for identity and turn in. %s is used.
	printf("\n\nYour name is: %s %s\n", first_name, last_name);
	printf("Your course number is: %d\n", course_num);
	printf("This is C project #4\n\n");

	/*printf("The starting and ending numbers are %d and %d\n", lower_limit, upper_limit);*/

	printf("The numbers in the array are: \n");

	for (num = 0; num < count; num++){
		printf(" %d", array[num]);
	}

	printf("\n\nThe divisible numbers in the array are: \n");

	for (num = 0; num < div_count; ++num)
	{
		printf(" %d", divisible[num]);
	}

	printf("\n\nThe digit numbers in the array are: \n");

	for (num = 0; num < digit_count; ++num)
	{
		printf(" %d", digits[num]);
	}

	printf("\n\n\nThe count of the numbers is: %d\n", count);
	printf("The count of the divisible numbers within the range is: %d\n", div_count);
	printf("The count of the 7 digit numbers within the range is: %d\n", digit_count);
	
	printf("\nThe sum of the numbers is: %d\n", sum);
	printf("The sum of the divisible numbers within the range is: %d\n", div_sum);
	printf("The sum of the digit numbers within the range is: %d\n", dig_sum);
	
	printf("\n\nThe average of the numbers is: %.2f\n", avg);
	printf("The average of the divisible numbers is %.2f\n", div_avg);
	printf("The average of the digit numbers is %.2f\n", dig_avg);
	
	return 0;
}