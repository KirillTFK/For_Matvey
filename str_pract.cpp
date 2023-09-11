#include <stdio.h>
#include <string.h>

 const unsigned SIZE = 100;

int    myputs (const char* str);//const. Сделано!
char*  mygets (const char* str);
char*  mystrchr (const char* str, int ch);
size_t mystrlen (const char* str);
char*  mystrcpy ( char* s1, const char* s2); //переименовать
char*  mystrncpy (char* s1, const char* s2, size_t n);
char*  mystrcat (char* s1, const char* s2);
char*  mystrncat (char* s1, const char* s2, size_t n);
char*  myfgets (char* s1, int max, FILE*const adres);


int main (void)
{
    FILE* adres = 0;

    adres = fopen("testtxt","r");

    printf ("%llu", adres);
}

char* mygets (char* str)
{
    unsigned i = 0;
    char ch = 0;

    printf ("ВНИМАНИЕ! эта функция бувально является моей версией функции "
            "gets, которая признана небезопасной, пожалуйста, не используйте"
            " эту функцию\n");

    while ((ch = getchar ()) != '\n' && ch != EOF)
    {
        str[i] = ch;
        i++;
    }
    

    if (ch == '\n')
    {
        str[i] = '\0';
        return str;
    }

    else
        return NULL;
    
}

int myputs (const char* str)
{
    char ch = 0;
    int i = 0;

    while( str[i] != '\0' && str[i] != EOF)
    {
        printf ("%c", str[i]);
        i++;
    }

    ch = str[i];
    
    if (ch == '\0')
    {
        putchar ('\n');
        return 1;
    }

    else
    {
        return EOF;
    }
    
}

char* mystrchr (char*str, int ch)
{
    int check = 0;
    int i = 0;//переплести функции

    while ((int)str[i] != ch && str[i] != '\0') 
    {
        printf ("%d %d\n", str[i], ch);
        i++;
    }
    
    check = str[i];
    
    if (check == ch)
        return &str[i];
         
    else 
        return NULL;

}

size_t mystrlen (const char* str)
{
    unsigned count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count ++;

    return count;
}

char* mystrcpy (char* s1,const char* s2)
{
    int i = 0;

    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    
    return s1;
}

char* mystrncpy (char* s1, const char* s2, size_t n)
{
    int i = 0;
    while (i<n)
    {
        if (s2[i] == '\0')
        {
            while (i<n)
            {
                s1[i]='\0';
                i++;
            }
            return s1;
        }

        s1[i] = s2[i];
        i++;
        
    }
    return s1;
}

char* mystrcat (char* s1, const char* s2)
{
    int i = 0;

    printf ("Внимание, использование этой функции не безопасно, она "
            "может выйти за пределы массива, в котором хранится строка s1 "
            "пожалуйста, будте внимательны при ее использовании\n");

    while (s1[i] != '\0')
        i++;
    
    for (int j = 0; s2[j] != 0; j++)
    {
        s1[i] = s2[j];

        i++;
    }

    s1[i] = '\0';

    return s1;

    
}

char*  mystrncat (char* s1, const char* s2, size_t n)
{

    printf ("Внимание, использование этой функции не безопасно, она "
            "может выйти за пределы массива, в котором хранится строка s1 "
            "пожалуйста, будте внимательны при ее использовании\n");

    if (n > strlen(s2))
    {
        int i = 0;

    while (s1[i] != '\0')
        i++;
    
    for (int j = 0; s2[j] != 0; j++)
    {
        s1[i] = s2[j];

        i++;
    }

    s1[i] = '\0';

    return s1;

    }

    if (n <= strlen(s2))
    {
        int i = 0;

        while (s1[i] != '\0')
            i++;
        
        for (int j = 0; j < n; j++)
        {
            s1[i] = s2[j];

            i++;
        }

        s1[i] = '\0';

        return s1;
            
    }
}

char* myfgets (char* s1, int max, FILE*const adres )
{
    
}