#ifndef SHELL_H
#define SHELL_H

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* for command chaining */
#define CMD_NORM  0
#define CMD_OR    1
#define CMD_AND    2
#define CMD_CHAIN  3

/* for convert_number() */
#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED  2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE  ".simple_shell_history"
#define HIST_MAX  4096

extern char environ;


/*
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 * struct liststr - singly linked list
 */


typedef struct liststr
{
  int num;
  char *str;
  struct liststr *next;

} 

list_t;

/*
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ 
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct from ALL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */

typedef struct passinfo

{
  flag;
  char *fname;
  list_t *env;
  list_t *history;
  list_t *alias;
  char **environ;
  int env_changed;
  int status;

char *arg;
  char **argv;
  char *path;
  int argc;
  unsigned int line_count;
  int linecount_

  char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
  int cmd_buf_type; /* CMD_type ||, &&, ; */
} 

info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
    0, 0, 0}

/*
 * struct builtin - contains a builtin string 
 * @func: the function
 * @type: the builtin command flag
 */

typedef struct builtin
{
  char *type;
  int (*func)(info_t *);
} 

builtin_table;


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
int bfree(void );

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
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

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

#endif