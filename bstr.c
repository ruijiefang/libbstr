/*
 * =====================================================================================
 *
 *       Filename:  bstr.c
 *
 *    Description:  implementation of bstr.h
 *
 *        Version:  1.0
 *        Created:  10/24/2019 21:09:49
 *
 * =====================================================================================
 */
#include "bstr.h"
#include <memory.h>
#include <string.h>
#include <assert.h>

struct _bstr { char _c; };
typedef size_t longword_t;
#define bstr_get_end(end_, o_str) \
  do { end_ = (char *)(((longword_t) (o_str)) - 1UL); } while (0)


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  char * bstr_to_str(bstr_t * str)
 *       Params:  
 *      Returns:
 *  Description:  
 * =====================================================================================
 */
char * bstr_to_str(bstr_t * str)
{
  return (char *) str;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstr_new(size_t len)
 *       Params:  len: the length of the new string.
 *      Returns:  Pointer to a heap-allocated string.
 *  Description:  Creates a new bstring-type object.
 * =====================================================================================
 */
bstr_t * bstr_new(size_t len)
{
  void * begin; bstr_t * end;
  assert(len > 0);
  begin = malloc(sizeof(char*) + len + 1);
  if (!begin) return NULL;
  end = begin + sizeof(char*) + len;
  memcpy(begin, (void *) (&end), sizeof(char *));
  return begin + sizeof(char *);
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstr_from(const char * src)
 *       Params:  src: The source string, either a bstring or a null-terminated string
 *      Returns:  A bstring from the source string.
 *  Description:  Creates a bstring from a source string.
 * =====================================================================================
 */
bstr_t * bstr_from(const char * src)
{
  bstr_t * dst;
  size_t len;
  assert(src);
  len = strlen(src); 
  dst = bstr_new(len);
  if (!dst) return NULL; 
  memcpy(dst, src, len);
  return dst;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstrdup(bstr_t * str)
 *       Params:  str: A bstring-type object.
 *      Returns:  A duplicated bstring
 *  Description:  Duplicates a given bstring
 * =====================================================================================
 */
bstr_t * bstrdup(bstr_t * str)
{
  bstr_t * dst;
  assert(str);
  dst = bstr_new(bstrlen(str));
  if (!dst) return NULL;
  memcpy(dst, str, bstrlen(str));
  return dst;
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstrcat(bstr_t * str1, bstr_t * str2)
 *       Params:
 *      Returns:
 *  Description:  Concatinates two bstrings str1 and str2, and return a new one.
 * =====================================================================================
 */
bstr_t * bstrcat(bstr_t * str1, bstr_t * str2)
{
  bstr_t * newstr;
  assert(str1);
  assert(str2);
  newstr = bstr_new(bstrlen(str1) + bstrlen(str2));
  if (!newstr) return NULL;
  memcpy(newstr, str1, bstrlen(str1));
  memcpy(newstr + bstrlen(str1), str2, bstrlen(str2));
  return newstr;
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  int bstrcat(bstr_t * str1, bstr_t * str2)
 *       Params:  str1: a bstring
 *                str2: a bstring
 *      Returns:  1 if str1 > str2, -1 if str1 < str2, 0 if equal
 *  Description:  Compares str1 and str2. Returns 1 if str1 > str2, -1 if str1 < str2,
 *                0 if equal.
 * =====================================================================================
 */
int bstrcmp(bstr_t * str1, bstr_t * str2)
{
#define S1_GREATER (1)
#define EQUALS (0)
#define S1_SMALLER (-1)
  longword_t * lptr1, * lptr2;
  char * endptr1, * endptr2;

  assert(str1); assert(str2);
  bstr_get_end(endptr1, str1);
  bstr_get_end(endptr2, str2);
 
  assert(endptr1 >= (char *) str1);
  assert(endptr2 >= (char *) str2);

  while (1) {
    if (endptr1 - (char *) str1 < sizeof(longword_t) || 
        endptr2 - (char *) str2 < sizeof(longword_t)) {
      while ((void *) str1 != (void *) endptr1 &&
          (void *) str2 != (void *) endptr2 &&
          *str1 == *str2) { ++str1; ++str2; }
      if (*str1 == '\0') 
        return *str2 == '\0' ? 0 : S1_SMALLER;
    
      if (*str2 == '\0')
        return *str1 == '\0' ? 0 : S1_GREATER;
  
      return (*str2 > *str1) ? 1 : -1;
    }
  
    lptr1 = (longword_t *) str1;
    lptr2 = (longword_t *) str2;

    while ((void *) lptr1 < (void *) endptr1 && 
        (void *) lptr2 < (void *) endptr2 &&
        *lptr1 == *lptr2) { ++lptr1; ++lptr2; }
    str1 = (bstr_t *) lptr1;
    str2 = (bstr_t *) lptr2;
  }
#undef S1_GREATER
#undef EQUALS
#undef S1_SMALLER
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  bstr_t * bstrlen(bstr_t * s)
 *       Params:  bstr_t * s: a bstring
 *      Returns: The length of a bstring
 *  Description: Returns the length of a bstring
 * =====================================================================================
 */
size_t bstrlen(bstr_t * s)
{
  char * endptr;
  assert(s);
  bstr_get_end(endptr, s);
  assert(endptr >= (char *) s);
  return endptr - (char *) s;
}

