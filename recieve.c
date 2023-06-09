#include "main.h"
/**
 * recieve_funds - sends funds to another user
 * @myAccount: user's account
 */
void recieve_funds(struct Account **myAccount)
{
	char *amt = NULL, *name = NULL;
	size_t n_chars, n = 0;
	double money;

	printf("Enter amount\n$ ");
	n_chars = getline(&amt, &n, stdin);
	if (n_chars == -1)
	{
		puts("Wrong input");
		return;
	}
	money = _atoi(amt);
	if (money ==-1)
	{
		puts("You entered a not allowed character");
		return;
	}
	if (!money)
	{
		puts("You can not recieve $0");
		return;
	}
	printf("Recieve $%.2lf from: ", money);
	n = 0;
	n_chars = getline(&name, &n, stdin);
	name[n_chars - 1] = '\0';
	if (n_chars == -1)
	{
		puts("Incorrect input");
		return;
	}
	(*myAccount)->balance += money;
	add_recieve(money, name, &((*myAccount)->recieve));
	printf("Successfully recieved $%.2lf from %s\n", money, name);
	puts("RECIEPT");
	puts("----------------------------------------------------");
	printf("Amount Recieved: $%.2lf\n", money);
	printf("From: %s\n", name);
	show_balance(*myAccount);
}

/**
 * add_recieve - adds a recieve node to the fron of my recieve linked list
 * @amount: amount
 * @name: name of recipient
 * @head: head of node
 */
void add_recieve(double amount, char *name, struct Recieved **head)
{
	struct Recieved *newNode;

	newNode = malloc(sizeof(struct Recieved));
	newNode->amount = amount;
	newNode->name = name;
	time(&(newNode->t));
	newNode->next = *head;
	*head = newNode;
}
