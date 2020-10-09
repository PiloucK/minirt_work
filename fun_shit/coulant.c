void
    ray_bounce(t_ray *ray, t_info *info, t_elem_list *hit_elem, double closest, int *i)
{
    t_elem_list     *cur_elem;
    t_vec3lf        origin;
    t_ray           incoming_ray;
    t_light         *cur_light;
    int             light_participation;

    (void)closest;
    (void)cur_elem;
    (void)cur_light;
    (void)light_participation;
    (void)origin;
    (void)info;
    i++;
    (void)incoming_ray;
    if (hit_elem)
    {
        incoming_ray = *ray;
        incoming_ray.color = (*(t_sphere *)(hit_elem->elem_detail)).color.r;
        incoming_ray.color = (incoming_ray.color << 8) + (*(t_sphere *)(hit_elem->elem_detail)).color.g;
        incoming_ray.color = (incoming_ray.color << 8) + (*(t_sphere *)(hit_elem->elem_detail)).color.b;
        // origin = vectranslat(ray->pos, ray->dir, closest);
        // cur_elem = info->first_elem;
        // while (cur_elem)
        // {
        //     if (cur_elem->id == L)
        //     {
        //         ray->pos = origin;
        //         ray->dir = vecnorm(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos));
        //         // printf("_________%lf\n", closest);
        //         if (find_closest(ray, info, closest, *i) >= vecmag(vecnew(origin, (*(t_light *)(cur_elem->elem_detail)).pos)))
        //         {
        //             ray->color = (*(t_sphere *)(hit_elem->elem_detail)).color.r * (*(t_light *)(cur_elem->elem_detail)).ratio;
        //             ray->color = (ray->color << 8) + (*(t_sphere *)(hit_elem->elem_detail)).color.g * (*(t_light *)(cur_elem->elem_detail)).ratio;
        //             ray->color = (ray->color << 8) + (*(t_sphere *)(hit_elem->elem_detail)).color.b * (*(t_light *)(cur_elem->elem_detail)).ratio;
        //         }
        //         // print_vec3lf(ray->pos);
        //         // print_vec3lf(ray->dir);
        //     }
        //     cur_elem = cur_elem->next_elem;
        // }
        ray->color = incoming_ray.color;
    }
    else
    {
        ray->color = info->ambiant->color.r * info->ambiant->ratio;
        ray->color = (ray->color << 8) + info->ambiant->color.g * info->ambiant->ratio;
        ray->color = (ray->color << 8) + info->ambiant->color.b * info->ambiant->ratio;
    }
}
