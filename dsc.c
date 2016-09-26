#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{

    char **staff;
    char **degree;
    int *exp;
     int n;
}department;
    department cse,ise,ec;
     int c[3]={0,0,0};
    int p[3]={0,0,0};
    int fill[3]={0,0,0};
    int hod[3]={0,0,0};
    int d[3]={0,0,0};

      void insert(int i);
      void deletedep(int i);
      void print(int i);
        void change(int i);
void main()
{


    int ch,dep;

    while(1)
    {
        printf("\n\tEnter\n 1-Insert department details\n 2-Delete department details\n 3-Print department details\n 4-Change department details\n 5-Exit\n ");
        scanf("%d",&ch);
        if(ch==5)
        exit(0);
        printf("\nEnter\n\t1-CS DEPARTMENT\n\t2-IS DEPARTMENT\n\t3-EC DEPARTMENT\n");
        scanf("%d",&dep);

        switch(ch)
        {

         case 1: insert(dep);
               break;

         case 2: deletedep(dep);
                   break;

         case 3: print(dep);
                  break;

        case 4: change(dep);
                 break;
       }
    }


}

    void insert(int i)
    {
         char ch,*s,*d;
         int j,e,t,r,l;


        department temp;
        printf("\n Enter\nA-To insert whole depatment faculty details\nB-To insert new faculty details\nC-To insert hod details\n ");
        fflush(stdin);
        ch=getchar();
             if(i==1)
            temp=cse;
           else if(i==2)
            temp=ise;
           else if(i==3)
            temp=ec;

               if(c[i-1]==0)
           {

               temp.staff=(char**)calloc((30),sizeof(char*));
               temp.degree=(char**)calloc((30),sizeof(char*));
               temp.exp=(int*)calloc(30,sizeof(int));
              c[i-1]++;
           }

             if((hod[i-1]==0)&&(p[i-1]==0)&&(fill[i-1]==0))
             temp.n=0;

         switch(ch)
        {
         case 'a':
         case 'A' : printf("\nEnter the number of faculty\n");
                    scanf("%d",&t);
                    if(hod[i-1])
                  r=temp.n+t;
                else
                  r=temp.n+t+1;
                    for(j=p[i-1]+1;j<r;j++,temp.n++)
                    {
                         temp.staff[j]=(char*)calloc(20,sizeof(char));
                         temp.degree[j]=(char*)calloc(20,sizeof(char));

                     printf("\n Enter faculty name %d\n",j);
                     scanf("%s",temp.staff[j]);
                      printf("\n Enter faculty degree\n");
                      scanf("%s",temp.degree[j]);
                       printf("\n Enter faculty  expirience\n");
                      scanf("%d",&temp.exp[j]);


                    } fill[i-1]=1;
                    break;
        case 'C' :
        case 'c' :      temp.staff[0]=(char*)calloc(20,sizeof(char));
                      temp.degree[0]=(char*)calloc(20,sizeof(char));
                      printf("\n Enter hod name\n");
                      scanf("%s",temp.staff[0]);
                      printf("\n Enter hod degree\n");
                      scanf("%s",temp.degree[0]);
                      printf("\n Enter hod  expirience\n");
                      scanf("%d",&temp.exp[0]);
                      hod[i-1]=1;
                      temp.n++;
                    break;
         case 'b':
         case 'B':
                          printf("\nEnter the new faculty name\n");
                                   s=(char*)calloc(20,sizeof(char));
                                     d=(char*)calloc(20,sizeof(char));
                          scanf("%s",s);
                          printf("\nEnter Degree\n");
                           scanf("%s",d);
                           printf("\n Enter expirience\n");
                           scanf("%d",&e);
                             if(fill[i-1]==0)

                                   {
                                       p[i-1]++;
                                       temp.n++;
                                    temp.staff[p[i-1]]=s;
                                    temp.degree[p[i-1]]=d;
                                    temp.exp[p[i-1]]=e;


                                  }
                                 else if(fill[i-1])
                                   {
                                      p[i-1]++;
                                       temp.n++;
                                       if(hod[i-1])
                                       l=temp.n-1;
                                       else
                                       l=temp.n;
                                    temp.staff[l]=s;
                                         temp.degree[l]=d;
                                      temp.exp[l]=e;
                                   }

                             break;


        }
       if(i==1)
       cse=temp;
    else if(i==2)
       ise=temp;
       else
       ec=temp;
    }

     void deletedep(int i)
     {
         char choice,n[20];int j,r;
         int m;
         department temp;
         printf("\n Enter\n  A-To delete faculty\n  B-To delete hod\n");
             fflush(stdin);
              choice=getchar();
          if(i==1)
       temp=cse;
       else if(i==2)
       temp=ise;
       else
       temp=ec;
          switch(choice)
         {
              case 'a' :
             case 'A' : printf("\n Enter faculty name to be deleted\n");
                       scanf("%s",n);
                       if(hod[i-1])
                       m=temp.n-1;
                       else
                       m=temp.n;
                     for(j=1;j<=m;j++)
                           if(strcmp(n,temp.staff[j])==0)
                              { printf("\n Name found\n");

                                  free(temp.staff[j]);
                                  free(temp.degree[j]);
                                   temp.staff[j]=NULL;
                                   d[i-1]++;
                                  temp.exp[j]=0;
                                  temp.n--;
                                  r=1;
                                    break;
                              }
                              if(!r)
                            printf("\n Name not found\n");
                               break;

           case  'b' :
           case 'B'  :
                        free(temp.staff[0]);
                        free(temp.degree[0]);
                        hod[i-1]=0;

                        temp.n--;
                        break;

         }
           if(i==1)
       cse=temp;
       else if(i==2)
       ise=temp;
       else
       ec=temp;
     }

      void print(int i)
      {
          int j,n;
           department temp;
                if(i==1)
          {   temp=cse;
             printf("\n\t COMPUTER SCIENCE DEPARTMENT");
         }
       else if(i==2)
       {
       temp=ise;
        printf("\n\t INFORMATION SCIENCE DEPARTMENT");
         }
       else
       {
          temp=ec;
            printf("\n\t ELECTRONICS AND COMMUNICATION DEPARTMENT");
         }
               printf("\n----------------------------------------------");
               printf("\n\tNAME\tDEGREE\tEXPERIENCE\n");
                     printf("\n----------------------------------------------");
               if(hod[i-1])
               {
               printf("\nHOD :  %s\t%s\t %d\n",temp.staff[0],temp.degree[0],temp.exp[0]);
                 printf("\n================================================");
               n=temp.n-1;
              }
              else
                  n=temp.n;
               printf("\n The faculty consists of :");
                 for(j=1;j<=n+d[i-1];j++)
               {

                     if(temp.staff[j]==NULL)
                       continue;
                else

                    printf("\n\t%s\t%s\t %d\n",temp.staff[j],temp.degree[j],temp.exp[j]);
               }
                printf("\n================================================");
               printf("\n Total number of staff : %d\n\t",temp.n);
                 printf("\n----------------------------------------------");
      }


      void change(int i)
      { department temp;
       char s[15],n[15],d[15];
        int j,e,k=0,h;
             if(i==1)
           temp=cse;
        else if(i==2)
         temp=ise;
         else
          temp=ec;
             printf("\n Enter the name that has to be changed\n");
             scanf("%s",s);
             printf("\n Enter the new name that has to be added\n");
              scanf("%s",n);
              printf("\n Enter the degree\n");
               scanf("%s",d);
               printf("\n Enter expirience\n");
               scanf("%d",&e);
               if(hod[i-1])
               {   j=0;
                  h=temp.n;
               }
               else
               {
               h=temp.n+1;
               j=1;
               }
             for(;j<h;j++)
                if(strcmp(s,temp.staff[j])==0)
                  {
                      strcpy(temp.staff[j],n);
                      strcpy(temp.degree[j],d);
                      temp.exp[j]=e;
                         k=1;
                         break;
                  }

                if(k==0)
                    {
                      printf("\n Name not found\n");
                    }

                 if(i==1)
                 cse=temp;
               else if(i==2)
                ise=temp;
               else
                 ec=temp;


      }
