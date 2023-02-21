#include <stdio.h>
#include <stdint.h>

int main()
{
    int dice[4];
    int rotate;
    uint16_t result;
    uint8_t temp_array[4];
    uint32_t bit_array[4];
    uint32_t N, first_byte, second_byte, third_byte, forth_byte;
    uint32_t temp = 0x00000000;

    scanf("%u", &N);
    scanf("%d %d %d %d", &dice[0], &dice[1], &dice[2], &dice[3]);

    first_byte = (N >> 24) & 0x000000ff;
    second_byte = (N >> 16) & 0x000000ff;
    third_byte = (N >> 8) & 0x000000ff;
    forth_byte = (N >> 0) & 0x000000ff;

    for (int i = 0; i < 4; i++)
    {
        switch (dice[i])
        {
        case 1:
            bit_array[i] = first_byte;
            break;
        case 2:
            bit_array[i] = second_byte;
            break;
        case 3:
            bit_array[i] = third_byte;
            break;
        case 4:
            bit_array[i] = forth_byte;
            break;
        default:
            break;
        }
        // printf("dice[%d] = %d, bit_array = %x\n", i, dice[i], bit_array[i]);
    }

    // step1 : temp_array[3] (MSB) = (d1)th byte XOR (d2)th byte
    temp_array[3] = bit_array[0] ^ bit_array[1];

    // step2 : temp_array[2] = (d2)th byte AND (d3)th byte
    temp_array[2] = bit_array[1] & bit_array[2];

    // step3 : temp_array[1] = (d3)th byte OR (d1) the byte
    temp_array[1] = bit_array[2] | bit_array[0];

    // step4 : temp_array[0] = ~(d4)th byte
    temp_array[0] = ~bit_array[3];

    // concat temp by temp_array
    temp = temp | (temp_array[3] << 24);
    temp = temp | (temp_array[2] << 16);
    temp = temp | (temp_array[1] << 8);
    temp = temp | (temp_array[0] << 0);

    // steps6 : Rotate the temp right by (d1 + d2 + d3 + d4) bits.
    rotate = dice[0] + dice[1] + dice[2] + dice[3];
    temp = (temp >> rotate) | (temp << (32 - rotate));

    // FIXME: Xor the upper 16 bits of temp with the lower 16 bits of temp to form a 16-bit unsigned integer
    result = ((temp & 0xffff0000) >> 16) ^ (temp & 0x0000ffff);

    printf("%d\n", result);
    return 0;
}