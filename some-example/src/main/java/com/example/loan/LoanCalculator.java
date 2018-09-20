package com.example.loan;

/**
 * simple loan calculator for average capital plus interest (等额本息)
 * formula
 * monthly payment = principal * (APR / 12) * ((1 + APR / 12)^duration) / ((1 + APR / 12)^duration - 1)
 *
 * Created by RBK-WY-1010 on 2018/9/20.
 */
public class LoanCalculator {

    public double[] calAPR(double[] p1, double[] p2, int n, double[] loan) {

        double x = (p1[0] + p2[0]) / 2;
        double p = Math.pow(1 + x, loan[1]);
        double y = (loan[0] * x * p) / (p - 1) - loan[2];

        double yy = y * y;

        double[] pn = {x, yy};
        System.out.println(n + " cpu : x = " + x + " y^2 = " + yy);
        if (n > 1) {
            if (p1[1] <= p2[1]) {
                pn = calAPR(p1, pn, n - 1, loan);
            } else {
                pn = calAPR(p2, pn, n - 1, loan);
            }
        }
        return pn;
    }
}
