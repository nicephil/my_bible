static int a;
extern int b;

void bar ()
{
    a = 1;
    b = 2;
}

void foo ()
{
    bar ();
    ext ();
}
