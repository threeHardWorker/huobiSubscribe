#include <stdio.h>
#include <stdlib.h>
#include "WebSocketClient.h"
#include <unistd.h>

/*#include "include/uv.h"

int main() {
    uv_loop_t *loop = (uv_loop_t*)malloc(sizeof(uv_loop_t));
    uv_loop_init(loop);

    printf("Now quitting.\n");
    uv_run(loop, UV_RUN_DEFAULT);

    uv_loop_close(loop);
    free(loop);
    return 0;
}*/

int main()
{
    WebSocketClient w("ws://localhost:9002");
    while(1)
    {
        sleep(10);
    }
}
