#include "rayTracing.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 600, 400, "RayTracing");
    mlx_pixel_put(mlx, win, 300, 200, 0xffff00);
    mlx_loop(mlx);
    return (printf("Ray Tracing!\n"), 0);
}