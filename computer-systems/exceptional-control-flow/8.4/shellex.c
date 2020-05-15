#include "csapp.h"
#define MAXARGS 128
#define MAXLINE 128

void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

int main() {
  char cmdline[MAXLINE];

  while(1) {
    printf("> ");
    fgets(cmdline, MAXLINE, stdin);
    if (feof(stdin)) {
      exit(0);
    }
    printf("cmdline = %s\n", cmdline);
    eval(cmdline);
  }
}

void eval(char *cmdline) {
  char *argv[MAXARGS];
  char buf[MAXLINE];
  int bg;
  pid_t pid;
  extern char** environ;

  strcpy(buf, cmdline);
  bg = parseline(buf, argv);
  printf("argv[0] = %s\n", argv[0]);
  if (argv[0] == NULL) {
    return;
  }

  if (!builtin_command(argv)) {
    printf("start fork\n");
    if ((pid = Fork()) == 0) {
      if (execve(argv[0], argv, environ) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(0);
      }
    }
  
    if (!bg) {
      int status;
      if (waitpid(pid, &status, 0) < 0) {
        unix_error("waitfg: waitpid error");
      }
    } else {
      printf("%d %s", pid, cmdline);
    }
  }
  return;
}

int builtin_command(char **argv) {
  if (!strcmp(argv[0], "quit")) {
    exit(0);
  }
  if (!strcmp(argv[0], "&")) {
    return 1;
  }
  return 0;
}

int parseline(char *buf, char **argv) {
  printf("buf = %s", buf);
  char *delim;
  int argc;
  int bg;

  buf[strlen(buf) - 1] == ' ';
  while (*buf && (*buf == ' ')) {
    buf++;
  }

  argc = 0;
  while ((delim = strchr(buf, ' '))) {
    printf("delim = %s\n", delim)
    argv[argc++] = buf;
    *delim = '\0';
    buf = delim + 1;
    while (*buf && (*buf == ' ' )) {
      buf++;
    }
  }
  argv[argc] = NULL;

  if (argc == 0) {
    return 1;
  }

  if ((bg = (*argv[argc -1] == '&')) != 0) {
    argv[--argc] = NULL;
  }
  return bg;
}