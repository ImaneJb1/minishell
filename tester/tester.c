/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:13:45 by imeslaki          #+#    #+#             */
/*   Updated: 2025/05/13 16:25:35 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void clear_the_list(void) 
{
    t_cmd *cur = *v_cmd();
    t_cmd *next;
    while (cur) {
        next = cur->next;
        free(cur->content);
        free(cur);
        cur = next;
    }
    *v_cmd() = NULL;
}

void setUp(void)
{
    clear_the_list();
}
void tearDown(void)
{
    add_to_cmd_list(0, 0);
}

int exp_len(char **exp)
{
    int i = 0;
    while(exp[i])
        i++;
    return i;
}

static void prepare(char *input)
{
    creat_the_cmd_list(input);
    identify_all_types();
}


static void assert_tokens(char *input, t_case *exp, int exp_len)
{
    t_cmd *head;

    prepare(input);
    head = *v_cmd();
    for (int i = 0; i < exp_len; i++, exp++, head = head->next)
    {
        //  check the command string
        TEST_ASSERT_EQUAL_STRING_MESSAGE(exp->command, head->content, "token string mismatch");
        //  check the token type enum
        TEST_ASSERT_EQUAL_INT_MESSAGE(exp->type, head->type, "token type mismatch");
    }
    // after consuming exp_len tokens, head should be NULL
    TEST_ASSERT_NULL_MESSAGE(head, "extra tokens in list");
}


// ---------------- SIMPLE TESTS -------------------------------------------------------

void simple_test1(void) {
    char *input = "hello world";
    t_case exp[] = {
        {"hello", WORD | CMD},                // first word is command :contentReference[oaicite:0]{index=0}
        {"world", WORD | CMD_ARG},            // next word is argument :contentReference[oaicite:1]{index=1}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test2(void) {
    char *input = "echo foo | grep 'foo'";
    t_case exp[] = {
        {"echo", WORD | CMD},                 // command 
        {"foo", WORD | CMD_ARG},              // argument 
        {"|", PIPE},                         // pipe operator :contentReference[oaicite:2]{index=2}
        {"grep", WORD | CMD},                 // new command after pipe :contentReference[oaicite:3]{index=3}
        {"'foo'", WORD | CMD_ARG | SINGLE_Q}, // single-quoted argument :contentReference[oaicite:4]{index=4}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test3(void) {
    char *input = "cat < infile";
    t_case exp[] = {
        {"cat", WORD | CMD},                  // command :contentReference[oaicite:5]{index=5}
        {"<", REDIR_IN},                      // input redirection 
        {"infile", WORD | FILE_NAME},         // filename after redir 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test4(void) {
    char *input = "echo foo > outfile";
    t_case exp[] = {
        {"echo", WORD | CMD},                 // command :contentReference[oaicite:6]{index=6}
        {"foo", WORD | CMD_ARG},              // argument :contentReference[oaicite:7]{index=7}
        {">", REDIR_OUT},                     // output redirection 
        {"outfile", WORD | FILE_NAME},        // filename 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test5(void) {
    char *input = "echo foo >> outfile";
    t_case exp[] = {
        {"echo", WORD | CMD},                 // command :contentReference[oaicite:8]{index=8}
        {"foo", WORD | CMD_ARG},              // argument :contentReference[oaicite:9]{index=9}
        {">>", APPEND},            // append redirection 
        {"outfile", WORD | FILE_NAME},        // filename 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test6(void) {
    char *input = "<< EOF";
    t_case exp[] = {
        {"<<", HERE_DOC},                     // here-doc operator 
        {"EOF", WORD},                        // here-doc limiter is treated as WORD 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test7(void) {
    char *input = "echo 'a b' c";
    t_case exp[] = {
        {"echo", WORD | CMD},                 // command :contentReference[oaicite:10]{index=10}
        {"'a b'", WORD | CMD_ARG | SINGLE_Q}, // single-quoted arg :contentReference[oaicite:11]{index=11}
        {"c", WORD | CMD_ARG},                // unquoted arg :contentReference[oaicite:12]{index=12}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test8(void) {
    char *input = "echo \"a b\" c";
    t_case exp[] = {
        {"echo", WORD | CMD},                 // command :contentReference[oaicite:13]{index=13}
        {"\"a b\"", WORD | CMD_ARG | DOUBLE_Q}, // double-quoted arg :contentReference[oaicite:14]{index=14}
        {"c", WORD | CMD_ARG},                // unquoted arg :contentReference[oaicite:15]{index=15}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test9(void) {
    char *input = "echo $";
    t_case exp[] = {
        {"echo", WORD | CMD},                 // command :contentReference[oaicite:16]{index=16}
        {"$", WORD | CMD_ARG },               // lone dollar is variable token 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test10(void) {
    char *input = "echo $USER";
    t_case exp[] = {
        {"echo", WORD | CMD},                 // command :contentReference[oaicite:17]{index=17}
        {"$USER", WORD | CMD_ARG | VARIABLE}, // variable arg 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test11(void) {
    char *input = "echo this\"is 'a'\"test >>> cat || ls";
    t_case exp[] = {
        {"echo", WORD | CMD},                      // command 
        {"this\"is 'a'\"test", WORD | CMD_ARG | DOUBLE_Q | SINGLE_Q}, // merged by quotes 
        {">>", APPEND},                 // first >> 
        {">", REDIR_OUT},                           // then > 
        {"cat", WORD | FILE_NAME},                        // new cmd :contentReference[oaicite:18]{index=18}
        {"|", PIPE},                                // first pipe :contentReference[oaicite:19]{index=19}
        {"|", PIPE},                                // second pipe of || :contentReference[oaicite:20]{index=20}
        {"ls", WORD | CMD},                         // command after || :contentReference[oaicite:21]{index=21}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test12(void) {
    char *input = "<< del      file1 >| ./path/file2";
    t_case exp[] = {
        {"<<", HERE_DOC},                           // here-doc 
        {"del", WORD},                  // limiter as filename 
        {"file1", WORD | CMD},                      // next word :contentReference[oaicite:22]{index=22}
        {">", REDIR_OUT},                           // > 
        {"|", PIPE},                                // escaped pipe token in >| treated as PIPE 
        {"./path/file2", WORD | FILE_NAME | PATH},  // path 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test13(void) {
    char *input = "<\"cat\"|echo\"test\"|ls";
    t_case exp[] = {
        {"<", REDIR_IN},                            // < 
        {"\"cat\"", WORD | FILE_NAME | DOUBLE_Q},  // quoted filename :contentReference[oaicite:23]{index=23}
        {"|", PIPE},                                // pipe :contentReference[oaicite:24]{index=24}
        {"echo\"test\"", WORD | CMD | DOUBLE_Q},    // command+quoted part :contentReference[oaicite:25]{index=25}
        {"|", PIPE},                                // pipe :contentReference[oaicite:26]{index=26}
        {"ls", WORD | CMD},                         // command :contentReference[oaicite:27]{index=27}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void simple_test14(void) {
    char *input = "echo 'a \"b\" c'";
    t_case exp[] = {
        {"echo", WORD | CMD},                       // command :contentReference[oaicite:28]{index=28}
        {"'a \"b\" c'", WORD | CMD_ARG | SINGLE_Q | DOUBLE_Q}, // mixed quotes :contentReference[oaicite:29]{index=29} 
    };
    assert_tokens(input, exp, COUNT(exp));
}


// ---------------- PIPES -------------------------------------------------------

void test_pipe_1(void) {
    char *input = "ls | wc";
    t_case exp[] = {
        {"ls", WORD | CMD},
        {"|", PIPE},
        {"wc", WORD | CMD},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_pipe_2(void) {
    char *input = "cat file | grep test | sort";
    t_case exp[] = {
        {"cat", WORD | CMD},
        {"file", WORD | CMD_ARG},
        {"|", PIPE},
        {"grep", WORD | CMD},
        {"test", WORD | CMD_ARG},
        {"|", PIPE},
        {"sort", WORD | CMD},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_pipe_3(void) {
    char *input = "echo hi|wc -l";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"hi", WORD | CMD_ARG},
        {"|", PIPE},
        {"wc", WORD | CMD},
        {"-l", WORD | CMD_ARG},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_pipe_4(void) {
    char *input = "   ls    |    wc   ";
    t_case exp[] = {
        {"ls", WORD | CMD},
        {"|", PIPE},
        {"wc", WORD | CMD},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_pipe_5(void) {
    char *input = "ls|grep main|sort|uniq";
    t_case exp[] = {
        {"ls", WORD | CMD},
        {"|", PIPE},
        {"grep", WORD | CMD},
        {"main", WORD | CMD_ARG},
        {"|", PIPE},
        {"sort", WORD | CMD},
        {"|", PIPE},
        {"uniq", WORD | CMD},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_pipe_6(void) {
    char *input = "|| echo hi";
    t_case exp[] = {
        {"|", PIPE},        // two consecutive pipes :contentReference[oaicite:30]{index=30}
        {"|", PIPE},
        {"echo", WORD | CMD},
        {"hi", WORD | CMD_ARG},
    };
    assert_tokens(input, exp, COUNT(exp));
}


// ---------------- QUOTES -------------------------------------------------------

void test_quote_1(void) {
    char *input = "echo \"this is 'a' test\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"\"this is 'a' test\"", WORD | CMD_ARG | DOUBLE_Q | SINGLE_Q},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_quote_2(void) {
    char *input = "echo 'this is \"a\" test'";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"'this is \"a\" test'", WORD | CMD_ARG | SINGLE_Q | DOUBLE_Q},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_quote_3(void) {
    char *input = "echo this\"is\"a\"test\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"this\"is\"a\"test\"", WORD | CMD_ARG | DOUBLE_Q},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_quote_4(void) {
    char *input = "echo \"\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"\"\"", WORD | CMD_ARG | DOUBLE_Q},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_quote_5(void) {
    char *input = "echo 'hello world' \"foo bar\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"'hello world'", WORD | CMD_ARG | SINGLE_Q},
        {"\"foo bar\"", WORD | CMD_ARG | DOUBLE_Q},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_quote_6(void) {
    char *input = "echo \"'nested' quotes\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"\"'nested' quotes\"", WORD | CMD_ARG | DOUBLE_Q | SINGLE_Q},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_quote_7(void) {
    char *input = "echo '\"double\" inside single'";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"'\"double\" inside single'", WORD | CMD_ARG | SINGLE_Q | DOUBLE_Q},
    };
    assert_tokens(input, exp, COUNT(exp));
}


// ---------------- REDIRECTIONS -------------------------------------------------------

void test_redir_1(void) {
    char *input = "< infile > outfile";
    t_case exp[] = {
        {"<", REDIR_IN},
        {"infile", WORD | FILE_NAME},
        {">", REDIR_OUT},
        {"outfile", WORD | FILE_NAME},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_redir_2(void) {
    char *input = ">> appendfile";
    t_case exp[] = {
        {">>", APPEND},
        {"appendfile", WORD | FILE_NAME},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_redir_3(void) {
    char *input = "ls >| force_write";
    t_case exp[] = {
        {"ls", WORD | CMD},
        {">", REDIR_OUT},
        {"|", PIPE},
        {"force_write", WORD | CMD},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_redir_4(void) {
    char *input = "<infile cmd >outfile";
    t_case exp[] = {
        {"<", REDIR_IN},
        {"infile", WORD | FILE_NAME},
        {"cmd", WORD | CMD},
        {">", REDIR_OUT},
        {"outfile", WORD | FILE_NAME},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_redir_5(void) {
    char *input = "<<EOF cat >>log";
    t_case exp[] = {
        {"<<", HERE_DOC},
        {"EOF", WORD},
        {"cat", WORD | CMD},
        {">>", APPEND},
        {"log", WORD | FILE_NAME},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_redir_6(void) {
    char *input = "echo >   > file";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {">", REDIR_OUT},
        {">", REDIR_OUT},   // two successive >, each a redir token 
        {"file", WORD | FILE_NAME},
    };
    assert_tokens(input, exp, COUNT(exp));
}


// ---------------- VARIABLE -------------------------------------------------------

void test_var_1(void) {
    char *input = "echo $USER";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"$USER", WORD | CMD_ARG | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_2(void) {
    char *input = "echo ${HOME}";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"${HOME}", WORD | CMD_ARG | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_3(void) {
    char *input = "echo \"$USER is logged in\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"\"$USER is logged in\"", WORD | CMD_ARG | DOUBLE_Q | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_4(void) {
    char *input = "echo $?";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"$?", WORD | CMD_ARG | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_5(void) {
    char *input = "echo $USER$PATH";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"$USER$PATH", WORD | CMD_ARG | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_6(void) {
    char *input = "echo \"hi $USER\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"\"hi $USER\"", WORD | CMD_ARG | DOUBLE_Q | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_7(void) {
    char *input = "$VAR=hello";
    t_case exp[] = {
        {"$VAR=hello", WORD | CMD | VARIABLE}, // assignment treated as WORD 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_8(void) {
    char *input = "echo $USER $PATH";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"$USER", WORD | CMD_ARG | VARIABLE},
        {"$PATH", WORD | CMD_ARG | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_9(void) {
    char *input = "echo$USER$$PATH";
    t_case exp[] = {
        {"echo$USER$$PATH", WORD | CMD | VARIABLE}, // no separator → single word 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_10(void) {
    char *input = "echo $$$test $PATH";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"$$$test", WORD | CMD_ARG | VARIABLE}, // $$ → $, then $test 
        {"$PATH", WORD | CMD_ARG | VARIABLE},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void test_var_11(void) {
    char *input = "echo $$$test$$PATH $VAR $ $$$$$ USER";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"$$$test$$PATH", WORD | CMD_ARG | VARIABLE},
        {"$VAR", WORD | CMD_ARG | VARIABLE},
        {"$", WORD | CMD_ARG},
        {"$$$$$", WORD | CMD_ARG | VARIABLE},
        {"USER", WORD | CMD_ARG},
    };
    assert_tokens(input, exp, COUNT(exp));
}


// ---------------- OHTER EDGE-CASES -------------------------------------------------------

void other_test_1(void) {
    char *input = "echo \\$HOME";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"\\$HOME", WORD | CMD_ARG | VARIABLE},    // backslash preserved 
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_2(void) {
    char *input = "ls *";
    t_case exp[] = {
        {"ls", WORD | CMD},
        {"*", WORD | CMD_ARG},          // glob left unexpanded by lexer :contentReference[oaicite:31]{index=31}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_3(void) {
    char *input = "ls file?.txt";
    t_case exp[] = {
        {"ls", WORD | CMD},
        {"file?.txt", WORD | CMD_ARG},  // ? is literal in WORD :contentReference[oaicite:32]{index=32}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_4(void) {
    char *input = "echo {a,b,c}";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"{a,b,c}", WORD | CMD_ARG},    // brace literal :contentReference[oaicite:33]{index=33}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_6(void) {
    char *input = "./script.sh arg1 arg2";
    t_case exp[] = {
        {"./script.sh", WORD | CMD | PATH },    // path as command 
        {"arg1", WORD | CMD_ARG},
        {"arg2", WORD | CMD_ARG},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_7(void) {
    char *input = "echo `uname -s`";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"`uname", WORD | CMD_ARG},     // backtick splits into two tokens :contentReference[oaicite:34]{index=34}
        {"-s`", WORD | CMD_ARG},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_8(void) {
    char *input = "(echo hi)";
    t_case exp[] = {
        {"(echo", WORD | CMD},          // parenthesis not special in our lexer :contentReference[oaicite:35]{index=35}
        {"hi)", WORD | CMD_ARG},
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_9(void) {
    char *input = "echo \"$(whoami)\"";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"\"$(whoami)\"", WORD | CMD_ARG | DOUBLE_Q | VARIABLE}, // command-substitution literal :contentReference[oaicite:36]{index=36}
    };
    assert_tokens(input, exp, COUNT(exp));
}

void other_test_10(void) {
    char *input = "echo $((1 + 2))";
    t_case exp[] = {
        {"echo", WORD | CMD},
        {"$((1", WORD | CMD_ARG | VARIABLE},  // arithmetic split :contentReference[oaicite:37]{index=37}
        {"+", WORD | CMD_ARG},
        {"2))", WORD | CMD_ARG},
    };
    assert_tokens(input, exp, COUNT(exp));
}



// ---------------- SYNTAX ERRORS -------------------------------------------------------

// void test_unmatched_single_quote_01(void) {
//     prepare("echo 'unclosed");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_unmatched_double_quote_02(void) {
//     prepare("echo \"unclosed");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_trailing_pipe_03(void) {
//     prepare("ls |");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_leading_pipe_04(void) {
//     prepare("| ls");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_redir_missing_target_05(void) {
//     prepare("cat <");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_append_redir_06(void) {
//     prepare("echo hello >>");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_if_missing_then_07(void) {
//     prepare("if true; echo done; fi");
//     TEST_ASSERT_TRUE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_if_missing_fi_08(void) {
//     prepare("if true; then 'echo done;");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_bad_arithmetic_09(void) {
//     prepare("echo <>$((5 + ))");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_unexpected_paren_10(void) {
//     prepare("echo >|ls");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_unterminated_backtick_11(void) {
//     prepare("echo \"hel'lo\"");
//     TEST_ASSERT_TRUE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_here_doc_12(void) {
//     prepare("cat <<");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_check_pipe_syntax_13(void) {
//     prepare("ls || grep foo");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_check_unclosed_quotes_14(void) {
//     prepare("echo 'abc");
//     TEST_ASSERT_FALSE_MESSAGE(check_unclosed_quotes(), NULL);
// }

// void test_unexpected_token_15(void) {
//     prepare("echo foo)");
//     TEST_ASSERT_TRUE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_redir_errors_16(void) {
//     prepare("cat >");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }

// void test_if_special_at_end_17(void) {
//     prepare("if true then");
//     TEST_ASSERT_FALSE_MESSAGE(is_valid_syntax(), NULL);
// }


int tester(void) {
    UNITY_BEGIN();

    /* simple tests */
    RUN_TEST(simple_test1);
    RUN_TEST(simple_test2);
    RUN_TEST(simple_test3);
    RUN_TEST(simple_test4);
    RUN_TEST(simple_test5);
    RUN_TEST(simple_test6);
    RUN_TEST(simple_test7);
    RUN_TEST(simple_test8);
    RUN_TEST(simple_test9);
    RUN_TEST(simple_test10);
    RUN_TEST(simple_test11);
    RUN_TEST(simple_test12);
    RUN_TEST(simple_test13);
    RUN_TEST(simple_test14);

    /* pipe tests */
    RUN_TEST(test_pipe_1);
    RUN_TEST(test_pipe_2);
    RUN_TEST(test_pipe_3);
    RUN_TEST(test_pipe_4);
    RUN_TEST(test_pipe_5);
    RUN_TEST(test_pipe_6);

    /* quote tests */
    RUN_TEST(test_quote_1);
    RUN_TEST(test_quote_2);
    RUN_TEST(test_quote_3);
    RUN_TEST(test_quote_4);
    RUN_TEST(test_quote_5);
    RUN_TEST(test_quote_6);
    RUN_TEST(test_quote_7);

    /* redirection tests */
    RUN_TEST(test_redir_1);
    RUN_TEST(test_redir_2);
    RUN_TEST(test_redir_3);
    RUN_TEST(test_redir_4);
    RUN_TEST(test_redir_5);
    RUN_TEST(test_redir_6);

    /* variable expansion tests */
    RUN_TEST(test_var_1);
    RUN_TEST(test_var_2);
    RUN_TEST(test_var_3);
    RUN_TEST(test_var_4);
    RUN_TEST(test_var_5);
    RUN_TEST(test_var_6);
    RUN_TEST(test_var_7);
    RUN_TEST(test_var_8);
    RUN_TEST(test_var_9);
    RUN_TEST(test_var_10);
    RUN_TEST(test_var_11);

    /* other edge‐case tests */
    RUN_TEST(other_test_1);
    RUN_TEST(other_test_2);
    RUN_TEST(other_test_3);
    RUN_TEST(other_test_4);
    RUN_TEST(other_test_6);
    RUN_TEST(other_test_7);
    RUN_TEST(other_test_8);
    RUN_TEST(other_test_9);
    RUN_TEST(other_test_10);


    // // Syntax validation tests
    // RUN_TEST(test_unmatched_single_quote_01);
    // RUN_TEST(test_unmatched_double_quote_02);
    // RUN_TEST(test_trailing_pipe_03);
    // RUN_TEST(test_leading_pipe_04);
    // RUN_TEST(test_redir_missing_target_05);
    // RUN_TEST(test_append_redir_06);
    // RUN_TEST(test_if_missing_then_07);
    // RUN_TEST(test_if_missing_fi_08);
    // RUN_TEST(test_bad_arithmetic_09);
    // RUN_TEST(test_unexpected_paren_10);
    // RUN_TEST(test_unterminated_backtick_11);
    // RUN_TEST(test_here_doc_12);

    // // Specific checker tests
    // RUN_TEST(test_check_pipe_syntax_13);
    // RUN_TEST(test_check_unclosed_quotes_14);
    // RUN_TEST(test_unexpected_token_15);
    // RUN_TEST(test_redir_errors_16);
    // RUN_TEST(test_if_special_at_end_17);



    return UNITY_END();
}













// void simple_test1(void) {
//     char *input = "hello world";
//     char *exp[] = {"hello", "world", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test2(void) {
//     char *input = "echo foo | grep \'foo\'";
//     char *exp[] = {"echo", "foo", "|", "grep", "\'foo\'", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test3(void) {
//     char *input = "cat < infile";
//     char *exp[] = {"cat", "<", "infile", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test4(void) {
//     char *input = "echo foo > outfile";
//     char *exp[] = {"echo", "foo", ">", "outfile", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test5(void) {
//     char *input = "echo foo >> outfile";
//     char *exp[] = {"echo", "foo", ">>", "outfile", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test6(void) {
//     char *input = "<< EOF";
//     char *exp[] = {"<<", "EOF", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test7(void) {
//     char *input = "echo 'a b' c";
//     char *exp[] = {"echo", "'a b'", "c", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test8(void) {
//     char *input = "echo \"a b\" c";
//     char *exp[] = {"echo", "\"a b\"", "c", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test9(void) {
//     char *input = "echo $";
//     char *exp[] = {"echo", "$", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test10(void) {
//     char *input = "echo $USER";
//     char *exp[] = {"echo", "$USER", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test11(void) {
//     char *input = "echo this\"is 'a'\"test >>> cat || ls";
//     char *exp[] = {"echo", "this\"is 'a'\"test", ">>", ">", "cat", "|", "|", "ls", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test12(void) {
//     char *input = "<< del      file1 >| ./path/file2";
//     char *exp[] = {"<<", "del", "file1", ">", "|", "./path/file2", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test13(void) {
//     char *input = "<\"cat\"|echo\"test\"|ls";
//     char *exp[] = {"<", "\"cat\"", "|", "echo\"test\"", "|", "ls", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void simple_test14(void) {
//     char *input = "echo 'a \"b\" c'";
//     char *exp[]  = {"echo", "'a \"b\" c'", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }


// // PIPES
// void test_pipe_1(void) {
//     char *input = "ls | wc";
//     char *exp[] = {"ls", "|", "wc", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_pipe_2(void) {
//     char *input = "cat file | grep test | sort";
//     char *exp[] = {"cat", "file", "|", "grep", "test", "|", "sort", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_pipe_3(void) {
//     char *input = "echo hi|wc -l";
//     char *exp[] = {"echo", "hi", "|", "wc", "-l", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_pipe_4(void) {
//     char *input = "   ls    |    wc   ";
//     char *exp[] = {"ls", "|", "wc", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_pipe_5(void) {
//     char *input = "ls|grep main|sort|uniq";
//     char *exp[] = {"ls", "|", "grep", "main", "|", "sort", "|", "uniq", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_pipe_6(void) {
//     char *input = "|| echo hi";
//     char *exp[] = {"|", "|", "echo", "hi", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }


// // QUOTES
// void test_quote_1(void) {
//     char *input = "echo \"this is 'a' test\"";
//     char *exp[] = {"echo", "\"this is 'a' test\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_quote_2(void) {
//     char *input = "echo 'this is \"a\" test'";
//     char *exp[] = {"echo", "'this is \"a\" test'", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_quote_3(void) {
//     char *input = "echo this\"is\"a\"test\"";
//     char *exp[] = {"echo", "this\"is\"a\"test\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_quote_4(void) {
//     char *input = "echo \"\"";
//     char *exp[] = {"echo", "\"\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_quote_5(void) {
//     char *input = "echo 'hello world' \"foo bar\"";
//     char *exp[] = {"echo", "'hello world'", "\"foo bar\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_quote_6(void) {
//     char *input = "echo \"'nested' quotes\"";
//     char *exp[] = {"echo", "\"'nested' quotes\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_quote_7(void) {
//     char *input = "echo '\"double\" inside single'";
//     char *exp[] = {"echo", "'\"double\" inside single'", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// // void test_quote_8(void) {
// //     char *input = "echo \"unclosed";
// //     char *exp[] = {"echo", "\"unclosed", NULL};
// //     assert_tokens(input, exp, exp_len(exp));
// // }

// void test_quote_9(void) {
//     char *input = "echo $USER $'\"'\"PATH\"'\"'";
//     char *exp[] = {"echo", "$USER", "$'\"'\"PATH\"'\"'", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }



// // REDIRECTIONS
// void test_redir_1(void) {
//     char *input = "< infile > outfile";
//     char *exp[] = {"<", "infile", ">", "outfile", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_redir_2(void) {
//     char *input = ">> appendfile";
//     char *exp[] = {">>", "appendfile", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_redir_3(void) {
//     char *input = "ls >| force_write";
//     char *exp[] = {"ls", ">", "|", "force_write", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_redir_4(void) {
//     char *input = "<infile cmd >outfile";
//     char *exp[] = {"<", "infile", "cmd", ">", "outfile", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_redir_5(void) {
//     char *input = "<<EOF cat >>log";
//     char *exp[] = {"<<", "EOF", "cat", ">>", "log", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_redir_6(void) {
//     char *input = "echo >   > file";
//     char *exp[] = {"echo", ">", ">", "file", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }


// // VARIABLE
// void test_var_1(void) {
//     char *input = "echo $USER";
//     char *exp[] = {"echo", "$USER", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_2(void) {
//     char *input = "echo ${HOME}";
//     char *exp[] = {"echo", "${HOME}", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_3(void) {
//     char *input = "echo \"$USER is logged in\"";
//     char *exp[] = {"echo", "\"$USER is logged in\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_4(void) {
//     char *input = "echo $?";
//     char *exp[] = {"echo", "$?", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_5(void) {
//     char *input = "echo $USER$PATH";
//     char *exp[] = {"echo", "$USER$PATH", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_6(void) {
//     char *input = "echo \"hi $USER\"";
//     char *exp[] = {"echo", "\"hi $USER\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_7(void) {
//     char *input = "$VAR=hello";
//     char *exp[] = {"$VAR=hello", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_8(void) {
//     char *input = "echo $USER $PATH";
//     char *exp[] = {"echo", "$USER", "$PATH", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_9(void) {
//     char *input = "echo$USER$$PATH";
//     char *exp[] = {"echo$USER$$PATH", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_10(void) {
//     char *input = "echo $$$test $PATH";
//     char *exp[] = {"echo", "$$$test", "$PATH", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void test_var_11(void) {
//     char *input = "echo $$$test$$PATH $VAR $ $$$$$ USER";
//     char *exp[] = {"echo", "$$$test$$PATH", "$VAR", "$", "$$$$$", "USER", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// // OUTHER_TESTS
// void other_test_1(void) {
//     char *input = "echo \\$HOME";
//     char *exp[] = {"echo", "\\$HOME", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void other_test_2(void) {
//     char *input = "ls *";
//     char *exp[] = {"ls", "*", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void other_test_3(void) {
//     char *input = "ls file?.txt";
//     char *exp[] = {"ls", "file?.txt", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void other_test_4(void) {
//     char *input = "echo {a,b,c}";
//     char *exp[] = {"echo", "{a,b,c}", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// // void other_test_5(void) {
// //     char *input = "echo \"hi\\\"there\"";
// //     char *exp[] = {"echo", "\"hi\\\"there\"", NULL};
// //     assert_tokens(input, exp, exp_len(exp));
// // }

// void other_test_6(void) {
//     char *input = "./script.sh arg1 arg2";
//     char *exp[] = {"./script.sh", "arg1", "arg2", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void other_test_7(void) {
//     char *input = "echo `uname -s`";
//     char *exp[] = {"echo", "`uname", "-s`", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void other_test_8(void) {
//     char *input = "(echo hi)";
//     char *exp[] = {"(echo", "hi)", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void other_test_9(void) {
//     char *input = "echo \"$(whoami)\"";
//     char *exp[] = {"echo", "\"$(whoami)\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

// void other_test_10(void) {
//     char *input = "echo $((1 + 2))";
//     char *exp[] = {"echo", "$((1" ,"+" , "2))", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }


// int tester(void) {
//     UNITY_BEGIN();
    
//     // SIMPLE TESTS
//     RUN_TEST(simple_test1);
//     RUN_TEST(simple_test2);
//     RUN_TEST(simple_test3);
//     RUN_TEST(simple_test4);
//     RUN_TEST(simple_test5);
//     RUN_TEST(simple_test6);
//     RUN_TEST(simple_test7);
//     RUN_TEST(simple_test8);
//     RUN_TEST(simple_test9);
//     RUN_TEST(simple_test10);
//     RUN_TEST(simple_test11);
//     RUN_TEST(simple_test12);
//     RUN_TEST(simple_test13);
    
//     // PIPE TESTS
//     RUN_TEST(test_pipe_1);
//     RUN_TEST(test_pipe_2);
//     RUN_TEST(test_pipe_3);
//     RUN_TEST(test_pipe_4);
//     RUN_TEST(test_pipe_5);
//     RUN_TEST(test_pipe_6);


//     // QUOTE TESTS
//     RUN_TEST(test_quote_1);
//     RUN_TEST(test_quote_2);
//     RUN_TEST(test_quote_3);
//     RUN_TEST(test_quote_4);
//     RUN_TEST(test_quote_5);
//     RUN_TEST(test_quote_6);
//     RUN_TEST(test_quote_7);
//     // RUN_TEST(test_quote_8);
//     RUN_TEST(test_quote_9);
    


//     // REDIRECTIONS TESTS
//     RUN_TEST(test_redir_1);
//     RUN_TEST(test_redir_2);
//     RUN_TEST(test_redir_3);
//     RUN_TEST(test_redir_4);
//     RUN_TEST(test_redir_5);
//     RUN_TEST(test_redir_6);


//     // VARIABLE TESTS
//     RUN_TEST(test_var_1);
//     RUN_TEST(test_var_2);
//     RUN_TEST(test_var_3);
//     RUN_TEST(test_var_4);
//     RUN_TEST(test_var_5);
//     RUN_TEST(test_var_6);
//     RUN_TEST(test_var_7);
//     RUN_TEST(test_var_8);
//     RUN_TEST(test_var_9);
//     RUN_TEST(test_var_10);
//     RUN_TEST(test_var_11);
//     // RUN_TEST(test_var_12);


//     // OUTHER TESTS
//     RUN_TEST(other_test_1);
//     RUN_TEST(other_test_2);
//     RUN_TEST(other_test_3);
//     RUN_TEST(other_test_4);
//     // RUN_TEST(other_test_5);
//     RUN_TEST(other_test_6);
//     RUN_TEST(other_test_7);
//     RUN_TEST(other_test_8);
//     RUN_TEST(other_test_9);
//     RUN_TEST(other_test_10);

// 	return (UnityEnd());
// }


