/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kato <kato@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:00:00 by kato              #+#    #+#             */
/*   Updated: 2025/05/09 00:54:22 by kato             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_zoom(t_fractal *f, double mouse_re, double mouse_im,
		double zoom_factor)
{
	double	new_zoom;

	new_zoom = f->zoom * zoom_factor;
	if (new_zoom < 0.01 || new_zoom > 1000.0)
		return ;
	f->offset_x = mouse_re - (mouse_re - f->offset_x) * zoom_factor;
	f->offset_y = mouse_im - (mouse_im - f->offset_y) * zoom_factor;
	f->zoom = new_zoom;
}

void	handle_zoom(t_fractal *f, int button, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	mouse_im = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
	if (button == ZOOM_IN)
		zoom_factor = 0.9;
	else if (button == ZOOM_OUT)
		zoom_factor = 1.1;
	else
		return ;
	update_zoom(f, mouse_re, mouse_im, zoom_factor);
}
