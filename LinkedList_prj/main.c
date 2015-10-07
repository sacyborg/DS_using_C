#include <stdio.h>
#include <stdlib.h>

    struct node{
        int data;
        struct node *link;
    };

 typedef struct node n;

    n *start=NULL;

 int cou_create=0, cou_inslft=0, cou_insrht=0, cou_dellft=0, cou_delrht=0;

void create();
void ins_left();
void ins_right();
void del_left();
void del_right();
void display();



int main()
{
    int op;
    do{
        printf("\n\n\t\t\tMain Menu\t\t\t\n\n");
        printf("\t0. Create node\n");
        printf("\t1. Insert at begin\n");
        printf("\t2. Insert at end\n");
        printf("\t3. Delete at begin\n");
        printf("\t4. Delete at end\n");
        printf("\t5. Display\n");
        printf("\n\n\t\tPress any key to exit\n\n");
        printf("\n\tEnter : ");
        scanf("%d",&op);
        switch(op){
        case 0:
            create();
            break;
        case 1:
            ins_left();
            break;
        case 2:
            ins_right();
            break;
        case 3:
            del_left();
            break;
        case 4:
            del_right();
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
            break;
        }
    }while(1);
    return 0;
}


void create(){

    int d;
    n *newpt;
    if(cou_create==1){
        printf("\n\n**First node has been created you need to add or delete elements at begin or end");
        return;
    }

    printf("\n\n\t---------*******\n");

    printf("\n\t\tEnter the number to enter for first time (integer) : ");
    scanf("%d",&d);
    newpt=(n *)malloc(sizeof(n));
    newpt->data=d;
    start=newpt;
    newpt->link=NULL;
    cou_create=1;

}

void ins_left(){
    n *newpt;
    int d;
    char cntyu;
    int countnode=0;
    if(cou_create==0||start==NULL){
        printf("\n\n  ** #First node is not created \n");
        return;
    }

    printf("\n\n\t----------*********---------------\n");

    do{
        printf("\n\t\tEnter the data in integer : ");
        scanf("%d",&d);
        newpt=(n *)malloc(sizeof(n));
        newpt->data=d;
        newpt->link=start;
        start=newpt;
        countnode++;
        printf("\n\t\tDo you want to add more (Y/N)");
        scanf("%s",&cntyu);

    }while(cntyu=='Y'||cntyu=='y');
    printf("\n\n\t\t %d nodes are created at the begin \n\n ",countnode);
    cou_inslft=cou_inslft+countnode;
    return;
}

void ins_right(){
    n *newpt, *ptr;
    int d;
    char letter;
    int countnode=0;
    if(cou_create==0){
        printf("\n\n  ** #First node is not created \n");
        exit(0);
    }

    printf("\n\n\t----------*********---------------\n");

    do{
        printf("\n\t\tEnter the data in integer : ");
        scanf("%d",&d);
        newpt=(n *)malloc(sizeof(n));
        newpt->data=d;
        ptr=start;
        //ptr=ptr->link;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=newpt;
        newpt->link=NULL;
        countnode++;
        printf("\n\t\tDo you want to add more (Y/N)");
        scanf("%s",&letter);
}while(letter=='Y'||letter=='y');
    printf("\n\n\t\t %d nodes are created at the end \n\n ",countnode);
    cou_insrht=cou_insrht+countnode;
    return;
}

void del_left(){
    n *ptr, *dptr;
    int d;
    char cniit;
    int countnode=0;
    if(cou_create==0){
        printf("\n\n  ** #First node is not created \n");
        exit(0);
    }

    printf("\n\n\t----------*********---------------\n");
    dptr=start;
    printf("\n\n\t[ ");
    while(dptr!=NULL){

        printf(" %d ",dptr->data);
        dptr=dptr->link;

    }
    printf("] \n\n\t List before left deletion");
    do{
    ptr=start;
    start=start->link;
    d=ptr->data;
    free(ptr);
    printf("\n\n\t\t ** {%d} is deleted\n\n",d);
     printf("\n\t\tDo you want to delete more (Y/N)");
        scanf("%s",&cniit);
        countnode++;
    }while(cniit=='Y'||cniit=='y');
    dptr=start;
    printf("\n\n\t[ ");
    while(dptr!=NULL){

        printf(" %d ",dptr->data);
        dptr=dptr->link;

    }
    printf("] \n\n\t List after left deletion");
    printf("\n\n\t\t %d nodes are deleted at the begin \n\n ",countnode);
    cou_dellft=cou_dellft+countnode;
    return;
}





void del_right(){
    n *ptr, *dptr, *cpt;
    int d;
    char cnt;
    int countnode=0;
    if(cou_create==0){
        printf("\n\n  ** #First node is not created \n");
        exit(0);
    }

    printf("\n\n\t----------*********---------------\n");
    dptr=start;
    printf("\n\n\t[ ");
    while(dptr!=NULL){
        printf(" %d ",dptr->data);
        dptr=dptr->link;
    }
    printf("] \n\n\t List before left deletion");

    do{
        ptr=start;
        while(ptr->link!=NULL){
            cpt=ptr;
            ptr=ptr->link;
        }
        cpt->link=NULL;
        d=cpt->data;
        free(ptr);
        printf("\n\n\t\t ** {%d} is deleted\n\n",d);
        printf("\n\t\tDo you want to delete more (Y/N)");
        scanf("%s",&cnt);
        countnode++;
    }while(cnt=='Y'||cnt=='y');
    dptr=start;
    printf("\n\n\t[ ");
    while(dptr!=NULL){
        printf(" %d ",dptr->data);
        dptr=dptr->link;
    }
    printf("] \n\n\t List after left deletion");
    printf("\n\n\t\t %d nodes are deleted at the end \n\n ",countnode);
    cou_delrht=cou_delrht+countnode;
    return;
}


void display(){
    n *ptr;
    int d=0;
    if(start==NULL||cou_create==0){
        printf("\n\n\t\t\t** LIST IS EMPTY\t\t\n\n");
        exit(0);
    }
    else{
        printf("\n\n\t\tLIST MAP\n");
        ptr=start;
        //ptr=ptr->link;
        printf("\n\n\tSTART----> ");
        while(ptr!=NULL){
            printf("-[%d]-",ptr->data);
            ptr=ptr->link;
            d++;
    }
    printf(" >----NULL \n\n\t");
    }
    printf("---- **Total Elements : %d",d);
    printf("\n\n\t\t\t\tOPERATION DETAILS: \n \t\t");
    printf("\n  \t\t~~~~| %d | ----elements are inserted at begin",cou_inslft);
    printf("\n  \t\t~~~~| %d | ----elements are inserted at end",cou_insrht);
    printf("\n  \t\t~~~~| %d | ----elements are deleted at begin",cou_dellft);
    printf("\n  \t\t~~~~| %d | ----elements are deleted at end\n",cou_delrht);

}


















