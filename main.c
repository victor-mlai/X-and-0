#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void init(int **mat)
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            mat[i][j] = 0;
}

int putX0(int **mat, int semn)  // pune X sau 0 daca are 2 de X sau 2 0 pe aceeasi linie/diagonala
{
    int i;
    //ver posibilitate 3 de semn
    for(i=0;i<3;i++)
    {
        if( mat[i][0] == 0 && mat[i][1] == semn && mat[i][2] == semn )    //ver fiecare linie
        {   mat[i][0] = semn;  return 1;    }
        if( mat[i][0] == semn && mat[i][1] == 0 && mat[i][2] == semn )
        {   mat[i][1] = semn;  return 1;    }
        if( mat[i][0] == semn && mat[i][1] == semn && mat[i][2] == 0 )
        {   mat[i][2] = semn;  return 1;    }

        if( mat[0][i] == 0 && mat[1][i] == semn && mat[2][i] == semn )    //ver fiecare coloana
        {   mat[0][i] = semn;  return 1;    }
        if( mat[0][i] == semn && mat[1][i] == 0 && mat[2][i] == semn )
        {   mat[1][i] = semn;  return 1;    }
        if( mat[0][i] == semn && mat[1][i] == semn && mat[2][i] == 0 )
        {   mat[2][i] = semn;  return 1;    }
    }

    if( mat[0][0] == 0 && mat[1][1] == semn && mat[2][2] == semn) //ver diag I
    {   mat[0][0] = semn;  return 1;    }
    if( mat[0][0] == semn && mat[1][1] == 0 && mat[2][2] == semn)
    {   mat[1][1] = semn;  return 1;    }
    if( mat[0][0] == semn && mat[1][1] == semn && mat[2][2] == 0)
    {   mat[2][2] = semn;  return 1;    }

    if( mat[0][2] == 0 && mat[1][1] == semn && mat[2][0] == semn) //ver diag II
    {   mat[0][2] = semn;  return 1;    }
    if( mat[0][2] == semn && mat[1][1] == 0 && mat[2][0] == semn)
    {   mat[1][1] = semn;  return 1;    }
    if( mat[0][2] == semn && mat[1][1] == semn && mat[2][0] == 0)
    {   mat[2][0] = semn;  return 1;    }

    //ver posibilitate 3 de 0 - semn
    for(i=0;i<3;i++)
    {
        if( mat[i][0] == 0 && mat[i][1] == 0 - semn && mat[i][2] == 0 - semn )    //ver fiecare linie
        {   mat[i][0] = semn;  return 1;    }
        if( mat[i][0] == 0 - semn && mat[i][1] == 0 && mat[i][2] == 0 - semn )
        {   mat[i][1] = semn;  return 1;    }
        if( mat[i][0] == 0 - semn && mat[i][1] == 0 - semn && mat[i][2] == 0 )
        {   mat[i][2] = semn;  return 1;    }

        if( mat[0][i] == 0 && mat[1][i] == 0 - semn && mat[2][i] == 0 - semn )    //ver fiecare coloana
        {   mat[0][i] = semn;  return 1;    }
        if( mat[0][i] == 0 - semn && mat[1][i] == 0 && mat[2][i] == 0 - semn )
        {   mat[1][i] = semn;  return 1;    }
        if( mat[0][i] == 0 - semn && mat[1][i] == 0 - semn && mat[2][i] == 0 )
        {   mat[2][i] = semn;  return 1;    }
    }

    if( mat[0][0] == 0 && mat[1][1] == 0 - semn && mat[2][2] == 0 - semn) //ver diag I
    {   mat[0][0] = semn;  return 1;    }
    if( mat[0][0] == 0 - semn && mat[1][1] == 0 && mat[2][2] == 0 - semn)
    {   mat[1][1] = semn;  return 1;    }
    if( mat[0][0] == 0 - semn && mat[1][1] == 0 - semn && mat[2][2] == 0)
    {   mat[2][2] = semn;  return 1;    }

    if( mat[0][2] == 0 && mat[1][1] == 0 - semn && mat[2][0] == 0 - semn) //ver diag II
    {   mat[0][2] = semn;  return 1;    }
    if( mat[0][2] == 0 - semn && mat[1][1] == 0 && mat[2][0] == 0 - semn)
    {   mat[1][1] = semn;  return 1;    }
    if( mat[0][2] == 0 - semn && mat[1][1] == 0 - semn && mat[2][0] == 0)
    {   mat[2][0] = semn;  return 1;    }

    return 0;
}

void play_with_IA(int **mat)    // IA "joaca"
{
    int i,j,r,win=0,mut=0,a,b;
    static int ia=0, pl=0, par_meci=1;

    if( par_meci == 1 )
    {
        citire_X_sau_0(mat,-1,&i,&j);

        if( i%2 == 1 && j%2 == 1 )    // daca am X pe vreun colt
        {
            mat[1][1] = 1;

            system("cls");  // golire consola
            afisare(mat);

            citire_X_sau_0(mat,-1,&i,&j);

            if( putX0(mat,1) == 0 )
            {
                printf("%d,%d\n",i,j);
                if( i%2 == j%2 )
                {
                    i = (rand())%4;
                    switch (i)
                    {
                        case 0: mat[0][1] = 1; break;
                        case 1: mat[1][0] = 1; break;
                        case 2: mat[1][2] = 1; break;
                        case 3: mat[2][1] = 1; break;
                        default: printf("%d WTF?\n",i); break;
                    }
                }
                else
                {
                    if( i%2 == 1 )
                    {
                        j = (rand())%2;
                        if( j != 0 )
                            j = 2;
                        mat[1][j] = 1;
                    }
                    if( j%2 == 1 )
                    {
                        i = (rand())%2;
                        if( i != 0 )
                            i = 2;
                        mat[i][1] = 1;
                    }
                }
            }

            system("cls");  // golire consola
            afisare(mat);

            while( win == 0 )
            {
                x_mijloc:
                citire_X_sau_0(mat,-1,&i,&j);
                system("cls");  // golire consola

                win = verif(mat);
                if( win )
                {
                    a=win;
                    afisare(mat);
                    break;
                }

                if( putX0(mat,1) == 0 && mut <2 )
                {
                    tryagain:    // pune random 0

                    i = (rand())%3;
                    j = (rand())%3;

                    if( mat[i][j] != 0 )
                        goto tryagain;
                    mat[i][j] = 1;
                }

                system("cls");  // golire consola
                afisare(mat);
                win = verif(mat);
                a=win;
                if( mut++ == 2 )
                    win = 1;
            }
        }
        else
            if( i==2 && j==2 )
            {
                r = (rand())%4;
                switch (r)
                {
                    case 0: a=0; b=0; mat[a][b] = 1; break;
                    case 1: a=2; b=0; mat[a][b] = 1; break;
                    case 2: a=0; b=2; mat[a][b] = 1; break;
                    case 3: a=2; b=2; mat[a][b] = 1; break;
                }

                system("cls");  // golire consola
                afisare(mat);
                citire_X_sau_0(mat,-1,&i,&j);

                if( a==3-i && b==3-j )
                {
                    r = (rand())%2;
                    printf("%d!!!!\n",r);
                    switch (r)
                    {
                        case 0: mat[2-a][b] = 1; break;
                        case 1: mat[a][2-b] = 1; break;
                    }
                    system("cls");  // golire consola
                    afisare(mat);

                    goto x_mijloc;
                }
                else
                {
                    if( putX0(mat,1) == 0 )
                        goto tryagain;
                    else
                    {
                        system("cls");  // golire consola
                        afisare(mat);
                        goto x_mijloc;
                    }
                }
            }
            else
            {
                r = (rand())%2; //r=0;
                if( r==0 )
                {
                    r = (rand())%2;
                    switch (r)
                    {
                        case 0:{ if( i == 2 )
                                    mat[i][j-1] = 1;
                                else
                                    mat[i-1][j] = 1;
                                break; }
                        case 1:{ if( i == 2 )
                                    mat[i-2][j-1] = 1;
                                else
                                    mat[i-1][j-2] = 1;
                                break; }
                    }

                    system("cls");  // golire consola
                    afisare(mat);
                    citire_X_sau_0(mat,-1,&i,&j);

                    if( mat[1][1] == 0 )
                        mat[1][1] = 1;
                    else
                        putX0(mat,1);

                    system("cls");  // golire consola
                    afisare(mat);

                    goto x_mijloc;
                }
                else
                {
                    r = (rand())%2;
                    a=i;  b=j;

                    switch (r)
                    {
                        case 0:{ if( i == 2 )
                                    mat[2-i][1] = 1;
                                 else
                                    mat[1][2-j] = 1;
                                break; }
                        case 1:{ if( i == 2 )
                                    mat[i][1] = 1;
                                 else
                                    mat[1][j] = 1;
                                break; }
                    }

                    system("cls");  // golire consola
                    afisare(mat);
                    citire_X_sau_0(mat,-1,&i,&j);

                    if( putX0(mat,1) == 1 )
                    {
                        system("cls");  // golire consola
                        afisare(mat);
                        goto x_mijloc;
                    }
                    else
                        if( i == 2 || j == 2 )
                            if( r == 0 )
                                if( a == 2 )
                                    mat[a][b-1] = 1;
                                else
                                    mat[a-1][b] = 1;
                            else
                                if( a == 2 )
                                    mat[a-2][b-1] = 1;
                                else
                                    mat[a-1][b-2] = 1;
                        else
                        {
                            mat[1][1] = 1;
                            system("cls");  // golire consola
                            afisare(mat);

                            a=i; b=j;
                            citire_X_sau_0(mat,-1,&i,&j);

                            r=(rand())%2;
                            switch (r)
                            {
                                case 0: if( mat[0][0] == 0 )
                                        {
                                            mat[0][0] =1;
                                            break;
                                        }
                                case 1: if( mat[0][2] == 0 )
                                        {
                                            mat[0][2] =1;
                                            break;
                                        }
                            }
                            system("cls");  // golire consola
                            afisare(mat);
                            mut=1;
                            goto x_mijloc;
                        }

                    system("cls");  // golire consola
                    afisare(mat);

                    goto x_mijloc;
                }
            }
    }
    else
    {
        r=(rand())%4;
        switch(r)
        {
            case 0: a=0; b=0; mat[a][b] = -1; break;
            case 1: a=0; b=2; mat[a][b] = -1; break;
            case 2: a=2; b=0; mat[a][b] = -1; break;
            case 3: a=2; b=2; mat[a][b] = -1; break;
        }

        system("cls");  // golire consola
        afisare(mat);
        citire_X_sau_0(mat, 1, &i, &j);

        if(i==2 && j==2)
        {
            mat[2-a][2-b] = -1;

            system("cls");  // golire consola
            afisare(mat);
            citire_X_sau_0(mat, 1, &i, &j);

            if( i==2 || j==2 )
            {
                putX0(mat,-1);

                another:

                system("cls");  // golire consola
                afisare(mat);
                citire_X_sau_0(mat, 1, &i, &j);

                if( putX0(mat,-1) == 0 )
                {
                    tryagain2:
                    i=(rand())%3;
                    j=(rand())%3;
                    if( mat[i][j] != 0 )
                        goto tryagain2;
                    mat[i][j] = 1;
                }
                printf("m=%d\n",mut);
                a = verif(mat);
                system("cls");  // golire consola
                afisare(mat);
                if( a == 0 && mut++ < 1 )
                    goto another;
            }
            else
            {
                mat[3-i][3-j] = -1;

                system("cls");  // golire consola
                afisare(mat);
                citire_X_sau_0(mat, 1, &i, &j);

                putX0(mat,-1);

                system("cls");  // golire consola
                afisare(mat);
                a = -1;
            }

        }
        else
        {
            if( a == 3-i && b == 3-j )
            {
                r=(rand())%2;
                if( r==0 )
                    mat[2-a][b] = -1;
                else
                    mat[a][2-b] = -1;
            }
            else
            {
                if( a == i-1 )
                    mat[2-a][b] = -1;
                else
                    mat[a][2-b] = -1;
            }

            a=i; b=j;
            system("cls");  // golire consola
            afisare(mat);
            citire_X_sau_0(mat, 1, &i, &j);

            if( putX0(mat,-1) == 0 )
            {
                if(a%2 == b%2)
                {
                    for(i=0;i<=2;i+=2)
                        for(j=0;j<=2;j+=2)
                            if(mat[i][j] == 0 )
                                mat[i][j] = -1;
                }
                else
                    mat[1][1] = -1;
                goto another;
            }
            else
            {
                a = verif(mat);
                if( a == 0 )
                    goto another;
                system("cls");  // golire consola
                afisare(mat);
            }

        }
    }

    a *= par_meci;
    if( a == 1 )
        ia++;
    else
        if( a == -1 )
            pl++;
    printf("\n Player : IA\n    %d   -  %d\n\n",pl,ia);   // print scor

    par_meci *= -1;
}

void citire_X_sau_0(int **mat, int semn, int *i, int *j)
{
    if(semn == -1)
        printf("\nScrie coordonatele pentru X\n\n");
    else
        printf("\nScrie coordonatele pentru 0\n\n");
    readX:
    scanf("%d%d",i,j);    //citire coord X
    if( *i>3 || *j>3 )
    {
        printf("Ai dat niste coordonate cam mari, scrie-le iar\n");
        goto readX;
    }
    if( *i<1 || *j<1 )
    {
        printf("Ai dat niste coordonate cam mici, scrie-le iar\n");
        goto readX;
    }
    if( mat[*i-1][*j-1] == 0 )
        mat[*i-1][*j-1] = semn;
    else
    {
        printf("Ocupat!\n");
        goto readX;
    }
}

void maimuta(int **mat) // maimuta "joaca"
{
    static int p, q, paritate_meci=1;
    int i, j, k=5, win=0, ocupat=0; // k- nr mutari ramase

    if(paritate_meci == 1)
    {
        citire_X_sau_0(mat, -paritate_meci, &i, &j);
        system("cls");  // golire consola
        afisare(mat);
        k=4;
    }
    while( k>0 && win == 0 )
    {
        win = verif(mat);
        if( win == 0 && k>0 )
            if( putX0(mat,paritate_meci) == 0 )
            {
                ocupat=0;
                while( ocupat == 0 )
                {
                    i=(rand())%3;
                    j=(rand())%3;
                    if( mat[i][j] == 0 )
                    {
                        mat[i][j] = paritate_meci;
                        ocupat = 1;
                    }
                }
            }
        system("cls");  // golire consola
        afisare(mat);

        if( win == 0 )
            win = verif(mat);
        else
            break;

        k--;
        if(paritate_meci == -1 && k==0)
            break;  // opresc sa nu mai ajung la citirea altei pozitii

        citire_X_sau_0(mat, 0-paritate_meci, &i, &j);
        system("cls");  // golire consola
        afisare(mat);

    }
    if( win == - paritate_meci )
        p++;
    else if( win == paritate_meci )
        q++;

    printf("\n Player : Maimuta\n    %d   -    %d\n\n",p,q);   // print scor

    paritate_meci *= -1;
}

void afisare(int **mat) // afisare joc
{
    int i,j;

    printf("  ");
    for(i=0;i<3;i++)
        printf(" %d  ",i+1);
    printf("\n");
    for(i=0;i<3;i++)
    {
        printf("%d ",i+1);
        for(j=0;j<3;j++)
        {
            printf(" ");
            if(mat[i][j] == 0)
                printf("  ");
            else
                if(mat[i][j] == -1)
                    printf("X ");
                else
                    printf("0 ");
            if(j!=2)
                printf("|");
        }
        if(i!=2)
            printf("\n  -----------");
        printf("\n");
    }
}

int verif(int **mat)    //verif daca a castigat cineva
{
    int ok1=1, ok2=1, i;
    for(i=0;i<3;i++)
    {
        if( mat[i][0]==mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0] != 0)
        {
            if( mat[i][0] == -1 )
                {printf("X won\n"); return -1;}
            else
                {printf("0 won\n"); return  1;}
        }
        if( mat[0][i]==mat[1][i] && mat[1][i] == mat[2][i] && mat[0][i] != 0)
        {
            if( mat[0][i] == -1 )
                {printf("X won\n"); return -1;}
            else
                {printf("0 won\n"); return  1;}
        }
        if( mat[i][i] != mat[0][0] )
            ok1=0;
        if( mat[i][2-i] != mat[0][2] )
            ok2=0;
    }

    if( ok1 == 1 && mat[0][0] != 0 )
    {
        if( mat[0][0] == -1 )
            {printf("X won\n"); return -1;}
        else
            {printf("0 won\n"); return  1;}
    }

    if( ok2 == 1 && mat[2][0] != 0)
    {
        if( mat[2][0] == -1 )
            {printf("X won\n"); return -1;}
        else
            {printf("0 won\n"); return  1;}
    }

    return 0;
}

int main()  // PVP si alte decizii
{
    int i,j, win, mutari, x=0, z=0, semn, dz, par_meci=-1;
    char ch,ch2;

    int **mat=malloc(3 * sizeof(int*));   //alocare memorie
    if( !mat )  return 0;
    for(i=0;i<3;i++)
    {   mat[i]=malloc(3 * sizeof(int));
        if( !mat[i] )   return 0;   }

    srand((unsigned)time(NULL));

    cine:
    printf("Cu cine joci?\n1) cu IA\n2) cu un prieten\n3) cu maimuta\nApasati 1, 2 sau 3 daca v-ati decis\n\n");

    ch = getch();
    switch (ch)
    {
        case '1': system("cls"); dz=1; break;
        case '2': system("cls"); dz=2; break;
        case '3': system("cls"); dz=3; break;
        default: system("cls"); printf("1, 2 sau 3 !!!!\n\n"); goto cine;
    }

    replay:

    init(mat);    win=0;    mutari=0;    semn=-1;  //inititializare joc

    printf("Here we go again ... \n\n");

    afisare(mat);

    switch (dz)
    {
        case 1: win=2; play_with_IA(mat); break;
        case 2: break;
        case 3: win=3; maimuta(mat); break;
        default: goto cine;
    }

    while( win==0 && mutari<9 )   // cat timp n-a castigat nimeni si matricea nu e plina
    {
        if( semn == par_meci )
            printf("\nPlayer1");
        else
            printf("\nPlayer2");
        citire_X_sau_0(mat,semn,&i,&j);

        system("cls");  // golire consola

        afisare(mat);

        win = verif(mat);

        mutari++;
        semn = 0 - semn;
    }

    win *= par_meci;
    if( dz == 2 )
    {
        if( win == 1 )
            x++;
        else
            if( win == -1 )
                z++;
        printf("\n Player1 : Player2\n    %d    -    %d\n\n",x,z);   // print scor
    }
    par_meci *= -1;

    printf("Play again?\n\n1) Da\n2) Nu\n3) Schimb oponentul\n");

    ch2 = getch();
    system("cls");  // golire consola

    switch (ch2)
    {
        case '1': goto replay;
        case '3': goto cine;
        default:  break;
    }

    return 0;
}
