//
// Name: Evan Lemker
// Date: 10/08/2019
// Filename: CostOfGoodsComparison.cpp
// Description: Based on a users input, compare the cost of goods from Costco to either Amazon or HyVee. Then, calculate the total costs of going to one store as well as Costco, and then calculating the total price of you got the best deals out of both places.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Formating numbers to have same decimal places as proper dollars and cents
    cout << setprecision(2) << fixed;
    
    // Obtaining the Amazon vs. HyVee choice from the user, file 1 being Amazon and file 2 being Hyvee
    int fileNum;
    cout << "Which option would you like to compare to Costco? (1 = Amazon, 2 = HyVee): ";
    cin >> fileNum;
    
    // Ensuring user chooses a valid option
    while (fileNum != 1 && fileNum != 2)
    {
        cout << "The option you selected is invalid, please select option 1 or 2. " << endl;
        cout << "Which option would you like to compare to Costco? (1 = Amazon, 2 + HyVee): ";
        cin >> fileNum;
    }
    
    // If the user chooses Amazon, opening the Amazon file and ensuring it opens correctly
    if (fileNum == 1)
    {
        ifstream finA("amazon.txt");
        
        if (finA.fail() )
        {
            cerr << "File amazon.txt could not be opened." << endl;
            return -1;
        }
        
        // Opening the Costco file and ensuring that it opens correctly
        ifstream finB("costco.txt");
        
        if (finB.fail() )
        {
            cerr << "File costco.txt could not be opened." << endl;
            return -1;
        }
        
        // Reading in the number of items on the Amazon list as well as the Costco list to be used in loop later
        int numItemsAmazon;
        finA >> numItemsAmazon;
        
        int numItemsCostco;
        finB >> numItemsCostco;
        
        // Initializing variable for values from text files as well as totals that need to be calculated
        string itemNameAmazon;
        double itemAmountAmazon;
        string itemUnitAmazon;
        double itemPriceAmazon;
        double totalPriceAmazon = 0;
        
        string itemNameCostco;
        double itemAmountCostco;
        string itemUnitCostco;
        double itemPriceCostco;
        double itemCostcoEquivalentPrice;
        double totalCostcoEquivalentPrice = 0;
        
        double totalBestPrice = 0;
        
        // Reading first line of Amazon file so that it can be used for comaparison with if statement
        finA >> itemNameAmazon >> itemAmountAmazon >> itemUnitAmazon >> itemPriceAmazon;
        
        // Looping through Costco file and matching names with Amazon file to determine when to run calculations
        for (int i = 0; i < numItemsCostco; i++)
        {
            finB >> itemNameCostco >> itemAmountCostco >> itemUnitCostco >> itemPriceCostco;
            
            if (itemNameCostco == itemNameAmazon)
            {
                // Calculating total price if everything was bought from Amazon
                totalPriceAmazon += itemPriceAmazon;
                
                // Calculating the price of the same amount of goods if bought from Costco, then calculating the total of these prices
                itemCostcoEquivalentPrice = (itemPriceCostco/itemAmountCostco)*itemAmountAmazon;
                
                totalCostcoEquivalentPrice += itemCostcoEquivalentPrice;
                
                // Displaying the price differences and then identifying which store has the better deal, then calculating total price if always going with best deal
                cout << itemNameAmazon << ": $" << itemPriceAmazon << " amazon vs. $" << itemCostcoEquivalentPrice << " costco equivalent" << endl;
                
                if (itemPriceAmazon < itemCostcoEquivalentPrice)
                {
                    cout << "   --> amazon better" << endl;
                    totalBestPrice += itemPriceAmazon;
                }
                else
                {
                    cout << "   --> costco better" << endl;
                    totalBestPrice += itemCostcoEquivalentPrice;
                }
                
                finA >> itemNameAmazon >> itemAmountAmazon >> itemUnitAmazon >> itemPriceAmazon;
            }
        }
        // Closing input files
        finA.close();
        finB.close();
        
        // Displaying the totals calculated
        cout << "Total amazon costs: $" << totalPriceAmazon << endl;
        cout << "Total costco costs: $" << totalCostcoEquivalentPrice << endl;
        cout << "Total best costs: $" << totalBestPrice << endl;
    }
    
    // If the user chooses HyVee, openeing the HyVee file and ensuring it opens correctly
    else
    {
        ifstream finA("hyvee.txt");
        
        if (finA.fail() )
        {
            cerr << "File hyvee.txt could not be opened." << endl;
            return -1;
        }
        
        // Opening the Costco file and ensuring that it opens correctly
        ifstream finB("costco.txt");
        
        if (finB.fail() )
        {
            cerr << "File costco.txt could not be opened." << endl;
            return -1;
        }
        
         // Reading in the number of items on the HyVee list as well as the Costco list to be used in loop later
        int numItemsHyvee;
        finA >> numItemsHyvee;
        
        int numItemsCostco;
        finB >> numItemsCostco;
        
        // Initializing variable for values from text files as well as totals that need to be calculated
        string itemNameHyvee;
        double itemAmountHyvee;
        string itemUnitHyvee;
        double itemPriceHyvee;
        double totalPriceHyvee = 0;
        
        string itemNameCostco;
        double itemAmountCostco;
        string itemUnitCostco;
        double itemPriceCostco;
        double itemCostcoEquivalentPrice;
        double totalCostcoEquivalentPrice = 0;
        
        double totalBestPrice = 0;
        
        // Reading first line of HyVee file so that it can be used for comaparison with if statement
        finA >> itemNameHyvee >> itemAmountHyvee >> itemUnitHyvee >> itemPriceHyvee;
        
        // Looping through Costco file and matching names with HyVee file to determine when to run calculations
        for (int i = 0; i < numItemsCostco; i++)
        {
            finB >> itemNameCostco >> itemAmountCostco >> itemUnitCostco >> itemPriceCostco;
                        
            if (itemNameCostco == itemNameHyvee)
            {
                // Calculating total price if everything was bought from HyVee
                totalPriceHyvee += itemPriceHyvee;
                
                // Calculating the price of the same amount of goods if bought from Costco, then calculating the total of these prices
                itemCostcoEquivalentPrice = (itemPriceCostco/itemAmountCostco)*itemAmountHyvee;
                
                totalCostcoEquivalentPrice += itemCostcoEquivalentPrice;
                
                // Displaying the price differences and then identifying which store has the better deal, then calculating total price if always going with best deal
                cout << itemNameHyvee << ": $" << itemPriceHyvee << " hyvee vs. $" << itemCostcoEquivalentPrice << " costco equivalent" << endl;
                
                if (itemPriceHyvee < itemCostcoEquivalentPrice)
                {
                    cout << "   --> hyvee better" << endl;
                    totalBestPrice += itemPriceHyvee;
                }
                else
                {
                    cout << "   --> costco better" << endl;
                    totalBestPrice += itemCostcoEquivalentPrice;
                }
                
                finA >> itemNameHyvee >> itemAmountHyvee >> itemUnitHyvee >> itemPriceHyvee;
            }
        }
        // Closing input files
        finA.close();
        finB.close();
        
        // Displaying the totals calculated
        cout << "Total hyvee costs: $" << totalPriceHyvee << endl;
        cout << "Total costco costs: $" << totalCostcoEquivalentPrice << endl;
        cout << "Total best costs: $" << totalBestPrice << endl;
    }
    
    return 0;
}
