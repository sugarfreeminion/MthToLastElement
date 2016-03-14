/*************************************************************************
 * Author:          sugarfreeoh
 * Date:            13 March 2016
 * Description:     Write a program which determines the Mth to the last
 *                  element in a list.
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;
        stringstream lineStream;
        unsigned int mthElement;

        while(getline(inputFile,line))
        {
            vector<string> elements;
            string element;
            stringstream ss;

            //cout << "Input Line: " << line << endl;

            lineStream << line;

            while(getline(lineStream,element,' '))
            {
                //cout << "Element: " << element << endl;
                elements.push_back(element);
            }

            ss << elements.back();

            ss >> mthElement;

            //cout << "Mth Element: " << mthElement << endl;
           
            if(mthElement < elements.size())
            {
                //cout << "Mth Element Position: " << elements.size()-mthElement-1 << endl;
                cout << elements.at(elements.size()-mthElement-1) << endl;
            }
            else
            {
                //cout << "position does not exist" << endl;
            }

            lineStream.str("");
            lineStream.clear();
        }

        inputFile.close();
    }

    return 0;
}
