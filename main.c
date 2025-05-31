
#include "minishell.h"
#include "string.h"





// int main(int argc, char const *argv[])
// {
//     char *d[] = {"ls", NULL};
//     // d[0] = strdup("ls");
//     // d[1]  = NULL;

//     // char *c = x;
//     // int pid = fork();
//     // if(pid == 0)
//     // {
//         char *str = malloc(2);
//        char *x = malloc(2);
//         x = str;
//         execve("/usr/bin/ls",d,NULL);
//         printf("gggggggggggggggggggg\n");
//         // exit(1);
//     // }
//     // free(c);
//     // free(x);
//     return 0;
// }
















// void handle_sigint(int signum)
// {
//     (void)signum;
//     rl_replace_line("", 0);
//     // write(1, "this signal\n", 12);
//     write(1, "\n", 1);
//     rl_on_new_line();
//     rl_redisplay();
// }

// void sig(int g)
// {
//     printf("its ctr+c\n");
//     // exit(130);
// }

// int main(int argc, char const *argv[])
// {
//     int status;
//     while (1)
//     {
//         // signal(SIGINT, handle_sigint);
//         signal(SIGINT, sig);
//         int pid = fork();
//         if(pid == 0)
//         {
//             signal(SIGINT, SIG_DFL);
//             while (1)
//             {
//                 if(readline(" << ") == NULL)
//                 {
//                     exit(0);
//                 }
//             }
//             // exit(34);
//         }
//         else
//         {
//             printf("wating for child\n");
//             waitpid(pid, &status, 0);
//             // printf("status = %d\n", WEXITSTATUS(status));
//             if (WIFSIGNALED(status))
//             {
//                 printf("Parent: Child killed by signal %d (exit code %d)\n",
//                        WTERMSIG(status), 128 + WTERMSIG(status));
//             }
//             else if (WIFEXITED(status))
//             {
//                 printf("Parent: Child exited with code %d\n", WEXITSTATUS(status));
//             }
//             printf("restarting the loop\n");
//         }
//     }
    
//     return 0;
// }






















// // void sig(int g)
// // {
// //     printf("Parent: Caught Ctrl+C (SIGINT)\n");
// // }

// // int main()
// // {
// //     int status;

// //     while (1)
// //     {
// //         signal(SIGINT, sig); // Parent handles SIGINT

// //         int pid = fork();
// //         if (pid == 0)
// //         {
// //             // In child
// //             signal(SIGINT, SIG_DFL); // Reset SIGINT to default
// //             while (1)
// //             {
// //                 char *input = readline(" << ");
// //                 if (!input) {
// //                     printf("Child: readline returned NULL (maybe Ctrl+C?)\n");
// //                     exit(130); // Explicitly exit with SIGINT-style code
// //                 }
// //                 if (strcmp(input, "ss") == 0)
// //                     break;
// //                 free(input);
// //             }
// //             exit(0); // normal exit
// //         }
// //         else
// //         {
// //             // In parent
// //             printf("Parent: waiting for child %d\n", pid);
// //             waitpid(pid, &status, 0);

// //             if (WIFSIGNALED(status))
// //             {
// //                 printf("Parent: Child killed by signal %d (exit code %d)\n",
// //                        WTERMSIG(status), 128 + WTERMSIG(status));
// //             }
// //             else if (WIFEXITED(status))
// //             {
// //                 printf("Parent: Child exited with code %d\n", WEXITSTATUS(status));
// //             }

// //             printf("Parent: Restarting loop\n\n");
// //         }
// //     }

// //     return 0;
// // }