#include <stdio.h>

void func (int a, int b, int c)
{
    while (1) {
        printf ("%d, %d, %d\n", a++, b++, c++);
        sleep (5);
    }
}
main ()
{
    func(1, 2, 3);
}
