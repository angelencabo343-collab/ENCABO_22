#include <stdio.h>

int main() {
    int plannedPayments, i = 1;
    double balance = 20000.00;
    double payment, totalPayments = 0.00;

    printf("=== LOAN PAYMENT TRACKER ===\n");
    printf("Original Loan: P20,000.00\n");

    printf("Enter number of planned payments: ");
    scanf("%d", &plannedPayments);

    while (plannedPayments <= 0) {
        printf("Invalid input! Enter a positive number: ");
        scanf("%d", &plannedPayments);
    }

    while (i <= plannedPayments && balance > 0) {
        printf("\nPayment %d\n", i);
        printf("Enter amount paid: P");
        scanf("%lf", &payment);

        while (payment <= 0 || payment > balance) {
            printf("Invalid payment! Enter an amount ");
            printf("greater than 0 and not more than P%.2f: ",
                   balance);
            scanf("%lf", &payment);
        }

        balance = balance - payment;
        totalPayments = totalPayments + payment;

        printf("Remaining Balance: P%.2f\n", balance);

        i++;
    }

    printf("\n=== FINAL SUMMARY ===\n");
    printf("Total Payments Received: P%.2f\n", totalPayments);
    printf("Remaining Balance: P%.2f\n", balance);

    if (balance == 0) {
        printf("Loan Status: FULLY PAID\n");
    } else {
        printf("Loan Status: NOT YET FULLY PAID\n");
    }

   return 0;
}
