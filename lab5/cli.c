#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "types.h"
#include "cli.h"

void cli_get_string(char *msg, char *buf, size_t len)
{
    printf("%s", msg);
    fgets(buf, len, stdin);
    fflush(stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

long cli_get_number(char *msg)
{
    int num = 0;
    char str[11] = "";
    char *end = NULL;

    while (true)
    {
        cli_get_string(msg, str, sizeof (str));
        num = strtol(str, &end, 10);

        if (errno == 0 && str && *end != 0 || str == end) printf("Blad - nie podano liczby\n");
        else if (errno == ERANGE && num == LONG_MIN)      printf("Blad - wystapilo niedopelnienie\n");
        else if (errno == ERANGE && num == LONG_MAX)      printf("Blad - wystapilo przepelnienie\n");
        else break;
    }

    return num;
}