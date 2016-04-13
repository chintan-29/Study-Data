
#include "stdio.h"
#include "string.h"
#include "stdlib.h"#include <set>
#include <map>
#include <iterator>
#include <utility>

typedef FILE *stream;
typedef char *string;
using namespace std;
int main(int ac, char** av)
{
  stream f;
if(ac != 2)
{
rintf("Usage:  filename \n");
return 1;
}
printf("Reading file : %s \n",av[1]);
f= fopen(av[1],"r");

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
