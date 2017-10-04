package core.servicetests;

import core.services.PlusService;
import org.junit.Test;
import static org.junit.Assert.assertEquals;

/**
 * @author azozello
 */
public class PlusServiceTest {

    @Test
    public void plusTest(){
        PlusService plusService = new PlusService();
        int a = 1, b = 2;
        int c = a + b;
        assertEquals(c,plusService.plus(a,b));
    }
}
