#include "shell.h"

/**
 * close - exits the shell
 * @intel: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int close(info_t *intel)
{
	int close_check;

	if (intel->argv[1])  /* If there is an exit arguement */
	{
		close_check = _erratoi(intel->argv[1]);
		if (close_check == -1)
		{
			intel->status = 2;
			print_error(intel, "number is unknown: ");
			_eputs(intel->argv[1]);
			_eputchar('\n');
			return (1);
		}
		intel->err_num = _erratoi(intel->argv[1]);
		return (-2);
	}
	intel->err_num = -1;
	return (-2);
}

/**
 * change - changes the current directory of the process
 * @intel: Structure containing potential arguments.
 *  Return: 0
 */
int change(info_t *intel)
{
	char *a, *rec, buffer[1024];
	int chrec;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!intel->argv[1])
	{
		rec = _getenv(intel, "HOME=");
		if (!rec)
			chrec = /* TODO: what should this be? */
				chdir((rec = _getenv(intel, "PWD=")) ? rec : "/");
		else
			chrec = chdir(rec);
	}
	else if (_strcmp(intel->argv[1], "-") == 0)
	{
		if (!_getenv(intel, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(intel, "OLDPWD=")), _putchar('\n');
		chrec = /* TODO: what should this be? */
			chdir((rec = _getenv(intel, "OLDPWD=")) ? rec : "/");
	}
	else
		chrec = chdir(intel->argv[1]);
	if (chrec == -1)
	{
		print_error(intel, "can't cd to ");
		_eputs(intel->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(intel, "OLDPWD", _getenv(intel, "PWD="));
		_setenv(intel, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * cd_process - changes the current directory of the process
 * @intel: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int cd_process(info_t *intel)
{
	char **arg_array;

	arg_array = intel->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
