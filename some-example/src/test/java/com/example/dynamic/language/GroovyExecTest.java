package com.example.dynamic.language;

import com.google.common.base.Splitter;
import org.junit.Assert;
import org.junit.Test;

import java.io.IOException;
import java.util.Map;

/**
 * Created by RBK-WY-1010 on 2018/9/20.
 */
public class GroovyExecTest {

    @Test
    public void execFileTest() throws IOException {
        GroovyExec groovy = new GroovyExec();
        Map<String, String> properties = Splitter.on(",").withKeyValueSeparator(":").split(
                "name:wayne, age:30"
        );
        Object actual = groovy.execFile(properties);
        Assert.assertEquals("Hello wayne", actual);
    }

    @Test(expected = IOException.class)
    public void noFileExecTest() throws IOException {
        GroovyExec groovy = new GroovyExec();
        groovy.noFileExec();
    }
}
