package com.huomoe;

import com.huomoe.config.SpringConfig;
import com.huomoe.dao.BookDAO;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import javax.sql.DataSource;

public class App {
    public static void main(String[] args) {

        ApplicationContext ctx = new AnnotationConfigApplicationContext(SpringConfig.class);


        BookDAO bookDao = ctx.getBean(BookDAO.class);
        bookDao.select();
    }
}
