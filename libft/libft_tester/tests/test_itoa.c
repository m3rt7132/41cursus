#include "tester.h"

void test_ft_itoa(void)
{
	log_start("ft_itoa");

	struct
	{
		int input;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{0, "0", "Zero should return \"0\""},
		{42, "42", "Positive number"},
		{-42, "-42", "Negative number"},
		{2147483647, "2147483647", "INT_MAX"},
		{-2147483648, "-2147483648", "INT_MIN"},
		{1, "1", "Single-digit positive"},
		{-1, "-1", "Single-digit negative"},
		{1000, "1000", "Four-digit positive"},
		{-1000, "-1000", "Four-digit negative"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (size_t i = 0; i < num_tests; i++) {
        int input = test_cases[i].input;
        const char *expected = test_cases[i].expected;
        const char *reason = test_cases[i].reason;

		char *result = ft_itoa(input);

		int passed = 0;

		if (strcmp(result, expected) == 0)
			passed = 1;
		
		log_assert(passed, "ft_itoa(%d) | (Reason: %s) expected=%s, got=%s", input,
			reason && !passed ? reason: "-", expected, result);

		free(result);
	}
}