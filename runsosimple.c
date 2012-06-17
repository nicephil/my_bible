#include <stdio.h>
#include <dlfcn.h>

int main (int argc, char *argv[])
{
    void *handle;
    double (*func)(dobule);
    char *error;

    handle = dlopen (argv[1], RTLD_NOW);
    if (NULL == handle) {
        printf ("open library %s error: %s\n", argv[1], dlerror());
        return -1;
    }

    func = dlsym (handle, "sin");
    if ((error = dlerror()) != NULL) {
        printf ("symbol sin not found: %s\n", error);
        goto exit_runso;
    }

    printf ("%f\n", func(3.1415926/2));
exit_runso:
    dlclose (handle);

    return 0;
}
