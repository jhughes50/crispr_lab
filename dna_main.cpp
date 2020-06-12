/* Jason Hughes
 * Test driver for DNAStrand with DNASequences
 *
 *
 *
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "dnasequence.h"
 
using namespace std;
 
// int main()
//
// Implements the driver for the DNAStrand testing using DNASequences.
//
int main()
{
    char answer;
    string nucleotides;
    int number;
    // Implement your test functions here.
    
    //greeting
    cout << "Welcome to CRISPR!" <<endl;
    cout << endl;
    
    // 1. Start a do-while loop that spans the rest of the instructions.
    do
    {
        DNASequence big_strand, bad_dna, clean_strand;
        // 2. Ask the user to enter the number of DNASequences needed for the CRISPR application.
        cout << "Enter the number of DNA sequences needed: " << endl;
        cin  >> number;
        
        // 3. Either declare a vector of DNASequence or a dynamic array where the user enters the number of elements.
        DNASequence* dna_seq;
        dna_seq = new DNASequence[number];
        
        // 4. In a for-loop, read in a DNASequence for each element in the array using >> operator.
        // 5. Declare a DNASequence called big_strand and add each element in the array to big_strand in a for-loop.
        
        for(int i=0; i < number; i++)
        {
            cout << "Processing DNA sequence #" << i+1 <<endl;
            cout << "Enter the elements in sequence #" << i+1 << endl;
            cout << endl;
            cin  >> dna_seq[i];
            // cout << dna_seq[i];
        }
        
        for (int i=0; i < number; i++)
        {
            big_strand = big_strand + dna_seq[i];
        }
        
        // 6. Declare two variables: one for a small sequence of bad_dna and one to hold the clean_strand.
        // NOTE: Make sure that clean_strand is set directly to big_strand when declared.
        
        // 7. Print the final big_strand after the loop using the << operator.
        
        cout << "The contents in the big strand is: ";
        cout << big_strand << endl;
        cout << endl;
        
        clean_strand = big_strand;
        
        // 6 a. Test == operator
        cout << "Checking == operator ... " << endl;
        if(clean_strand == big_strand)
            cout << "Functioning properly" << endl;
        cout << endl;
        
        // 6 b. Test != operator
        cout << "Checking != operator... " << endl;
        //if (bad_dna != big_strand)
        if (bad_dna != big_strand)
            cout << "Functioning properly" << endl;
        cout << endl;
        
        // 8. Ask the user to enter the bad DNASequence to remove from big_strand and put it in the bad_dna variable.
        cout << "Enter a bad DNASequence to remove from big_strand: ";
        cin  >> bad_dna;
        
        big_strand = clean_strand;
        // 9. In a do-while loop add the following lines
        do
        {
            // 9 a. set the big_strand to the clean_strand
            big_strand = clean_strand;
            // 9 b. subtract the bad_dna from big_strand and put the result in clean_strand
            clean_strand = big_strand - bad_dna;
            cout << "clean_strand[" << clean_strand << "] != big_strand[" << big_strand << "]" << endl;
            cout << endl;
            
        } while (clean_strand != big_strand);
        // 10. Use clean_strand != big_strand as the while condition so that it loops until the big_strand is clean.
        
        // 11. Print the clean_strand as you go and the final result.
        cout << "The contents in the clean strand is: ";
        cout << clean_strand << endl;
        cout << endl;
        
        // 13. Clean up array/vector
        delete [] dna_seq;
        
        // 14. Ask the user to try again.
        cout << "Would you like to try again (y/n)?" << endl;
        cin  >> answer;
        
    } while (answer == 'Y' || answer =='y');
    
    cout << "Have a nice day!" << endl;
}
