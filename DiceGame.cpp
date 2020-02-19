//
// Name: Evan Lemker
// Date: 10/23/19
// Filename: DiceGame.cpp
// Description: A two player dice game that consists of players rolling dice, choosing whether or not to reroll any of their dice, and receiving a score based on the values of the dice after they're done rerolling. The player with the highest score after 3 rounds wins.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// prototyping functions for deciding which side to display, rerolling dice, and calculating round score's of players
void whichSide(int diceVal);
int rerollDice(int diceToRerole, int &dice1, int &dice2, int &dice3);
int playerRoundScoreCalculator(int dice1, int dice2, int dice3);

int main()
{
    srand(time(0));
    
    // initializing variables for player scores, dice values, whether or not a player wants to reroll, the number of dice they want to reroll, and which dice they want to reroll
    int player1TotalScore = 0;
    int player2TotalScore = 0;
    int dice1;
    int dice2;
    int dice3;
    int wantToRerole;
    int numOfReroles;
    int diceToRerole;
    
    // loop that goes 3 times for the 3 rounds the game is supposed to have
    for (int i = 1; i < 4; i++)
    {
        cout << endl << "Round " << i << ":" << endl;
        
        // player 1's turn
        cout << endl << "Player 1: " << endl;
        
        // intial roll of dice
        dice1 = rand() % (6-1+1) + 1;
        cout << endl << "Dice 1:" << endl;
        whichSide(dice1);
        
        dice2 = rand() % (6-1+1) + 1;
        cout << endl << "Dice 2:" << endl;
        whichSide(dice2);
        
        dice3 = rand() % (6-1+1) + 1;
        cout << endl << "Dice 3:" << endl;
        whichSide(dice3);
        
        // determining if the player would like to reroll any dice, how many dice they would like to reroll, and which dice they would like to reroll, while ensuring the user is entering valid options throughout the process
        cout << endl << "Would you like to reroll any of your dice? (1 = no, 2 = yes): ";
        cin >> wantToRerole;
        while (wantToRerole != 1 && wantToRerole != 2)
        {
            cout << endl << "The option you selected is invalid, please select option 1 or 2. " << endl;
            cout << endl << "Would you like to reroll any of your dice? (1 = no, 2 = yes): ";
            cin >> wantToRerole;
        }
        if (wantToRerole == 2)
        {
            cout << endl << "How many dice would you like to reroll? (1 = one dice, 2 = two dice, 3 = all three dice): ";
            cin >> numOfReroles;
            while (numOfReroles != 1 && numOfReroles != 2 && numOfReroles != 3)
            {
                cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                cout << endl << "How many dice would you like to reroll? (1 = one dice, 2 = two dice, 3 = three dice): ";
                cin >> numOfReroles;
            }
            if (numOfReroles == 1)
            {
                cout << endl << "Which dice would you like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                cin >> diceToRerole;
                while (diceToRerole != 1 && diceToRerole != 2 && diceToRerole != 3)
                {
                    cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                    cout << endl << "Which dice would you like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                    cin >> diceToRerole;
                }
                rerollDice(diceToRerole, dice1, dice2, dice3);
            }
            else if (numOfReroles == 2)
            {
                cout << endl << "What is the first dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                cin >> diceToRerole;
                while (diceToRerole != 1 && diceToRerole != 2 && diceToRerole != 3)
                {
                    cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                    cout << endl << "What is the first dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                    cin >> diceToRerole;
                }
                rerollDice(diceToRerole, dice1, dice2, dice3);
                
                cout << endl << "What is the second dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                cin >> diceToRerole;
                while (diceToRerole != 1 && diceToRerole != 2 && diceToRerole != 3)
                {
                    cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                    cout << endl << "What is the second dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                    cin >> diceToRerole;
                }
                rerollDice(diceToRerole, dice1, dice2, dice3);
            }
            else if (numOfReroles == 3)
            {
                dice1 = rand() % (6-1+1) + 1;
                dice2 = rand() % (6-1+1) + 1;
                dice3 = rand() % (6-1+1) + 1;
            }
        
        // displaying the new dice
        cout << endl << "New dice for player 1:" << endl;
            
        cout << endl << "Dice 1:" << endl;
        whichSide(dice1);
               
        cout << endl << "Dice 2:" << endl;
        whichSide(dice2);
               
        cout << endl << "Dice 3:" << endl;
        whichSide(dice3);
        }
        
        // calculating the total score for player 1
        player1TotalScore += playerRoundScoreCalculator(dice1, dice2, dice3);
      
        // player 2's turn
        cout << endl << "Player 2:" << endl;
        
        // initial roll of dice
        dice1 = rand() % (6-1+1) + 1;
        cout << endl << "Dice 1:" << endl;
        whichSide(dice1);
        
        dice2 = rand() % (6-1+1) + 1;
        cout << endl << "Dice 2:" << endl;
        whichSide(dice2);
        
        dice3 = rand() % (6-1+1) + 1;
        cout << endl << "Dice 3:" << endl;
        whichSide(dice3);
        
        // determining if the player would like to reroll any dice, how many dice they would like to reroll, and which dice they would like to reroll, while ensuring the user is entering valid options throughout the process
        cout << endl << "Would you like to reroll any of your dice? (1 = no, 2 = yes): ";
        cin >> wantToRerole;
        while (wantToRerole != 1 && wantToRerole != 2)
        {
            cout << endl << "The option you selected is invalid, please select option 1 or 2. " << endl;
            cout << endl << "Would you like to reroll any of your dice? (1 = no, 2 = yes): ";
            cin >> wantToRerole;
        }
        if (wantToRerole == 2)
        {
            cout << endl << "How many dice would you like to reroll? (1 = one dice, 2 = two dice, 3 = all three dice): ";
            cin >> numOfReroles;
            while (numOfReroles != 1 && numOfReroles != 2 && numOfReroles != 3)
            {
                cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                cout << endl << "How many dice would you like to reroll? (1 = one dice, 2 = two dice, 3 = three dice): ";
                cin >> numOfReroles;
            }
            if (numOfReroles == 1)
            {
                cout << endl << "Which dice would you like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                cin >> diceToRerole;
                while (diceToRerole != 1 && diceToRerole != 2 && diceToRerole != 3)
                {
                    cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                    cout << endl << "Which dice would you like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                    cin >> diceToRerole;
                }
                rerollDice(diceToRerole, dice1, dice2, dice3);
            }
            else if (numOfReroles == 2)
            {
                cout << endl << "What is the first dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                cin >> diceToRerole;
                while (diceToRerole != 1 && diceToRerole != 2 && diceToRerole != 3)
                {
                    cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                    cout << endl << "What is the first dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                    cin >> diceToRerole;
                }
                rerollDice(diceToRerole, dice1, dice2, dice3);
                
                cout << endl << "What is the second dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                cin >> diceToRerole;
                while (diceToRerole != 1 && diceToRerole != 2 && diceToRerole != 3)
                {
                    cout << endl << "The option you selected is invalid, please select option 1, 2, or 3. " << endl;
                    cout << endl << "What is the second dice you would like to reroll? (1 = dice one, 2 = dice two, 3 = dice three): ";
                    cin >> diceToRerole;
                }
                rerollDice(diceToRerole, dice1, dice2, dice3);
            }
            else if (numOfReroles == 3)
            {
                dice1 = rand() % (6-1+1) + 1;
                dice2 = rand() % (6-1+1) + 1;
                dice3 = rand() % (6-1+1) + 1;
            }
        
        // displaying the new dice
        cout << endl << "New dice for player 2:" << endl;
            
        cout << endl << "Dice 1:" << endl;
        whichSide(dice1);
               
        cout << endl << "Dice 2:" << endl;
        whichSide(dice2);
               
        cout << endl << "Dice 3:" << endl;
        whichSide(dice3);
        }
        
        // calculating the total score for player 2
        player2TotalScore += playerRoundScoreCalculator(dice1, dice2, dice3);
        
        if (i <= 2)
        {
        cout << endl << "The current score is " << player1TotalScore << " (Player 1) to " << player2TotalScore << " (Player 2)." << endl;
        }
    }
    
    // based on final total scores of players 1 and 2, determine and display who won the game or if it was a tie
    if (player1TotalScore > player2TotalScore)
    {
        cout << endl << "Player 1 won! The final score was " << player1TotalScore << " to " << player2TotalScore << "." << endl << endl;
    }
    if (player2TotalScore > player1TotalScore)
    {
        cout << endl << "Player 2 won! The final score was " << player2TotalScore << " to " << player1TotalScore << "." << endl << endl;
    }
    if (player2TotalScore == player1TotalScore)
    {
        cout << endl << "The game ended in a tie! Play again to find out who the real winner is!" << endl << endl;
    }
    return 0;
}

//
// Function Name: whichSide
// Description: Determining which side of the dice to display based on what the value of the side is, then displaying that side of the dice
// Input: The value of the side
// Output: A picture of the given side
//
void whichSide(int diceVal)
{
    int side = diceVal;
    
    if (side == 1)
    {
         cout << ".---------." << endl << "|         |" << endl << "|    *    |" << endl << "|         |" << endl << "'---------'" << endl;
    }
    else if (side == 2)
    {
        cout << ".---------." << endl << "|      *  |" << endl << "|         |" << endl << "|  *      |" << endl << "'---------'" << endl;
    }
    else if (side == 3)
    {
        cout << ".---------." << endl << "|      *  |" << endl << "|    *    |" << endl << "|  *      |" << endl << "'---------'" << endl;
    }
    else if (side == 4)
    {
        cout << ".---------." << endl << "|  *   *  |" << endl << "|         |" << endl << "|  *   *  |" << endl << "'---------'" << endl;
    }
    else if (side == 5)
    {
        cout << ".---------." << endl << "|  *   *  |" << endl << "|    *    |" << endl << "|  *   *  |" << endl << "'---------'" << endl;
    }
    else if (side == 6)
    {
        cout << ".---------." << endl << "|  *   *  |" << endl << "|  *   *  |" << endl << "|  *   *  |" << endl << "'---------'" << endl;
    }
}

//
// Function Name: whichDiceToRerole
// Description: Based on a user input, determining which dice should be rerolled, and then rerolling it by giving it a new random value.
// Input: Which dice the user would like to reroll, and references to the different dice values so that they can be changed.
// Output: New value for dice1, dice2, or dice3, depending on which dice is being rerolled
//
int rerollDice(int diceToRerole, int &dice1, int &dice2, int &dice3)
{
    if (diceToRerole == 1)
    {
        dice1 = rand() % (6-1+1) + 1;
        return dice1;
    }
    else if (diceToRerole == 2)
    {
        dice2 = rand() % (6-1+1) + 1;
        return dice2;
    }
    else
    {
        dice3 = rand() % (6-1+1) + 1;
        return dice3;
    }
}

//
// Function Name: playerRoundScoreCalculator
// Description: Calculating the player's round score based off their final dice
// Input: The values of each of their dice
// Output: Their score for the round
//
int playerRoundScoreCalculator(int dice1, int dice2, int dice3)
{
    int playerRoundScore = 0;
    
    if (dice1 == dice2 && dice1 == dice3)
    {
        playerRoundScore = 20 + dice1;
    }
    
    else if (dice1 == dice2 || dice1 == dice3)
    {
        playerRoundScore = 10 + dice1;
    }
        
    else if (dice2 == dice3)
    {
        playerRoundScore = 10 + dice2;
    }
    
    else
    {
        playerRoundScore = dice1;
       
        if (dice2 > playerRoundScore)
        {
            playerRoundScore = dice2;
        }
      
        if (dice3 > playerRoundScore)
        {
            playerRoundScore = dice3;
        }
    }
    
    return playerRoundScore;
}
