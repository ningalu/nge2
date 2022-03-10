#ifndef _TESTS_TESTING_H
#define _TESTS_TESTING_H

enum class TestResult {
    PASS,
    FAIL
};

#define ASSERT(result) { \
    if (!result) { \
        return TestResult::FAIL; \
    } \
} \


#endif