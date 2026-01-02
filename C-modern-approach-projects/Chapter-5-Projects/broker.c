/*
Modify the b ro k e r. c program of Section 5.2 by making both of the following changes:
(a) Ask (he user lo enter the number ofshares and the price per share, instead of the value
of the trade.
(b) Add statements that compute the commission charged by a rival broker (533 plus 3tf per
share for fewer than 2000 shares: $33 plus 2$j per share for 2000 shares or more). Dis
play the rival's commission as well as the commission charged by the original broker.
*/

#include <stdio.h>

int main(void)
{
    float rivalCommission, origCommission, pricePerShare, transactSize;
    int numShares = 0;

    printf("Enter the number of shares: ");
    scanf("%d", &numShares);

    printf("Enter the price per shares: ");
    scanf("%f", &pricePerShare);

    transactSize = numShares * pricePerShare;

    rivalCommission = (numShares > 2000) ? 33 + 0.03 * pricePerShare : 33 + 0.02 * pricePerShare;

    if (transactSize < 2500.00f)
    origCommission = 30.00f + .017f * transactSize;
    else if (transactSize < 6250.00f)
    origCommission = 56.00f + .0066f * transactSize;
    else if (transactSize < 20000.00f)
    origCommission = 76.00f + .0034f * transactSize;
    else if (transactSize < 50000.00f)
    origCommission = 100.00f + .0022f * transactSize;
    else if (transactSize < 500000.00f)
    origCommission = 155.00f + .0011f * transactSize;
    else
    origCommission = 255.00f + .0009f * transactSize;
    if (origCommission < 39.00f)
    origCommission = 39.00f;


    printf("\tCommission: $%.2f per share \t |", origCommission);
    printf("\tRival's Commission: $%.2f per share", rivalCommission);

    return 0;
}

/*
int main(void)
float commission, value;
printf("Enter value of trade: ”);
scanf("%f", &value);
if (value < 2500.00f)
commission = 30.00f + .017f * value;
else if (value < 6250.00f)
commission = 56.00f + .0066f * value;
else if (value < 20000.00f)
commission = 76.00f + .0034f * value;
else if (value < 50000.00f)
commission = 100.00f + .0022f * value;
else if (value < 500000.00f)
commission = 155.00f + .0011f * value;
else
commission = 255.00f + .0009f * value;
if (commission < 39.00f)
commission = 39.00f;
printf("Commission: $%.2f\n”, commission);
return 0;

*/