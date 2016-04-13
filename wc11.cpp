#include <set>
#include <map>
#include <fstream>
#include <iostream>
#include <iterator>
#include <utility>
using namespace std;
int main(int ac, char** av)
{
if(ac != 2)
{
cout << "Usage: " << av[0] << " filename" << endl;
return 1;
}
cout << "Reading file " << av[1] << endl;
ifstream f(av[1]);

// read and count words
istream_iterator<string> i(f);
multiset<string> s(i, istream_iterator<string>());

// sort by count
multimap<size_t, string> wordstats;
for(multiset<string>::const_iterator i = s.begin(); i != s.end(); i = s.upper_bound(*i))
wordstats.insert( make_pair( s.count(*i), *i ));

// output in decreasing order
for( multimap<size_t, string>::const_reverse_iterator i = wordstats.rbegin(); i != wordstats.rend(); ++i)
cout << " word " << i->second << " found " << i->first << " times " << endl;
}
