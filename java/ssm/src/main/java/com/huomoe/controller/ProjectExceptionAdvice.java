package com.huomoe.controller;

import com.huomoe.exception.BusinessException;
import com.huomoe.exception.SystemException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import static com.huomoe.controller.Code.SYSTEM_UNKNOW_ERR;


@RestControllerAdvice
public class ProjectExceptionAdvice {


    @ExceptionHandler(BusinessException.class)
    public Result doBusinessException(BusinessException ex) {

        return new Result(ex.getCode(),null, ex.getMessage());
    }



    @ExceptionHandler(SystemException.class)
    public Result doSystemException(SystemException ex) {

        return new Result(ex.getCode(),null, ex.getMessage());
    }


    @ExceptionHandler(Exception.class)
    public Result doException(Exception ex) {

        return new Result(SYSTEM_UNKNOW_ERR,null, "系统繁忙，请稍后再试");
    }
}
