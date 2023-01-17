#include "cub3D.h"

void    error_msg(char *str)
{
    ft_putendl_fd("Error", 2);
    ft_putendl_fd(str, 2);
}

void    free_tab_char(char **tab)
{
    int    i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int    filled_color(char *name, t_parse *parse, char **color)
{
    int    i;

    i = 0;
    if (!ft_strncmp(name, "F", 2))
    {
        while (i < 3)
        {
            if (parse->F[i] != -1)
            {
                error_msg("Color F is in double");
                return (0);
            }
            parse->F[i] = ft_atoi(color[i]);
            i++;
        }
    }
    else if (!ft_strncmp(name, "C", 2))
    {
        while (i < 3)
        {
            if (parse->C[i] != -1)
            {
                error_msg("Color C is in double");
                return (0);
            }
            parse->C[i] = ft_atoi(color[i]);
            i++;
        }
    }
    return (1);
}

int    init_color(char **tab, t_parse *parse)
{
    char **color;
    int    i;
    int    j;

    color = ft_split(tab[1], ',');
    i = 0;
    while (color[i])
    {
        j = 0;
        while(color[i][j])
        {
        	printf("digit = %c\n", color[i][j]);
            if(!ft_isdigit(color[i][j]))
            {
                error_msg("Color need only positive number");
                return (0);
             }
            j++;
        }
        i++;
    }
	if (i != 3)
	{
       	 error_msg("Color need 3 arguments");
		return (0);
	}
    if (!filled_color(tab[0], parse, color))
    	return (0);
    free_tab_char(color);
    return (1);
}
