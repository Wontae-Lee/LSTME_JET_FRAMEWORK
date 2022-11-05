#ifndef SRC_TESTS_PERF_TESTS_PERF_TESTS_H_
#define SRC_TESTS_PERF_TESTS_PERF_TESTS_H_
#include <string>
#include <utility>
#include <vector>
void
printMemReport(double memUsage, const std::string& memMessage);
size_t
getCurrentRSS();
std::pair<double, std::string>
makeReadableByteSize(size_t bytes);

#endif // SRC_TESTS_PERF_TESTS_PERF_TESTS_H_
