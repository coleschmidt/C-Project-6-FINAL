#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	//arrays for the values to be filled
	int array[100000], divisible[100000], digits[100000];
	

	//course number interger as for the project requirement
	int course_num = 1101;
	

	//values for artithmic. All equal to zero for operations to add up to
	int sum = 0, div_sum = 0, dig_sum = 0;
	float avg = 0, div_avg = 0, dig_avg = 0;
	

	//empty values to be declared by user input 
	int num, count, lower_limit, upper_limit;


	//empty value for the for loops to work with
	int num;


	//since these array counts don't need to be inputted by user, they  
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
	printf("\nWhat two numbers do you want for the lower and upper limit?\n");
	printf("It can be any number as long it's an interger between 1 to 350\n");
	scanf("%d", &lower_limit);
	scanf("%d", &upper_limit);


	//as for another project reuqirement the range must be within 1 to 350.
	//this algorithim is supposed to ask the user to resummit the numbers if it doesn't fall under 1 to 350. 
	while (lower_limit < 1 || lower_limit > 350){
		printf("You resumit the lower_limit\n");
		printf("It's not within the limit of 1 to 350\n");
		scanf("%d", &lower_limit);
	}

	while (upper_limit < 1 || upper_limit > 350){
		printf("You resumit the upper_limit\n");
		printf("It's not within the limit of 1 to 350\n");
		scanf("%d" , &upper_limit);
	}


	//this is the alogirthm that checks the array for the two respective conditions and adds them to their arrays
	for (num = 0; num < count; ++num)
	{

		//this if statement checks if the number is divisible by 7 
		//and if it fits within the range of lower limit and upper limit
		if ((array[num] % 7) == 0 && array[num] >= lower_limit && array[num] <= upper_limit){

			//this statement allocates the detected number into the array of divisible numbers
			divisible[div_count] = array[num];
			div_count++;
		}

		//this if statement checks if the number has at least one digit of 7 
		//and if it fits within the range of lower limit and upper limit
		if ((array[num]) % 10 == 7 && array[num] >= lower_limit && array[num] <= upper_limit)
		{

			//this statement allocates the detected number into the array of digit numbers
			digits[digit_count] = array[num];
			digit_count++;
		}
	}


	//this for loop takes all of the numbers of the divisible and digit
	//arrays, respectively, and adds them to their respective sums
	for (num = 0; num < div_count; ++num)
	{
		div_sum += divisible[num];
	}

	for (num = 0; num < digit_count; ++num)
	{
		dig_sum += digits[num];
	}

	//this statement caluclates the averages for the divisible and digit arrays, respectively.
	div_avg = (float)div_sum / div_count;
	dig_avg = (float)dig_sum / digit_count;


	//the required print statements that'll output the values for name, course number, and project number and turn in. %s is used.
	printf("\n\nYour name is: %s %s\n", first_name, last_name);
	printf("Your course number is: %d\n", course_num);
	printf("This is C project #6\n\n");


	//another required output is the starting and ending range numbers of the number array
	printf("The starting and ending numbers are %d and %d\n\n", lower_limit, upper_limit);


	//this is the statement that prints the number array
	printf("The numbers in the array are: \n");

	for (num = 0; num < count; num++){
		printf(" %d", array[num]);
	}


	//this is the statement that prints the divisible array
	printf("\n\nThe divisible numbers in the array are: \n");

	for (num = 0; num < div_count; ++num)
	{
		printf(" %d", divisible[num]);
	}


	//this is the statement that prints the digit array
	printf("\n\nThe digit numbers in the array are: \n");

	for (num = 0; num < digit_count; ++num)
	{
		printf(" %d", digits[num]);
	}

	//the statements that'll print the counts of each array
	printf("\n\n\nThe count of the numbers is: %d\n", count);
	printf("The count of the divisible numbers within the range is: %d\n", div_count);
	printf("The count of the 7 digit numbers within the range is: %d\n", digit_count);
	

	//the statements that'll print the sum of each array
	printf("\nThe sum of the numbers is: %d\n", sum);
	printf("The sum of the divisible numbers within the range is: %d\n", div_sum);
	printf("The sum of the digit numbers within the range is: %d\n", dig_sum);
	

	//in order to avoid print statements reading "numbers is %.2f", an if statement has been added to each array 
	// to detect if the value isn't less than 0 existed. 
	if (avg > 0) {
		printf("\n\nThe average of the numbers is: %.2f\n", avg);
	}
	else{
		printf("The average cannot be caluclated from the numbers\n");
	}


	if (div_avg > 0){
		printf("The average of the divisible numbers is %.2f\n", div_avg);
	}
	else{
		printf("The average cannot be caluclated from the divisible numbers\n");
	}
	

	if (dig_avg > 0){
		printf("The average of the digit numbers is %.2f\n", dig_avg);
	}
	else{
		printf("The average cannot be caluclated from the digit numbers\n");
	}
	
	return 0;
}