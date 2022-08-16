#include <cs50.h>
#include <stdio.h>


// check length of an int
int int_len(long a)
{
    // lenght set to 0
    int count = 0;

    while (a != 0)
    {
        // remove one digit
        a /= 10;

        // count + 1
        count ++;
    }

    return count;
}

// if number = 32, return  = 3 + 2
int decompose(long a)
{
    int sum = 0;
    while (a != 0)
    {
        sum += (a % 10);
        a /= 10;
    }

    return sum;
}


// get the second to last digit, multiply them and make a sum
int second_to_last(long a)
{
    int position = 1;

    int ans = 0;

    while (a != 0)
    {
        // count the position
        position++;

        // get each second digit
        if (position % 2)
        {
            // get the last digit
            int val = (a % 10) * 2;

            // make sum of each value
            ans += decompose(val);
        }

        // remove the last digit
        a /= 10;
    }

    // return ans;
    return ans;
}


// get the rest that weren't multiplied and sum them
int not_multiplied(long a)
{
    // set position to 0
    int position = 0;

    int ans = 0;

    while (a != 0)
    {
        // position start by 1
        position++;

        if (position % 2)
        {
            ans += (a % 10);
        }

        a /= 10;
    }

    return ans;
}



// will return true if the last digit is 0
int makeSum(a, b)
{
    int last_digit = (a + b) % 10;

    if (last_digit == 0)
    {
        return true;
    }
    return false;
}


int two_first_digit(long card)
{
    // get only the two first digit
    while (card / 100 != 0)
    {
        card /= 10;
    }

    return card;
}


int is_first_digit_four(long card)
{
    // get only the first digit
    while (card / 10 != 0)
    {
        card /= 10;
    }

    // if it's 4, return true
    if (card == 4)
    {
        return true;
    }
    return false;
}


int is_master(int digit)
{
    int val = 0;

    // list 51-52-53-54-55
    for (int i = 51; i <= 55; i++)
    {

        if (digit == i)
        {
            val++;
        }
    }

    // return true if digit in one of the above
    if (val == 1)
    {
        return true;
    }
    return false;
}


int isValidCard(long card)
{
    // if first digit 13/14 and card length 15 -> AMEX
    if (int_len(card) == 15 && (two_first_digit(card) == 34 || two_first_digit(card) == 37))
    {
        printf("AMEX\n");
    }

    else if (int_len(card) == 16)
    {
        // if card length 16 and first digit 4 -> VISA
        if (is_first_digit_four(card))
        {
            printf("VISA\n");
        }

        // if card length 16 and two first digit one of the above, -> MASTERCARD
        else if (is_master(two_first_digit(card)))
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    // if card lentgh 13 and first digit 4, -> VISA
    else if (int_len(card) == 13 && is_first_digit_four(card))
    {
        printf("VISA\n");
    }

    // if none of the case true, INVALID
    else
    {
        printf("INVALID\n");
    }

    // fct has no return
    return 0;
}



int main(void)
{
    // get users input
    long card = get_long("Insert number: ");

    // if sum of the digits correspond to the formula
    if (makeSum(second_to_last(card), not_multiplied(card)))
    {
        // check if it's a valid card or not
        isValidCard(card);
    }

    // in cas it doesn't correspond to any type of card
    else
    {
        printf("INVALID\n");
    }
}
