#include "tester.h"

void test_ft_calloc(void) {
    log_start("ft_calloc");

    struct {
        size_t nmemb;
        size_t size;
    } test_cases[] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
        {4, 4},
        {100, 1},
        {1, 100},
        {10, sizeof(int)},
        {5, 1000000},
        {SIZE_MAX, 2}, // overflow olmalı
        {2, SIZE_MAX}, // overflow olmalı
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        size_t nmemb = test_cases[i].nmemb;
        size_t size = test_cases[i].size;

        void *expected = calloc(nmemb, size);
        void *got = ft_calloc(nmemb, size);

        int passed = 0;

        if (!expected && !got) {
            passed = 1; // ikisi de NULL dönmüş
        } else if (expected && got) {
            passed = (memcmp(expected, got, nmemb * size) == 0);
        }
        log_assert(
            passed,
            "calloc(%zu, %zu)",
            nmemb, size
        );
        if (expected)
            free(expected);
        if (got)
            free(got);
    }
    log_end();
}