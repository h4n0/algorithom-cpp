#include <stdio.h>
#include <fstream>
#include <vector>
#include "QuickSort.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        cout<<"Please input the file path"<<endl;
        return -1;
    }
    
    char *path = argv[1];
    ifstream input;
    input.open(path);
    // declare a vector of int and a temp int for storing temporary int
    // from text file
    vector<int> array;
    int temp;

    if (!input)
    {
        cout<<"Invalid path for the file"<<endl;
        return -1;
    }
    else
    {
        // bad practice here!
        //while(input.good() && !input.eof())
        // good practice in the following, see
        // http://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-considered-wrong
        while(input >> temp)
        {
            //input>>temp;
            array.push_back(temp);
        }
        input.close();
    }

    QuickSort(array.begin(), array.end());

    // const_iterator means that the data pointed by this iterator cannot
    // be modified during the loop 
    // http://stackoverflow.com/questions/10750057/c-printing-out-the-contents-of-a-vector
    for(vector<int>::const_iterator i = array.begin(); i != array.end(); i++)
        cout<<*i<<" "<<endl;
        
    return 0;
} 
