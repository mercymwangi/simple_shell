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


<<<<<<< HEAD

/* toem_shloop.c */

void fork_cmd(info_t *);
int hsh(info_t *, char );
int find_builtin(info_t *);
void find_cmd(info_t *);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char );

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_errors.c */
int _putsfd(char *str, int fd);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char );
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_tokenizer.c */
char strtow(char *, char *);
char **strtow2(char *, char);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* for read/write buffers */
#define READ_BUF_SIZE 4096
#define WRITE_BUF_SIZE 4096
#define BUF_FLUSH -1

/* toem_builtin.c */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* toem_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char , size_t *);
void sigintHandler(int);
=======
/* main */
extern void non_interactive(void);
extern void init(char **current_cmd, int cmd_type);
>>>>>>> b2efa39ac5e91a65f324e5d8a555a33c6f8702d6

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
