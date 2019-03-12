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
void getTextFile(); //function defined below
void printTextFile(); //function defined below
void move2array(); //function defined below
int main() {
	getTextFile(); //call the function to get the text file and read it
	printTextFile(); //call the function to print what was in the text file
	system("pause"); //remove this line if compiling on Xcode
	return 0;
}

//ask for the name of the text file open it and take its components
void getTextFile() {
	int demand, disperse; //will hold the int values that were demanded and dispursed later
	string name_of_text_file; //name of the text file from the user
	cout << "What is the name of the text file?\n";
	//cin >> name_of_text_file; //get the name
	//now create the text file and open it
	ifstream file;
	file.open("infile.txt");
	if (file.is_open())
	{
		cout << "File successfully opened!\n";
		while (!file.eof())
		{
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[0][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[0][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[1][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[1][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[2][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[2][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[3][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[3][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				maximum_array[4][i] = demand;
			}
			for (int i = 0; i < maximum_resources; i++)
			{
				file >> demand;
				allocated_array[4][i] = demand;
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

}
//this function just prints what was inside the text file
void printTextFile() {
	for (int i = 0; i < number_of_processors; i++)
	{
		for (int j = 0; j < maximum_resources; j++)
		{
			cout << maximum_array[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < number_of_processors; i++)
	{
		for (int j = 0; j < maximum_resources; j++)
		{
			cout << allocated_array[i][j] << " ";
		}
		cout << endl;
	}
}
//function that will move the vectors into 2d array
void move2array() {

}