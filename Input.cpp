#include "Input.h"

void read(istream& in, vector<string>& text)
{
        string line;
        while (getline(in, line))
                text.push_back(line);
}

