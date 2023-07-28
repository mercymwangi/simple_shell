#ifndef SHELL_H_
#define SHELL_H_

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <signal.h>

/* for command chaining */
#define EXTERNAL_CMD 1
#define INTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * struct map - a struct that maps a command name to a function 
 *
 * @cmd_name: name of the command
 * @function: the function that executes the command
 */
typedef struct map
{
	char *cmd_name;
	void (*function)(char **cmd);
} function_map;

extern char **environ;
extern char *input;
extern char **cmds;
extern char name_of_shell;
extern int status; 


/* main */
extern void non_interactive(void);
extern void init(char **current_cmd, int cmd_type);

void execmd(char **argv);
char *get_path(char *cmd);
int stat(const char *pathname, struct stat *statbuf);
void exit(char **);
void current_env(char **);
char **tokenizer(char *str_input, char *del);
void std_output(char *str, int stream);
void delete_newline(char *str);
void _strcpy(char *str, char *dest);
int _strlen(char *str);
int parse_cmd(char *cmd);
void exec_cmd(char **tokenized_cmd, int type_cmd);
char *evaluate_path(char *cmd);
void (*get_function(char *cmd))(char **);
char *_getenv(char *name);
char *_strtok_r(char *str, char *del, char **std_ptr);
int _atoi(char *str);
void *_realloc(void *ptr, unsigned int initial_sz, unsigned int current_sz);
void ctrl_c_cmd(int signum);
void delete_comment(char *input);
int _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *str);
int _strspn(char *string1, char *string2);
int _strcspn(char *string1, char *string2);
char *_strchr(char *str, char c);


#endif
