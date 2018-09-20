package com.example.loan;

import org.junit.Test;

/**
 * Created by RBK-WY-1010 on 2018/9/20.
 */
public class LoanCalculatorTest {

    @Test
    public void calAPRTest() {
        LoanCalculator cal = new LoanCalculator();

        double[] p1 = {0.005, 99225.0};
        double[] p2 = {0.004, 841.0};
        double[] loan = {510000, 240, 3338.6};

        double[] p = cal.calAPR(p1, p2, 30, loan);
        System.out.println("APR = " + p[0] * 12 * 100);
    }
}
