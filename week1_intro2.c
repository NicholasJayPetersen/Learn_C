//Nicholas Petersen

//variable rules
//no spaces
// cant start with a number
//no symbols other than underscore
//no reserved words

//variable guidleines
//meaniful words
//dont start with capital

#include <stdio.h>

int main(){
	
	float price, amount;
	float taxRate = .06;
	
	printf("Enter the price: ");
	scanf("%f", &price);
	
	printf("Enter amount paid: ");
	scanf("%f", &amount);
	
	float tax = price * taxRate;
	float total = tax + price;
	float change = amount - total;
	
	
	//to specify decimal places instert .# between datatype
	//field width: add an nother number in front of the deciaml #.#
	//should look like %8.2F for 8 field with and 2 decimals
	printf("\nPrice:  $%8.2f", price);
	printf("\nTax:    $%8.2f", tax);
	printf("\nTotal:  $%8.2f", total);
	printf("\nPaid:   $%8.2f", amount);
	printf("\nChange: $%8.2f", change);
	
	
	//more formatting 
	int a=5, b=10, c=350;
	char x = 'x', y='y', z = 'z';
	
	printf("\n%4d", a);
	printf("\n%4d", b);
	printf("\n\t%4d", c);
	
	printf("\n%4c", x);
	printf("\n%4c", y);
	printf("\n%-4c", z);
	
	return 0;
}
