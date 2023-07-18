package com.huomoe.web.request;

import javax.servlet.*;
import javax.servlet.annotation.WebServlet;

//@WebServlet("/demo3/*")
@WebServlet("*.do")
public class ServletDemo3 extends MyHttpServlet {

    protected void doPost(ServletRequest req, ServletResponse res) {
        System.out.println("doPost ...");

    }

    protected void doGet(ServletRequest req, ServletResponse res) {
        System.out.println("doGet ...");
    }
}
