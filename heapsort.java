import java.util.*;
class sorting{
    int[] shellsort(int[] arr){
        int n = arr.length;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
        return arr;
    }
    int[] heapsort(int[] arr){
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            heapify(arr, i, 0);
        }
        return arr;
    }
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]){
            largest = l;
        }
        if (r<n && arr[r]>arr[largest]){
            largest = r;
        }
        if (largest != i) {
            int swap=arr[i];
            arr[i]=arr[largest];
            arr[largest] = swap;
            heapify(arr, n, largest);
        }
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("hello world");
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        sorting obj=new sorting();
        //shellsort
        int[] arr2=obj.shellsort(arr);
        for(int i=0;i<n;i++){
            System.out.print(arr2[i]);
            System.out.print(" ");
        }
        System.err.println();
        //heapsort
        int[] arr3=obj.heapsort(arr);
        for(int i=0;i<n;i++){
            System.out.print(arr3[i]);
            System.out.print(" ");
        }
    }
}