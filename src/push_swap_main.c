#include<push_swap.h>
#include<stdio.h>

// void print_input(int argc, char **argv);
// void	ft_putstr_fd(char *s, int fd);
void input_to_ar(int argc, char **argv);
int only_digits(char *s);
void make_arr(int value, int **arr, int *capacity, int *length);
int within_int_range(char *s);
void print_error(void);
void lex_comparison(char *s, char *value);

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    // print_input(argc, argv);
    input_to_ar(argc, argv);

	return(0);
}

void input_to_ar(int argc, char **argv)
{
    int i;
    int j;
    char **split_argv;

    int capacity = 5;
    int *new_arr = malloc(sizeof(int) * capacity);
    if (!new_arr)
        return ;
    int length = 0;

    i = 1;
    while (i < argc)
    {
        if (only_digits(argv[i]))
        {
            split_argv = ft_split(argv[i], ' ');
            j = 0;
            while(split_argv[j])
            {
                if (within_int_range(split_argv[j]))
                {                
                    int value = atoi(split_argv[j]);
                    make_arr(value, &new_arr, &capacity, &length);
                }
                j++;
            }
        }
        i++;
    }
    printf("ar length - %d\n", length);
    printf("ar capacity - %d\n", capacity);

    i = 0;
    while (i < length)
    {
        printf("%d ", new_arr[i]);
        i++;
    }
}

void make_arr(int value, int **arr, int *capacity, int *length)
{
    int *temp_arr = NULL;
    int i = 0;

    if (*length >= *capacity)
    {
        *capacity *= 2;
        temp_arr = malloc(sizeof(int) * (*capacity));
        while(i < *length)
        {
            temp_arr[i] = (*arr)[i];
            i++;
        }
        free(*arr);
        *arr = temp_arr;
    }
    (*arr)[*length] = value;
    (*length)++;
}

int only_digits(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] != ' ' && s[i] != '-' && !ft_isdigit(s[i]))
            print_error();
        i++;
    }
    return (1);
}

int within_int_range(char *s)
{
    int is_negative;
    size_t len_s;
    char *max;
    char *min;

    max = "2147483647";
    min = "-2147483648";
    is_negative = 0;

    if (*s++ == '-')
        is_negative = 1;
    while(*s == '0')
        s++;
    if (*s == '\0')
        return (1);
    len_s = ft_strlen(s);
    if (is_negative && len_s == ft_strlen(min) - 1)
        lex_comparison(s, min + 1);
    else if (len_s == ft_strlen(max))
        lex_comparison(s, max);
    else if (ft_strlen(max) < len_s || (is_negative && ft_strlen(min) - 1 < len_s))
        print_error();
    return (1);
}
void lex_comparison(char *s, char *value)
{
    int i;

    i = 0;
    while (value[i])
    {
        if (s[i] > value[i])
            print_error();
        i++;
    }
}

void print_error(void)
{
    write(2, "Error\n", 6);
    exit (1);
}

// void print_input(int argc, char **argv)
// {
//     int i = 1;
//     int j;
//     char **split;

//     while (i < argc)
//     {
//         split = ft_split(argv[i], ' ');
//         j = 0;
//         while (split[j])
//         {
//             ft_putstr_fd(split[j], 1);
//             ft_putchar_fd('\n', 1);
//             j++;
//         }
//         i++;
//     }
// }

