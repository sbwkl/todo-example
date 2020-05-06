package com.example;

import io.reactivex.Observable;
import io.reactivex.schedulers.Schedulers;
import org.apache.commons.lang3.time.StopWatch;

public class MultipleCall {


    public static void main(String[] args) {
        StopWatch watch = new StopWatch();
        watch.start();
        Observable<Object> k1 = Observable.create(emitter -> {
            try {
                // get tk pwd
                Thread.sleep(2000);
                String tkPwd = "k1";
                emitter.onNext(tkPwd);
                emitter.onComplete();
            } catch (Exception e) {
                emitter.onError(e);
            }
        }).subscribeOn(Schedulers.io());
        Observable<Object> k2 = Observable.create(emitter -> {
            try {
                // get tk pwd
                Thread.sleep(1500);
                String tkPwd = "k2";
                emitter.onNext(tkPwd);
                emitter.onComplete();
            } catch (Exception e) {
                emitter.onError(e);
            }
        }).subscribeOn(Schedulers.io());
        watch.split();
        System.out.println(watch.getSplitTime());
        Observable.merge(k1, k2).blockingSubscribe(System.out::println);
        watch.stop();
        System.out.println(watch.getTime());
    }
}
