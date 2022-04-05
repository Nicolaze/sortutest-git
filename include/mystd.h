#pragma once

#include <stdio.h>
#include <stdbool.h>

// assert whether file ends
bool noteof(FILE *fp);
// assert end line, not ungetc
bool notendline(FILE *fp);

// get datas from data file
void getdata(FILE *infile,int *keys, size_t *n);

// print data to screen
void printdata(int *keys, size_t start, size_t end);
// print data to log file
void fprintdata(FILE *outfile, int *keys, size_t start, size_t end);