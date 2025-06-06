#include "tester.h"

void to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void test_ft_striteri(void)
{
	log_start("ft_striteri");

	struct {
		char input[20];
		const char *expected;
		const char *reason;
	} test_cases[] = {
		{"hello", "HELLO", "Simple lowercase to uppercase"},
		{"Test123", "TEST123", "Mixed characters"},
		{"", "", "Empty string"},
	};

	size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

	for (size_t i = 0; i < num_tests; i++) {
		char buffer[20];
		strcpy(buffer, test_cases[i].input);

		ft_striteri(buffer, to_upper);

		int passed = strcmp(buffer, test_cases[i].expected) == 0;

		log_assert(passed,
			"ft_striteri(\"%s\") | (Reason: %s) expected=\"%s\", got=\"%s\"",
			test_cases[i].input,
			test_cases[i].reason && !passed ? test_cases[i].reason : "-",
			test_cases[i].expected,
			buffer);
	}

	log_end();
}
