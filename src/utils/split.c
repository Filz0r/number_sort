#include "../../includes/c_lists.h"
#include <string.h>

static int is_ws(char c) 
{
	return (c == 32 || c == '\t');
}

static int count_words(char *str)
{
	int result = 0, i = 0;
	while (str[i])
	{
		while (is_ws(str[i]))
			i++;
		if (str[i] != '\0' && !is_ws(str[i]))
			result++;
		while (str[i] && !(is_ws(str[i])))
			i++;
	}
	return (result);
}

static int get_word_end(char *str, int pos)
{
	while (str[pos] && !(is_ws(str[pos])))
		pos++;
	return (pos);
}

static char	*get_word(char *str, int *pos)
{
	int	k = 0, i = 0;
	int	wl;
	char	*word;

	if (*pos > 0)
		i = *pos;
	wl = get_word_end(str, i) - i;
	if (wl > 0)
	{
		word = (char *)malloc(sizeof(char) * (wl + 1));
		if (!word)
			errors(3);
		while (i < *pos + wl)
			word[k++] = str[i++];
		word[k] = '\0';
		*pos = i;
	}
	else 
		return (get_word(str, ((*pos)++, pos)));
	return (word);	
}

char	**ft_split(char *str)
{
	int	i = 0, k = 0, words;
	char	**result;

	words = count_words(str);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		errors(3);
	while (i < words)
	{
		if (k <= (int)strlen(str))
			result[i] = get_word(str, &k);
		i++;
	}
	result[i] = 0;
	return (result);
}
