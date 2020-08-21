#include <stdio.h>
#include <stdlib.h>

#include <introduction/version.h>
#include <introduction/util/util.h>

int main(int argc, char const *argv[])
{
  printf("Introduction project version: %s\n", INTRODUCTION_VERSION);
  printf("The answer is %d\n", get_answer());
  printf("JUST WANT TO SEE IT FAIL ONCE. I'm getting the hang of using Github actions.\n");
  return EXIT_FAILURE;
}
