#include <iostream>
#include <ctime>
int j = 0;

void swapping(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
int pivotig(int* arr, int p, int left, int right)
{
   // int left = 0, right = size - 1, 
    int pivot = arr[p]; 
    while (true)
    {
        while (arr[left] < pivot) { left += 1; }
        while (arr[right] > pivot) { right -= 1; }
        std::cout << "left= " << left << " rgiht= " << right << " pivot[" << p << "]= " << pivot;
        if (left >= right) { return left; }

        int z; z = arr[left]; arr[left] = arr[right]; arr[right] = z;

        left += 1; right -= 1;
        std::cout << std::endl << "Отсортированный массив: ";
        for (int i = left; i <= right; i++) { std::cout << arr[i] << " "; }
        std::cout << std::endl;
       // std::cin >> j;
    } return right;
}
void quick_sort(int* arr, int i, int size)
{
    if (i < size) {
        std::cout << "Исходный массив: ";
        for (int k = i; k < size; k++) { std::cout << arr[k] << " "; }

        srand(time(0));

        if (size > 1)
        {
            int p, bord;
           // p = abs(rand() % (size-1));
            p = size/2;
            bord = pivotig(arr, p, i, size-1);
            std::cout << " bord= " << bord << " ";
            quick_sort(arr, 0, bord - 1);
            quick_sort(arr, bord + 1, size-1);
        }
       // std::cout << "j= " << j << " ";
       // j += 1;
    }

    std::cout << std::endl << "Отсортированный массив окончательный: ";
    for (int i = 0; i < size; i++) { std::cout << arr[i] << " "; }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    // int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
   //  int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

    quick_sort(arr1, 0, sizeof(arr1) / sizeof(arr1[0]));
    // quick_sort(arr2, sizeof(arr2) / sizeof(arr2[0]));
    // quick_sort(arr3, sizeof(arr3) / sizeof(arr3[0]));
}

