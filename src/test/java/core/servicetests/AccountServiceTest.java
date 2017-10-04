package core.servicetests;

import core.services.AccountService;
import core.services.PlusService;
import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import static org.junit.Assert.assertEquals;

/**
 * @author azozello
 */
public class AccountServiceTest {

    private AccountService accountService;
    private PlusService mockedPlusService;

    @Before
    public void setUp(){
        mockedPlusService = Mockito.mock(PlusService.class);
        accountService = new AccountService(mockedPlusService);
    }

    @Test
    public void accountServiceAddTest(){
        Mockito.when(mockedPlusService.plus(60,50)).thenReturn(200);
        accountService.add(1,50);
        assertEquals(AccountService.getBalances()[1],110);
        Mockito.verify(mockedPlusService,Mockito.never()).plus(60,50);
    }
}
