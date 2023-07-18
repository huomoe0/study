package week7.Test;

// 省份统计输出结果的封装
public class Result {
    private String province;
    private int count;
    private String names;

    @Override
    public String toString() {
        return province + "：" + count + "人（" + names + "）";
    }

    public Result() {
    }

    public Result(String province, int count, String names) {
        this.province = province;
        this.count = count;
        this.names = names;
    }

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public String getNames() {
        return names;
    }

    public void setNames(String names) {
        this.names = names;
    }
}
