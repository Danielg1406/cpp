#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

static int g_failedTests = 0;

static void report(bool condition, const std::string &label) {
  std::cout << (condition ? "[PASS] " : "[FAIL] ") << label << std::endl;
  if (!condition)
    ++g_failedTests;
}

template <typename Container>
static void testFindExisting(Container &container, int value, const std::string &label) {
  try {
    typename Container::iterator it = easyfind(container, value);
    report(*it == value, label);
  } catch (const std::exception &e) {
    report(false, label + std::string(" (unexpected exception: ") + e.what() + ")");
  }
}

template <typename Container>
static void testFindExistingConst(const Container &container, int value, const std::string &label) {
  try {
    typename Container::const_iterator it = easyfind(container, value);
    report(*it == value, label);
  } catch (const std::exception &e) {
    report(false, label + std::string(" (unexpected exception: ") + e.what() + ")");
  }
}

template <typename Container>
static void testFindMissing(Container &container, int value, const std::string &label) {
  try {
    (void)easyfind(container, value);
    report(false, label + " (expected exception)");
  } catch (const std::exception &) {
    report(true, label);
  }
}

int main() {
  std::vector<int> vectorValues;
  vectorValues.push_back(4);
  vectorValues.push_back(7);
  vectorValues.push_back(4);
  vectorValues.push_back(12);
  
  testFindExisting(vectorValues, 4, "vector finds the first matching element");
  testFindExistingConst(vectorValues, 12, "const vector finds a value");
  testFindMissing(vectorValues, 99, "vector throws when the value is missing");

  std::list<int> listValues;
  listValues.push_back(-3);
  listValues.push_back(8);
  listValues.push_back(15);
  testFindExisting(listValues, 8, "list finds a middle value");

  std::deque<int> dequeValues;
  dequeValues.push_back(1);
  dequeValues.push_back(2);
  dequeValues.push_back(3);
  testFindExisting(dequeValues, 3, "deque finds the last value");
  testFindMissing(dequeValues, -1, "deque throws on missing value");

  std::vector<int> emptyValues;
  testFindMissing(emptyValues, 0, "empty container throws");

  std::cout << "Failed tests: " << g_failedTests << std::endl;
  return g_failedTests == 0 ? 0 : 1;
}