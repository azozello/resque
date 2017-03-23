package core.exception;

public class HugeException extends RuntimeException{
    public HugeException(){}
    public HugeException(String massage){
        super(massage);
    }
}
