#include "shell.h"

/**
<<<<<<< HEAD
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: file path
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

=======
 * parse_args - parse arguments
 * @cmd: tokenized string with arguments
 * @del: delimeter
 * @args: argument vector
 * @mod: delimeter method 0-character 1-string
 *
 * Return: none
 */

void parse_args(char *cmd, const char *del, char ***args, int mod)
{
	char *tokenized = NULL, **tmp, *trimmed_arg;
	int index = 0, i;

	*args = NULL;
	tokenized = _strtok(cmd, del, mod);
	while (tokenized != NULL)
	{
		tmp = (char **)_malloc((_arlen(*args) +  2) * sizeof(char *));
		if (!*args)
			*args = tmp;
		else
		{
			i = 0;
			while ((*args)[i])
			{
				tmp[i] = _strdup((*args)[i]);
				i++;
			}
			free_pp(*args);
			*args = tmp;
		}
		(*args)[index] = NULL;
		trimmed_arg = tokenized;
		if ((tokenized[0] == '"' && tokenized[_strlen(tokenized) - 1] == '"') ||
				(tokenized[0] == '\'' && tokenized[_strlen(tokenized) - 1] == '\''))
		{
			trimmed_arg = _strdup(tokenized + 1);
			trimmed_arg[_strlen(trimmed_arg) - 1] = '\0';
		}
		trim_spaces(&((*args)[index]), trimmed_arg);
		(*args)[index + 1] = NULL;
		if (trimmed_arg != tokenized)
			free(trimmed_arg);
		tokenized = _strtok(NULL, del, mod);
		index++;
	}
}
>>>>>>> 1f3bcad18655b25f551e5308149ec66393471cef
