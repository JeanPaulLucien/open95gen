/*
Open95Keygen version 1.0 - Febuary 7th 2021
100% ANSI X3.159-1989 compliant (ANSI/C89)

BSD 3-Clause License

Copyright (c) 2021, Alex Free
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIGIT_RANGE 10
#define OEM_DAY_RANGE 367

typedef enum { FALSE, TRUE } bool;

bool gen;

int oem_key_year[2] = {1, 1}; // 2 - gen_oem_year
int oem_key_5[5];
int oem_key_5_random[5];
int retail_key_1[3];
int retail_key_2[7];

int oem_key_day = 0; // 1 - gen_oem_day
int digit;
int i;
int sum7;

void gen_oem_day() 
{
  do
  {
    oem_key_day = rand() % OEM_DAY_RANGE;
  }
  while(oem_key_day == 0);
}

void gen_oem_year() 
{
    do
    {
        oem_key_year[0] = rand() % DIGIT_RANGE;
        oem_key_year[1] = rand() % DIGIT_RANGE;
    }
    while((oem_key_year[0] != 9 && oem_key_year[1] < 5) && (oem_key_year[0] != 0 && oem_key_year[1] >= 3));
}

void gen_5digits_oem()
{
    do
    {
        for(i = 0; i < 5; i++)
        {
            oem_key_5[i] = rand() % DIGIT_RANGE;
        }
        sum7 = oem_key_5[0] + oem_key_5[1] + oem_key_5[2] + oem_key_5[3] + oem_key_5[4];
    }
    while(sum7 % 7 != 0);
}

void gen_5digits_random_oem()
{
    for(digit = 0 ; digit < 5; ++digit)
    {
        oem_key_5_random[digit] = rand() % DIGIT_RANGE;
    }
}

void gen_3digits_retail() 
{
    gen = TRUE;
    while(gen) 
    {
        for(digit = 0; digit < 3; ++digit)
        retail_key_1[digit] = rand() % DIGIT_RANGE;

        if((retail_key_1[0] == 3 && retail_key_1[1] == 3 && retail_key_1[2] == 3) || (retail_key_1[0] == 4 && retail_key_1[1] == 4 && retail_key_1[2] == 4) || (retail_key_1[0] == 5 && retail_key_1[1] == 5 && retail_key_1[2] == 5) || (retail_key_1[0] == 6 && retail_key_1[1] == 6 && retail_key_1[2] == 6) || (retail_key_1[0] == 7 && retail_key_1[1] == 7 && retail_key_1[2] == 7) || (retail_key_1[0] == 8 && retail_key_1[1] == 8 && retail_key_1[2] == 8) || (retail_key_1[0] == 9 && retail_key_1[1] == 9 && retail_key_1[2] == 9))
        {
            gen = TRUE; //printf("generating...");
        }
        else
        {
            gen = FALSE;
        }
    }
}

void gen_7digits_retail()
{
    do
    {
        for(digit = 0; digit < 7; ++digit)
        {
            retail_key_2[digit] = rand() % DIGIT_RANGE;
        }
        sum7 = retail_key_2[0] + retail_key_2[1] + retail_key_2[2] + retail_key_2[3] + retail_key_2[4] + retail_key_2[5] + retail_key_2[6];
    }
    while(sum7 % 7 != 0);  
}

int main()
{
    srand(time(NULL));
    printf("Open95Keygen by Alex Free (C)2021\n");
    gen_3digits_retail();
    gen_7digits_retail();
    printf("Retail Product Key: %d%d%d-%d%d%d%d%d%d%d\n", retail_key_1[0], retail_key_1[1], retail_key_1[2], retail_key_2[0], retail_key_2[1], retail_key_2[2], retail_key_2[3], retail_key_2[4], retail_key_2[5], retail_key_2[6]);
    gen_oem_day();
    gen_oem_year();
    gen_5digits_oem();
    gen_5digits_random_oem();
    printf("OEM Product Key: %03d%d%d-OEM-00%d%d%d%d%d-%d%d%d%d%d\n", oem_key_day, oem_key_year[0], oem_key_year[1], oem_key_5[0], oem_key_5[1], oem_key_5[2], oem_key_5[3], oem_key_5[4], oem_key_5_random[0], oem_key_5_random[1], oem_key_5_random[2], oem_key_5_random[3], oem_key_5_random[4]);
    return(0);
}
