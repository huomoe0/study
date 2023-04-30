package week10.Excel;

import jxl.Workbook;
import jxl.write.Label;
import jxl.write.WritableSheet;
import jxl.write.WritableWorkbook;
import jxl.write.WriteException;

import java.io.File;
import java.io.IOException;

public class ExcelTest1 {
    public static void main(String[] args) throws WriteException, IOException {
        File file = new File(System.getProperty("user.dir") + "/data/stu.xls");
        WritableWorkbook book = Workbook.createWorkbook(file);

        WritableSheet sheet = book.createSheet("学生信息", 0);
        Label label = new Label(0, 0, "学号");
        sheet.addCell(label);
        label = new Label(1, 0, "姓名");
        sheet.addCell(label);
        label = new Label(2, 0, "性别");
        sheet.addCell(label);
        label = new Label(3, 0, "省份");
        sheet.addCell(label);

        book.write();
        book.close();
    }
}
