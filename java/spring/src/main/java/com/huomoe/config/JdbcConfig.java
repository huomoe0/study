package com.huomoe.config;

import com.alibaba.druid.pool.DruidDataSource;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

import javax.sql.DataSource;

public class JdbcConfig {

        @Bean
        public DataSource dataSource() {
            DruidDataSource ds = new DruidDataSource();
            ds.setDriverClassName("${driver}");
            ds.setUrl("${url}");
            ds.setUsername("${username}");
            ds.setPassword("${password}");
            return ds;
        }

}
