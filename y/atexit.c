# include<stdio.h>
# include<stdlib.h>
static void f1(void) {
	printf("f1 working\n");
}
static void f2(void) {
	printf("f2 working\n");
}
static void f3(void) {
	printf("f3 working\n");
}

int main(int argc, char **argv) {
	printf("begin\n");
  atexit(f1);
  atexit(f2);
  atexit(f3);
  printf("end\n");
  exit(0);
}
