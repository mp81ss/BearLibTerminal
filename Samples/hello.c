/*
 * Install mesa-common-dev, libgl-dev
 * gcc -DBEARLIBTERMINAL_STATIC_BUILD -Wall -pedantic -Wformat=2 -Wshadow -Wbad-function-cast -Wimplicit-fallthrough -I ..\Terminal\Include\C -L ..\bin\static -O3 -s -oh hello.c -lBearLibTerminal -lstdc++ -lFreeType2 -lPicoPng -lopengl32 -lwinmm -lgdi32
 */

#include <BearLibTerminal.h>


int main(void)
{
    const int ok = terminal_open(); 

    if (ok) {
        int code;

        terminal_print(1, 1, "Hello, world!");
        terminal_refresh();

        do code = terminal_read(); while (code != TK_CLOSE && code != TK_ESCAPE);

        terminal_print(1, 2, "Bye!");
        terminal_refresh();

        terminal_delay(1000);

        terminal_close();
    }
    else {
        puts("Unable to init BearLibTerminal");
    }

    return ok ? 0 : 1;
}
