//
// Name: Evan Lemker
// Date: 11/6/19
// Filename: MeetingScheduler.cpp
// Description: A program that determines a one-hour meeting time for a group of students in a space that is available weekdays from 8 am to 6 pm that uses availability as its first priority followed by preference. All of the information will be read in from files. It will then display the minimum conflicts and maximum preferences, as well as the time blocks that meet these criteria.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // opening the files containing the files to process and ensuring it opens correctly
    ifstream finFiles("filesToProcess.txt");
    
    if (finFiles.fail())
    {
        cerr << "File filesToProcess.txt could not be opened." << endl;
        return -1;
    }
    
    // reading in the number of files that need to be processed
    int numFiles;
    finFiles >> numFiles;
    
    // creating arrays that will be used in the computations throughout the rest of the program
    int conflicts[100] = {0};
    int preferences[100] = {0};
    string labels[100];
    
    // creating variables that will be used to determine how many values there will be within the arrays, and what those values will be
    int numTimes;
    int availability;
    
    // loop that goes through each file that needs to be processed in order to compute the best time blocks across all schedules
    for (int i = 0; i < numFiles; i++)
    {
        // opening the files included in the files to process file and ensuring they open correctly
        string fileName;
        finFiles >> fileName;
        ifstream finSchedule(fileName.c_str());
                
        if (finSchedule.fail())
        {
            cerr << "File " << fileName << " could not be opened." << endl;
            return -1;
        }
        
        // reading in the number of time blocks that need to be read, and a loop that calculates availability values for each of these time blocks
        finSchedule >> numTimes;
        
        for (int i = 0; i < numTimes; i++)
        {
            finSchedule >> labels[i];
            
            finSchedule >> availability;
            
            if (availability == 0)
            {
                conflicts[i] += 1;
            }
            if (availability == 2)
            {
                preferences[i] += 1;
            }
        }
        
        // closing files when finished reading from them
        finSchedule.close();
    }
    
    finFiles.close();
    
    // determining the minimum number of conflicts across all time blocks and schedules
    int minConflicts = numFiles;
    
    for (int i = 0; i < numTimes; i++)
    {
        if (conflicts[i] < minConflicts)
        {
            minConflicts = conflicts[i];
        }
    }
    
    // determining the maximum number of preferences across all time blocks and schedules
    int maxPreferences = 0;
    
    for (int i = 0; i < numTimes; i++)
    {
        if (conflicts[i] == minConflicts)
        {
            if (preferences[i] > maxPreferences)
            {
                maxPreferences = preferences[i];
            }
        }
    }
    
    // displaying the results of the calulations made above, and then displaying the time blocks that meet the criteria given by these values
    cout << "From " << numTimes << " time blocks, the time blocks with " << minConflicts << " conflicts and a preference count of " << maxPreferences << " are:" << endl;
    
    for (int i = 0; i < numTimes; i++)
    {
        if (conflicts[i] == minConflicts && preferences[i] == maxPreferences)
        {
            cout << labels[i] << endl;
        }
    }
    
    return 0;
}
