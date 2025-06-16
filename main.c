#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void	*dup_uppercase(void *content)
{
	char *str = (char *)content;
	char *new_str = ft_strdup(str);
	if (!new_str)
		return NULL;
	for (int i = 0; new_str[i]; i++)
		new_str[i] = toupper(new_str[i]);
	return new_str;
}

void exiteri(unsigned int i __attribute__((unused)), char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	free_content(void *content)
{
	free(content);
}

int	main()
{
	// t_list *a __attribute__((unused)) = ft_lstnew(ft_strdup("ilk"));
	// t_list *b __attribute__((unused)) = ft_lstnew(ft_strdup("ikişci"));
	// t_list *c __attribute__((unused)) = ft_lstnew(ft_strdup("ücücncü"));

	// ft_lstadd_back(&a, b);
	// ft_lstadd_back(&a, c);

	// t_list *mapped = ft_lstmap(a, dup_uppercase, free_content);

	// // Yazdırmak için:
	// t_list *tmp = mapped;
	// while (tmp)
	// {
	// 	printf("%s\n", (char *)tmp->content);
	// 	tmp = tmp->next;
	// }

	// // Temizle
	// ft_lstclear(&a, free_content);
	// ft_lstclear(&mapped, free_content);

	/* char *str = "---hello--";
	printf("%s", ft_strtrim(str, "-"));
	
	char *inputs[] = {
		"hello world",
		"   hello  world  ",
		"",
		"a,,b,c",
		"a,b,c",
		",",
		"abc,",
		",abc",
		"abc,,def",
		NULL
	};

	for (int i = 0; inputs[i]; i++) {
		printf("Input: \"%s\"\n", inputs[i]);
		char **arr = ft_split(inputs[i], ',');
		int i = 0;
		while (arr && arr[i])
			printf("[%s]\n", arr[i++]);
		printf("---\n");
	} */
	char *s = "hello world";
	char *new = ft_substr(s, 13, 5);
	printf("%s", new);
	free(new);
}
