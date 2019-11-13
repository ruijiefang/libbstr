/*
 * =====================================================================================
 *
 *       Filename:  bstr.h
 *
 *    Description:  Baselib string implementation
 *
 *        Version:  1.0
 *        Created:  10/24/2019 20:49:12
 *
 * =====================================================================================
 */
#ifndef _BSTR_H
#define _BSTR_H

#include <stddef.h>
#include <stdlib.h>
typedef struct _bstr * bstr_t;

#define bstr_get_start(o_str) \
  (void *)((size_t *)(o_str) - 1)
#define bstr_free(str) \
  do { free(bstr_get_start(str)); str = NULL; } while (0)
#undef bstr_get_end

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstr_new(size_t len)
 *       Params:  len: the length of the new string.
 *      Returns:  Pointer to a heap-allocated string.
 *  Description:  Creates a new bstring-type object.
 * =====================================================================================
 */
bstr_t * bstr_new(size_t len);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstr_from(const char * src)
 *       Params:  src: The source string, either a bstring or a null-terminated string
 *      Returns:  A bstring from the source string.
 *  Description:  Creates a bstring from a source string.
 * =====================================================================================
 */
bstr_t * bstr_from(const char * src);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstrdup(bstr_t * str)
 *       Params:  str: A bstring-type object.
 *      Returns:  A duplicated bstring
 *  Description:  Duplicates a given bstring
 * =====================================================================================
 */
bstr_t * bstrdup(bstr_t * str);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstrcat(bstr_t * str1, bstr_t * str2)
 *       Params:  
 *      Returns:
 *  Description:  Concatinates two bstrings str1 and str2, and return a new one.
 * =====================================================================================
 */
bstr_t * bstrcat(bstr_t * str1, bstr_t * str2);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  int bstrcmp(bstr_t * str1, bstr_t * str2)
 *       Params:  str1: a bstring
 *                str2: a bstring
 *      Returns:  -1 if str1 > str2, 1 if str1 < str2, 0 if equal
 *  Description:  Compares str1 and str2. Returns -1 if str1 > str2, 1 if str1 < str2,
 *                0 if equal.
 * =====================================================================================
 */
int bstrcmp(bstr_t * str1, bstr_t * str2);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstrlen(bstr_t * s)
 *       Params:  bstr_t * s: a bstring
 *      Returns: The length of a bstring
 *  Description: Returns the length of a bstring 
 * =====================================================================================
 */
size_t bstrlen(bstr_t * s);


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  char * bstr_to_str(bstr_t * s)
 *       Params:  
 *      Returns:
 *  Description:  
 * =====================================================================================
 */
char * bstr_to_str(bstr_t * s);

#endif
