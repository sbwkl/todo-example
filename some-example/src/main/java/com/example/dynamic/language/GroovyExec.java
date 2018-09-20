package com.example.dynamic.language;

import groovy.lang.Binding;
import groovy.lang.GroovyShell;
import org.springframework.util.ResourceUtils;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Map;

/**
 * Created by RBK-WY-1010 on 2018/9/20.
 */
public class GroovyExec {

    public Object execFile(Map<String, String> properties) throws IOException {
        Binding sharedData = new Binding();
        GroovyShell shell = new GroovyShell(sharedData);
        for (Map.Entry<String, String> entry : properties.entrySet()) {
            sharedData.setProperty(entry.getKey(), entry.getValue());
        }
        Object obj = shell.evaluate(ResourceUtils.getFile("classpath:groovy-scripts/Example.groovy"));
        return obj;
    }

    public Object noFileExec() throws IOException {
        GroovyShell shell = new GroovyShell();
        Object obj = shell.evaluate(ResourceUtils.getFile("calsspath:groovy-scripts/NoFile.groovy"));
        return obj;
    }
}
