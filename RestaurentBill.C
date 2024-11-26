#include<stdio.h>
#include<string.h>

int main() {
    printf("WELCOME TO THE ** THE GRAND PALACE RESTAURANT ** \n");
    printf("============================================\n");

    char name[100]; 
    printf("Name of Customer: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0; 

    int n; 
    printf("Enter the no. of items taken by the customer: ");
    scanf("%d", &n);

    int paneer = 200, roti = 25, dal = 150, rice = 100;
    int paneer_total = 0, roti_total = 0, dal_total = 0, rice_total = 0;

    printf("The Food Menu\n\n1. Paneer\n2. Roti\n3. Dal\n4. Rice\n");

    int qty[4] = {0}; 

    for(int i = 0; i < n; i++) {
        int ch;
        printf("Enter item no.: ");
        scanf("%d", &ch);

        if(ch < 1 || ch > 4) {
            printf("Invalid item number. Please enter a number between 1 and 4.\n");
            i--; // 
            continue;
        }

        printf("Enter quantity of item: ");
        scanf("%d", &qty[ch-1]); 

        switch(ch) {
            case 1: paneer_total += paneer * qty[ch-1]; break;
            case 2: roti_total += roti * qty[ch-1]; break;
            case 3: dal_total += dal * qty[ch-1]; break;
            case 4: rice_total += rice * qty[ch-1]; break;
        }
    }

    float discount;
    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    float total_price = paneer_total + roti_total + dal_total + rice_total;
    float discounted_price = total_price - (total_price * discount / 100);

    printf("\n");

    printf("** THE GRAND PALACE **\n");
    printf("----------------------\n");
    printf("Invoice To: %s\n", name);
    printf("------------------------------------------------------------\n");
    printf("Items \tQuantity\tTotal\n");

    if (paneer_total > 0) printf("Paneer\t%d\t\t%d\n", qty[0], paneer_total);
    if (roti_total > 0) printf("Roti\t%d\t\t%d\n", qty[1], roti_total);
    if (dal_total > 0) printf("Dal\t%d\t\t%d\n", qty[2], dal_total);
    if (rice_total > 0) printf("Rice\t%d\t\t%d\n", qty[3], rice_total);

    printf("------------------------------------------------------------\n");
    printf("Discount Offer: %.2f%%\n", discount);
    printf("------------------------------------------------------------\n");
    printf("Total Amount: %.2f\n", discounted_price);

    return 0;
}