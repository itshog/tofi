#ifndef SURFACE_H
#define SURFACE_H

#include <stdbool.h>
#include <stdint.h>
#include <wayland-client.h>
#include "color.h"
#include "image.h"

struct surface {
	struct wl_surface *wl_surface;
	struct wl_shm_pool *wl_shm_pool;
	int32_t width;
	int32_t height;
	int32_t stride;
	int index;
	struct wl_buffer *buffers[2];

	int shm_pool_size;
	int shm_pool_fd;
	uint8_t *shm_pool_data;
	bool redraw;
};

void surface_initialise(
		struct surface *surface,
		struct wl_shm *wl_shm,
		struct image *texture);
void surface_destroy(struct surface *surface);
void surface_draw(
		struct surface *surface,
		struct color *color,
		struct image *texture);

#endif /* SURFACE_H */
