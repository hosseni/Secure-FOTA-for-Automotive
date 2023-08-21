/*
 * decription.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Hosseni
 */




void decryptFile (unsigned char *Host_Buffer,unsigned char *decrypted )
{
    const char* key = "AA";
    unsigned char buffer;
    unsigned char keyLength = strlen(key);
    unsigned char i = 0;

    while (i < 8)
    {
    	decrypted [i] = Host_Buffer[i];
    	decrypted[i] ^= *key; // XOR operation with key
        i++;
    }
}
