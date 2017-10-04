package core.services;

/**
 * @author azozello
 */
public class AccountService {

    private static int balances[] = new int[] {25,60,70};

    private PlusService plusService;

    public AccountService(PlusService plusService) {
        this.plusService = plusService;
    }

    public void add(int index, int sum){
        balances[index] = plusService.plus(balances[index],sum);
    }

    public static int[] getBalances() {
        return balances;
    }
}
