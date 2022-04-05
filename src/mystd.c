#include "mystd.h"
#include <stddef.h>

bool noteof(FILE *fp)
{/* assert whethe is eof */
    wchar_t c;

    c = fgetc(fp);
    while (c==' ' || c=='\n')
    {
        c = fgetc(fp);
    }
    
    if (feof(fp)) return false;
    ungetc(c,fp);
    return true;
}

bool notendline(FILE *fp)
{/* assert whether to line end,if not unget */
    wchar_t c;
    FILE *data = fp;

    while ((c=fgetc(data))==' ' && !feof(data));
    if (c=='\n' || feof(data)) return false;
    else {
        ungetc(c,data);
        return true;
    }
    
}
