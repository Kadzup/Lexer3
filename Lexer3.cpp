#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <vector>
#include <algorithm>

using namespace std;

bool isKeyword(char buffer[]) {
    vector<string> keywords = {"call", "cancel"};
    bool flag = false;

    for (int i = 0; i < keywords.size(); i++) {
        if (strcmp(keywords[i].c_str(), buffer) == 0) {
            flag = true;
            break;
        }
    }

    return flag;
}

bool isNumber(string buffer) {
    vector<char> numbers = { '1', '2', '3' };
    int length = 4;
    bool flag = false;

    if (buffer.empty() || buffer.size() < 4) {
        return flag;
    }

    flag = true;

    for (int i = 0; i < buffer.size(); i++) {
        if (find(numbers.begin(), numbers.end(), buffer[i]) == numbers.end())
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void ParseFile(const string path) {
    char ch, buffer[15];
    ifstream fin(path);
    int i, j = 0;

    if (!fin.is_open()) {
        cout << "error while opening the file\n";
        exit(0);
    }

    while (!fin.eof()) {
        ch = fin.get();

        if (isalnum(ch)) {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer) == true)
                cout << "| " << buffer << " |\t | Keyword |\n";
            else if (isNumber(buffer) == true)
                cout << "| " << buffer << " |\t | Number |\n";
            else
                cout << "| " << buffer << " |\t | Unknown |\n";
        }

    }

    fin.close();
}

int main()
{
    ParseFile("test.txt");
}
