/*
 *  Unit test of the array poly
 *  
 *  this is the main test funcitons 
 */

#include "CUnit/Basic.h"

#define CONDITION (NULL == CU_add_test(pSuite, "test of insertsort1", testINSERTSORT) \
    || NULL == CU_add_test(pSuite, "test of insertsort2" ,testBSINSSORT))

extern void testINSERTSORT(void);
extern void testBSINSSORT(void);

/*  The empty suite funcionts
 *  return success.
*/
int init_suite1()
{
    return 0;
}

int clean_suite1()
{
    return 0;
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main(int argc, char const *argv[])
{
    CU_pSuite pSuite = NULL;

    /*  initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();

    /*  add a suite to the registry*/
    pSuite = CU_add_suite("Suite_1",init_suite1,clean_suite1);
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /*  add the tests to the suite */
    if (CONDITION)
    {
        CU_cleanup_registry();
        return CU_get_error();        
    }
    
    // Run all tests using console interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();       
}