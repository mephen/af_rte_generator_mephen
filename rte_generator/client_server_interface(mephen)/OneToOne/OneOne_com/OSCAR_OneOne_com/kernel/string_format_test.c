
char dec_to_hex ( unsigned char num ){
    if(num < 10){
        return num + '0';
    }
    else if ( num < 16 ){
        return (num - 10) + 'a';
    }
    else
        return 'x';     //i.e., WTF?!
}

/* assume char str[32] declared in caller*/
void itoa_16(char* str, unsigned int num){
    unsigned char n1, ii;
    unsigned char idx = 14;

    str[0] = 'a';
    str[1] = 'd';
    str[2] = 'd';
    str[3] = 'r';
    str[4] = ':';
    str[5] = '0';
    str[6] = 'x';
    
    for(ii = 7; ii < 15; ++ii){
        str[ii] = '0';
    }
    str[15] = '\r';
    str[16] = '\n';
    str[17] = '\0';
    str[31] = '\0';

    while( num ){
        n1 = num % 16;
        str[idx] = dec_to_hex(n1);
        --idx;
        num /= 16;
    }
}

/* assume char str[32] declared in caller*/
void itoa_16_show_id(char* str, unsigned int num){
    unsigned char n1, ii;
    unsigned char idx = 14;

    str[0] = 'c';
    str[1] = 'u';
    str[2] = 'r';
    str[3] = ' ';
    str[4] = 'i';
    str[5] = 'd';
    str[6] = ':';
    
    for(ii = 7; ii < 15; ++ii){
        str[ii] = '0';
    }
    str[15] = '\r';
    str[16] = '\n';
    str[17] = '\0';
    str[31] = '\0';

    while( num ){
        n1 = num % 16;
        str[idx] = dec_to_hex(n1);
        --idx;
        num /= 16;
    }
}

int strlen(char *str){
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    return i;
}

char *reverse(char *str)
{
    char tmp, *src, *dst;
    unsigned int len;
    if (str != '\0' )
    {
        len = strlen (str);
        if (len > 1) {
            src = str;
            dst = src + len - 1;
            while (src < dst) {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}


void itoa(char* str, unsigned int num)
{
    unsigned char n1, ii;
    unsigned char idx = 14;

    str[0] = 'n';
    str[1] = 'u';
    str[2] = 'm';
    str[3] = 'b';
    str[4] = 'e';
    str[5] = 'r';
    str[6] = ':';
    
    for(ii = 7; ii < 15; ++ii){
        str[ii] = '0';
    }
    str[15] = '\r';
    str[16] = '\n';
    str[17] = '\0';
    str[31] = '\0';

    while( num ){
        n1 = num % 16;
        str[idx] = dec_to_hex(n1);
        --idx;
        num /= 16;
    }
}