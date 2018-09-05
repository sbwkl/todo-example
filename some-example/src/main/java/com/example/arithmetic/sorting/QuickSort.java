package com.example.arithmetic.sorting;

import org.springframework.util.Assert;

/**
 * a simple quick sort arithmetic.
 * Created by RBK-WY-1010 on 2018/9/5.
 */
public class QuickSort {

    public static void sort(int[] arr) {
        Assert.notNull(arr, "array must not null");
        sort(arr, 0, arr.length - 1);
    }

    private static void sort(int[] arr, int start, int end) {
        if (start < end) {
            int pi = position(arr, start, end);
            sort(arr, start, pi - 1);
            sort(arr, pi + 1, end);
        }
    }

    /**
     * specify a pivot find the correct position (pi)
     * the element on the left (index < pi) < pivot
     * the element on the right (index > pi) > pivot
     */
    private static int position(int[] arr, int start, int end) {

        int pivot = arr[end];

        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (arr[j] < pivot) {
                i++;
                // swap arr[i] arr[j]
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        // swap arr[i + 1] pivot
        int temp = arr[i + 1];
        arr[i + 1] = pivot;
        arr[end] = temp;
        return i + 1;
    }
}