#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img1;
    void    *img2;
    int     current_img;
    int     width;
    int     height;
    int     frame_count;  // Added to control animation timing
} t_data;

// Function to swap between images with delay
int animate(t_data *data)
{
    // Increment frame counter
    data->frame_count++;
    
    // Change image every 50 frames (adjust this number to change delay)
    if (data->frame_count >= 50)
    {
        data->frame_count = 0;  // Reset counter
        
        if (data->current_img == 1)
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img2, 0, 0);
            data->current_img = 2;
        }
        else
        {
            mlx_put_image_to_window(data->mlx, data->win, data->img1, 0, 0);
            data->current_img = 1;
        }
    }
    
    // Add a small sleep to control overall animation speed
    usleep(1000);  // 1000 microseconds = 1 millisecond
    return (0);
}

// Handle window close
int close_window(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img1);
    mlx_destroy_image(data->mlx, data->img2);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int main(void)
{
    t_data  data;
    int     img_width;
    int     img_height;

    data.width = 800;
    data.height = 600;
    data.frame_count = 0;  // Initialize frame counter
    data.current_img = 1;  // Start with first image
    
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    
    data.win = mlx_new_window(data.mlx, data.width, data.height, "Animation");
    
    // Load your two images - replace paths with your actual image paths
    data.img1 = mlx_xpm_file_to_image(data.mlx, "image1.xpm", &img_width, &img_height);
    data.img2 = mlx_xpm_file_to_image(data.mlx, "image2.xpm", &img_width, &img_height);
    
    if (!data.img1 || !data.img2)
    {
        if (data.img1)
            mlx_destroy_image(data.mlx, data.img1);
        if (data.img2)
            mlx_destroy_image(data.mlx, data.img2);
        mlx_destroy_window(data.mlx, data.win);
        return (1);
    }
    
    // Display first image initially
    mlx_put_image_to_window(data.mlx, data.win, data.img1, 0, 0);
    
    // Set up hooks
    mlx_loop_hook(data.mlx, (void *)animate, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    
    mlx_loop(data.mlx);
    return (0);
}