

using namespace std;

vector<string> set1;
vector<string> set2;

void unionOf()
{
    vector temp = set1;
    for (int i = 0; i < set2.size(); i++)
        if(std::find(temp.begin(), temp.end(), set2.at(i)) != temp.end())
            temp.add(newSet.at(i));
    cout << "[Set1 or Set2] - " + toString(temp) << endl;
}

void intersection()
{
    vector temp;
    for (int i = 0; i < set2.size(); i++)
        if(std::find(set1.begin(), set1.end(), set2.at(i)) != set1.end())
            temp.add(set2.get(i));
    cout << "[Set1 and Set2] - " + toString(temp) << endl;
}

void difference(int order)
{
    if (order == 0)
    {
        vector temp = set1;
        for(int i = 0; i < set2.size(); i++)
            temp.remove(set2.get(i));
        cout << "[Set1 and !Set2] - " + toString(temp) << endl;
    }
    else
    {
        vector temp = set2;
        for(int i = 0; i < set1.size(); i++)
            temp.remove(set1.get(i));
        cout << "[Set2 and !Set1] - " + toString(temp) << endl;
    }
}

std::string toString(vector temp) const
{
    std::string temp = "";
    if (newSet.size() == 0)
        return "Empty";
    for (int i = 0; i < newSet.size(); i++)
        temp += newSet.at(i) + " ";
    return temp;
}

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
            set1.clear();
            for (int i = 1; i < input2.size(); i++)
                set1.add(input2.at(i));
            cout << "Modified Set1 Values.\n";
        }
        else if (input2.at(0) == "set2")
        {
            set2.clear();
            for (int i = 1; i < input2.size(); i++)
                set2.add(input2.at(i));
            cout << "Modified Set2 Values.\n";
        }
        else if (input2.at(0) == "union")
            unionOf();

        else if (input2.at(0) == "intersection")
            intersection();

        else if (input2.at(0) == "difference")
            if (input2.size() > 2 && input2.at(1) == "set1" && input2.at(2) == "set2")
                difference(0);
            else if (input2.size() > 2 && input2.at(1) == "set2" && input2.at(2) == "set1")
                difference(1);
            else
                cout << "Invalid Input.\n";

        else if (input2.at(0) == "view")
        {
            cout << "Set1: " + set1.toString() << endl;
            cout << "Set2: " + set2.toString() << endl;

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

