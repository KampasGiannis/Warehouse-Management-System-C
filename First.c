#include<stdio.h>
#include<stdbool.h>
struct Products{
    int ID;
    char name[50];
    float price;
};


int main()
{
    FILE *fptr;
    int i,id,change,answer;
    bool found = false;
    float PRICE;

    struct Products warehouse[3];

    for(i=0;i<3;i++){
        printf("\n--- Eisagwgh stoixeiwn gia to proion %d ---\n", i + 1);

        printf(" Dwse to ID ");
        scanf(" %d", &warehouse[i].ID);


        printf(" Dwse to onoma ");
        scanf(" %s", warehouse[i].name);


        printf(" Dwse thn timh ");
        scanf(" %f", &warehouse[i].price);

    }
    printf("\n--- APOTHIKI ---\n");

    for(i = 0; i < 3; i++) {
        printf("%d. %s - %.2f Euro\n", warehouse[i].ID, warehouse[i].name, warehouse[i].price);
    }

    printf("Dwse to ID pou theleis na breis");
    scanf("%d", &id);

    for(i=0;i<=2;i++){
        if(id == warehouse[i].ID){
            printf("To proion brethike");
            printf("%s. %f",warehouse[i].name, warehouse[i].price);
            found = true;
            change = i;
            break;
        }

    }
    if(!found){
        printf("Lypomaste, to ID den uparxei");
    }
    if(found){
        printf("Thelete na allajete thn timh tou proiontos;(1 gia NAI, 0 gia OXI)");
        scanf("%d", &answer);
        if(answer == 1){
            printf("Dwse thn nea timh");
            scanf("%f", &PRICE);
            warehouse[change].price = PRICE;
        }

    }



    fptr = fopen("apothiki.txt", "w");

    if (fptr == NULL) {
        printf("Sfalma sto anoigma tou arxeiou!");
        return 1;
    }


    fprintf(fptr, "--- KATASTASH APOTHIKHS ---\n");
    for(i = 0; i < 3; i++) {

        fprintf(fptr, "ID: %d | Onoma: %s | Timh: %.2f\n",warehouse[i].ID, warehouse[i].name, warehouse[i].price);
    }


    fclose(fptr);

    printf("\nTa dedomena sothikan sto arxeio 'apothiki.txt'!");

    return 0;
}
