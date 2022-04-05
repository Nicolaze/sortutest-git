#include "CUnit/TestRun.h"
#include "mystd.h"
#include "sort.h"

static FILE *casefp,*logfp;

//init test
static void inittest(char *casepath,char *logpath)
{
    casefp = fopen(casepath,"r");
    logfp = fopen(logpath,"w");    
}
static void closetest()
{
    fclose(casefp);
    fclose(logfp);
}

// check elememts algorthim
//static void check(element a[],element b[],size_t len);
static void check2(element a[],FILE *casefp, size_t len);


// test insert sort
void testINSERTSORT(void)
{
    element a[MAXDATAITEM]/*,b[MAXARRAYITEMS]*/;
    size_t len;

    inittest("test/insertsort.txt","test/insert_log.txt");

    while (noteof(casefp))
    {
        fetchdata(casefp,a,&len);
        insertsort1(a,len);
        check2(a,casefp,len);
    }
    
    closetest();
}

void testBSINSSORT(void)
{
    element a[MAXDATAITEM]/*,b[MAXARRAYITEMS]*/;
    size_t len;

    inittest("test/insertsort.txt","test/insert2_log.txt");

    while (noteof(casefp))
    {
        fetchdata(casefp,a,&len);
        insertsort2(a,len);
        check2(a,casefp,len);
    }
    
    closetest();   
}

///////////////////////
// check functions //
//////////////////////

//static void check(element a[],element b[],size_t len)
//{
//    u_int32_t state,cur_state;
//
//    state = CU_get_number_of_failures();
//    cur_state=state;
//    for (size_t i = 1; i<= len && cur_state==state; i++)
//    {
//        CU_ASSERT_EQUAL(a[i].key,b[i].key)
//        cur_state = CU_get_number_of_failures();
//    }
//
//    if (cur_state!=state) foutputdata(logfp,a,len);
//
//    return;
//}

static void check2(element a[],FILE *casefp, size_t len)
{/* check expect in file cache, save memory */
    u_int32_t state,cur_state;
    int target_data;

    state = CU_get_number_of_failures();
    cur_state = state;
    for (size_t i = 1; notendline(casefp); i++)
    {
        fscanf(casefp,"%d",&target_data);
        CU_ASSERT_EQUAL(a[i].key,target_data)
        cur_state = CU_get_number_of_failures();
    }

    if (cur_state!=state) foutputdata(logfp,a,len);

    return;
}
