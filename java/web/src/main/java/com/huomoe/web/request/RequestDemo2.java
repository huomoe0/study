package com.huomoe.web.request;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Map;

@WebServlet("/req2")
public class RequestDemo2 extends HttpServlet {
    protected void doGet(HttpServletRequest req, HttpServletResponse res) {
        System.out.println("get ....");
        Map<String, String[]> map = req.getParameterMap();
        for(String key : map.keySet()) {
            System.out.print(key + ":");

            for (String s : map.get(key)) {
                System.out.print(s + " ");
            }
            System.out.println();
        }
        System.out.println("----------------------");

        String[] hobbies = req.getParameterValues("hobby");
        for(String s : hobbies) {
            System.out.println(s);
        }
    }

    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
        this.doGet(req,res);
    }


}
