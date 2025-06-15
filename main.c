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

void	free_content(void *content)
{
	free(content);
}

int	main()
{
	// t_list *a __attribute__((unused)) = ft_lstnew(ft_strdup("hello"));
	// t_list *b __attribute__((unused)) = ft_lstnew(ft_strdup("world"));
	// t_list *c __attribute__((unused)) = ft_lstnew(ft_strdup("libft"));

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

	// char *str = "---hello--";
	// printf("%s", ft_strtrim(str, "-"));
	
	// char *inputs[] = {
	// 	"hello world",
	// 	"   hello  world  ",
	// 	"",
	// 	"a,,b,c",
	// 	"a,b,c",
	// 	",",
	// 	"abc,",
	// 	",abc",
	// 	"abc,,def",
	// 	NULL
	// };

	// for (int i = 0; inputs[i]; i++) {
	// 	printf("Input: \"%s\"\n", inputs[i]);
	// 	char **arr = ft_split(inputs[i], ',');
	// 	int i = 0;
	// 	while (arr && arr[i])
	// 		printf("[%s]\n", arr[i++]);
	// 	printf("---\n");
	// }
	int a = ft_strncmp("test\200", "test\0", 6);
	printf("%d", a);
	
}
