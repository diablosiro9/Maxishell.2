#include "../include/include.h"

unsigned int	starter_env(char *s)
{
	unsigned int	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

t_env *get_env(char **env)
{
    int i = 0;
    t_env *list = NULL;
    list = malloc(sizeof(t_env)* 100);
   
   while (env[i])
    {
        list[i].name = ft_strsub(env[i], 0, ft_strchr(env[i], '=') - env[i]);
        list[i].content =  ft_strsub(env[i], starter_env(env[i]), ft_strlen(env[i] -  (env[i] - ft_strchr(env[i], '='))));
		i++;
    }
    return (list);
}

t_list	dquote_mod(char *tp, int flag)
{
	char	*stock = NULL;
	t_list	*temp = ft_lstnew((void *)tp);
	t_list	*cmd = malloc(sizeof(t_list *) * 1);
	t_list	*save = cmd;

	cmd = ft_lstnew((void *)tp);
	while (42)
	{
	 	ft_putstr("dquote>");
        stock = get_next_line(0);
		printf("Yes or not\n");
		temp = (void *)stock;
		printf("Maybe\n");
		ft_lstadd(&cmd, temp);
		printf("reeee\n");
		if (flag == -1)
		{
			if (ft_strchr(stock, '\''))
			{
				cmd->next = NULL;
				return (*save);
			}
		}
		if (flag == 0)
		{
			printf("la\n");
			if (ft_strchr(stock, '"'))
			{
				cmd->next = NULL;
				return (*save);
			}
		}
		printf("see u\n");
		// printf("history->content = %s\n", history->content);
		// *history = (*history)->next;
        //printf("La commande que tu tape = %s\n", str);
        // lexer(str);
	}
}

t_list *lexer(t_list *str)
{
    t_list *list;
    t_list *tmp = malloc(sizeof(t_list) * 100);
	t_list cmd_quote;
    char **tab;
	char *tp = (char *)str->content;
	int	val_test = 0;
	val_test = checking_closed(tp);
	printf("val_Test = %d\n", val_test);
	if (val_test == 0 || val_test == -1)
	{
		cmd_quote = dquote_mod(tp, val_test);
		printf("command not found:");
		afflist(&cmd_quote, "COMMAND");
	}
    int i = 0;
    tab = ft_strsplit(tp, ' ');
    while (tab[i])
    {
        list = ft_lstnew(tab[i]);
        list->next = tmp;
        tmp = list;
        i++;
    }
	// afftab(tab);
    // afflist(list, "Lexer");
    return (list);
}


int main(int ac, char **av, char **env)
{
    t_env *list;
	t_list	*history = NULL;
    t_list *str = NULL;
	history = ft_lstnew(NULL);
    list = get_env(env);
    (void)ac;
    (void)av;
	int	i = 0;

	while (list[i].name)
	{
		printf("Env[i] -- >%s\n", list[i].content);
		i++;
	}
    while (42)
	{
		printf("0\n");
	 	ft_putstr("minishell>");
        str = ft_lstnew(get_next_line(0));
		printf("1\n");
		ft_lstadd(&history, str);
		// afflist(history, "History");
		// printf("history->content = %s\n", history->content);
		// *history = (*history)->next;
        //printf("La commande que tu tape = %s\n", str);
		// printf("je vois avant lexer\n");
        lexer(str);
	}
    return (0);
}