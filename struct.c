#include <stdio.h>

/*
struct foo{
	int a;
	char x;
};
*/
struct foo {int a; char x;};

void printfoo(struct foo *f);
struct foo * make_foo(int i, char c);

int main() {
	//struct foo h = make_foo(100, 'q');
	//printfoo(&h);
	/*
	The above^^ seems fine BUT IS NOT FINE.
	This is because it is making too many copies and is not efficient enough.
	When you return a struct, you're making a unnecessary copy;
	TO FIX, make a pointer:
	*/
	struct foo * h = make_foo(100, 'q');
	/*
	Still a problem since n is a local variable.
	*/
	
	struct foo s;
	struct foo g;
	
	s.a = 137;
	s.x = '+';
	
	//printfoo(s);
	//When you pass struct as an argument, you're making a unnecessary copy.
	printfoo(&s);
	
	g = s;
	s.a = 0;
	//printfoo(s);
	//printfoo(g);
	printfoo(&s);
	printfoo(&g);
	
	//printf("int a in struct foo: %d \t char x in struct foo: %c \n", s.a, s.x);
	
	return 0;
}

void printfoo(struct foo *f) {
	//printf("int: %d \t char: %c \n", f.a, f.x);
	//printf("int: %d \t char: %c \n", (*f).a, (*f).x);
	//or (it's the same as)
	printf("int: %d \t char: %c \n", f->a, f->x);
	
}

struct foo * make_foo(int i, char c) {
	struct foo n;
	n.a = i;
	n.x = c;
	return &n;
}



