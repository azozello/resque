package core.model;

/**
 * @author azozello
 */
public class Droid extends Warrior {

    private int armor;

    public Droid(float health, int armor) {
        super(health);
        this.armor = armor;
    }

    public int getArmor() {
        return armor;
    }
}
