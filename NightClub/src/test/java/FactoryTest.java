import framework.factory.Ann;
import framework.factory.BeanFactory;
import org.junit.Test;

import java.util.Set;

public class FactoryTest {

    @Test
    public void testAllBeans() throws Exception{
        Set<Class<?>> testSet = BeanFactory.getAllBeans();
    }

    @Test
    public void testAllBeansEnum() throws Exception{
        Set<Class<?>> testSetC = BeanFactory.getAllBeans(Ann.CUSTOMER);
        Set<Class<?>> testSetB = BeanFactory.getAllBeans(Ann.BUILDING);
        Set<Class<?>> testSetE = BeanFactory.getAllBeans(Ann.EMPLOYEE);
    }

    @Test
    public void testBean() throws Exception{
        Object exist = BeanFactory.createBeanForName("custom.Me");
        Object spam = BeanFactory.createBeanForName("sadasd");
    }
}
