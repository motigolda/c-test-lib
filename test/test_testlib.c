#include <stdio.h>
#include <stdbool.h>
#include "testlib.h"

void TestTestlibBasicFlowStr(){
    bool success = AssertStrEquals("arr", "arr", "arr = arr");
    printf("basic flow: %s\n", success ? "success" : "failed");
    printf("Make sure also the prints\n");
}

void TestTestlibBasicFlowInt(){
    bool success = AssertIntEquals(1, 1, "1=1");
    printf("basic flow: %s\n", success ? "success" : "failed");
    printf("Make sure also the prints\n"); 
    success = !AssertIntEquals(2, 1, "2!=1");
    printf("basic negative flow: %s\n", success ? "success" : "failed");
    printf("Make sure also the prints\n");       
}

int main(){
    TestTestlibBasicFlowStr();
    TestTestlibBasicFlowInt();
    return 0;
}