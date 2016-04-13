#include<iostream>
#include<string>
#include<map>
#include<fstream>
using namespace std;
int main()
{
    ifstream file;
    file.open("aa.txt");
    if(!file.is_open()) return 1;
    map<string, map<string, int> > categories;
    while(file.good())
    {
        string s;
        getline(file, s);
        int pos = s.find_first_of(' ');
        if(pos < 0) continue;
        string word = s.substr(0, pos);
        string category = word;
        s = s.erase(0, pos+1);
        while(s.size() > 0)
        {
            pos = s.find_first_of(' ');
            if(pos < 0)
                pos = s.size();
            string word = s.substr(0, pos);
            if(word != "")
                categories[category][word]++;
            s = s.erase(0, pos+1);
        }
    }
    for(map<string, map<string, int> >::iterator cit = categories.begin(); cit != categories.end(); ++cit)
    {
        cout << "Category - " << cit->first << endl;
        for(map<string, int>::iterator wit = cit->second.begin(); wit != cit->second.end(); ++wit)
            cout << "\tword: " << wit->first << ",\t" << wit->second << endl;
    }
    return 0;
}
