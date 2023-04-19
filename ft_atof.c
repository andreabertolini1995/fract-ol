#include "fract_ol.h"

static char	*ft_malloc_str(char const *s, char c, int substr_start)
{
	char	*str;
	int		substr_end;

	substr_end = substr_start;
	while (s[substr_end] != c && s[substr_end] != '\0')
		substr_end++;
	str = (char *) malloc (sizeof(char) * (substr_end - substr_start + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

static int	ft_count_substrs(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	if (strlen(s) == 0)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (i != 0)
		{
			if (s[i] == c && s[i - 1] != c)
				count++;
		}
		i++;
	}
	if (s[strlen(s) - 1] == c)
		count = count - 1;
	return (count);
}

static void	ft_fill_array2(char **arr, char *str, int j, int k)
{
	str[j] = '\0';
	arr[k] = str;
}

static void	ft_fill_array(char **arr, char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str = ft_malloc_str(s, c, i);
			j = 0;
			while (s[i] != c && s[i] != '\0')
			{
				str[j] = s[i];
				i++;
				j++;
			}
			ft_fill_array2(arr, str, j, k);
			k++;
		}
		if (s[i] != '\0')
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		num_substr;

	num_substr = ft_count_substrs(s, c);
	arr = (char **) malloc (sizeof(char *) * (num_substr + 1));
	if (arr == NULL)
		return (NULL);
	ft_fill_array(arr, s, c);
	arr[num_substr] = 0;
	return (arr);
}

static double calc_divider(int length)
{
	int i;
	int n;

	i = 1;
	n = 10;
	while (i < length)
	{
		n = n * 10;
		i++;
	}
	return (n);
}

int is_char_in_str(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

double  ft_atof(char *str)
{
	char    **strs;
	int     n;
	int     m;
	double  result;

	if (!is_char_in_str(str, '.'))
		result = atoi(str);
	else
	{
		strs = ft_split(str, '.');
		n = abs(atoi(strs[0]));
		m = atoi(strs[1]);
		result = m / calc_divider(strlen(strs[1])) + n;
		if (str[0] == '-')
		{
			printf("Minus present.\n");
			return (-result);
		}
	}
	return (result);
}
