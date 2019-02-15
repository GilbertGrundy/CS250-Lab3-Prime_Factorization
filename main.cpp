/*
Name: Gilbert Grundy
Assignment: Lab #3
*/


#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

bool repeat();
bool check_int(long long & data);

int main()
{
	long long number = 0;
	long long copy = 0;
	bool prime = false;

	cout << "Gilbert Grundy CS250 Lab #3 \n\n";
	
	do{		

		do{
		cout << "What number would you like to find the prime factorization of?" << endl;

		cin >> number;
		cin.clear();
		cin.ignore(100, '\n');	
		copy = number + 1;

		}while(check_int(number)); //is the input correct?

		cout << "\n\nThe prime factorization of " << number << " is: ";

	for(long long i = 2; i < copy; ++i)
	{
		if(!(number % i)) //checks if i is a prime factor
		{
			number = (number / i); //divide i
			cout << i;		//spit out the prime factor
			if(number >= i) cout << ", "; 	//checks if number is greater than i, 
			if(i == (copy - 1)) prime = true;				//so it figures out if I need to add 
							//a comma
			--i;//decrement i, to check for repeat prime factors
		}
	}

	cout << "\n";

	if(prime) cout << "Number is a prime!\n\n";
	else cout << "\n";
	

	number = 0;	//reset for next go
	copy = 0;
	prime = false;
	}while(repeat()); //do you want to repeat program?

	return 0;
}




//function to check if the user would like to check the prime factorization 
//of an integer again
bool repeat()
{
	char again;
	bool repeat = true;
	do
	{
		cout << "Would you like to find the prime factorization of another integer? y/n" << endl;

		cin >> again;
		cin.clear();
		cin.ignore(100, '\n');

		if(again == 'y' || again == 'Y') return true;
		if(again == 'n' || again == 'N') return false;
	}while(repeat);
}


//checks if the input is an integer more than 1
bool check_int(long long & data)
{
	if(data < 2)
	{
		cout << "Sorry, please enter an integer greater than 1.\n" << endl;
		return true;
	}

	return false;
}
