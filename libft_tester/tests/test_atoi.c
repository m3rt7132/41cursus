#include "tester.h"

void test_ft_atoi(FILE *log)
{
    const char *inputs[] = {
        "42", "-42", "0", "+42", "    123", "   -00123", "a42", "  +00123abc",
        "", "    ", "2147483647", "-2147483648", "9999999999", "-9999999999"
		};
	size_t	num_tests = sizeof(inputs) / sizeof(inputs[0]);
	printf("%zu", num_tests);
    fprintf(log, "Testing ft_atoi...\n");

    for (size_t i = 0; i < num_tests; ++i)
    {
        const char *input = inputs[i];
        int expected = atoi(input);
        int result = ft_atoi(input);

        if (expected != result)
        {
            fprintf(log, "[FAIL] input=\"%s\" | expected = %d | got = %d\n", input, expected, result);
            assert(expected == result);
        }
        else
        {
            fprintf(log, "[OK] input=\"%s\"\n", input);
        }
    }

    fprintf(log, "Done testing ft_atoi.\n\n");
}
