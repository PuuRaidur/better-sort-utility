#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sorts.c"
// help() function undone yet, got to code that
void main(int argc, char* argv[]){
    int result;
    long long unsigned int arr[] = {5, 1, 6, 2, 10, 3, 9, 8, 7, 4};
    double dblarr[] = {3.14, 2.14, 7.123, 45.3124, 32.132, 11.11, 98.32, 435.23, 5.243, 4.546};
    unsigned char charr[] = {'w', 'g', 'a', 'h', 'e', 'd', 't', 'j', 'o', 's'};
    // PS - don't change data types(mandatory for compatibility with functions in the sorts.c)
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    while((result = getopt(argc, argv, ":bsimhycndrp:")) != -1){
        switch(result){
            case 'b':
                if(strcmp(argv[2], "int") == 0){
                    printf("array before sorting:");
                    unsintprintarr(arr, size);
                    unsintbubsort(arr, size);
                    printf("\narray after being sorted:");
                    unsintprintarr(arr, size);
                }
                else if(strcmp(argv[2], "dbl") == 0){
                    printf("array before sorting:");
                    dblprintarr(dblarr, size);
                    dblbubsort(dblarr, size);
                    printf("\narray after being sorted:");
                    dblprintarr(dblarr, size);
                }
                else if(strcmp(argv[2], "chr") == 0){
                    printf("array before sorting:");
                    chprintarr(charr, size);
                    chbubsort(charr, size);
                    printf("\narray after being sorted:");
                    chprintarr(charr, size);
                }
                else{
                    printf("Wrong options. Here's help for you:\n");
                    help();
                }
            break;
            case 's':
                if(strcmp(argv[2], "int") == 0){
                    printf("array before sorting:");
                    unsintprintarr(arr, size);
                    unsintselsort(arr, size);
                    printf("\narray after being sorted:");
                    unsintprintarr(arr, size);
                }
                else if(strcmp(argv[2], "dbl") == 0){
                    printf("array before sorting:");
                    dblprintarr(dblarr, size);
                    dblselsort(dblarr, size);
                    printf("\narray after being sorted:");
                    dblprintarr(dblarr, size);
                }
                else if(strcmp(argv[2], "chr") == 0){
                    printf("array before sorting:");
                    chprintarr(charr, size);
                    chselsort(charr, size);
                    printf("\narray after being sorted:");
                    chprintarr(charr, size);
                }
                else{
                    printf("Wrong options. Here's help for you:\n");
                    help();
                }
            break;
            case 'i':
                if(strcmp(argv[2], "int") == 0){
                    printf("array before sorting:");
                    unsintprintarr(arr, size);
                    unsintinssort(arr, size);
                    printf("\narray after being sorted:");
                    unsintprintarr(arr, size);
                }
                else if(strcmp(argv[2], "dbl") == 0){
                    printf("array before sorting:");
                    dblprintarr(dblarr, size);
                    dblinssort(dblarr, size);
                    printf("\narray after being sorted:");
                    dblprintarr(dblarr, size);
                }
                else if(strcmp(argv[2], "chr") == 0){
                    printf("array before sorting:");
                    chprintarr(charr, size);
                    chinssort(charr, size);
                    printf("\narray after being sorted:");
                    chprintarr(charr, size);
                }
                else{
                    printf("Wrong choice. Here's help for you:\n");
                    help();
                }
            break;
            case 'm':
                if(strcmp(argv[2], "int") == 0){
                    printf("array before sorting:");
                    unsintprintarr(arr, size);
                    unsintmersort(arr, mid, size);
                    printf("\narray after being sorted:");
                    unsintprintarr(arr, size);
                }
                else if(strcmp(argv[2], "dbl") == 0){
                    printf("array before sorting:");
                    dblprintarr(dblarr, size);
                    dblmersort(dblarr, mid, size);
                    printf("\narray after being sorted:");
                    dblprintarr(dblarr, size);
                }
                else if(strcmp(argv[2], "chr") == 0){
                    printf("array before sorting:");
                    chprintarr(charr, size);
                    chmersort(charr, mid, size);
                    printf("\narray after being sorted:");
                    chprintarr(charr, size);
                }
                else{
                    printf("Wrong choice. Here's help for you:\n");
                    help();
                }
            break;
            case 'h':
                printf("Here's help for you:\n");
                help();
            break;
            case 'y':
            sort_system();
            break;
            case 'c':
            char_in_dec_oct_hex_bin();
            break;
            case 'n':
            unsintinput();
            break;
            case 'd':
            dblinput();
            break;
            case 'r':
            charinput();
            break;
            case 'p':
            char_print_system();
            break;
            case '?':
                printf("Unknown operand. Here's help for you:\n");
                help();
            break;
        }
    }
}