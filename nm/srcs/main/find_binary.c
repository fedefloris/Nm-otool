#include "nm.h"

static char			**get_paths(t_nm *nm)
{
	char			**env;
	char			*env_string;
	int				len;

	env_string = NULL;
	env = nm->env;
	while (*env)
	{
		len = ft_strstr(*env, "=") - *env;
		if (len > 0)
		{
			if (!ft_strncmp(*env, "PATH", len))
			{
				env_string = *env;
				break ;
			}
		}
		env++;
	}
	if (env_string)
		return (ft_strsplit(env_string + 5, ':'));
	else
		return (NULL);
}

static void			binary_exists(t_nm *nm, char *binary, char **binary_path)
{
	int				i;
	char			**path;
	struct stat		stat;

	i = 0;
	path = NULL;
	if ((path = get_paths(nm)))
	{
		while (path[i])
		{
			if ((*binary_path = ft_strjoin(path[i++], binary)))
			{
				if (!lstat(*binary_path, &stat))
					break ;
				ft_strdel(binary_path);
			}
		}
		i = 0;
		while (path && path[i])
			ft_strdel(&path[i++]);
		free(path);
	}
	if (!*binary_path && !lstat(binary + 1, &stat))
		*binary_path = ft_strdup(binary + 1);
}

char				*find_binary(t_nm *nm, char *file_name)
{
	char			*tmp_file_name;
	char			*binary_path;
	
	binary_path = NULL;
	if (!nm->env)
		return (NULL);
	if (!(tmp_file_name = ft_strjoin("/", file_name)))
		return (NULL);
	binary_exists(nm, tmp_file_name, &binary_path);
	free(tmp_file_name);
	return (binary_path);
}
