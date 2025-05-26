#include "../../parsing.h"

void    identify_path(void)
{
    t_cmd   *ptr;

    ptr = *v_cmd();
    while(ptr)
    {
        if(is_path(ptr->content))
            ptr->type = ptr->type | PATH;
        ptr = ptr->next;
    }
}

void    identify_double_q(void)
{
    t_cmd   *ptr;

    ptr = *v_cmd();
    while(ptr)
    {
        if(is_double_q(ptr->content))
            ptr->type = ptr->type | DOUBLE_Q;
        ptr = ptr->next;
    }
}

void    identify_single_q(void)          
{
    t_cmd   *ptr;

    ptr = *v_cmd();
    while(ptr)
    {
        if(is_single_q(ptr->content))
            ptr->type = ptr->type | SINGLE_Q;
        ptr = ptr->next;
    }
}

void    identify_cmd_arg(void) 
{
    t_cmd   *ptr;

    ptr = *v_cmd();
    while(ptr)
    {
        if((ptr->type == WORD))
            ptr->type |= CMD_ARG;
        ptr = ptr->next;
    }
}

void    identify_delimiter(void)
{
    t_cmd   *ptr;

    ptr = *v_cmd();
    while(ptr)
    {
        if(ptr->prev && (ptr->prev->type & HERE_DOC))
        {
            if(ptr->type & WORD)
                ptr->type |= DELIMITER;
        }
        ptr = ptr->next;
    }
}
