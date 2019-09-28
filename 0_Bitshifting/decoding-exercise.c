#include <stdio.h>


/**
 * Main function
 */
int main(void)
{

    uint32_t message1[8] = {0x442202ac, 0x93d48631, 0xeac45990, 0xa2a4Cbbd, 0x7784c122, 0x7124f098, 0x442202ac, 0x00000000};
    uint8_t decoded_message1[8];

    uint8_t message2[12] = {0xdf, 0xaa, 0xbd, 0xbc, 0xdf, 0xac, 0xb0, 0xb3, 0xbe, 0xad, 0xdf, 0x00};
    uint8_t decoded_message2[12];

    uint8_t message3[9] = {0x02, 0xd4, 0x54, 0xd4, 0x24, 0x54, 0x25, 0x02, 0x00};
    uint8_t decoded_message3[9];

    // MEMBER
    // 0x20, 0x4D, 0x45, 0x4D, 0x42, 0x45, 0x52, 0x20

    uint8_t i;

    for (i = 0; i < 8; i++)
    {
        decoded_message1[i] = 0x00;
    }

    for (i = 0; i < 12; i++)
    {
        decoded_message2[i] = 0x00;
    }

    for (i = 0; i < 9; i++)
    {
        decoded_message3[i] = 0x00;
    }

    for (i = 0; i < 8; i++)
    {
        //decoded_message1[i] =  0xFF & (message1[i] >> 12);
    }
    decoded_message1[7] = '\0';

    for (i = 0; i < 12; i++)
    {
        //decoded_message2[i] = ~(message2[i]);
    }
    decoded_message2[11] = '\0';

    for (i = 0; i < 9; i++)
    {
        //decoded_message3[i] = (message3[i] >> 4) | (message3[i] << 4);
    }
    decoded_message3[8] = '\0';


    printf("%s\n", decoded_message1);
    printf("%s\n", decoded_message2);
    printf("%s\n", decoded_message3);

    getchar();

    return 0;
}