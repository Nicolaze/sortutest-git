#pragma once
#include "mydef.h"
#include "mystd.h"

// input element from FILE
void fetchdata(FILE *in, element a[], size_t *nitem);
// print data to screen
void outputdata(element a[],size_t nitem);
// print data to file
void foutputdata(FILE *out,element a[],size_t nitem);

///////////////////////
/*  sort functions */

// insert move sort
void insertsort1(element a[],size_t nitem);
// bseach insert sort
void insertsort2(element a[],size_t nitem);