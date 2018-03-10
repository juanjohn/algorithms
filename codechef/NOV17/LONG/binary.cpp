// C++ program to generate binary numbers from 1 to n
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// This function prints the longest palindrome substring
// of str[].
// It also returns the length of the longest palindrome
int llcs( char *str )
{
    int n = strlen( str ); // get length of input string

    // table[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];
    memset(table, 0, sizeof(table));

    // All substrings of length 1 are palindromes
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k)
    {
        // Fix the starting index
        for (int i = 0; i < n-k+1 ; ++i)
        {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    return maxLength; // return length of LPS
}

// This function uses queue data structure to print binary numbers
void generatePrintBinary(int n)
{
    // Create an empty queue of strings
    queue<string> q;

    // Enqueue the first binary number
    q.push("1");

    // This loops is like BFS of a tree with 1 as root
    // 0 as left child and 1 as right child and so on
    while (n--)
    {
        // print the front of queue
        string s1 = q.front();
        q.pop();
		//text.c_str()
		char* myPtr = new char[s1.size() + 1];
		s1.copy(myPtr, s1.size());
		myPtr[s1.size()] = '\0';

		if(llcs(myPtr)<4 )//&& strlen(myPtr)==21 )//&& myPtr[9]==myPtr[0] && myPtr[10]==myPtr[1] && myPtr[11]==myPtr[2] && myPtr[12]==myPtr[3])
        cout << llcs(myPtr) <<"  "<< s1 << "\n";

        string s2 = s1;  // Store s1 before changing it

        // Append "0" to s1 and enqueue it
        q.push(s1.append("0"));

        // Append "1" to s2 and enqueue it. Note that s2 contains
        // the previous front
        q.push(s2.append("1"));
    }
}

// Driver program to test above function
int main()
{
    int n = 1024*10000;
    generatePrintBinary(n);
    return 0;
}
