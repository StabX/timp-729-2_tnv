#include <stdio.h>
#include <stdlib.h>

FILE *quicksort_log;
FILE *heapsort_log;

// Быстрая сортировка
void quicksort(int *arr, int first, int last, int n)
{
    if (first < last)
    {
        int left = first; 
        int right = last;
        int middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) 
                left++;
            while (arr[right] > middle) 
                right--;
            if (left <= right)
            {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
	            print_file(arr, n, quicksort_log);
            }
        } while (left <= right);
        quicksort(arr, first, right, n);
        quicksort(arr, left, last, n);
    }
}


void heapify(int *arr, int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;
       // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

// Пирамидальная сортировка
void heapsort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        print_file(arr, n, heapsort_log);
        
        heapify(arr, i, 0);
    }
}

// Вывод результата в файл
int print_file(int *arr, int last, FILE *file) {
    for (int i = 0; i < last; i++) {
        if(i == last - 1) {
            fprintf(file, "%d\n", arr[i]);
        }
        else {
            fprintf(file, "%d, ", arr[i]);
        }
    }
    return 0;
}

int main() {
    quicksort_log = fopen("quicksort.log","w+b");
    heapsort_log = fopen("heapsort.log","w+b");

	int n, i;
    // Быстрая сортировка
	scanf("%d", &n);
	int quick_arr[n];
	for (i = 0; i < n; i++){
		scanf("%d", &quick_arr[i]);
	}
    quicksort(quick_arr, 0, n-1, n);
    fclose(quicksort_log);

    // Пирамидальная сортировка
    scanf("%d", &n);
	int heap_arr[n];
	for (i = 0; i < n; i++){
		scanf("%d", &heap_arr[i]);
	}
    heapsort(heap_arr, n);
    fclose(heapsort_log);

    // Вывод быстрой сортировки
	for (i = 0; i < n; i++)
	{
        if(i == n-1) {
            printf("%d\n", quick_arr[i]);
        }
        else {
            printf("%d, ", quick_arr[i]);
	    }
    }
    // Вывод пирамидальной сортировки
	for (i = 0; i < n; i++)
	{
        if(i == n-1) {
            printf("%d\n", heap_arr[i]);
        }
        else {
            printf("%d, ", heap_arr[i]);
	    }
    }   
	return 0;
}
