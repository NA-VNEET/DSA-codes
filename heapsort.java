public class Main {

    // Heapify subtree rooted at index i
    public static void heapify(int a[], int n, int i) {
        int largest = i; 
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }

        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        // If root is not largest, swap and continue heapifying
        if (largest != i) {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;

            heapify(a, n, largest);
        }
    }

    // Main heapsort function
    public static void heapsort(int a[]) {
        int n = a.length;

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(a, n, i);
        }

        // Extract elements from heap one by one
        for (int i = n - 1; i >= 0; i--) {
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;

            heapify(a, i, 0);
        }
    }

  
    public static void printArray(int[] a) {
        for (int i : a) {
            System.out.print(i + " ");
        }
        System.out.println();
    }


    public static void main(String[] args) {
        int a[] = {4, 2, 1, 6, 9, 3};

        System.out.println("Original array:");
        printArray(a);

        heapsort(a);

        System.out.println("Sorted array:");
        printArray(a);
    }
}
