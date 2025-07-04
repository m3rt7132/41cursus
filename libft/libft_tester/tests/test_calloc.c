#include "tester.h"

void test_ft_calloc(void)
{
    log_start("ft_calloc");

	struct {
    	size_t nmemb;
    	size_t size;
    	const char *reason;
	} test_cases[] = {
		{0, 0, "0 0 should return 1 byte alloc"},
    	{1, 1, "Minimum allocation of 1 byte"},
    	{10, 4, "Normal allocation of 10 integers"},
    	{0, 4, "Zero nmemb should return NULL or equivalent"},
    	{4, 0, "Zero size should return NULL or equivalent"},
    	{1000000, 1000000, "Large allocation to test overflow"},
    	{SIZE_MAX, 2, "Overflow test with huge nmemb"},
    	{2, SIZE_MAX, "Overflow test with huge size"},
	};

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        size_t nmemb = test_cases[i].nmemb;
        size_t size = test_cases[i].size;
        const char *reason = test_cases[i].reason;

        void *expected = calloc(nmemb, size);
        void *got = ft_calloc(nmemb, size);

        int passed = 0;

        if (!expected && !got) {
            passed = 1;
        } else if (expected && got) {
            passed = (memcmp(expected, got, nmemb * size) == 0);
        }

		log_assert(passed, "ft_calloc(%zu, %zu) | (Reason: %s)  &expected=%p, &got=%p", nmemb, size,
			reason && !passed ? reason : "-", got);
        if (expected)
            free(expected);
        if (got)
            free(got);
    }
    log_end();
}