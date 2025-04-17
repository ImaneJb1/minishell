/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeslaki <imeslaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:13:45 by imeslaki          #+#    #+#             */
/*   Updated: 2025/04/17 22:18:57 by imeslaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"




void setUp(void)
{
  
}
void tearDown(void)
{
    
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

/* Test cases for various redirections and pipes */

void test1(void) {
    char *input = "echo hello";
    char *exp[] = {"echo", "hello"};
    assert_tokens(input, exp, 2);
}

void test2(void) {
    char *input = "grep hi \"<infile\" <         ./test_files/infile";
    char *exp[] = {"grep", "hi", "\"<infile\"", "<", "./test_files/infile"};
    assert_tokens(input, exp, 5);
}

void test3(void) {
    char *input = "echo hi < ./test_files/infile bye bye";
    char *exp[] = {"echo", "hi", "<", "./test_files/infile", "bye", "bye"};
    assert_tokens(input, exp, 6);
}

void test4(void) {
    char *input = "grep hi <./test_files/infile_big <./test_files/infile";
    char *exp[] = {"grep", "hi", "<./test_files/infile_big", "<./test_files/infile"};
    assert_tokens(input, exp, 4);
}

void test5(void) {
    char *input = "echo <\"./test_files/infile\" \"bonjour       42\"";
    char *exp[] = {"echo", "<\"./test_files/infile\"", "\"bonjour       42\""};
    assert_tokens(input, exp, 3);
}

void test6(void) {
    char *input = "cat <\"./test_files/file name with spaces\"";
    char *exp[] = {"cat", "<\"./test_files/file name with spaces\""};
    assert_tokens(input, exp, 2);
}

void test7(void) {
    char *input = "cat <./test_files/infile_big ./test_files/infile";
    char *exp[] = {"cat", "<./test_files/infile_big", "./test_files/infile"};
    assert_tokens(input, exp, 3);
}

void test8(void) {
    char *input = "cat <\"1\"\"2\"\"3\"\"4\"\"5\"";
    char *exp[] = {"cat", "<\"1\"\"2\"\"3\"\"4\"\"5\""};
    assert_tokens(input, exp, 2);
}

void test9(void) {
    char *input = "echo <\"./test_files/infile\" <missing <\"./test_files/infile\"";
    char *exp[] = {"echo", "<\"./test_files/infile\"", "<missing", "<\"./test_files/infile\""};
    assert_tokens(input, exp, 4);
}

void test10(void) {
    char *input = "echo <missing <\"./test_files/infile\" <missing";
    char *exp[] = {"echo", "<missing", "<\"./test_files/infile\"", "<missing"};
    assert_tokens(input, exp, 4);
}

void test11(void) {
    char *input = "cat <\"./test_files/infile\"";
    char *exp[] = {"cat", "<\"./test_files/infile\""};
    assert_tokens(input, exp, 2);
}

void test12(void) {
    char *input = "echo <\"./test_files/infile_big\" | cat <\"./test_files/infile\"";
    char *exp[] = {"echo", "<\"./test_files/infile_big\"", "|", "cat", "<\"./test_files/infile\""};
    assert_tokens(input, exp, 5);
}

void test13(void) {
    char *input = "echo <\"./test_files/infile_big\" | cat \"./test_files/infile\"";
    char *exp[] = {"echo", "<\"./test_files/infile_big\"", "|", "cat", "\"./test_files/infile\""};
    assert_tokens(input, exp, 5);
}

void test14(void) {
    char *input = "echo <\"./test_files/infile_big\" | echo <\"./test_files/infile\"";
    char *exp[] = {"echo", "<\"./test_files/infile_big\"", "|", "echo", "<\"./test_files/infile\""};
    assert_tokens(input, exp, 5);
}

void test15(void) {
    char *input = "echo hi | cat <\"./test_files/infile\"";
    char *exp[] = {"echo", "hi", "|", "cat", "<\"./test_files/infile\""};
    assert_tokens(input, exp, 5);
}

void test16(void) {
    char *input = "echo hi | cat \"./test_files/infile\"";
    char *exp[] = {"echo", "hi", "|", "cat", "\"./test_files/infile\""};
    assert_tokens(input, exp, 5);
}

void test17(void) {
    char *input = "cat <\"./test_files/infile\" | echo hi";
    char *exp[] = {"cat", "<\"./test_files/infile\"", "|", "echo", "hi"};
    assert_tokens(input, exp, 5);
}

void test18(void) {
    char *input = "cat <\"./test_files/infile\" | grep hello";
    char *exp[] = {"cat", "<\"./test_files/infile\"", "|", "grep", "hello"};
    assert_tokens(input, exp, 5);
}

void test19(void) {
    char *input = "cat <\"./test_files/infile_big\" | echo hi";
    char *exp[] = {"cat", "<\"./test_files/infile_big\"", "|", "echo", "hi"};
    assert_tokens(input, exp, 5);
}

void test20(void) {
    char *input = "cat <missing";
    char *exp[] = {"cat", "<missing"};
    assert_tokens(input, exp, 2);
}

void test21(void) {
    char *input = "cat <missing | cat";
    char *exp[] = {"cat", "<missing", "|", "cat"};
    assert_tokens(input, exp, 4);
}

void test22(void) {
    char *input = "cat <missing | echo oi";
    char *exp[] = {"cat", "<missing", "|", "echo", "oi"};
    assert_tokens(input, exp, 5);
}

void test23(void) {
    char *input = "cat <missing | cat <\"./test_files/infile\"";
    char *exp[] = {"cat", "<missing", "|", "cat", "<\"./test_files/infile\""};
    assert_tokens(input, exp, 5);
}

void test24(void) {
    char *input = "echo <123 <456 hi | echo 42";
    char *exp[] = {"echo", "<123", "<456", "hi", "|", "echo", "42"};
    assert_tokens(input, exp, 7);
}

void test25(void) {
    char *input = "ls >./outfiles/outfile01";
    char *exp[] = {"ls", ">./outfiles/outfile01"};
    assert_tokens(input, exp, 2);
}

void test26(void) {
    char *input = "ls >         ./outfiles/outfile01";
    char *exp[] = {"ls", ">", "./outfiles/outfile01"};
    assert_tokens(input, exp, 3);
}

void test27(void) {
    char *input = "echo hi >         ./outfiles/outfile01 bye";
    char *exp[] = {"echo", "hi", ">", "./outfiles/outfile01", "bye"};
    assert_tokens(input, exp, 5);
}

void test28(void) {
    char *input = "ls >./outfiles/outfile01 >./outfiles/outfile02";
    char *exp[] = {"ls", ">./outfiles/outfile01", ">./outfiles/outfile02"};
    assert_tokens(input, exp, 3);
}

void test29(void) {
    char *input = "ls >./outfiles/outfile01 >./test_files/invalid_permission";
    char *exp[] = {"ls", ">./outfiles/outfile01", ">./test_files/invalid_permission"};
    assert_tokens(input, exp, 3);
}

void test30(void) {
    char *input = "ls >\"./outfiles/outfile with spaces\"";
    char *exp[] = {"ls", ">\"./outfiles/outfile with spaces\""};
    assert_tokens(input, exp, 2);
}

void test31(void) {
    char *input = "ls >\"./outfiles/outfile\"\"1\"\"2\"\"3\"\"4\"\"5\"";
    char *exp[] = {"ls", ">\"./outfiles/outfile\"\"1\"\"2\"\"3\"\"4\"\"5\""};
    assert_tokens(input, exp, 2);
}

void test32(void) {
    char *input = "ls >\"./outfiles/outfile01\" >./test_files/invalid_permission >\"./outfiles/outfile02\"";
    char *exp[] = {"ls", ">\"./outfiles/outfile01\"", ">./test_files/invalid_permission", ">\"./outfiles/outfile02\""};
    assert_tokens(input, exp, 4);
}

void test33(void) {
    char *input = "ls >./test_files/invalid_permission >\"./outfiles/outfile01\" >./test_files/invalid_permission";
    char *exp[] = {"ls", ">./test_files/invalid_permission", ">\"./outfiles/outfile01\"", ">./test_files/invalid_permission"};
    assert_tokens(input, exp, 4);
}

void test34(void) {
    char *input = "cat <\"./test_files/infile\" >\"./outfiles/outfile01\"";
    char *exp[] = {"cat", "<\"./test_files/infile\"", ">\"./outfiles/outfile01\""};
    assert_tokens(input, exp, 3);
}

void test35(void) {
    char *input = "echo hi >./outfiles/outfile01 | echo bye";
    char *exp[] = {"echo", "hi", ">./outfiles/outfile01", "|", "echo", "bye"};
    assert_tokens(input, exp, 6);
}

void test36(void) {
    char *input = "echo hi >./outfiles/outfile01 >./outfiles/outfile02 | echo bye";
    char *exp[] = {"echo", "hi", ">./outfiles/outfile01", ">./outfiles/outfile02", "|", "echo", "bye"};
    assert_tokens(input, exp, 7);
}

void test37(void) {
    char *input = "echo hi | echo >./outfiles/outfile01 bye";
    char *exp[] = {"echo", "hi", "|", "echo", ">./outfiles/outfile01", "bye"};
    assert_tokens(input, exp, 6);
}

int	tester(void)
{
    char *str;

	RUN_TEST(test1);
    // RUN_TEST(test2);
    // RUN_TEST(test3);
    // RUN_TEST(test4);
    // RUN_TEST(test5);
    // RUN_TEST(test6);
    // RUN_TEST(test7);
    // RUN_TEST(test8);
    // RUN_TEST(test9);
    // RUN_TEST(test10);
    // RUN_TEST(test11);
    // RUN_TEST(test12);
    // RUN_TEST(test13);
    // RUN_TEST(test14);
    // RUN_TEST(test15);
    // RUN_TEST(test16);
    // RUN_TEST(test17);
    // RUN_TEST(test18);
    // RUN_TEST(test19);
    // RUN_TEST(test20);
    // RUN_TEST(test21);
    // RUN_TEST(test22);
    // RUN_TEST(test23);
    // RUN_TEST(test24);
    // RUN_TEST(test25);
    // RUN_TEST(test26);
    // RUN_TEST(test27);
    // RUN_TEST(test28);
    // RUN_TEST(test29);
    // RUN_TEST(test30);
    // RUN_TEST(test31);
    // RUN_TEST(test32);
    // RUN_TEST(test33);
    // RUN_TEST(test34);
    // RUN_TEST(test35);
    // RUN_TEST(test36);
    // RUN_TEST(test37);
	return (UnityEnd());
}

	// str = separat_with_one_space("echo bonjour ; |");
 	// str = separat_with_one_space("echo bonjour | |");
 	// str = separat_with_one_space("|");
 	// str = separat_with_one_space("echo bonjour |;");
 	// str = separat_with_one_space("echo bonjour ; ls");
 	// str = separat_with_one_space("echo bonjour > test\ 1");
 	// str = separat_with_one_space("cd $HOME/Documents");
 	// str = separat_with_one_space("echo \"\s\" & echo \"\s\"");
 	// str = separat_with_one_space("echo >");
 	// str = separat_with_one_space("echo -n -n -nnnn -nnnnm");
 	// str = separat_with_one_space("cat /dev/random | head -n 1 | cat -e");
 	// str = separat_with_one_space("unset var1 # with undefined var1");
 	// str = separat_with_one_space("export "" et unset """);
 	// str = separat_with_one_space("echo test > file test1");
 	// str = separat_with_one_space("$");
 	// str = separat_with_one_space("not_cmd bonjour > salut");
 	// str = separat_with_one_space("env puis export puis env # vars aren't sorted");
 	// str = separat_with_one_space("cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code");
 	// str = separat_with_one_space("cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code");
 	// str = separat_with_one_space("cat Makefile | grep pr | head -n 5 | hello (NA) # check status code");
 	// str = separat_with_one_space("echo bonjour >>> test");
 	// str = separat_with_one_space("echo bonjour > > out");
 	// str = separat_with_one_space("echo 2 >> out1 > out2");
	// str = separat_with_one_space("echo hudifg d | | hugdfihd");
 	// str = separat_with_one_space("echo");
 	// str = separat_with_one_space("echo simple");
 	// str = separat_with_one_space("echo -n simple");
 	// str = separat_with_one_space("echo \'\'");
 	// str = separat_with_one_space("echo \"\"");
 	// str = separat_with_one_space("echo \"\"");
 	// str = separat_with_one_space("echo \"\n \n \n\"");
 	// str = separat_with_one_space("echo \"\n \n \\n\"");
	// str = separat_with_one_space("echo \'hello|world!\'test_test |cat -e| ls     -la>file     ");
	// str = separat_with_one_space("> a ls > b < Makefile");