/*
Write a program in c to create a structure product having the data members pno, pname, price and quantity.
Now input the details of the product using input function.
Then calculate the total price according to the quantity and display the details of the product with total price using display function.
*/

#include <stdio.h>

struct Product
{
    int pno;
    char pname[50];
    float price;
    int quantity;
};

void inputProduct(struct Product *p)
{
    printf("Enter product number: ");
    scanf("%d", &p->pno);
    printf("Enter product name: ");
    scanf("%s", p->pname);
    printf("Enter product price: ");
    scanf("%f", &p->price);
    printf("Enter product quantity: ");
    scanf("%d", &p->quantity);
}

float calculateTotalPrice(struct Product p)
{
    return p.price * p.quantity;
}

void displayProduct(struct Product p)
{
    float totalPrice = calculateTotalPrice(p);
    printf("\nProduct Details:\n");
    printf("Product Number: %d\n", p.pno);
    printf("Product Name: %s\n", p.pname);
    printf("Product Price: %.2f\n", p.price);
    printf("Product Quantity: %d\n", p.quantity);
    printf("Total Price: %.2f\n", totalPrice);
}

int main()
{
    struct Product p;

    inputProduct(&p);

    displayProduct(p);

    return 0;
}