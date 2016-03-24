import java.io.*;
import java.util.*;

/**
 * Created by yaoming on 3/24/16.
 */
public class Main {

    static int pivotCounter;

    public static void swap(int[] arr, int pos1, int pos2) {
        final int temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }

    public static int partition(int arr[], int start, int last) {

        pivotCounter++;

        int pivotValue = arr[last];
        int pivotPosition = start;

        for (int pos = start; pos < last; pos++) {
            if (arr[pos] <= pivotValue) {
                swap(arr, pivotPosition, pos);
                pivotPosition++;
            }
        }
        swap(arr, last, pivotPosition);
        return pivotPosition;
    }

    public static void quickSort(int arr[], int start, int last) {

        if(start < last) //base case
        {
            int pivot = partition(arr, start, last);
            quickSort(arr, start, pivot - 1);     //sort recursively sort elements less than the pivot
            quickSort(arr, pivot + 1 , last);     //sort recursively sort elements greater than the pivot
        }
    }


    public static void main(String[] args) {
        try (Scanner in  = new Scanner(new File(args[0]))) {
            while (in.hasNextLine()) {
                String[] strnum = in.nextLine().split(" ");
                int[] nums = new int[strnum.length];
                for (int i = 0; i < strnum.length; i++) {
                    nums[i] = Integer.parseInt(strnum[i]);
                }

                pivotCounter = 0;
                quickSort(nums, 0, nums.length-1);
                System.out.println(pivotCounter);

            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
