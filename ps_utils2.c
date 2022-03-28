#include "push_swap.h"

int	count_w(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] && (s[i]!= c))
		i++;
	if (i > 0)
		w++;
	while (s[i - 1])
	{
		if (s[i] == c)
		{
			w++;
			while (s[i] == c)
				i++;
			if (!s[i])
				w--;
		}
		i++;
	}
	return (w);
}

static int	count_l(char const *s, int i, char c)
{
	unsigned int	l;

	l = 0;
	while (s[i] != c)
	{
		i++;
		l++;
	}
	return (l);
}

static char	**free_all(char **new_s, unsigned int l)
{
	while (l > 0)
	{
		free(new_s[l - 1]);
		l--;
	}
	free(new_s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new_s;
	unsigned int		i;
	int		l;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = 0;
	new_s = (char **)malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!new_s)
		return (NULL);
	while (s[i] && l < count_w(s, c))
	{
		while (s[i] == c)
			i++;
		new_s[l] = (char *)malloc(sizeof(char) * (count_l(s, i, c) + 1));
		if (!new_s[l])
			return (free_all(new_s, count_l(s, i, c)));
		new_s[l] = ft_substr(s, i, (count_l(s, i, c)));
		i = i + count_l(s, i, c); 
		l++;
	}
	new_s[l] = NULL;
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*substr;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	substr = (char *)malloc((len + 1) * sizeof(*s));
	if (!substr)
		return (NULL);
	while (i < start)
		i++;
	while (k < len)
	{
		substr[k] = s[i];
		i++;
		k++;
	}
	substr[k] = '\0';
	return (substr);
}