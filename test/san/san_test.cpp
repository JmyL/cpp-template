#include <gtest/gtest.h>
#include <gmock/gmock.h>

/*TEST(Sanitizer, ChecksMemoryLeak) { new int; }*/
/**/
/*TEST(Sanitizer, ChecksDeletingTwice) {*/
/*  auto p = new int;*/
/*  delete p;*/
/**/
/*  delete p;*/
/*}*/
/**/
/*TEST(Sanitizer, ChecksAccessingInvalidMemory) {*/
/*  int* p = (int*)42;*/
/*  *p = 0;*/
/*}*/
/**/
/*TEST(Sanitizer, ChecksUsingMemoryAfterDeletingIt) {*/
/*  auto p = new int;*/
/*  delete p;*/
/*  *p = 0;*/
/*}*/
/**/
/*TEST(Sanitizer, ChecksDeletingMemoryThatWasNeverAllocated) {*/
/*  int* p = (int*)42;*/
/*  delete p;*/
/*}*/

/*TEST(Sanitizer, ChecksDevidingByZero) {*/
/*  int n = 42;*/
/*  int d = 0;*/
/*  auto f = n / d;*/
/*}*/
/**/
/*TEST(Sanitizer, ChecksNullPointerDereferences) {*/
/*  int *p = 0;*/
/*  *p = 42;*/
/*}*/
/**/
/*TEST(Sanitizer, ChecksOutOfBoundErrors) {*/
/*  int numbers[] = {1,5,7};*/
/*  numbers[10] = 0;*/
/*}*/

TEST(Sanitizer, HasNothingToDoWhenTheresNoError) {
  int i = INT_MAX - 1;
  i++;
}


TEST(Sanitizer, ChecksOverflowErrors) {
#ifndef NDEBUG
  std::cout << "hello world" << "\n";
#endif
  /*int i = INT_MAX;*/
  /*i++;*/
  EXPECT_TRUE(false);
}
