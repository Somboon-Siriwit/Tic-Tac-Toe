#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

struct myDataType{
    int i;
    char choice;
}inputValue();


void main(){
    char ch[1];
    again:
    play();
    printf("\n\t\t\t\t\t\tDo you want to play again (y/n) : ");
    scanf("%s",ch);
    PlaySound(TEXT("C:\\For C\\CProject\\Osound.wav"),NULL,SND_SYNC);
    do
    {
        if(*ch == 'y')
            goto again;
        else if (*ch == 'n')
            exit(0);
        else
            printf("\t\t\t\t\t\tPlease choose again (y/n): ");
            scanf("%s",ch);
    }while(ch != 'y' || ch != 'n');
}


void play(){
    int count=0;
    struct myDataType info;
    char sym[9] = {'1','2','3','4','5','6','7','8','9'};
    Drawboard(sym);
    Again:
    info = inputValue(sym,count);
    sym[info.i] = info.choice;
    Drawboard(sym);
    if(CheckWin(sym,info.choice, count) == 1);
    else{
    count ++;
    goto Again;
    }
}

int CheckWin(char square[9],char choice[1], int count){
    int i;
    for(i=0;i<3;i++)
    if(square[i] == choice && square[i+1] == choice && square[i+2] == choice){
            printf("The WINNER is : %c",choice);
            PlaySound(TEXT("C:\\For C\\CProject\\Ta Da-SoundBible.com-1884170640.wav"),NULL,SND_SYNC);
            return 1;
        }
    for(i=0;i<3;i++)
    if(square[i] == choice && square[i+3] == choice && square[i+6] == choice){
            printf("\t\t\t\t\t\t    The WINNER is : %c",choice);
            PlaySound(TEXT("C:\\For C\\CProject\\Ta Da-SoundBible.com-1884170640.wav"),NULL,SND_SYNC);
            return 1;
        }
    if(square[0] == choice && square[4] == choice && square[8] == choice){
            printf("\t\t\t\t\t\t    The WINNER is : %c",choice);
            PlaySound(TEXT("C:\\For C\\CProject\\Ta Da-SoundBible.com-1884170640.wav"),NULL,SND_SYNC);
            return 1;
        }
    else if(square[2] == choice && square[4] == choice && square[6] == choice){
            printf("\t\t\t\t\t\t    The WINNER is : %c",choice);
            PlaySound(TEXT("C:\\For C\\CProject\\Ta Da-SoundBible.com-1884170640.wav"),NULL,SND_SYNC);
            return 1;
        }
    else if (count == 8){
        printf("\t\t\t\t\t\t    The Game is Draw");
        return 1;
    }
    else
        return 0;
}

struct myDataType inputValue(char sym[9], int count){
    char value[1];
    int i;
    struct myDataType info;
    inputAgain:
    if (count %2 == 0){
        printf("\n\t\t\t\t\t\tEnter number to mark X : ");
    }else{
        printf("\n\t\t\t\t\t\tEnter number to mark O : ");
    }
    scanf("%s",value);
    for (i=0;i<9;i++){
        if(*value == sym[i]){
            info.i = i;
            if(count % 2 == 0){
                PlaySound(TEXT("C:\\raylib\\raylib\\examples\\textures\\resources\\buttonfx.wav"),NULL,SND_SYNC);
                info.choice = 'X';
            }else{
                PlaySound(TEXT("C:\\For C\\CProject\\Osound.wav"),NULL,SND_SYNC);
                info.choice = 'O';
            }break;
        }else{
            info.i = -1;
            info.choice = "";
        }
    }
    if(info.i == -1){
        printf("\n\t\t\t\t\t\tInvalid Move !!!\n");
        PlaySound(TEXT("C:\\For C\\CProject\\bruh.wav"),NULL,SND_SYNC);
        goto inputAgain;
    }
    return info;
};


void Drawboard(char square[9]){
    system("cls");
    printf("\n\n\t\t\t\t\t\t      Tic Tac Toe \n\n");
    printf("\t\t\t\t\t\tPlayer1 (X) - Player2 (O) \n\n\n");
    printf(" \t\t\t\t\t\t   ------------------\n");
    printf(" \t\t\t\t\t\t  |     |     |      |\n");
    printf(" \t\t\t\t\t\t  |  %c  |  %c  |  %c   |\n",square[0],square[1],square[2]);
    printf(" \t\t\t\t\t\t  |     |     |      |\n");
    printf(" \t\t\t\t\t\t   ------------------\n");
    printf(" \t\t\t\t\t\t  |     |     |      |\n");
    printf(" \t\t\t\t\t\t  |  %c  |  %c  |  %c   |\n",square[3],square[4],square[5]);
    printf(" \t\t\t\t\t\t  |     |     |      |\n");
    printf(" \t\t\t\t\t\t   ------------------\n");
    printf(" \t\t\t\t\t\t  |     |     |      |\n");
    printf(" \t\t\t\t\t\t  |  %c  |  %c  |  %c   |\n",square[6],square[7],square[8]);
    printf(" \t\t\t\t\t\t  |     |     |      |\n");
    printf(" \t\t\t\t\t\t   ------------------\n");
}



