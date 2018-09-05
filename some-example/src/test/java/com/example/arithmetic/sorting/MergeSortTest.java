package com.example.arithmetic.sorting;

import org.junit.Assert;
import org.junit.Test;

/**
 * test case 1 : sort array is not null
 * test case 2 : sort array is null
 * Created by RBK-WY-1010 on 2018/9/5.
 */
public class MergeSortTest {

    int[] arr = {2,5,0,6,8,1,7,3,9,4};
    int[] expected = {0,1,2,3,4,5,6,7,8,9};

    @Test
    public void sortTestCase1() {
        MergeSort.sort(arr);
        Assert.assertArrayEquals(expected, arr);
    }

    @Test(expected = IllegalArgumentException.class)
    public void sortTestCase2() {
        MergeSort.sort(null);
    }
}
