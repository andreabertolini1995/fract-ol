#include <stdio.h>

// 'Encodes' four individual bytes into an int.
int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int main()
{
    printf("%d\n", get_rgba(234, 234, 234, 1));
}