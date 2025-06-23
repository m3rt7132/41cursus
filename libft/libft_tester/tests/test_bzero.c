#include "tester.h"

void test_ft_bzero() {
    log_start("ft_bzero");

	struct {
    	const char *desc;
    	size_t size;
    	size_t n;
    	const char *reason;
	} test_cases[] = {
    	{"Zero middle of array", 10, 5, "Zero first 5 bytes of a 10-byte buffer"},
    	{"Zero full array", 8, 8, "Entire buffer should be zeroed"},
    	{"Zero nothing", 6, 0, "Zeroing 0 bytes should leave buffer unchanged"},
    	{"Zero more than size", 4, 10, "Trying to zero beyond buffer size (undefined behavior test)"},
	};

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        size_t size = test_cases[i].size;
        size_t n = test_cases[i].n;
        const char *desc = test_cases[i].desc;
        const char *reason = test_cases[i].reason;

        unsigned char *expected = malloc(size);
        unsigned char *got = malloc(size);
        if (!expected || !got) {
            log_error("ft_bzero() Malloc Fail");
            exit(EXIT_FAILURE);
        }

        for (size_t j = 0; j < size; j++) {
            unsigned char val = (unsigned char)(65);
            expected[j] = val;
            got[j] = val;
        }

        bzero(expected, n);
        ft_bzero(got, n);

        int passed = memcmp(expected, got, size) == 0;

        log_assert(passed, "ft_bzero(\"%s\") | (Reason: %s) size=%zu, n=%zu", desc,
			reason && !passed ? reason : "-", size, n);

        free(expected);
        free(got);
    }
    log_end();
}