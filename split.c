#include "push_swap.h"
#include <stddef.h>

int	count_words(char *str, char sep);
static char	*get_next_word(char *str, char sep);
char	**ft_split(char *str, char sep);

int	count_words(char *str, char sep)
{
	int	count;
	int	inside;
	int	i;

	inside = i = count = 0;
	while(str[i])
	{
		while(str[i] == sep && str[i])
			i++;
		while(str[i] != sep && str[i])
		{
			if (!inside)
			{
				count++;
				inside = 1;
			}
			i++;
		}
		inside = 0;
	}
	return (count);
}

static char	*get_next_word(char *str, char sep)
{
	static int	i = 0;
	char		*next_word;
	int			word_len;
	int			k;

	word_len = k = 0;
	while(str[i] == sep)
		i++;
	while(str[i + word_len] != sep && str[i + word_len])
		word_len++;
	next_word = malloc((size_t)word_len * sizeof(char) + 1);
	while(str[i] != sep && str[i])
		next_word[k++] = str[i++];
	next_word[k] = '\0';
	return (next_word);
}

char	**ft_split(char *str, char sep)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, sep);
	if (!words_number)
		exit(1);
	vector_strings = malloc((size_t)(words_number + 2) * sizeof(char *));
	if (!vector_strings)
		return (NULL);
	while(words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, sep);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}

// # include <stdio.h>
// int main (int ac,char **av)
// {
// 	int a;
// 	int i = 0;
// 	a =  count_words(av[1], ' ');
// 	printf("%d\n", a);
// 	av = ft_split(av[1], ' ');

// 	while(av[++i])
// 		printf("%s\n",av[i]);
// }