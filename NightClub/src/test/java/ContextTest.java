import framework.Context;
import org.junit.Test;

public class ContextTest {

    @Test
    public void testGetContext() throws Exception{
        Context.start();
        Context.stop();
    }
}
