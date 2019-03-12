#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//creating global variables
const int maximum_resources = 3; //these are constant because they will not change
const int resources_allocated = 3; 
vector<int> processor_maximum; //will hold the maximum resource values
vector<int> processor_allocation; //will hold the resources allocated to the processors
void getTextFile(); //function defined below
void printTextFile(); //function defined below
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
			//for loop because the first 3 integers are for maximum resources
			for (int a = 0; a < maximum_resources; a++)
			{
				file >> demand;
				processor_maximum.push_back(demand); //add it into the vector
			}
			//for loop because the last 3 integers are for allocated resources
			for (int b = 0; b < resources_allocated; b++)
			{
				file >> disperse;
				processor_allocation.push_back(disperse); //add it into the vector
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
	cout << "Maximum\n";
	for (auto k = processor_maximum.begin(); k != processor_maximum.end(); k++)
	{
		cout << *k << " ";
	}
	cout << "\nAllocated\n";
	for (auto i = processor_allocation.begin(); i != processor_allocation.end(); i++)
	{
		cout << *i << " ";
	}
}