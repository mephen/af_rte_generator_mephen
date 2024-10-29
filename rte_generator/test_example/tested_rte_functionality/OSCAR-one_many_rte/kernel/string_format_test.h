#ifndef STRING_FORMAT_TEST_H
#define STRING_FORMAT_TEST_H

/* this file should not be include in the final released project*/

char dec_to_hex ( unsigned char num );

/* assume char str[32] declared in caller*/
void itoa_16(char* str, unsigned int num);
void itoa_16_show_id(char* str, unsigned int num);
void itoa(char* str, unsigned int num);
#endif