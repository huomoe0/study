package com.huomoe.web.request;

import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/req1")
public class RequestDemo1 extends HttpServlet {

    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
        BufferedReader reader = req.getReader();
        String s = reader.readLine();
        System.out.println(s);
    }

    protected void doGet(HttpServletRequest req, HttpServletResponse res) {
        String method = req.getMethod();
        System.out.println(method);

        String contextPath = req.getContextPath();
        System.out.println(contextPath);

        StringBuffer url = req.getRequestURL();
        System.out.println(url.toString());

        String uri = req.getRequestURI();
        System.out.println(uri);

        String queryString = req.getQueryString();
        System.out.println(queryString);

        String header = req.getHeader("user-agent");
        System.out.println(header);

    }
}
