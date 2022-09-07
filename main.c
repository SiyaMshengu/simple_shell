#include "main.h"
/**
 * main - Entry point
 *
 * @argc: not going to use it
 *
 * @argv: not going to use it
 *
 * @envp: takes environment variables
 *
 * Return: type int : 0 on SUCCESS
 * and exit with FAILURE
 */
int main(
		int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)),
		char *envp[]

		)
{
	char *copy_PATH, *copy_PWD;

	copy_PATH = malloc(sizeof(char *) * 50);
	if (copy_PATH == NULL)
	{
		free(copy_PATH);
		perror("./shell");
		exit(1);
	}
	copy_PWD = malloc(sizeof(char *) * 50);
	if (copy_PWD == NULL)
	{
		free(copy_PWD);
		perror("./shell");
		exit(1);
	}
	copy_from_envp(copy_PATH, copy_PWD, envp);
	/* copy_PATH = getenv("PATH"); */
/*	copy_PWD = getenv("PWD");*/
	loop(envp, copy_PATH, copy_PWD);
	free(copy_PATH);
	free(copy_PWD);
	exit(98);
	return (0);
}
