#include "../include/include.h"

#include "../include/include.h"

void afflist(t_list *list, char *name)
{
    while (list)
    {
        printf("		--------------------\n\
		| Affichage %s  |\n\
		---------------------\n\
			%s\n", name, list->content);
        list = list->next;
    }
}

t_list *ft_lstadd(t_list **alst, t_list *new)
{
    t_list *tmp;

    tmp = *alst;
    if (tmp)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
    else
        *alst = new;
    return (new);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

char *ft_strchr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (!*s++)
            return (NULL);
    }
    return ((char *)s);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t i;

    i = 0;
    if (!s)
        return (NULL);
    if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char **ft_strsplit(char *str, char delim)
{
    char **tab;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    if (!(tab = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1))))
        return (NULL);
    while (str[i])
    {
        if (str[i] == delim)
        {
            tab[j] = ft_strsub(str, k, i - k);
            k = i + 1;
            j++;
        }
        i++;
    }
    tab[j] = ft_strsub(str, k, i - k);
    tab[j + 1] = NULL;
    return (tab);
}

void afftab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        printf("tab[%d] = %s et la taille = %d\n", i, tab[i], ft_strlen(tab[i]));
        i++;
    }
}


int	closed_elem(char *str, char c)
{
	int	i = 0;
	// int	start = 0;
	// int	end = ft_strlen(str) - 1;
	int	flag = 0;
	int counter = 0;
	char	*start = ft_strchr(str, c);
	if (start == NULL)
		return (1);
	while (start[i])
	{
		if (counter == 1 && start[i] == c)
		{
			counter = 0;
			flag = 0;
		}
		if (flag == 1 && start[i] == c)
		{
			counter = 1;
			flag = 0;
		}
		if (start[i] == c && counter != 1)
			flag = 1;
		i++;
	}
	return (counter);
}

int	checking_closed(char *tp)
{
	int	val_test = closed_elem(tp, '"');
	if (val_test == 0)
		return (0);
	val_test = closed_elem(tp, '\'');
	if (val_test == 0)
		return (-1);
	return (val_test);
}