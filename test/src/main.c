#include <stdio.h>
#include <stdlib.h>

#include <introduction/version.h>
#include <introduction/util/util.h>

int main(int argc, char const *argv[])
{
  printf("Introduction project version: %s\n", INTRODUCTION_VERSION);
  printf("The answer is %d\n", get_answer());
  return EXIT_SUCCESS;
}
