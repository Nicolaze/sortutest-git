#include "mystd.h"
#include "sort.h"
#include <stddef.h>

#define MAXITEM 100

// casefile
static char casefile[20] = "test/insertsort.txt";
// data array
static element a[MAXDATAITEM];
static size_t npos = 0;


static void clear()
{
    npos = 0;
}


int main(int argc, char const *argv[])
{
    /* test sort algorthim */
    FILE *datafile = fopen(casefile, "r");

    while (noteof(datafile))
    {
        fetchdata(datafile,a,&npos);

        insertsort(a,npos);

        outputdata(a,npos);
        clear();
    }
    
    fclose(datafile);
    return 0;
}