#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include "dnasequence.h"
#include <sstream>
 
using namespace std;
 
// Assume that the strand is made up of 100 sequences.
DNASequence::DNASequence()
{
    // cout << "DNASequence::Not implemented yet" << endl;
    max_sequence = 100;
    dna_sequence = new char[max_sequence+1];
    dna_sequence[0]='\0';
}
 
// Assume that the sequence is initialized to the nucleotides string.
DNASequence::DNASequence(string nucleotides)
{
    // cout << "DNASequence(string)::Not implemented yet" << endl;
    max_sequence = nucleotides.length();
    dna_sequence = new char[max_sequence];
    strcpy (dna_sequence, nucleotides.c_str());
}
 
// Copy constructor
DNASequence::DNASequence(const DNASequence& arg)
{
    // cout << "DNASequence(const DNASequene&)::Not implemented yet" << endl;
    dna_sequence = new char[max_sequence+1];
    *dna_sequence = *arg.dna_sequence;
    dna_sequence[0]='\0';
}
 
// Destructor
DNASequence::~DNASequence()
{
    // cout << "~DNASequence::Not implemented yet" << endl;
    delete [] dna_sequence;
}
 
// Assignment operator
DNASequence& DNASequence::operator=(const DNASequence& arg)
{
    // cout << "operator=::Not implemented yet" << endl;
    int newLength = strlen(arg.dna_sequence);
    
    if (this == &arg)
    {
        return *this;
    }
    
    if (max_sequence < strlen(arg.dna_sequence))
    {
        delete [] dna_sequence;
        dna_sequence = new char[strlen(arg.dna_sequence)+1];
        max_sequence = strlen(arg.dna_sequence);
    }
    strcpy (dna_sequence, arg.dna_sequence);
    return *this;
}
 
// Equals operator compares the given sequence with the invoking object.
bool DNASequence::operator==(const DNASequence& arg)
{
    // cout << "operator==::Not implemented yet" << endl;
    if(strlen(dna_sequence)>=strlen(arg.dna_sequence))
    {
        for(int i=0; i<(strlen(dna_sequence)); i++)
        {
            if (dna_sequence[i] != arg.dna_sequence[i])
                return false;
        }
    }
    else if(strlen(dna_sequence)<strlen(arg.dna_sequence))
    {
        for(int i=0; i<(strlen(arg.dna_sequence)); i++)
        {
            if(arg.dna_sequence[i] != dna_sequence[i])
                return false;
        }
    }
    return true;
}
 
// Not equals operator coompares the given sequence with the invoking object
bool DNASequence::operator!=(const DNASequence& arg)
{
    string arg1 = dna_sequence;
    string arg2 = arg.dna_sequence;
    if(arg1 == arg2)
        return false;
    else
        return true;
}
 
// Append the given sequence onto the end of the invoking object sequence.
DNASequence operator+(const DNASequence& arg1, const DNASequence& arg2)
{
    DNASequence result;
    int newLength;
    //newLength = strlen(arg1.dna_sequence) + strlen(arg2.dna_sequence) + 1;
    //result.max_sequence = newLength;
    
    strcpy(result.dna_sequence, arg1.dna_sequence);
    strcat(result.dna_sequence, arg2.dna_sequence);
    
    return result;
}
 
// Remove the given sequence from the invoking object if it exists. Return
// the modified sequence. If the given sequence is not found, return the
// first argument sequence unaltered.
DNASequence operator-(const DNASequence& arg1, const DNASequence& arg2)
{
    DNASequence result;
    string s1 = arg1.dna_sequence;
    string s2 = arg2.dna_sequence;
    result = s1;
    size_t length;
    length = s1.find(s2);
    
    if (length != string::npos)
    {
        result = s1.erase(length, s2.size());
    }
    
    return result;
}
 
// Implement the friend function to read in a nucleotide sequence made up
// of only the following characters: adenine (A), thymine (T), guanine (G)
// and cytosine (C). Assume case insensitive but convert to upper internally.
istream& operator>>(istream& ins, DNASequence& arg)
{
    // cout << "operator>>::Not implemented yet" << endl;
    string inputStr;
    ins >> inputStr;
    
    // istringstream istr(inputStr);
    for (int i = 0; i < inputStr.length(); i++)
    {
        switch (inputStr[i])
        {
            case 'A':
            case 'a':
                inputStr[i] = 'A';
                break;
            case 'T':
            case 't':
                inputStr[i] = 'T';
                break;
            case 'G':
            case 'g':
                inputStr[i] = 'G';
                break;
            case 'C':
            case 'c':
                inputStr[i] = 'C';
                break;
            default:
                inputStr = "";
                break;
        }
    }
    
    arg = DNASequence(inputStr);
    
    return ins;
}
 
// Implement the friend function to write out a nucleotide sequence. No blanks.
 
ostream& operator<<(ostream& out, const DNASequence& arg)
{
    out << arg.dna_sequence;
    return out;
}
