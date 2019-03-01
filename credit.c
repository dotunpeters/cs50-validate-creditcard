#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Declare all used variables and array globally
    long cc_number;
    int sum_odd = 0;
    int sum_even = 0;
    int sum_all = 0;
    long cc_chksum[16];
    //prompt user for creditcard number
    do
    {
        cc_number = get_long_long("credit-card number: ");
    }
    while (cc_number <= 0);
    //summation of checksum
    for (int i = 0; cc_number != 0; i++)
    {
        if (i % 2 != 0)
        {
            //multipying and odd i by 2 and adding them together
            cc_chksum[i] = cc_number % 10;
            cc_number = cc_number / 10;
            if (cc_chksum[i] * 2 > 9)
            {

                sum_odd = sum_odd + (cc_chksum[i] * 2 / 10) + (cc_chksum[i] * 2 % 10);
            }
            else
            {
                sum_odd = sum_odd + cc_chksum[i] * 2;
            }
        }
        else
        {
            //summation of all even i of the array
            cc_chksum[i] = cc_number % 10;
            cc_number = cc_number / 10;
            sum_even = sum_even + cc_chksum[i];
        }
    }
    //total sum
    sum_all = sum_odd + sum_even;

    //varified if valid and print out respective creditcard company
    if (sum_all % 10 == 0)
    {
        //output for valid creditcard
        if (((cc_number > 1000000000000000) || (cc_number < 9999999999999999)) && (cc_chksum[15] == 5) &&
            ((cc_chksum[14] == 1) || (cc_chksum[14] == 2) || (cc_chksum[14] == 3) || (cc_chksum[14] == 4) || (cc_chksum[14] == 5)))
        {
            printf("MASTERCARD\n");
        }
        else if (((cc_number > 100000000000000) || (cc_number < 999999999999999)) && (cc_chksum[14] == 3) && ((cc_chksum[13] == 4) || (cc_chksum[13] == 7)))
        {
            printf("AMEX\n");
        }
        else if ((((cc_number > 1000000000000000) || (cc_number < 9999999999999999)) && (cc_chksum[15] == 4))
                 || (((cc_number > 1000000000000) || (cc_number < 9999999999999)) && (cc_chksum[12] == 4)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //output for invalid creditcard
    else
    {
        printf("INVALID\n");
    }
}