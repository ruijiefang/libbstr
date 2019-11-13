/*
 * =====================================================================================
 *
 *       Filename:  bstrtest.c
 *
 *    Description:  Tests bstr.c
 *
 *        Version:  1.0
 *        Created:  10/25/2019 12:53:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  RuiJie Fang (ruijief), ruijief@princeton.edu
 *   Organization:  Princeton University
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include "bstr.h"
typedef size_t longword_t;
int main(int argc, char **argv)
{
  assert(sizeof(longword_t) == sizeof(char *));
  assert(sizeof(bstr_t) == sizeof(char *));
  bstr_t * a, * b;
  a = bstr_from("hello world");
  b = bstr_from("good bye!");
  assert(a);
  assert(b);
  printf("%s\n", bstr_to_str(a));
  printf("%s\n", bstr_to_str(b));
  bstr_free(a);
  bstr_free(b);
  assert(!b); assert(!a);
  return 0;
}
