#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//creating global variables
const int maximum_resources = 3; //these are constant because they will not change
const int resources_allocated = 3;
const int number_of_processors = 5;
vector<int> processor_maximum; //will hold the maximum resource values
vector<int> processor_allocation; //will hold the resources allocated to the processors
int maximum_array[number_of_processors][maximum_resources]; //array for the maxiumum matrix
int allocated_array[number_of_processors][resources_allocated]; //array for the resources allocated
int need_array[number_of_processors][maximum_resources]; //array for how much resources is needed for each processor
int available_array[maximum_resources] = { 10, 5, 7 }; //an array for the initial set of available resources
bool still_running = true; //will be used to let the menu know the state is still running set it initially to be true
void getTextFile(); //function defined below
void printTextFile(); //function defined below
void calculateNeed(); //function defined below
void menu(); //function defined below
int main() {
	getTextFile(); //call the function to get the text file and read it
	int user_choice; //will be for user decision in the main menu
	while (still_running)
	{
		menu(); //print the menu
		cin >> user_choice;
		//switch statement to catch user selection
		switch (user_choice)
		{
		case 1:
			printTextFile();
			break;
		case 2:
			cout << "not implemented yet\n";
			break;
		case 3:
			cout << "not implemented yet\n";
			break;
		case 4:
			cout << "Quitting program...Press enter again.\n";
			still_running = false;
			break;
		}
	}

	//printTextFile(); //call the function to print what was in the text file
	//calculateNeed(); //call the function to calculate the need
	system("pause"); //remove this line if compiling on Xcode
	return 0;
}

//ask for the name of the text file open it and take its components
void getTextFile() {
	int demand, disperse; //will hold the int values that were demanded and dispursed later
	string name_of_text_file; //name of the text file from the user
	cout << "What is the name of the text file?\n";
	cin >> name_of_text_file; //get the name
	//now create the text file and open it
	ifstream file;
	file.open(name_of_text_file);
	if (file.is_open())
	{
		cout << "File successfully opened!\n";
		while (!file.eof())
		{
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[0][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[0][i] = demand;
			}
			//this code can read this
			/*
			0 1 0 7 5 3
			2 0 0 3 2 2
			3 0 2 9 0 2
			2 1 1 2 2 2
			0 0 2 4 3 3
			*/
			//but not this
			/*
			0,1,0,7,5,3
			2,0,0,3,2,2
			3,0,2,9,0,2
			2,1,1,2,2,2
			0,0,2,4,3,3
			*/
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[1][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[1][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[2][i] = demand;
			}

			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[2][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[3][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[3][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[4][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[4][i] = demand;
			}

		}
		//always proper to close the file you opened
		file.close();
	}
	else
	{
		//let the user know you could not open the file
		cout << "Unable to open file " << name_of_text_file << endl;
	}
	calculateNeed(); //calculate need for first state
}
//this function just prints what was inside the text file
void printTextFile() {
	cout << "Maximum\n";
	for (int i = 0; i < number_of_processors; i++)
	{
		for (int j = 0; j < maximum_resources; j++)
		{
			cout << maximum_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Allocated\n";
	for (int i = 0; i < number_of_processors; i++)
	{
		for (int j = 0; j < maximum_resources; j++)
		{
			cout << allocated_array[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Need\n";
	for (int i = 0; i < number_of_processors; i++)
	{
		for (int j = 0; j < maximum_resources; j++)
		{
			cout << need_array[i][j] << " ";
		}
		cout << endl;
	}
}
//this function calculates the need by subtracting the maximum by the allocated 
void calculateNeed() {
	for (int i = 0; i < number_of_processors; i++)
	{
		for (int k = 0; k < maximum_resources; k++)
		{
			need_array[i][k] = maximum_array[i][k] - allocated_array[i][k];
		}
	}
	//just testing right here by asking the array to be printed

}
//this function presents the user which the menu to request or print state or produced automatic resources request
void menu() {
	cout << "	Menu\n";
	cout << "1. Print the current state of the system.\n";
	cout << "2. Request resources.\n";
	cout << "3. Automatic mode.\n";
	cout << "4. Quit.\n";
	cout << "Enter your choice and press enter.\n";
}
