#include <iostream>
#include <stdarg.h>
using namespace std;

void foo(int n, ...) {
	va_list ap;
	va_start(ap, n);
	int para;
	for(int i = 0; i < n; i++) {
		para = va_arg(ap, int);
		cout << para << endl;
	}
	va_end(ap);
}

int main() {
	foo(6,100,101,102,103,104,105);
	return 0;
}
