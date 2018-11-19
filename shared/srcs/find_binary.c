#include "nm_otool.h"

static char		**get_paths(char **env)
{
	char			*env_string;
	int				len;

	env_string = NULL;
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

static void		binary_exists(char **env, char *binary, char **binary_path)
{
	struct stat		stat;
	char			**path;
	int				i;

	i = 0;
	path = NULL;
	if ((path = get_paths(env)))
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

char			*find_binary(t_nm_otool *nm_otool)
{
	char			*tmp_file_name;
	char			*binary_path;

	binary_path = NULL;
	if (!nm_otool->env)
		return (NULL);
	if (!(tmp_file_name = ft_strjoin("/", nm_otool->file.name)))
		return (NULL);
	binary_exists(nm_otool->env, tmp_file_name, &binary_path);
	free(tmp_file_name);
	return (binary_path);
}
