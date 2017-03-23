import core.HugeInteger;

public class Main {
    public static void main(String[] args){

        HugeInteger a = new HugeInteger("8");
        System.out.println(a.sub(new HugeInteger("9")));
        System.out.println(a.div(3));
    }
}
