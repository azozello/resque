package core.inner;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * @author azozello
 */
public class OuterClass {

    private static void print(Collection<Object> list){
        for (Object o : list){
            System.out.println(o.toString());
        }
    }

    public static void main(String[] args){
    }
}
