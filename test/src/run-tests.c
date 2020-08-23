#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <introduction/util/util.h>
#include <introduction/version.h>

#include <munit.h>

/*
 *
 * UNIT TEST FUNCTIONS
 * ===================
 *
 * All unit tests are of the form:
 *
 * MunitResult <test_name>(const MunitParameter params[],
 *                         void *user_data_or_fixture) {
 *   // perform tests.
 *   // use the munit_assert_... macros.
 *   return MUNIT_OK;
 * }
 *
 * It is necessary for the unit test functions to be added to
 * the `test` array.
 */

MunitResult get_answer_returns_42(const MunitParameter ignored_params[],
                                  void *ignored_data) {

  munit_assert(get_answer() == 42);

  return MUNIT_OK;
}

MunitResult
get_message_returns_correct_string(const MunitParameter ignored_params[],
                                   void *ignored_data) {
  munit_assert(
      strcmp(get_message(), "Hello, World!\nI'm a separated string!\n") == 0);
  return MUNIT_OK;
}

/*
 * MUNIT TEST CONFIGURATION
 * ========================
 *
 * Boilerplate code for the munit testing library.
 *
 */

MunitTest tests[] = {{"/get_answer_returns_42", get_answer_returns_42, NULL,
                      NULL, MUNIT_TEST_OPTION_NONE, NULL},
                     {"/get_message_returns_correct_string",
                      get_message_returns_correct_string, NULL, NULL,
                      MUNIT_TEST_OPTION_NONE, NULL},
                     {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suite = {"/grapefruit-test-suite", tests, NULL, 1,
                                 MUNIT_SUITE_OPTION_NONE};

/*
 * MAIN FUNCTION
 * =============
 */

int main(int argc, char *argv[]) {
  printf("Introduction project version: %s\n\n", INTRODUCTION_VERSION);
  return munit_suite_main(&suite, NULL, argc, argv);
}