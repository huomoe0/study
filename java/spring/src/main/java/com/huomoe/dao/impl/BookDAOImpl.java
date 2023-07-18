package com.huomoe.dao.impl;

import com.huomoe.dao.BookDAO;
import org.springframework.stereotype.Repository;

@Repository
public class BookDAOImpl implements BookDAO {
    public void save() {
        System.out.println(System.currentTimeMillis());
        System.out.println("book dao save ...");
    }

    public void select() {
        System.out.println("book dao select ...");
    }
}

