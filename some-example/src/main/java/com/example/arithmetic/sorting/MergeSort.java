package com.example.arithmetic.sorting;

import org.springframework.util.Assert;

import java.util.Arrays;

/**
 * a simple merge sort arithmetic
 * Created by RBK-WY-1010 on 2018/9/5.
 */
public class MergeSort {

    public static void sort(int[] arr) {
        Assert.notNull(arr, "array must not null");
        sort(arr, 0, arr.length - 1);
    }

    private static void sort(int[] arr, int start, int end) {
        if (start < end) {
            int m = (start + end) / 2;
            sort(arr, start, m);
            sort(arr, m + 1, end);
            merge(arr, start, m, end);
        }
    }

    private static void merge(int[] arr, int start, int mid, int end) {

        int n1 = mid - start + 1;
        int n2 = end - mid;

        int[] L = new int[n1];
        int[] R = new int[n2];

        System.arraycopy(arr, start, L, 0, n1);
        System.arraycopy(arr, mid + 1, R, 0, n2);

        int i = 0, j = 0;
        int index = start;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[index] = L[i];
                i++;
            } else {
                arr[index] = R[j];
                j++;
            }
            index++;
        }

        while (i < n1) {
            arr[index] = L[i];
            i++;
            index++;
        }

        while (j < n2) {
            arr[index] = R[j];
            j++;
            index++;
        }
    }
}