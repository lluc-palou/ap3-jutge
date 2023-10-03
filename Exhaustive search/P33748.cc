/*
===============================================================================
Description:
    This program reads a natural number m and n different words, and prints all
    the subsets of m elements that can be made up with the words.

Input:
    Two natural numbers m and n, followed by n different words. Assume n > 0
    and 0 <= m <= n.

Output:
    Print all the subsets of m words that can be made up with the words.

Algorithms:
    Exhaustive search with growing search tree constraints.
    
===============================================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Generates the search tree and writes the complete partial solutions. 
void write_subsets(const vector<string>& words,
                   vector<bool>& chosen,
                   uint idx,
                   uint n_chosen,
                   uint m) {
    // Growing search tree constraints.
    if (n_chosen > m) return; // More elements in the partial solution than expected.
    if ((chosen.size() - idx) + n_chosen < m) return; // The partial solution cannot reach the expected number of elements that must contain.

    // Base case: A partial solution is complete.
    if (idx == chosen.size()) {
        if (n_chosen == m) {
            // Output format.
            bool first_word = true;
            cout << '{';
            for (uint i = 0; i < chosen.size(); ++i) {
                if (chosen[i]) {
                    if (first_word) {
                        first_word = false;
                        cout << words[i];
                    } else cout << ',' << words[i]; 
                }
            }
            cout << '}' << endl;
        }
    } 
    
    // Recursive case: Extend the search tree growing partial solutions.
    else {
        chosen[idx] = false;
        write_subsets(words, chosen, idx+1, n_chosen, m);

        chosen[idx] = true;
        write_subsets(words, chosen, idx+1, n_chosen+1, m);
    }
}

// The generation of solutions for this problem using exhaustive search starts
// with stating a general partial solution (root node of the search tree).
void write_subsets(const vector<string>& words,
                   uint m) {
    // States a partial solution of the problem.
    vector<bool> chosen(words.size());
    uint idx = 0;
    uint n_chosen = 0;
    write_subsets(words, chosen, idx, n_chosen, m);
}

int main() {
    // Reads two natural numbers.
    int m, n;
    cin >> m >> n;

    // Reads n different words.
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];

    // Writes all the possible subsets.
    write_subsets(words, m);
}