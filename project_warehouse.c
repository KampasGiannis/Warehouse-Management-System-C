#include<stdio.h>
#include<stdbool.h>
#define N 3
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

    struct Products warehouse[N];
    fptr = fopen("apothiki.txt", "r");

    if (fptr != NULL) {

        printf("\n--- Fortwsh dedomenwn apo thn apothikh... ---\n");
        for(i = 0; i < 3; i++) {

            fscanf(fptr, "%d %s %f", &warehouse[i].ID, warehouse[i].name, &warehouse[i].price);
        }
        fclose(fptr);
        printf("H fortwsh oloklhrwthike. Proxwrame sthn anazhthsh....\n");
    }
    else {

        printf("\nDen brethike arxeio. Parakalw dwste nea stoixeia:\n");
        for(i=0; i<3; i++) {
            printf("\n--- Eisagwgh proiontos %d ---\n", i + 1);
            printf("ID: "); scanf("%d", &warehouse[i].ID);
            printf("Onoma: "); scanf("%s", warehouse[i].name);
            printf("Timh: "); scanf("%f", &warehouse[i].price);
        }
    }

    for(i = 0; i < N; i++) {
        printf(" %d. %s - %.2f Euro\n", warehouse[i].ID, warehouse[i].name, warehouse[i].price);
    }

    printf("Dwse to ID pou theleis na breis");
    scanf(" %d", &id);

    for(i=0;i<N;i++){
        if(id == warehouse[i].ID){
            printf("\n============================"); 
            printf("\nTo proion brethike!\n");
            printf("Onoma: %s | Timh: %.2f Euro\n", warehouse[i].name, warehouse[i].price);
            printf("============================\n");
            found = true;
            change = i;
        }

    }
    if(!found){
        printf("Lypomaste, to ID den uparxei");
    }
    if(found){
        printf("\nThelete na allajete thn timh tou proiontos;(1 gia NAI, 0 gia OXI)");
        scanf(" %d", &answer);
        if(answer == 1){
            printf("Dwse thn nea timh");
            scanf("%f", &PRICE);
            warehouse[change].price = PRICE;
        }

    }



    fprintf(fptr, "%d %s %f\n", warehouse[i].ID, warehouse[i].name, warehouse[i].price);

    if (fptr == NULL) {
        printf("Sfalma sto anoigma tou arxeiou!");
        return 1;
    }


    fprintf(fptr, "--- KATASTASH APOTHIKHS ---\n");
    for(i = 0; i < N; i++) {

        fprintf(fptr, "%d %s %f\n", warehouse[i].ID, warehouse[i].name, warehouse[i].price);
    }


    fclose(fptr);

    printf("\nTa dedomena sothikan sto arxeio 'apothiki.txt'!");

    return 0;
}
