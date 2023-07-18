package com.huomoe.config;

import com.alibaba.druid.pool.DruidDataSource;
import org.springframework.context.annotation.*;

import javax.sql.DataSource;

@Configuration
@ComponentScan({"com.huomoe.dao", "com.huomoe.aop"})
@PropertySource("classpath:jdbc.properties")
@Import(JdbcConfig.class)
@EnableAspectJAutoProxy
public class SpringConfig {

}
