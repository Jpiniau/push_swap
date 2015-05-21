#include "libft.h"
#include <stdlib.h>

t_list  *ft_lstnewcust(void const *content, size_t content_size)
{
        t_list  *elem;

        elem = (t_list *)malloc(sizeof(t_list));
        if (elem != NULL)
        {
                if (content == NULL)
                {
                        elem->content_size = 0;
                        elem->content = NULL;
                }
                else
                {
                        elem->content = (void *)content;
                        if (elem->content)
                                elem->content = ft_memcpy(elem->content, content, content_size);
                        elem->content_size = content_size;
                        elem->next = NULL;
                }
        }
        return (elem);
}
