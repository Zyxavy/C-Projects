#include <stdio.h>
#include <time.h>

int main(){
    int operation, months;
    double balance, deposit, fee, withdrawl, interest, loan;
    int atm;
    srand(time(NULL));

    printf("T H E A T M\n");
    do{
        printf("________________________________________________________\n");
        printf("| 1. Deposit | 2. Withdraw | 3. Check Balance | 4. Loan |\n");
        printf("________________________________________________________\n");
        printf("OPERATION: ");
        scanf("%d", &operation);

        switch(operation){
            case 1:
                printf("Depository\nThere is a 1%% fee for every deposit \nEnter the amount you would like to deposit: ");
                scanf("%lf", &deposit);
                printf("Deposit amount: %f\n", deposit);
                sleep(1);
                fee = deposit / 100;
                printf("Fee deduction: %f\n", fee);
                deposit-=fee;
                sleep(1);
                printf("Amount after fee deduction: %f\n", deposit);
                sleep(1);
                balance += deposit;
                deposit = 0;
                printf("Balance: %f",balance);
                break;
            case 2:
                printf("Current Balance: %f\n", balance);
                printf("Withdrawl\nThere is a 1%% fee for every withdraw\nHow much would you like to withdraw: ");
                scanf("%lf", &withdrawl);
                printf("Withdraw amount: %f\n", withdrawl);
                sleep(1);
                fee = withdrawl / 100;
                printf("Fee deduction: %f\n", fee);
                sleep(1);
                withdrawl-=fee;
                printf("Amount after fee deduction: %f\n", withdrawl);
                sleep(1);
                balance-=withdrawl;
                withdrawl = 0;
                printf("Balance: %f\n", balance);
                break;
            case 3:
                printf("There is 2%% interest rate after 1 month\n");
                months = rand() % 12 + 1;
                printf("weeks: %d\n", months);
                sleep(1);
                interest = (balance / 100) * months;
                printf("Interest acculumated: %f\n", interest);
                sleep(1);
                balance+=interest;
                printf("Current Balance: %f\n", balance);
                break;
            case 4:
                printf("There is a 3%% interest rate for every month\nEnter the amount you would like to loan out: ");
                scanf("%lf", &loan);
                sleep(1);
                printf("Loan amount: %f\n", loan);
                sleep(1);
                balance+=loan;
                printf("Current Amount: %f\n", balance);
                break;
            default:
                printf("ERROR!\n");
        }
            printf("\nContinue banking?(1 = yes/ 2 = no): ");
            scanf("%d", &atm);
            sleep(1);

    } while(atm == 1);
}