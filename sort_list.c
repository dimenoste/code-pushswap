#include <stdio.h> // A SUPPRIMER !!!!!!!!!!!!!!!!!!!
#include <stdlib.h>
#include <unistd.h>




void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int *arr, int len)
{
    
    int end_idx;
    int i;
    if (!arr|| len < 2)
    {
        return ;
    }
    end_idx = len - 1;
    while (end_idx > 0)
    {
        i = 0;
        while (i < end_idx)
        {
            if (arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
            i++;
        }
        end_idx--;
    }
}

void	print_array(int *arr, int len)
{
	int	i;

	i = 0;
    printf("==============================================\n");
	while (i < len)
	{
		printf("number at index %d is %d\n", i, arr[i]);
		i++;
	}
    printf("==============================================\n");
}

int main(void)
{
    int arr[] = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};

	print_array(arr, 10);
	bubble(arr, 10);
    print_array(arr, 10);
	return (0);
}