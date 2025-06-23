#include "tester.h"

void test_ft_split(void)
{
	log_start("ft_split");

	struct {
		const char *input;
		char delim;
		const char **expected;
		const char *reason;
	} test_cases[] = {
		{"hello world", ' ', 
			(const char *[]){ "hello", "world", NULL }, "Split by space"},
		{"a,b,c", ',', 
			(const char *[]){"a", "b", "c", NULL}, "Comma delimiter"},
		{"one,,three", ',', 
			(const char *[]){"one", "three", NULL}, "Empty segment"},
		{"", ' ', 
			(const char *[]){NULL}, "Empty string"}
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char **got = ft_split(test_cases[i].input, test_cases[i].delim);

		int passed = 1;
		for (int j = 0; test_cases[i].expected[j]; j++) {
			if (!got || !got[j] || strcmp(got[j], test_cases[i].expected[j]) != 0) {
				passed = 0;
				break;
			}
		}

		log_assert(passed,
			"ft_split(\"%s\", '%c') | (Reason: %s) expected first=\"%s\", got first=\"%s\"",
			test_cases[i].input,
			test_cases[i].delim,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected[0] ? test_cases[i].expected[0] : "(null)",
			got && got[0] ? got[0] : "(null)");

		if (got) {
			for (int j = 0; got[j]; j++)
				free(got[j]);
			free(got);
		}
	}

	log_end();
}
