#include "tester.h"

char to_upper_indexed(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

void test_ft_strmapi(void)
{
	log_start("ft_strmapi");

	struct {
		const char *input;
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"hello", "HELLO", "Basic lowercase"},
		{"123abc", "123ABC", "Mixed"},
		{"", "", "Empty string"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char *got = ft_strmapi(test_cases[i].input, to_upper_indexed);
		int passed = got && strcmp(got, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_strmapi(\"%s\") | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].input,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			got ? got : "NULL");

		free(got);
	}

	log_end();
}
