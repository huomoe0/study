package com.huomoe.config;

import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;

@Configuration
@ComponentScan({"com.huomoe.controller", "com.huomoe.config"})
@EnableWebMvc
public class SpringMvcConfig {

}
