#include<stdio.h>

void result(int x){

    int y = x%6,z = x/6;

    switch(y){

        case 0:

            if(z%2 == 0)

            printf("%d WS\n",x-11);

            else

            printf("%d WS\n",x+1);

            break;

        case 1:

            if(z%2 == 0)

            printf("%d WS\n",x+11);

            else

            printf("%d WS\n",x-1);

            break;

        case 2:

            if(z%2 == 0)

            printf("%d MS\n",x+9);

            else

            printf("%d MS\n",x-3);

            break;

        case 3:

            if(z%2 == 0)

            printf("%d AS\n",x+7);

            else

            printf("%d AS\n",x-5);

            break;

        case 4:

            if(z%2 == 0)

            printf("%d AS\n",x+5);

            else

            printf("%d AS\n",x-7);

            break;

        case 5:

            if(z%2 == 0)

            printf("%d MS\n",x+3);

            else

            printf("%d MS\n",x-9);

            break;

    }

}


 

int main(void){

    int T =0;

    scanf(" %d",&T);

    for(int i=0;i<T;i++){

        int num =0;

        scanf(" %d",&num);

        result(num);

    }

    return 0;

