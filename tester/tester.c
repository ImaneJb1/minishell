/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:13:45 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/18 11:51:38 by imeslaki         ###   ########.fr       */
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
    add_to_list(0, 0);
}

int exp_len(char **exp)
{
    int i = 0;
    while(exp[i])
        i++;
    return i;
}

static void assert_tokens(char *input, char **exp, int exp_len) {
    t_cmd *head;
    creat_the_list(input);
    head = *v_cmd();
    for (int i = 0; i < exp_len; i++, head = head->next) {
        if (strcmp(exp[i], head->content))
            printf("Expected '%s', got '%s'\n", exp[i], head->content);
        TEST_ASSERT_EQUAL_CHAR_ARRAY(exp[i], head->content, strlen(exp[i]) + 1);
    }
    TEST_ASSERT_EQUAL_INT64(0, head);
}

void simple_test1(void) {
    char *input = "hello world";
    char *exp[] = {"hello", "world", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test2(void) {
    char *input = "echo foo | grep \'foo\'";
    char *exp[] = {"echo", "foo", "|", "grep", "\'foo\'", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test3(void) {
    char *input = "cat < infile";
    char *exp[] = {"cat", "<", "infile", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test4(void) {
    char *input = "echo foo > outfile";
    char *exp[] = {"echo", "foo", ">", "outfile", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test5(void) {
    char *input = "echo foo >> outfile";
    char *exp[] = {"echo", "foo", ">>", "outfile", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test6(void) {
    char *input = "<< EOF";
    char *exp[] = {"<<", "EOF", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test7(void) {
    char *input = "echo 'a b' c";
    char *exp[] = {"echo", "'a b'", "c", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test8(void) {
    char *input = "echo \"a b\" c";
    char *exp[] = {"echo", "\"a b\"", "c", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test9(void) {
    char *input = "echo $";
    char *exp[] = {"echo", "$", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test10(void) {
    char *input = "echo $USER";
    char *exp[] = {"echo", "$USER", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test11(void) {
    char *input = "echo this\"is 'a'\"test >>> cat || ls";
    char *exp[] = {"echo", "this\"is 'a'\"test", ">>", ">", "cat", "|", "|", "ls", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test12(void) {
    char *input = "<< del      file1 >| ./path/file2";
    char *exp[] = {"<<", "del", "file1", ">", "|", "./path/file2", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test13(void) {
    char *input = "<\"cat\"|echo\"test\"|ls";
    char *exp[] = {"<", "\"cat\"", "|", "echo\"test\"", "|", "ls", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void simple_test14(void) {
    char *input = "echo 'a \"b\" c'";
    char *exp[]  = {"echo", "'a \"b\" c'", NULL};
    assert_tokens(input, exp, exp_len(exp));
}


// PIPES
void test_pipe_1(void) {
    char *input = "ls | wc";
    char *exp[] = {"ls", "|", "wc", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_pipe_2(void) {
    char *input = "cat file | grep test | sort";
    char *exp[] = {"cat", "file", "|", "grep", "test", "|", "sort", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_pipe_3(void) {
    char *input = "echo hi|wc -l";
    char *exp[] = {"echo", "hi", "|", "wc", "-l", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_pipe_4(void) {
    char *input = "   ls    |    wc   ";
    char *exp[] = {"ls", "|", "wc", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_pipe_5(void) {
    char *input = "ls|grep main|sort|uniq";
    char *exp[] = {"ls", "|", "grep", "main", "|", "sort", "|", "uniq", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_pipe_6(void) {
    char *input = "|| echo hi";
    char *exp[] = {"|", "|", "echo", "hi", NULL};
    assert_tokens(input, exp, exp_len(exp));
}


// QUOTES
void test_quote_1(void) {
    char *input = "echo \"this is 'a' test\"";
    char *exp[] = {"echo", "\"this is 'a' test\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_quote_2(void) {
    char *input = "echo 'this is \"a\" test'";
    char *exp[] = {"echo", "'this is \"a\" test'", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_quote_3(void) {
    char *input = "echo this\"is\"a\"test\"";
    char *exp[] = {"echo", "this\"is\"a\"test\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_quote_4(void) {
    char *input = "echo \"\"";
    char *exp[] = {"echo", "\"\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_quote_5(void) {
    char *input = "echo 'hello world' \"foo bar\"";
    char *exp[] = {"echo", "'hello world'", "\"foo bar\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_quote_6(void) {
    char *input = "echo \"'nested' quotes\"";
    char *exp[] = {"echo", "\"'nested' quotes\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_quote_7(void) {
    char *input = "echo '\"double\" inside single'";
    char *exp[] = {"echo", "'\"double\" inside single'", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

// void test_quote_8(void) {
//     char *input = "echo \"unclosed";
//     char *exp[] = {"echo", "\"unclosed", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }


// REDIRECTIONS
void test_redir_1(void) {
    char *input = "< infile > outfile";
    char *exp[] = {"<", "infile", ">", "outfile", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_redir_2(void) {
    char *input = ">> appendfile";
    char *exp[] = {">>", "appendfile", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_redir_3(void) {
    char *input = "ls >| force_write";
    char *exp[] = {"ls", ">", "|", "force_write", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_redir_4(void) {
    char *input = "<infile cmd >outfile";
    char *exp[] = {"<", "infile", "cmd", ">", "outfile", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_redir_5(void) {
    char *input = "<<EOF cat >>log";
    char *exp[] = {"<<", "EOF", "cat", ">>", "log", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_redir_6(void) {
    char *input = "echo >   > file";
    char *exp[] = {"echo", ">", ">", "file", NULL};
    assert_tokens(input, exp, exp_len(exp));
}


// VARIABLE
void test_var_1(void) {
    char *input = "echo $USER";
    char *exp[] = {"echo", "$USER", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_var_2(void) {
    char *input = "echo ${HOME}";
    char *exp[] = {"echo", "${HOME}", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_var_3(void) {
    char *input = "echo \"$USER is logged in\"";
    char *exp[] = {"echo", "\"$USER is logged in\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_var_4(void) {
    char *input = "echo $?";
    char *exp[] = {"echo", "$?", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_var_5(void) {
    char *input = "echo $USER$PATH";
    char *exp[] = {"echo", "$USER$PATH", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_var_6(void) {
    char *input = "echo \"hi $USER\"";
    char *exp[] = {"echo", "\"hi $USER\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void test_var_7(void) {
    char *input = "$VAR=hello";
    char *exp[] = {"$VAR=hello", NULL};
    assert_tokens(input, exp, exp_len(exp));
}


// OUTHER_TESTS
void other_test_1(void) {
    char *input = "echo \\$HOME";
    char *exp[] = {"echo", "\\","$HOME", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void other_test_2(void) {
    char *input = "ls *";
    char *exp[] = {"ls", "*", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void other_test_3(void) {
    char *input = "ls file?.txt";
    char *exp[] = {"ls", "file?.txt", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void other_test_4(void) {
    char *input = "echo {a,b,c}";
    char *exp[] = {"echo", "{a,b,c}", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

// void other_test_5(void) {
//     char *input = "echo \"hi\\\"there\"";
//     char *exp[] = {"echo", "\"hi\\\"there\"", NULL};
//     assert_tokens(input, exp, exp_len(exp));
// }

void other_test_6(void) {
    char *input = "./script.sh arg1 arg2";
    char *exp[] = {"./script.sh", "arg1", "arg2", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void other_test_7(void) {
    char *input = "echo `uname -s`";
    char *exp[] = {"echo", "`uname -s`", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void other_test_8(void) {
    char *input = "(echo hi)";
    char *exp[] = {"(", "echo", "hi", ")", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void other_test_9(void) {
    char *input = "echo \"$(whoami)\"";
    char *exp[] = {"echo", "\"$(whoami)\"", NULL};
    assert_tokens(input, exp, exp_len(exp));
}

void other_test_10(void) {
    char *input = "echo $((1 + 2))";
    char *exp[] = {"echo", "$((1 + 2))", NULL};
    assert_tokens(input, exp, exp_len(exp));
}


int tester(void) {
    UNITY_BEGIN();
    
    // SIMPLE TESTS
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
    
    // PIPE TESTS
    RUN_TEST(test_pipe_1);
    RUN_TEST(test_pipe_2);
    RUN_TEST(test_pipe_3);
    RUN_TEST(test_pipe_4);
    RUN_TEST(test_pipe_5);
    RUN_TEST(test_pipe_6);


    // QUOTE TESTS
    RUN_TEST(test_quote_1);
    RUN_TEST(test_quote_2);
    RUN_TEST(test_quote_3);
    RUN_TEST(test_quote_4);
    RUN_TEST(test_quote_5);
    RUN_TEST(test_quote_6);
    RUN_TEST(test_quote_7);
    // RUN_TEST(test_quote_8);


    // REDIRECTIONS TESTS
    RUN_TEST(test_redir_1);
    RUN_TEST(test_redir_2);
    RUN_TEST(test_redir_3);
    RUN_TEST(test_redir_4);
    RUN_TEST(test_redir_5);
    RUN_TEST(test_redir_6);


    // VARIABLE TESTS
    RUN_TEST(test_var_1);
    RUN_TEST(test_var_2);
    RUN_TEST(test_var_3);
    RUN_TEST(test_var_4);
    RUN_TEST(test_var_5);
    RUN_TEST(test_var_6);
    RUN_TEST(test_var_7);


    // OUTHER TESTS
    RUN_TEST(other_test_1);
    RUN_TEST(other_test_2);
    RUN_TEST(other_test_3);
    RUN_TEST(other_test_4);
    // RUN_TEST(other_test_5);
    RUN_TEST(other_test_6);
    RUN_TEST(other_test_7);
    RUN_TEST(other_test_8);
    RUN_TEST(other_test_9);
    RUN_TEST(other_test_10);

	return (UnityEnd());
}
