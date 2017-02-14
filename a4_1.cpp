/*
    a4_1.cpp
    Fundamentals of Programming in C++ 110B
    Instructor David Lee Harden
    by Stacey Rivet Beck on 2/11/17
 
 This program simulates a integer only (no face values)
 Poker game that asks the user for 5 card inputs using numbers 
 only 2 - 9. The computer outputs the type of poker hand the user has.
 The combinations are Pair, Two Pair, Three of a kind, Four of a Kind, 
 Straight, Full House and High Card.
 
 In the main function, the user inputs 5 card values and 
 are read into an array with int size. The main function uses
 if/else logic that calls bool functions to help identify the hand
 type.  When the function returns true it prints the hand type. The bool 
 functions use two helper functions to determine the hand.
 One of the functions named SumOfArrInstances is called inside the bool
 function. Another functioned named countAll is called inside SumofArrInstances.
 
 SumofArrInstances sums up the count values returned by countAll
 for each array element and returns a specific number that pertains uniquely
 to each different poker hand. The function countAll counts how many times 
 a number appears in an array and returns that count value back to SumofArrInstances.
 
 Each poker hand type has a unique combination. When using specifically 
 5 elements in an array a Pair combination is 22111 such that only two elements 
 appear with the same value. Two pairs will have a combination of 22221, 
 three of a kind will have 33311, etc.
 
 One last function named findingStraight is called to differentiate a 
 straight hand from a high card hand.  When findingStraight determines that
 the number combination is that of a straight it returns true, else it will
 return High Card.
 
 */

#include <iostream>
using namespace std;

//function prototypes
int countAll(const int [], int, int);
int sumOfArrInstances(const int []);
int findingStraight(const int []);
bool  containsPair(const int []);
bool  containsTwoPair(const int []);
bool  containsThreeOfaKind(const int []);
bool  containsFourOfaKind(const int []);
bool  containsStraight(const int []);
bool  containsFullHouse(const int []);



int main()
{
    int CARD_SIZE = 5;
    int arrHand[CARD_SIZE];
    int index;
    
    cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;
    
    for (index = 0; index < CARD_SIZE; index ++)
    {
        cout << "Card " << (index +1) << ": ";
        cin >> arrHand[index];
            
    }
    
    if (containsPair(arrHand))
            cout << "Contains a Pair!" << endl;
    
    if (containsTwoPair(arrHand))
            cout << "Contains a Two Pair!" << endl;
        
    if (containsThreeOfaKind(arrHand))
            cout << "Contains a Three of a Kind!" << endl;
    
    if (containsFourOfaKind(arrHand))
            cout << "Contains a Four of a Kind!" << endl;
    
    if (containsFullHouse(arrHand))
        cout << "Full House!" << endl;
    
    if (containsStraight(arrHand))
        cout << "STRAIGHT!" << endl;
    
    else if (sumOfArrInstances(arrHand) == 5)
        cout << "High Card!" << endl;
    
    
}
/*
 This function passes in the array. We know the number range
 is from 2-9. We want to find the lowest value and the highest value
 and assign those to a min and max int and take the difference. 
 In order check for these values we set int MinVal to the highest possible
 value (just outside the high end of the range) and MaxVal to the lowest
 possible value in the range (just outside low end of range). 
 If the numbers in the array are all consecutive then the difference between
 the highest number and the lowest number will always be 4.
 For example: 23456, where 6 - 2 = 4; 34567, where 7 - 3 = 4; 45678, 8 - 4 = 4, etc.
 Therefore, when we are looking to determine whether our hand is a straight or high card
 the straight will return the function findingStraight == 4.
 */

int findingStraight(const int arrHand[])
{
    int MaxVal = 1;
    int MinVal = 10;
    for (int i = 0; i < 5; i ++)
    {
        if (arrHand[i] < MinVal)
            MinVal = arrHand[i];
        
        if (arrHand[i] > MaxVal)
            MaxVal = arrHand[i];
    }
    return MaxVal - MinVal;
}

/*
 This function is called in the bool functions.  It 
 passes in the array and calls a function called countAll.
 It takes the value from countAll and adds it to sum and returns the sum
 when called in the bool function.  It helps to determine the type of 
 poker hand being played.
 */

int sumOfArrInstances(const int arrHand[])
{
    int sum = 0;
    for (int i = 0; i < 5; i ++)
    {
        sum += countAll(arrHand, 5, arrHand[i]);
    }
    return sum;
}
/*
 This function is called in SumOfArrInstances and passes in the array,
 size of the array which is 5 and the value of the array element. It then
 runs a for-loop to compare the value of the array element with the passed
 in value of that array element.  If the values are equal to eachother
 count increments and the total value of count for that element is returned
 back to SumOfArrInstance to be summed up with the rest of the array element 
 count values.
 */

int countAll (const int arrHand[], int CARD_SIZE, int value)
{
    int count = 0;
    for (int index = 0; index < CARD_SIZE; index ++)
    {
        if (arrHand[index] == value)
        {
            count++;
        }
    }
    return count;
}

/* 
 These functions determine if an array contains a specific hand
 combination and will return true when the sum of instances returns with
 the correct poker combination for that array.

 if an array contains a pair of numbers, SumOfArrInstances
 returns 7, a true statement.  This is because a combination for a pair 
 is equal to 22111 where two elements out of the array contain the same number
 and three elements out of the array contain a number that only appears once.
 The sum of the combination is 2+2+1+1+1 = 7.
 */
bool  containsPair(const int arrHand[])
{
    return (sumOfArrInstances(arrHand) == 7);
}

/* 
 if an array contains two pairs of numbers, SumOfArrInstances
 returns 9, thus 'True' because the combination is equal to 22221 where
 2+2+2+2+1 = 9. Two different numbers appear in the array twice and one
 number only appears once.
 */
bool  containsTwoPair(const int arrHand[])
{
    return (sumOfArrInstances(arrHand) == 9);
}

/* 
 if an array contains Three of same number, SumOfArrInstances
 returns 11, thus 'True' because the combination is equal to 
 3+3+3+1+1 = 11. One number appears in the array three times and two
 numbers only appear once.
 */
bool  containsThreeOfaKind(const int arrHand[])
{
    return (sumOfArrInstances(arrHand) == 11);

}

/* 
 if an array contains four of the same number, SumOfArrInstances
 returns 17, thus 'True' because the combination is equal to
 44441. 4+4+4+4+1 = 17. One number appears in the array four times and one
 number only appears once.
 */
bool  containsFourOfaKind(const int arrHand[])
{
    return sumOfArrInstances(arrHand) == 17;
}

/* 
 if an array contains a full house, SumOfArrInstances
 returns 13, thus 'True' because the combination is equal to
 22333. 2+2+3+3+3 = 13. One number appears in the array twice and another
 number appears in the array three times.
 */
bool  containsFullHouse(const int arrHand[])
{
    return sumOfArrInstances(arrHand) == 13;
}

/* 
 if an array contains a straight, SumOfArrInstances
 returns 5 since the combination of how many times a number appears
 in the array is 11111 (A number appears in the array only once and there
 are five elements in the array) AND the function
 findingStraight returns 4. That way we can determine that the array
 contains consecutive integers that appear once in the array versus
 any sequence order of numbers that appear in the array once. 
 */
bool  containsStraight(const int arrHand[])
{
    return findingStraight(arrHand) == 4 && sumOfArrInstances(arrHand) == 5;
}

