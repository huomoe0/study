package com.huomoe.web.request;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.util.Map;

@WebServlet("/req3")
public class RequestDemo3 extends HttpServlet {
    protected void doGet(HttpServletRequest req, HttpServletResponse res) throws UnsupportedEncodingException {
        req.setCharacterEncoding("utf-8");
        String username = req.getParameter("username");

        // URL解码
        //username = new String(username.getBytes(StandardCharsets.ISO_8859_1), StandardCharsets.UTF_8);
        System.out.println(username);
        Object msg = (String) req.getAttribute("msg");
        System.out.print(msg);

    }

    protected void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
        this.doGet(req,res);
    }


}
