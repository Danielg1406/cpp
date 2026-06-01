#include <climits>
#include <iostream>
#include <list>
#include <vector>

#include "Span.hpp"

static int g_failedTests = 0;

static void report(bool condition, const std::string &label) {
  std::cout << (condition ? "[PASS] " : "[FAIL] ") << label << std::endl;
  if (!condition)
    ++g_failedTests;
}

static void testThrowShortSpan(const Span &span, const std::string &label) {
  try {
    (void)span.shortestSpan();
    report(false, label + " (expected exception)");
  } catch (const std::exception &) {
    report(true, label);
  }
}

static void testThrowLongSpan(const Span &span, const std::string &label) {
  try {
    (void)span.longestSpan();
    report(false, label + " (expected exception)");
  } catch (const std::exception &) {
    report(true, label);
  }
}

int main() {
  std::cout << "Exercise 01 - Span" << std::endl;

  Span sample(5);
  sample.addNumber(6);
  sample.addNumber(3);
  sample.addNumber(17);
  sample.addNumber(9);
  sample.addNumber(11);
  report(sample.shortestSpan() == 2, "sample shortest span is 2");
  report(sample.longestSpan() == 14, "sample longest span is 14");

  try {
    sample.addNumber(42);
    report(false, "adding beyond capacity throws");
  } catch (const std::exception &) {
    report(true, "adding beyond capacity throws");
  }

  Span empty(4);
  testThrowShortSpan(empty, "empty span throws for shortestSpan");
  testThrowLongSpan(empty, "empty span throws for longestSpan");

  Span single(4);
  single.addNumber(42);
  testThrowShortSpan(single, "single-element span throws for shortestSpan");
  testThrowLongSpan(single, "single-element span throws for longestSpan");

  Span negative(6);
  negative.addNumber(-10);
  negative.addNumber(0);
  negative.addNumber(5);
  negative.addNumber(20);
  report(negative.shortestSpan() == 5, "mixed values shortest span is 5");
  report(negative.longestSpan() == 30, "mixed values longest span is 30");

  std::list<int> listValues;
  listValues.push_back(100);
  listValues.push_back(250);
  listValues.push_back(101);
  listValues.push_back(500);
  Span rangeFilled(4);
  rangeFilled.addNumber(listValues.begin(), listValues.end());
  report(rangeFilled.shortestSpan() == 1, "range insertion works with list iterators");
  report(rangeFilled.longestSpan() == 400, "range insertion longest span is correct");

  Span big(10000);
  std::vector<int> bigValues;
  bigValues.reserve(10000);
  for (int i = 0; i < 10000; ++i)
    bigValues.push_back(i);
  big.addNumber(bigValues.begin(), bigValues.end());
  report(big.size() == 10000, "big span stores 10000 numbers");
  report(big.shortestSpan() == 1, "big span shortest span is 1");
  report(big.longestSpan() == 9999, "big span longest span is 9999");

  Span duplicateSpan(3);
  duplicateSpan.addNumber(12);
  duplicateSpan.addNumber(12);
  duplicateSpan.addNumber(20);
  report(duplicateSpan.shortestSpan() == 0, "duplicate values give shortest span 0");
  report(duplicateSpan.longestSpan() == 8, "duplicate values give longest span 8");

  Span bulkOverflow(3);
  std::vector<int> tooMany;
  tooMany.push_back(1);
  tooMany.push_back(2);
  tooMany.push_back(3);
  tooMany.push_back(4);

  try {
    bulkOverflow.addNumber(tooMany.begin(), tooMany.end());
    report(false, "range insertion beyond capacity throws");
  } catch (const std::exception &) {
    report(true, "range insertion beyond capacity throws");
  }

  Span copied(sample);
  report(copied.shortestSpan() == sample.shortestSpan(), "copy constructor preserves data");
  Span assigned(1);
  assigned = negative;
  report(assigned.longestSpan() == negative.longestSpan(), "assignment operator preserves data");

  std::cout << "Failed tests: " << g_failedTests << std::endl;
  return g_failedTests == 0 ? 0 : 1;
}