#include <iostream>
#include <sstream>
#include "Set.h"

using namespace std;

void replacePhrase(string& phrase, string word1, string word2)
{
    for(string::size_type i = 0; (i = phrase.find(word1, i)) != string::npos;)
    {
        phrase.replace(i, word1.length(), word2);
        i += word2.length();
    }
}

int main()
{
    Set<string> adt1;
    Set<string> adt2;
    string input1;
    vector<string> input2;

    cout << "Set Test\n=================\n";
    cout << "Type '?' for a list of commands.\n";

    while (true)
    {
        cout << "\nCommand: ";

        getline(cin,input1);
        replacePhrase(input1, " ",",");
        input2.clear();

        string word;
        stringstream stream(input1);
        while( getline(stream, word, ',') )
            input2.push_back(word);

        if (input2.size() == 0)
            cout << "Invalid Command.\n";
        else if (input2.at(0) == "set1")
        {
            adt1.clear();
            for (int i = 1; i < input2.size(); i++)
                adt1.add(input2.at(i));
            cout << "Modified Set1 Values.\n";
        }
        else if (input2.at(0) == "set2")
        {
            adt2.clear();
            for (int i = 1; i < input2.size(); i++)
                adt2.add(input2.at(i));
            cout << "Modified Set2 Values.\n";
        }
        else if (input2.at(0) == "union")
            cout << "[Set1 or Set2] - " + (adt1|adt2).toString() << endl;


        else if (input2.at(0) == "intersection")
            cout << "[Set1 and Set2] - " + (adt1&adt2).toString() << endl;

        else if (input2.at(0) == "difference")
            if (input2.size() > 2 && input2.at(1) == "set1" && input2.at(2) == "set2")
                cout << "[Set1 and !Set2] - " + (adt1^adt2).toString() << endl;
            else if (input2.size() > 2 && input2.at(1) == "set2" && input2.at(2) == "set1")
                cout << "[Set2 and !Set1] - " + (adt2^adt1).toString() << endl;
            else
                cout << "Invalid Input.\n";

        else if (input2.at(0) == "view")
        {
            cout << "Set1: " + adt1.toString() << endl;
            cout << "Set2: " + adt2.toString() << endl;

        }
        else if (input2.at(0) == "?")
        {
            cout << "\nHelp\n--------------\n";
            cout << "1. Assign Values to Set1(Separated by Space or Comma): [ set1 value1, value2, value3, ..., valueN ].\n";
            cout << "2. Assign Values to Set1(Separated by Space or Comma): [ set2 value1, value2, value3, ..., valueN ].\n";
            cout << "3. View the Contents of Both Sets: [ view ].\n";
            cout << "4. Find Union of Both Sets: [ union ].\n";
            cout << "5. Find Intersection of Both Sets: [ intersection ].\n";
            cout << "6. Find Difference Between Sets: [ difference set1 set2 ] or [ difference set2 set1 ].\n";
            cout << "7. Terminate the Program: [ exit ].\n";
        }
        else if (input2.at(0) == "exit")
        {
            cout << "Program Terminated.\n";
            return 0;
        }
        else
            cout << "Invalid Command.\n";
    }
}
