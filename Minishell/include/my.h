/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my
*/

#ifndef MYH
    #define MYH

void my_putchar(char c);
int my_putstr(char const *str);
int prmpt_display();
int count_space(char *str);
char *after_space(char *str);
int executer(char *str, char **tab);
int exe_long(char *path, char **tab);
char *my_strcat (char *dest, char const *src);
int exe_short(char *com, char *path, char **tb);
int arr_len(char *str);
int my_strcmp(const char *s1, const char *s2);
int my_pf_long(char *str);
int my_pf_short(char *str);
char *my_envset (char **tb);
char *my_unsetenv(char **tb);
int my_envpars(char **tb);
int my_cd(char **tab);
int my_strlen(char const *str);
int my_strncmp(int x, const char *s1, const char *s2);
int mouli_test(char **env);
char **my_getenv(char **env);
int authoriz_sh(char *str);
char **long_arr(char *str, char **tb, char spc, int count);
char **short_arr(char *str);
char **my_str_to_word_array(char *str, char spc);
int separator(char *str, char **env);
int my_detector(char *str);
int index_word(char *str);
char *space_remove(char *str);
int for_len(char *str);
int my_comma(char *str, char **env);
int basic_redirect(char *str, char **env);
int basic_redirect2(char *str, char **env);
int detect_pipe(char *str, char **env);
int command_exe2(char *buffer);
void command_exe(char *buff, char **env);

#endif /* !MYH */