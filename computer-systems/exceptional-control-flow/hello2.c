#include <unistd.h>

int main() {
  /*
   * first argumemt mean stdout
   * second argument mean the print text
   * third argument mean size of text
   */
  write(1, "hello world\n", 13);
  _exit(0);
}
