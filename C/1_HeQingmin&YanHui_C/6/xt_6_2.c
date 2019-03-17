# include<stdio.h>
# include<math.h>



int main(void)
{
    int sum_word,switch_word;
    char ch;
   
   


    printf("please input the some word:");



    sum_word=0;
    switch_word=0;

    
    while((ch=getchar())!='.'){
        if(ch==' '&&switch_word==1){sum_word++;switch_word=0;}
        if(ch!=' '&&switch_word==0)switch_word=1;
    }

    if(switch_word==1)sum_word++;

    printf("the number of word is :%d\n",sum_word);

    return 0;
}

