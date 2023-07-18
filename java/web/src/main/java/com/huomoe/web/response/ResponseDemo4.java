package com.huomoe.web.response;

import org.apache.commons.io.IOUtils;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/resp4")
public class ResponseDemo4 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        FileInputStream fis = new FileInputStream("src\\main\\resources\\kll.png");

        ServletOutputStream os = resp.getOutputStream();

//        byte[] bytes = new byte[1024];
//        int len = 0;
//        while ((len = fis.read(bytes)) != -1) {
//            os.write(bytes, 0, len);
//        }
        IOUtils.copy(fis, os);

        fis.close();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }
}
