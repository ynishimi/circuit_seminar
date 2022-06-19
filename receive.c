#include <stdio.h>

#define NUMBER_DATA 100
#define COLUMN 10
#define ROW 10
#define THRESHOLD 0.6

void csvread(const char *filename, float *out)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
        printf("Cannot open a file\n");
    else
    {
        for (int i = 0; i <NUMBER_DATA; i++)
        {
            //最初の一行は無視
             fscanf(fp, "%*[^,],%f", &out[i]);

            printf("out[%d]=%f\n", i, out[i]);
        }
            fclose(fp);
    }
}

void display(const float *in)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            if (in[COLUMN * i + j] >= THRESHOLD)
            {
                printf("█");
            }
            else
            {
                printf(" ");
            }
        }
        putchar('\n');
    }
}

int main()
{
    float data[NUMBER_DATA] = {0};
    csvread("data.csv", data);
    display(data);
    return 0;
}