#include <iostream>
#include <cstdio>
#include <chrono>
using namespace std;

int operations;		//Global Modulus Operations variable to keep track of the number of operations
int GCD(int u, int v) {	//GCD Function
	
	while (v != 0) {	//While the b is not equal to 0, keep looping
		int r = u % v;	//Find the remainder of a and b values
		operations++;	//Increment the Modulus Operations variable
		u = v;			//assign the b to a
		v = r;			//assign the remainder to b
	}
	return operations - 1;	//return the number of modulus operations that took to find the GCD
}

void Simulation(int n, bool bPrint) {
	int ra = 0;		//Instantiate a variable
	int rb = 0;		//Instantiate b variable
	int max;		//Instantiate Max variable to keep track of max number of modulus operations in each series of loops

	
	//Creating a Type File pointer that will create a new text file in the directory of the cpp file and write all of the data to that file
	// to be imported into excel for further examination
	FILE* pFile;
	pFile = fopen("Operations - Whileloop.txt", "w");
	
	//Prevents the program from crashing if the text file can not be created for any reason
	if (pFile == NULL) {
		return;
	}

	//Beginning of the for loop that tracks i to n
	for (int i = 8; i <= n; i++) {
		//Starts the clock to track the amount of time that every i loop takes
		auto start = chrono::steady_clock::now();
		//Sets the max variable each time the i variable is iterated up once
		max = 0;
		//Starts iterating b from 8 to i
		for (int b = 8; b <= i; b++) {
			//Starts iterating a (1) to whatever b is
			for (int a = 1; a <= b; a++) {
				//Calls the greatest common denominator function and returns the number of modulus operations it took to find it
				int count = GCD(a, b);
				//If the current max value is lower the the returned number of operations, then assign the operations to the max along
				// with the current a and b value
				if (max < count) {
					max = count;
					ra = a;
					rb = b;
				}
				//reset the number of operations before starting over again
				operations = 0;
			}
		}
		//Stop the timing clock and assign it to the "end" variable
		auto end = chrono::steady_clock::now();
		//Calculate the amount of time that it took to perform one round of GCD calls
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
		
		//If passes a true value, print all information to the console up to i=25 and then start printing in increments of 25
		if (bPrint) {
			if(i < 25 || i % 25 == 0)
			printf("At i = %d; gcd (%d, %d) = 1 took %d modulus operations in %I64d microseconds \n", i, ra, rb, max, duration);
		}

		//do the same thing as the previous print function but write to the text file created earlier
		if (bPrint)
		{
			if (i < 25 || i % 25 == 0) {
				fprintf(pFile, "%d, %d, %d, %d, %I64d\n", i, ra, rb, max, duration);
			}
		}
	}
	//Close the text file
	fclose(pFile);
	
}


int main() {

	//Call the simulation function passing the number that i should be counting up to and the bool to tell whether or not to print
	Simulation(3000, true);
	
	//end program
	return 0;
}
	



