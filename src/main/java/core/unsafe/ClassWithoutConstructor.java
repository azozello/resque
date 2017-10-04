package core.unsafe;

/**
 * @author azozello
 */
public class ClassWithoutConstructor {

    private final int value;

    public ClassWithoutConstructor() {
        value = doExpensiveLookup();
    }

    private int doExpensiveLookup() {
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return 1;
    }

    public int getValue() {
        return value;
    }
}
