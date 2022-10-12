#include <stdio.h>
#include <stdlib.h>
/* Do what you want with this code (I'm a supporter of open source).
Before using this library don't forget to declare variables with the right data types (e.g. long long unsigned int and double).
If implementing merge sort, declare and initialize mid point before that with a simple formula:
int mid = (number of elements) / 2;
This library's point is to give you guys a picture of how different sorting algorithms work.
That's why you see the sorting of the array step by step.
This library will get updated in the future(more sorting algorithms coming here), so don't worry.
I also added some functions with what you can see a char array in different codes(dec, oct, hex)
There could easily be some mistakes in the code, so if you catch them, feel totally free to change it to your needs. */
void help();
// provides help for command line arguments
void unsintswap(long long unsigned int *x, unsigned long long int *y);
// swaps two integer variables values
void unsintprintarr(long long unsigned int *arr, int size);
// prints out integer array
void unsintbubsort(unsigned long long int *arr, int size);
// performs bubble sort on integer array
void unsintselsort(unsigned long long int *arr, int size);
// performs selection sort on integer array
void unsintmersort(unsigned long long int *arr, int mid, int right);
// performs merge sort on integer array
void unsintinssort(unsigned long long int *arr, int size);
// performs insertion sort on integer array
void unsintinput();
// executes a text-based application with what you can give values to integer array and
// then choose sorting technique to apply to it.
// Uses recursion
void dblswap(double *x, double *y);
// swaps two double variables values
void dblprintarr(double *arr, int size);
// prints out double array
void dblbubsort(double arr[], int size);
// performs bubble sort on double array
void dblselsort(double arr[], int size);
// performs selection sort on double array
void dblmersort(double arr[], int mid, int right);
// performs merge sort on double array
void dblinssort(double arr[], int size);
// performs insertion sort on double array
void dblinput();
// executes a text-based application with what you can give values to double array and
// then choose sorting technique to apply to it.
// Uses recursion
void chswap(unsigned char *x, unsigned char *y);
// swaps two char variables values
void chprintarr(unsigned char *arr, int size);
// prints out char array
void chbubsort(unsigned char arr[], int size);
// performs bubble sort on char array
void chselsort(unsigned char arr[], int size);
// performs selection sort on char array
void chmersort(unsigned char arr[], int mid, int right);
// performs merge sort on char array
void chinssort(unsigned char arr[], int size);
// performs insertion sort on char array
void charinput();
// executes a text-based application with what you can give values to char array and
// then choose sorting technique to apply to it.
// Uses recursion
void print_char_in_dec_oct_hex(unsigned char arr[], int size);
// prints out char array in decimal code, octal code and hexadecimal code
void char_in_dec_oct_hex();
// executes a text-based application with what you can give values to char array and
// then see that array in decimal, octal and hexadecimal code.
// Uses recursion
void sort_system();
// function that lets you give values max to 10 arrays and then sort them
void char_print_system();
// function to give values to max 10 char arrays and see them in different codes
void help(){
    printf("\nHelp:\n");
    printf("command-line prototype:\n");
    printf("[executable file's name] [OPTIONS] [array type]\n");
    printf("OPTIONS:\n");
    printf("-b = bubble sort\n");
    printf("-s = selection sort\n");
    printf("-i = insertion sort\n");
    printf("-m = merge sort\n");
    printf("-h = help\n");
    printf("-y = sort system\n");
    printf("-c = char array in different codes\n");
    printf("-n = give-values-and-sort function for int array\n");
    printf("-d = give-values-and-sort function for double array\n");
    printf("-r = give-values-and-sort function for char array\n");
    printf("-p = char arrays print system\n");
    printf("array types:\n");
    printf("int = int array\n");
    printf("dbl = double array\n");
    printf("chr = char array\n");
}
void unsintswap(long long unsigned int *x, long long unsigned int *y){
    long long unsigned int temp = *x;
    *x = *y;
    *y = temp;
}
void unsintprintarr(long long unsigned int *arr, int size){
    for(int i = 0; i < size; i++){
        printf(" %llu", arr[i]);
    }
}
void unsintbubsort(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                unsintswap(&arr[j], &arr[j+1]);
                unsintprintarr(arr, size);
                printf("\n");
            }
        }
    }
}
void unsintselsort(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                unsintswap(&arr[i], &arr[j]);
                unsintprintarr(arr, size);
                printf("\n");
            }
        }
    }
}
void unsintmersort(long long unsigned int arr[], int mid, int size){
    int i,j,k;
    int n1 = mid;
    int n2 = size - mid;
    long long unsigned int l[n1],r[n2];
    for(i = 0; i < n1; i++){
        l[i] = arr[i];
    }
    for(j = 0; j < n2; j++){
        r[j] = arr[mid+j];
    }
    printf("\nValues given to first temporary subarray: ");
    unsintprintarr(l, n1);
    printf("\nValues given to second temporary subarray: ");
    unsintprintarr(r, n2);
    for(i = 0; i < n1; i++){
        for(j = 0; j < n1-1; j++){
            if(l[j] > l[j+1]){
                unsintswap(&l[j],&l[j+1]);
                printf("\n");
                unsintprintarr(l, n1);
            }
        }
    }
    for(i = 0; i < n2; i++){
        for(j = 0; j < n2-1; j++){
            if(r[j] > r[j+1]){
                unsintswap(&r[j],&r[j+1]);
                printf("\n");
                unsintprintarr(r, n2);
            }
        }
    }
    printf("\nSorted first temporary subarray: ");
    unsintprintarr(l, n1);
    printf("\nSorted second temporary subarray: ");
    unsintprintarr(r, n2);
    printf("\n");
    i = 0;
    j = 0;
    k = 0;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
        printf("\n");
        unsintprintarr(arr, k);
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
        printf("\n");
        unsintprintarr(arr, k);
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
        printf("\n");
        unsintprintarr(arr, k);
    }
}
void unsintinssort(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        long long unsigned int place = arr[i];
        int j = i - 1;
        while(place < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = place;
            unsintprintarr(arr, size);
            printf("\n");
        }
    }
}
void dblswap(double *x, double *y){
    double temp = *x;
    *x = *y;
    *y = temp;
}
void dblprintarr(double *arr, int size){
    for(int i = 0; i < size; i++){
        printf("   %.2lf", arr[i]);
    }
}
void dblbubsort(double arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                dblswap(&arr[j], &arr[j+1]);
                dblprintarr(arr, size);
                printf("\n");
            }
        }
    }
}
void dblselsort(double arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                dblswap(&arr[i], &arr[j]);
                dblprintarr(arr, size);
                printf("\n");
            }
        }
    }
}
void dblmersort(double arr[], int mid, int size){
    int i,j,k;
    int n1 = mid;
    int n2 = size - mid;
    double l[n1],r[n2];
    for(i = 0; i < n1; i++){
        l[i] = arr[i];
    }
    for(j = 0; j < n2; j++){
        r[j] = arr[mid+j];
    }
    printf("\nValues given to first temporary subarray: ");
    dblprintarr(l, n1);
    printf("\nValues given to first temporary subarray: ");
    dblprintarr(r, n2);
    for(i = 0; i < n1; i++){
        for(j = 0; j < n1-1; j++){
            if(l[j] > l[j+1]){
                dblswap(&l[j],&l[j+1]);
                printf("\n");
                dblprintarr(l, n1);
            }
        }
    }
    for(i = 0; i < n2; i++){
        for(j = 0; j < n2-1; j++){
            if(r[j] > r[j+1]){
                dblswap(&r[j],&r[j+1]);
                printf("\n");
                dblprintarr(r, n2);
            }
        }
    }
    printf("\nSorted first temporary subarray: ");
    dblprintarr(l, n1);
    printf("\nSorted second temporary subarray: ");
    dblprintarr(r, n2);
    printf("\n");
    i = 0;
    j = 0;
    k = 0;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
        printf("\n");
        dblprintarr(arr, k);
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
        printf("\n");
        dblprintarr(arr, k);
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
        printf("\n");
        dblprintarr(arr, k);
    }
}
void dblinssort(double arr[], int size){
    for(int i = 0; i < size; i++){
        double place = arr[i];
        int j = i - 1;
        while(place < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = place;
            dblprintarr(arr, size);
            printf("\n");
        }
    }
}
void chswap(unsigned char *x, unsigned char *y){
    unsigned char temp = *x;
    *x = *y;
    *y = temp;
}
void chprintarr(unsigned char *arr, int size){
    for(int i = 0; i < size; i++){
        printf("  %d.\'%c\'", i+1, arr[i]);
    }
}
void chbubsort(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                chswap(&arr[j], &arr[j+1]);
                chprintarr(arr, size);
                printf("\n");
            }
        }
    }
}
void chselsort(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                chswap(&arr[i], &arr[j]);
                chprintarr(arr, size);
                printf("\n");
            }
        }
    }
}
void chmersort(unsigned char arr[], int mid, int size){
    int i,j,k;
    int n1 = mid;
    int n2 = size - mid;
    unsigned char l[n1],r[n2];
    for(i = 0; i < n1; i++){
        l[i] = arr[i];
    }
    for(j = 0; j < n2; j++){
        r[j] = arr[mid+j];
    }
    printf("\nValues given to first temporary subarray: ");
    chprintarr(l, n1);
    printf("\nValues given to second temporary subarray: ");
    chprintarr(r, n2);
    for(i = 0; i < n1; i++){
        for(j = 0; j < n1-1; j++){
            if(l[j] > l[j+1]){
                chswap(&l[j],&l[j+1]);
                printf("\n");
                chprintarr(l, n1);
            }
        }
    }
    for(i = 0; i < n2; i++){
        for(j = 0; j < n2-1; j++){
            if(r[j] > r[j+1]){
                chswap(&r[j],&r[j+1]);
                printf("\n");
                chprintarr(r, n2);
            }
        }
    }
    printf("\nSorted first temporary subarray: ");
    chprintarr(l, n1);
    printf("\nSorted second temporary subarray: ");
    chprintarr(r, n2);
    printf("\n");
    i = 0;
    j = 0;
    k = 0;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
        printf("\n");
        chprintarr(arr, k);
        printf("\n");
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
        printf("\n");
        chprintarr(arr, k);
        printf("\n");
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
        printf("\n");
        chprintarr(arr, k);
        printf("\n");
    }
}
void chinssort(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        unsigned char place = arr[i];
        int j = i - 1;
        while(place < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = place;
            chprintarr(arr, size);
            printf("\n");
        }
    }
}
void unsintinput(){
    long long unsigned int arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2; char choice;
    printf("Select 10 integer numbers (max size: 18 quintillion).\nNegative numbers are not supported\n");
    printf("18 quintillion = 18,446,744,073,709,551,615\n");
    printf("Choices\n");
    for(int i = 0; i < size; i++){
        printf("\nNumber %d:", i+1);
        scanf(" %llu", &arr[i]);
    }
    printf("Array: ");
    unsintprintarr(arr, size);
    printf("\n");
    printf("Now choose your sort technique.\n");

    while(1){
        printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
        printf("E or e to exit the program.\n");
        printf("A or a to do it again (uses recursion).\n");
        printf("Choice:");
        scanf(" %c", &choice);

        switch(choice){

            case 'B':
            case 'b':
            unsintbubsort(arr, size);
            printf("Sorted Array:  ");
            unsintprintarr(arr, size);
            break;

            case 'S':
            case 's':
            unsintselsort(arr, size);
            printf("Sorted Array:  ");
            unsintprintarr(arr, size);
            break;

            case 'M':
            case 'm':
            unsintmersort(arr, mid, size);
            printf("\nSorted Array:  ");
            unsintprintarr(arr, size);
            break;

            case 'I':
            case 'i':
            unsintinssort(arr, size);
            printf("Sorted array:  ");
            unsintprintarr(arr, size);
            break;

            case 'E':
            case 'e':
            exit(0);
            break;

            case 'A':
            case 'a':
            unsintinput();
            break;

            default:
            printf("\nWrong choice, try again.\n");
        }
    }
}
void dblinput(){
    double arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    char choice;
    printf("Select 10 floating-point numbers (max size: 16 decimal places)\n");
    printf("Choices");
    for(int i = 0; i < size; i++){
        printf("\nNumber %d:", i+1);
        scanf(" %lf", &arr[i]);
    }
    printf("\nArray: ");
    dblprintarr(arr, size);
    printf("\nNow choose your sort technique.\n");

    while(1){
        printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
        printf("E or e to exit the program.\n");
        printf("A or a to do it again(uses recursion).\n");
        printf("Choice:");
        scanf(" %c", &choice);
        
        switch(choice){

            case 'B':
            case 'b':
            dblbubsort(arr, size);
            printf("Sorted Array:  ");
            dblprintarr(arr, size);
            break;

            case 'S':
            case 's':
            dblselsort(arr, size);
            printf("Sorted Array:  ");
            dblprintarr(arr, size);
            break;

            case 'M':
            case 'm':
            dblmersort(arr, mid, size);
            printf("\nSorted Array:  ");
            dblprintarr(arr, size);
            break;

            case 'I':
            case 'i':
            dblinssort(arr, size);
            printf("Sorted array:  ");
            dblprintarr(arr, size);
            break;

            case 'E':
            case 'e':
            exit(0);
            break;

            case 'A':
            case 'a':
            dblinput();
            break;

            default:
            printf("\nWrong choice. Try again.\n");
        }
    } 
}
void charinput(){
    unsigned char arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    char choice;
    printf("Enter 10 characters to sort them.\n");
    printf("Choices");
    for(int i = 0; i < size; i++){
        printf("\n%d. Character:", i+1);
        scanf(" %c", &arr[i]);
    }
    printf("Array: ");
    chprintarr(arr, size);
    printf("\n");
    printf("Now choose your sort technique\n");

    while(1){
        printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
        printf("E or e to exit the program.\n");
        printf("A or a to do it again(uses recursion).\n");
        printf("Choice:");
        scanf(" %c", &choice);

        switch(choice){

            case 'B':
            case 'b':
            chbubsort(arr, size);
            printf("Sorted Array:  ");
            chprintarr(arr, size);
            break;

            case 'S':
            case 's':
            chselsort(arr, size);
            printf("Sorted Array:  ");
            chprintarr(arr, size);
            break;

            case 'M':
            case 'm':
            chmersort(arr, mid, size);
            printf("\nSorted Array:  ");
            chprintarr(arr, size);
            break;

            case 'I':
            case 'i':
            chinssort(arr, size);
            printf("Sorted array:  ");
            chprintarr(arr, size);
            break;

            case 'E':
            case 'e':
            exit(0);
            break;

            case 'A':
            case 'a':
            charinput();
            break;

            default:
            printf("\nWrong choice. Try again.\n");
        }
    }
}
void sort_system(){
    long long unsigned int arr1[10]; long long unsigned int arr2[10]; unsigned long long int arr3[10]; unsigned long long int arr4[10];
    unsigned long long int arr5[10]; unsigned long long int arr6[10]; unsigned long long int arr7[10]; unsigned long long int arr8[10];
    unsigned long long int arr9[10]; unsigned long long int arr10[10]; int limit; int i; int j; char ch; int whilecon = 1;
    int size = sizeof(arr1)/sizeof(arr1[0]); int mid = size/2;
    printf("Choose the amount of integer arrays to sort and give values to them");
    printf("(max arrays: 10; 10 values for each array)"); printf("\nChoice:");
    scanf(" %d", &limit);
    while(limit > size | limit <= 0){
        printf("Too much! Try again!\nChoice:");
        scanf(" %d", &limit);
    }
    printf("Now give values to your arrays:");
    for(i = 1; i <= limit; i++){
        if(i == 1){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr1[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr1, size);
        }
        if(i == 2){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr2[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr2, size);
        }
        if(i == 3){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr3[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr3, size);
        }
        if(i == 4){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr4[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr4, size);
        }
        if(i == 5){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr5[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr5, size);
        }
        if(i == 6){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr6[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr6, size);
        }
        if(i == 7){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr7[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr7, size);
        }
        if(i == 8){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr8[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr8, size);
        }
        if(i == 9){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr9[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr9, size);
        }
        if(i == 10){
            printf("\n\nGive values to %d. array:\n", i);
            for(j = 0; j < size; j++){
                printf("%d. element:", j);
                scanf("%llu", &arr10[j]);
            }
            printf("\n%d. array:", i); unsintprintarr(arr10, size);
        }
    }
    printf("\nNow choose sorting algorithm for each array. This process is in endless repetition unless you exit the program.\n");
    printf("B or b for bubble sort, S or s for selection sort, I or i for insertion sort, M or m for merge sort.\n");
    printf("E or e to exit the program.\n"); printf("A or a to do it again(repeats the whole function,");
    printf(" not only this section(uses recursion)).");
    for(i = 1; i <= limit; i++){
        if(i == 1){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr1, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr1, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr1, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr1, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr1, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 2){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr2, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr2, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr2, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr2, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 3){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr3, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr3, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr3, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr3, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 4){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr4, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr4, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr4, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr4, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 5){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr5, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr5, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr5, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr5, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 6){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr6, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr6, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr6, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr6, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 7){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr7, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr7, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr7, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr7, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 8){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr8, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr8, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr8, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr8, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 9){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr9, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr9, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr9, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr9, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1;
        if(i == 10){
            while(whilecon == 1){
                printf("\n%d. array before sorting:", i);
                unsintprintarr(arr2, size);
                printf("\nsorting technique for %d. array:", i); scanf(" %c", &ch);
                switch(ch){
                    case 'B':
                    case 'b': unsintbubsort(arr10, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'S':
                    case 's': unsintselsort(arr10, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'I':
                    case 'i': unsintinssort(arr10, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'M':
                    case 'm': unsintmersort(arr10, mid, size);
                    printf("sorted array:"); unsintprintarr(arr1, size);
                    whilecon = 0;
                    break;
                    case 'E':
                    case 'e': exit(0);
                    break;
                    case 'A':
                    case 'a': sort_system();
                    break;
                    default: printf("Wrong choice! Try again\n");
                }
            }
        }
        whilecon = 1; // just in case I'm going to add stuff to the code
    }
}
void print_char_in_dec_oct_hex_bin(unsigned char arr[], int size){
    int i, j;
    printf("\nNormal array: ");
    for(i = 0; i < size; i++){
        printf(" %d.%c", i, arr[i]);
    }
    printf("\nDecimal array: ");
    for(i = 0; i < size; i++){
        printf("  %d.%d", i, arr[i]);
    }
    printf("\nOctal array: ");
    for(i = 0; i < size; i++){
        printf("  %d.%o", i, arr[i]);
    }
    printf("\nHexadecimal array: ");
    for(i = 0; i < size; i++){
        printf("  %d.%x", i, arr[i]);
    }
    printf("\nBinary array: ");
    for (i = 0; i < size; i++){
        printf(" %d.", i);
        for(j = 0; j < 8;j++){
            printf("%d", !!((arr[i] << j) & 0x80));
        }
    }
    // binary array doesn't work correctly in char_print_system(); function
}
void char_in_dec_oct_hex_bin(){
    unsigned char arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    char ch;
    while(1){
    printf("\nChoose up to 10 characters or symbols and see their decimal, octal and hexadecimal values\n");
    printf("Numbers are not accepted\n");
    printf("Choices:\n");
    for(int i = 0; i < size; i++){
        printf("\n%d. Character:", i+1);
        scanf(" %c", &arr[i]);
    }
    printf("\nCharacter array: ");
    chprintarr(arr, size);
    printf("\nNow choose what you want to do:\n");
    printf("P or p to proceed to see the array in decimal, octal and hexadecimal code.\n");
    printf("E or e to exit the program.\n");
    printf("Any other key to do it again.\n");
    printf("Decision:");
    scanf(" %c", &ch);
    switch(ch){

        case 'P':
        case 'p':print_char_in_dec_oct_hex_bin(arr, size);
        break;

        case 'E':
        case 'e':exit(0);
        break;

        default:printf("\nWe're going to do it again."); char_in_dec_oct_hex_bin();
        }
    }
}
void char_print_system(){
    unsigned char arr1[10]; unsigned char arr2[10]; unsigned char arr3[10]; unsigned char arr4[10]; unsigned char arr5[10];
    unsigned char arr6[10]; unsigned char arr7[10]; unsigned char arr8[10]; unsigned char arr9[10]; unsigned char arr10[10];
    int size = sizeof(arr1)/sizeof(arr1[0]); int limit; int i; int j; char ch;
    while(1){
        printf("Give values to max 10 char arrays(10 values for each array) and see them in binary, decimal and hexadecimal code.\n");
        printf("How many arrays do you want to give values to?\n");
        printf("Choice:"); scanf(" %d", &limit);
        while(limit > 10){
            printf("Too many. Try again. Choice:"); scanf(" %d", &limit);
        }
        while(limit <= 0){
            printf("Too little. Try again. Choice:"); scanf(" %d", &limit);
        }
        printf("Now it's time to give values to your arrays.\n");
        for(i = 1; i <= limit; i++){
            if(i == 1){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr1);
                }
                printf("\n%d. array:", i); chprintarr(arr1, size);
            }
            if(i == 2){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr2);
                }
                printf("\n%d. array:", i);chprintarr(arr2, size);
            }
            if(i == 3){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr3);
                }
                printf("\n%d. array:", i);chprintarr(arr3, size);
            }
            if(i == 4){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr4);
                }
                printf("\n%d. array:", i);chprintarr(arr4, size);
            }
            if(i == 5){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr5);
                }
                printf("\n%d. array:", i);chprintarr(arr5, size);
            }
            if(i == 6){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr6);
                }
                printf("\n%d. array:", i);chprintarr(arr6, size);
            }
            if(i == 7){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr7);
                }
                printf("\n%d. array:", i);chprintarr(arr7, size);
            }
            if(i == 8){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr8);
                }
                printf("\n%d. array:", i);chprintarr(arr8, size);
            }
            if(i == 9){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr9);
                }
                printf("\n%d. array:", i);chprintarr(arr9, size);
            }
            if(i == 10){
                printf("\ngive values to the %d. array:\n", i);
                for(j = 0; j < size; j++){
                    printf("%d. element:", j); scanf(" %c", &arr10);
                }
                printf("\n%d. array:", i);chprintarr(arr10, size);
            }
        }
        printf("The values of your arrays are:\n\n");
        for(i = 1; i <= limit; i++){
            if(i == 1){
                printf("details of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr1, size);
            }
            if(i == 2){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr2, size);
            }
            if(i == 3){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr3, size);
            }
            if(i == 4){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr4, size);
            }
            if(i == 5){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr5, size);
            }
            if(i == 6){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr6, size);
            }
            if(i == 7){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr7, size);
            }
            if(i == 8){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr8, size);
            }
            if(i == 9){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr9, size);
            }
            if(i == 10){
                printf("\ndetails of %d. array:", i);
                print_char_in_dec_oct_hex_bin(arr10, size);
            }
        }
        printf("\nE or e to exit the program, any other key to repeat the process(recursion NOT used, while loop instead).Choice:");
        scanf(" %c", &ch);
        switch(ch){
            case 'E':
            case 'e': exit(0);
            break;
            default: printf("Repeating the process...\n");
        }
    }
}