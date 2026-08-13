#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, word = "";
    string longest[100];
    int max = 0, count = 0;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    sentence = sentence + " ";

    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            word = word + sentence[i];
        }
        else
        {
            if (word.length() > max)
            {
                max = word.length();
                count = 0;
                longest[count] = word;
                count++;
            }
            else if (word.length() == max)
            {
                longest[count] = word;
                count++;
            }

            word = "";
        }
    }

    cout << "Longest word(s): ";
    for (int i = 0; i < count; i++)
    {
        cout << longest[i] << " ";
    }

    cout << "\nNumber of letters: " << max;

    return 0;
}