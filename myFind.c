#ifndef _MY_FIND_
#define _MY_FIND_
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int getaline(char s[],char origin[])
{
    char c;
    int i=0;
    c=origin[i];
    while(c!='\n' &&c!='\0' &&c!='\r' &&i<LINE)
    {
    
        s[i]=c;
        i++;
        c=origin[i];
        
    }
    
   return i;
}

int getword(char *w,char *origin){
    int i=0;
     char c=origin[i];
    while (c!='\0' && c!='\n' && c!='\t' && c!=' ' &&c!='\r' && i<LINE )
    {
        w[i]=c;
        i++;
        c=origin[i];
        
    }
    return i;
}

int substring( char * str1, char * str2)
{
    int len1=strlen(str1);
    int len2=strlen(str2);
    if (len1<len2)
        return 0;
    
    else
    {
    
    
        int i=0;
        int j=0;
        while(str1[i]!='\0')
        {
            if(str2[j]!='\0')
            {
                if(str1[i]==str2[j])
                {
                    j++;
                }
                else if (j)
                {
                    j=0;
                }
            
            i++; 
            }
            
            else
                return 1;
        }
         if(j==len2)
            return 1;
        
        return 0;   
    
    }
}


int similar (char *s, char *t, int n)
{ 
    if(strlen(s)<strlen(t))
        return 0;
    int i=0;
    int dif=0;
    int sim=0;
    while(s[i]!='\0' &&dif<=n)
    {
        if(s[i]!=t[sim])
        {
            dif++;
        }
        else
        {
            sim++;
        }
        i++;

    }

    if(dif<=n)
        return 1;
    
    return 0;
    
}

void print_lines(char * sub, char * str)
{
    
    int i=0;
    while(str[i]!='\0')
    {   char line[LINE]={0};
        int nl= getaline(line,str+i);
        if(nl!=0)
        {
           
            int j=0;
            int flag=0;
            while(line[j]!='\0' &&flag!=1)
            {  
                char word[WORD]={0};
                int nw= getword(word,line+j);
                
                if(nw!=0)
                {
                    if(substring(word,sub))
                    {
                        flag=1;
                    }
                }
                else
                    nw++;
                
                
                if(flag)
                {
                    printf("%s\n",line);
                }
                else
                    j+=nw;
            }
            
            
        }
        else
        {
            nl++;
        }
        i+=nl;

    }
}

void print_similar_words(char * sub,char * str)
{
    int i=0;
    while(str[i]!='\0')
    {  
        char word[WORD]={0};
        int nw= getword(word,str+i);
       
        if(nw!=0)
        {
            if(similar(word,sub,1))
            {
                printf("%s\n",word);
            }
        }
        else
            nw++;
        
        i+=nw;
    }
}

int main()
{
    char text[250*WORD]={'\0'};
    char ct=getchar();
    int i=0;
    while(ct!=EOF)
    {
        text[i]=ct;
        ct=getchar();
        i++;
    }
    char word[WORD]={'\0'};
    int indexOption=getword(word,text);
    char option[WORD]={'\0'};
    getword(option,text+indexOption+1);
    int index=indexOption+4;
    if(option[0]=='a')
        print_lines(word,text+index);
    else
    {
        print_similar_words(word,text+index);
    }
    return 0;

}

#endif

