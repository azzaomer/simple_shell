#include "shell.h"

/**
 * hsh - main shell loop
 * @info: the parameter and return info struct
 * @av" the argument vector from main()
 *
 * REturn: 0if success, 1 if error
 */

int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int bultin_ret = 0;

	while (r  != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if(interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);

