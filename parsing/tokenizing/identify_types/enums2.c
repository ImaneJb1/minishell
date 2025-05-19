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
<<<<<<< HEAD
        // if(ptr->type & WORD)
        // if(((ptr->type & CMD_ARG) || (ptr->type & CMD)))
=======
        // if(((ptr->type & CMD_ARG)||(ptr->type & CMD)))
>>>>>>> origin/imane3
        // {
        //     if(ptr->next && (ptr->next->type & WORD))
        //     {
        //         ptr->next->type |= CMD_ARG;
        //         // else
        //         //     ptr->next->type = ptr->next->type | FILE_NAME;
        //     }
        // }
<<<<<<< HEAD
=======
        if((ptr->type & WORD) && (!(ptr->type & CMD)&& (!(ptr->type & FILE_NAME))))
            ptr->type |= CMD_ARG;
>>>>>>> origin/imane3
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