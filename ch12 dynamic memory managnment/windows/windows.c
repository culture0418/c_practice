//! strchr

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // todo: Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}

Location *parse_url(char *url)
{
    Location *l = malloc(sizeof(Location) * 1);
    char url_cpy[500];
    strcpy(url_cpy, url);

    int index = -1;

    // todo : 切出 [protocol]
    char *token;
    token = strtok(url_cpy, ":");
    index += strlen(token);
    // printf("token = %s\n", token);
    l->protocol = token;

    index += 3; // todo : index move for "://"

    // todo : 切出 [host]
    token = strtok(NULL, ": / ? # \n");
    index += strlen(token);
    // printf("token = %s\n", token);
    l->host = token;

    index += 1; // todo : host 下一個位置字元

    // todo : check 有沒有 port
    if (url[index] == ':') // todo : 後面接port
    {
        // todo : 切出 [port]
        token = strtok(NULL, "/ ? # \n");
        // printf("token = %s\n", token);
        l->port = atoi(token);
        index += strlen(token);
        index += 1;
    }
    else
    {
        // printf("NO PORT\n");
        l->pathname = "";
    }

    // todo : check 有沒有 pathname
    if (url[index] == '/') // todo : 代表後面接 pathname
    {
        // todo : 切出[pathname]
        token = strtok(NULL, "? # \n");
        // printf("token = %s\n", token);
        l->pathname = token;
        index += strlen(token);
        index += 1;
    }
    else
    {
        // printf("NO PATHNAME\n");
        l->pathname = "";
    }

    // todo : check 有沒有 search
    if (url[index] == '?') // todo : 代表後面接 search
    {
        // todo : 切出[search]
        token = strtok(NULL, "# \n");
        // printf("token = %s\n", token);
        l->search = token;
        index += strlen(token);
        index += 1;
    }
    else
    {
        l->search = "";
    }

    // todo : check 有沒有 hash
    if (url[index] == '#') // todo : 代表後面接 hash
    {
        // todo : 切出[識別符號]
        token = strtok(NULL, "\n");
        // printf("token = %s\n", token);
        l->hash = token;
        index += strlen(token);
        index += 1;
    }
    else
    {
        // printf("NO HASH\n");
        l->hash = "";
    }

    return l;
}
