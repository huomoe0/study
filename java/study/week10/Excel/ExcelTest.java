package week10.Excel;

import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class ExcelTest {

    // 从表格中读取
    public static void main(String[] args) throws BiffException, IOException {
        File file = new File(System.getProperty("user.dir") + "\\data\\1.xls");

        Workbook workbook = Workbook.getWorkbook(file);
        Sheet sheet1 = workbook.getSheet(0);

        ArrayList<Student> list = new ArrayList<>();

        for(int i = 0;i < sheet1.getRows();i++) {
            Cell cell = sheet1.getCell(0, i);
            String id = cell.getContents();
            cell = sheet1.getCell(1, i);
            String name = cell.getContents();
            cell = sheet1.getCell(2, i);
            String gender = cell.getContents();
            cell = sheet1.getCell(3, i);
            String province = cell.getContents();
            list.add(new Student(id, name, gender, province));
        }
        for (Student i : list) {
            System.out.println(i);
        }

        workbook.close();
    }
}
