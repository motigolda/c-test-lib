#ifndef TESTLIB_H
#define TESTLIB_H

#include <stdbool.h>

bool AssertStrEquals(char *expected, char *actual, char *description);

bool AssertIntEquals(int expected, int actual, char *description);

bool AssertUnsignedCharEquals(unsigned char expected, unsigned char actual, char *description);

bool AssertBoolEquals(bool expected, bool actual, char *description);

#endif