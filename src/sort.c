#include "sort.h"

// insert into a[], i: ele count,move search ele
static void insert1(element e,element a[],size_t i);
// insert into a[], i: ele count,bssearch ele
static void insert2(element e,element a[],size_t i);


////////////////////////////
/*  main functions implenment */
void fetchdata(FILE *in, element a[], size_t *nitem)
{/* get array data from inputfile 
    data store in a[], the count is nitem */

    FILE *infp = in;
    element *data = a;
    size_t *plen = nitem, pos = 0;

    while (notendline(in))
    {
        pos++;
        fscanf(infp, "%d", &data[pos].key);
    } 
    
    *plen = pos;
    
    return;
}

void outputdata(element a[],size_t nitem)
{/* print data to secreen from start to end */
    for (size_t i = 1; i <= nitem; i++)
    {
        printf("%d ",a[i].key);
    }
    putchar('\n');

    return;
}

void foutputdata(FILE *out,element a[],size_t nitem)
{/* print data to logfile from start to end */

    FILE *outfp = out;

    for (size_t i = 1; i <= nitem; i++)
    {
        fprintf(outfp,"%d ",a[i].key);
    }
    fputc('\n',out);

    return;
}


////////////////////////////
/*  sort functions implenment*/

void insertsort1(element a[],size_t nitem)
{/* insert sort */
    element *array = a;

    for (size_t i = 2; i <= nitem; i++)
    {
        insert1(array[i],array,i-1);
    }
    
    return;
}

void insertsort2(element a[],size_t nitem)
{/* insert sort */
    element *array = a;

    for (size_t i = 2; i <= nitem; i++)
    {
        insert2(array[i],array,i-1);
    }
    
    return;
}



////////////////////////////
/*  axulary functions  */
static void insert1(element e,element a[],size_t i)
{/* a[] is a sorted array, i is count of ele,search from last
    to target one by one */
    element *array = a;
    size_t pos = i;

    while (pos > 0 && array[pos].key > e.key)
    {
        array[pos+1] = array[pos];
        pos--;
    }
    array[pos+1] = e;

    return;
}

static void insert2(element e,element a[],size_t i)
{/* a[] is a sorted array, start form 1,i is count of ele,bsearch
    the e, if not found,insert it  */
    element *array = a;
    size_t start,mid,end;

    if (e.key >= array[i].key) {
        array[i+1] = e;
        return;
    }
    if (e.key <= array[1].key) {
        for (size_t j = i; j >= 1; j--)
        {
            array[j+1] = array[j];
        }
        array[1] = e;
        return;
    }
    

    // when e in the array
    // find e
    start = 1; end = i; mid = (start+end)/2;
    while (array[mid].key != e.key && mid != start)
    {
        if (e.key > array[mid].key)
        {
            start = mid;
        }
        else
        {
            end = mid;
        }

        mid = (start+end)/2;
    }

    // if can't find e,insert it
    for (size_t j = i; j > mid; j--)
    {
        array[j+1] = array[j];
    }
    array[mid+1] = e;
    return;
}
