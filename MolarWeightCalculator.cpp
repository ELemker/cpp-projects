//
// Name: Evan Lemker
// Date: 11/18/19
// Filename: MolarWeightCalculator.cpp
// Description: A program that calculates the molar weight of a molecule using a chemical formula provided by the user and a periodic table file that it reads from.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int main()
{
    // opening the periodic table file
    ifstream fin("PeriodicTable.txt");
    
    // ensuring the periodic table file opens correctly
    if (fin.fail() )
    {
        cerr << "File PeriodicTable.txt could not be opened." << endl;
        return -1;
    }
    
    // reading in the number of elements in the periodic table
    int numElements;
    fin >> numElements;
    
    // creating arrays to store the values needed for calculations
    int numMoles[numElements];
    string elements[numElements];
    
    // creating temporary variables that will be stored in arrays
    string tempNumMoles;
    string tempElement;
    int numElementsInMolecule = 0;
    
    // receiving a chemical formula for a molecule from the user
    string chemicalFormula;
    cout << endl << "Please enter the chemical formula for your molecule using the specifications detailed in the homework description: ";
    cin >> chemicalFormula;
    
    // extracting the information needed from the chemical formula
    for (int i = 0; i <= chemicalFormula.size(); i++)
    {
        // parsing the individual elements
        if ((isupper(chemicalFormula[i]) && i != 0) || i == chemicalFormula.size())
        {
            numMoles[numElementsInMolecule] = atoi(tempNumMoles.c_str());
            elements[numElementsInMolecule] = tempElement;
            tempNumMoles = "";
            tempElement = chemicalFormula[i];
            numElementsInMolecule += 1;
        }
        // parsing the individual numbers
        else if (isdigit(chemicalFormula[i]))
        {
            tempNumMoles += chemicalFormula[i];
        }
        else
        {
            tempElement += chemicalFormula[i];
        }
    }
    
    // creating variables that will store read information from periodic table
    int atomicNumber;
    string element;
    double weight;
    double totalWeight = 0;
    
    // calculating the molecular weight using data inputted as well as read from the file
    for (int j = 0; j < numElements; j++)
    {
        fin >> atomicNumber >> element >> weight;
        
        for (int i = 0; i < numElementsInMolecule; i++)
        {
            if (elements[i] == element)
            {
                
                totalWeight += weight*numMoles[i];
            }
        }
    }
    
    // closing the periodic table file
    fin.close();
    
    // displaying the molecular weight
    cout << endl << "The molecular weight of the molecule you entered is " << totalWeight << " grams per mole." << endl << endl;
    
    return 0;
}
