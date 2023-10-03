/*
===============================================================================
Description:
    This program reads n consonants and n vowels, and prints all the words that
    can be made up by using each letter exactly once. The words must begin with
    a consonant, and alternate consonants and vowels. Assume 'y' is a vowel.

Input:
    A natural number n between 1 and 6, followed by n different consonants and
    n different vowels. Both given in alphabetical order.

Output:
    Print all the words that can be made up with the 2n given letters, starting
    with a consonant and always alternating. Print the words in alphabetical 
    order, one per line.

Algorithms:
    Exhaustive search with growing search tree constraints.
    
===============================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

// Generates the search tree and writes the complete partial solutions. 
void write(const vector<char>& vowels, 
           vector<bool>& used_vowels,
           const vector<char>& consonants,
           vector<bool>& used_consonants,
           vector<char>& solution,
           uint idx) {
    // Base case: A partial solution is completed.
    if (idx == solution.size()) {
        for (char c : solution) cout << c;
        cout << endl;
    } 
    
    // Recursive case: Extend the search tree growing partial solutions.
    else {
        // Factorizes the proposed solution with elegance.
        const vector<char>& candidates = (idx % 2 == 0 ? consonants : vowels);
        vector<bool>& used = (idx % 2 == 0 ? used_consonants : used_vowels);

        for (uint i = 0; i < candidates.size(); ++i) {
            if (not used[i]) {
                solution[idx] = candidates[i];
                used[i] = true;
                write(vowels, used_vowels, consonants, used_consonants, solution, idx+1);
                used[i] = false;
            }
        }
    }

}

// The generation of solutions for this problem using exhaustive search starts
// with stating a general partial solution (root node of the search tree).
void write(const vector<char>& vowels, 
           const vector<char>& consonants) {
    uint n = vowels.size();

    // States a partial solution of the problem.
    vector<char> solution(2*n);
    uint idx = 0;
    vector<bool> used_vowels(n, false);
    vector<bool> used_consonants(n, false);
    write(vowels, used_vowels, consonants, used_consonants, solution, idx);
}

int main() {
    // Reads a natural number corresponding to the vowels and consonants.
    uint n;
    cin >> n;

    // Reads the mentioned vowels and consonants.
    vector<char> vowels(n), consonants(n);

    for(uint i = 0; i < n; i++) cin >> consonants[i];
    for(uint i = 0; i < n; i++) cin >> vowels[i];

    // Writes all the possible words that can be generated following the problem
    // constraints.
    write(vowels, consonants);
}