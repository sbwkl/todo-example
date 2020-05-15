#include "csapp.h"

int main() {
  int i;
  char *filename = "target/myecho";
  char *argv[] = {"arg1", "arg2"};
  char *envp[] = {"TERM=emacs"};
  i = execve(filename, argv, envp);
}
