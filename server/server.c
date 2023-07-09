
#include"server.h"


/**
 * @Brief   Validate the every charater of string is digit or not
  * @Return 0 if any character is not digit 1 if all charaters are digits.
 */
int validate_number(char *str)
{
   while (*str)
   {
      if(!isdigit(*str)){ //if the character is not a number, return 0
         return 0;
   }
      str++; //point to next character
   }
   return 1;
}

/**
 *@Brief : Validate IP address
 * Argument is pointer which hold base addres of the string
 *strtok() is a library function called as string tokenizer which cut the string using given delimiter.
 *validate_number() is a user defined function checks whether all characters of string are digit or not
 *atoi() is library function convert asci to integer
 * Integer dot count number of dots and num hold converted asci value.
 * if num is greter than or equal to zero and less than or equal to 255 it checks for next token else return 0;
 * if dots count is not equal to 3 then return 0 else return 1
 * @Return: integer value 1 or 0
 */
int validate_ip(char *ip) {
   int  num, dots = 0;
   char *ptr;
   if (ip == NULL)
      return 0;
   ptr = strtok(ip, ".");

   if (ptr == NULL)
      return 0;

   while (ptr)
    {
      if (!validate_number(ptr)) //check whether the sub string is holding only number or not
               return 0;
      num = atoi(ptr); //convert substring to number
      if (num >= 0 && num <= 255)
          {
                ptr = strtok(NULL, "."); //cut the next part of the string
            if (ptr != NULL)
               dots++;
      } else
                return 0;
    }
    if (dots != 3) //if the number of dots are not 3, return false
        return 0;
    return 1;
}


/**
 *@Brief : Collect mac from client and send validation massage.
 * Argument is file discriptor of accept function.
 *bzero() fuction used to empty buffer.
 *read () and Write() functions used to send and receive messages.
 *After calling isValidMacAddress() send respective message to client.
 *@Return : void type return nothing.
*/
void forip(int acceptfd)
{
    bzero(buff, MAX);

    strcpy(buff,"Please send IP address");
    write(acceptfd, buff, sizeof(buff));
    bzero(buff, MAX);
        read(acceptfd, buff, sizeof(buff));

        printf("From client: %s\t \nTo client : ", buff);

        if (validate_ip(buff))
        {
        printf("IP address validated successfully\n ");
    bzero(buff, MAX);
        strcpy(buff,"IP address validated successfully");
    write(acceptfd, buff, sizeof(buff));
        }

        else
        {
        bzero(buff, MAX);
    strcpy(buff,"IP address not validated successfully");
    printf("IP address not Validated successfully\n");
        write(acceptfd, buff, sizeof(buff));
    }
        printf("\n\n");
}



/**
 *@Brief : Validate mac address
 * Argument is pointer which hold base addres of the string
 *isxdigit() is a library function which checks hexadecimal digits
 *Integer i count number of digits and s count number of seperaters
 *if number of digits are 12 and seperaters are 5 or 2 or 0 or 3 , then function returns 1
 *else function returns 0
 *@Return: integer value 1 or 0
 */
int isValidMacAddress(char* mac)
{
        int i = 0;
        int s = 0;


        while (*mac)
        {
                if (isxdigit(*mac))
                 {
                        i++;
                 }
                else if (*mac == ':' || *mac == '-' || * mac == ' ' || * mac == '.')
                {
                        ++s;
                }

                ++mac;
        }
        return (i == 12 && (s == 5 || s == 2 || s == 0 || s == 3));
}

/**
 *@Brief : Collect mac from client and send validation massage.
 * Argument is file discriptor of accept function.
 *bzero() fuction used to empty buffer.
 *read () and Write() functions used to send and receive messages.
 *After calling isValidMacAddress() send respective message to client.
 *@Return : void type return nothing.
 */
void formac(int acceptfd)
{

        bzero(buff, MAX);
    strcpy(buff,"Please send MAC address");
    write(acceptfd, buff, sizeof(buff));

    bzero(buff, MAX);
        read(acceptfd, buff, sizeof(buff));

        printf("From client: %s\t \nTo client : ", buff);
        if (isValidMacAddress(buff))
        {
        bzero(buff, MAX);
            strcpy(buff,"Mac address validated successfully");
        puts(buff);
            write(acceptfd, buff, sizeof(buff));

        }
        else
        {
                bzero(buff, MAX);
                strcpy(buff,"Mac address not validated successfully");
        puts(buff);
                write(acceptfd, buff, sizeof(buff));
        }
        printf("\n\n");
}
