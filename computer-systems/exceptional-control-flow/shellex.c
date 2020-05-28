#include "csapp.h"
#define MAXARGS 128

void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);

int main() {
  char cmdline[MAXLINE];

  while(1) {
    printf("> ");
    Fgets(cmdline, MAXLINE, stdin);
    if (feof(stdin)) {
      exit(0);
    }
    eval(cmdline);
  }
}

void eval(char *cmdline) {
  char *argv[MAXARGS];
  char buf[MAXLINE];
  int bg;                   /* run in background or not */
  pid_t pid;                /* process id */
  extern char** environ;

  strcpy(buf, cmdline);
  bg = parseline(buf, argv);
  if (argv[0] == NULL) {
    return;
  }
  int i;
  for (i = 0; i < MAXARGS; i++) {
    if (argv[i] == NULL) {
      break;
    }
    /* print argv for debug
    printf("argv[%d] = %s\n", i, argv[i]);
    */
  }
  if (builtin_command(argv)) {
    /* print for debug
    printf("fork new process exec %s\n", argv[0]);
    */
    if ((pid = Fork()) == 0) {   /* child runs user job */
      if (execve(argv[0], argv, environ) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(0);
      }
    }
  
    /* parent waits for foreground job to terminate */
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

/* if first arg is a builtin command */
int builtin_command(char **argv) {
  if (!strcmp(argv[0], "quit")) {
    exit(0);
  }
  if (!strcmp(argv[0], "&")) {
    return 1;
  }
  if (!strcmp(argv[0], "/usr/bin/ls")) {
    return 1;
  }
  return 0;
}

/* parse the command line and build the argv array */
int parseline(char *buf, char **argv) {
  char *delim;
  int argc;
  int bg;

  buf[strlen(buf) - 1] = ' ';
  while (*buf && (*buf == ' ')) {
    buf++;
  }

  argc = 0;
  while ((delim = strchr(buf, ' '))) {
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
