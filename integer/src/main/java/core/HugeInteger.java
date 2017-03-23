package core;

import core.exception.HugeException;

import java.util.ArrayList;

public class HugeInteger {

    private int[] value;

    private boolean negative;

    public HugeInteger(String hugeNumber) {
        try{
            char[] source = hugeNumber.toCharArray();
            if (source.length<1) throw new HugeException("Too short");
            else {
                if (String.valueOf(source[0]).equals("-")) {
                    negative = true;
                    int[] newValue = new int[source.length-1];
                    for (int i=1;i<newValue.length;i++){
                        newValue[i-1] = Integer.parseInt(String.valueOf(source[i]));
                    }
                    value = newValue;
                } else {
                    int[] newValue = new int[source.length];
                    for (int i=0;i<newValue.length;i++){
                        newValue[i] = Integer.parseInt(String.valueOf(source[i]));
                    }
                    value = newValue;
                }
            }
        } catch (IndexOutOfBoundsException e){
            e.printStackTrace();
        } catch (NumberFormatException nfe){
            System.out.println("Wrong input");
            value = null;
        } catch (HugeException he){
            System.out.println(he.getMessage());
            value = new int[]{0};
        }
    }

    public HugeInteger() {}

    public HugeInteger add(HugeInteger term){
        HugeInteger result = new HugeInteger();
        try {
            if (this.isNegative() !=term.isNegative()) throw new HugeException("Used subtraction instead");
            int[] sum = sum(this.getValue(),term.getValue());
            sum = normalize(sum);

            result.setNegative(this.isNegative());
            result.setValue(sum);

        } catch (HugeException he){
            System.out.println(he.getMessage());
            if (this.isNegative()){
                result = term.sub(this);
            } else {
                result = this.sub(term);
            }
        }
        return result;
    }

    public HugeInteger sub(HugeInteger source){
        HugeInteger result = new HugeInteger();
        if (!isNegative() && !source.isNegative()) {
            int[] a = this.getValue();
            int[] b = source.getValue();
            int flag = compare(a, b);
            switch (flag) {
                case 1:
                    result.setNegative(false);
                    break;
                case 2:
                    result.setNegative(true);
                    int[] temp = a;
                    a = b;
                    b = temp;
                    break;
                case 3:
                    result.setValue(new int[]{0});
                    result.setNegative(false);
                    return result;
            }
            result.setValue(subtraction(a, b));
        } else if (isNegative() && source.isNegative()){
            this.setNegative(false);
            source.setNegative(false);
            result = this.add(source);
            result.setNegative(true);
        } else {
            if (isNegative()){
                this.setNegative(false);
                result = source.sub(this);
            } else {
                source.setNegative(false);
                result = this.add(source);
            }
        } return result;
    }

    public HugeInteger multiply(int source){
        HugeInteger result = new HugeInteger("0");
        HugeInteger temp = this;
        for (int i=0;i<source;i++){
            result = result.add(this);
        }
        return result;
    }

    public HugeInteger div(int source){
        HugeInteger that = this;
        HugeInteger result = new HugeInteger();

        HugeInteger si = new HugeInteger(""+source);
        int flag = compare(this.getValue(),si.getValue());
        int resultInt = 0;
        switch (flag){
            case 1:
                while (!that.isNegative()){
                    that = that.sub(si);
                    resultInt++;
                }
                return new HugeInteger(""+(resultInt-1));
            case 2:
                result = new HugeInteger("0");
                return result;
            case 3:
                result = new HugeInteger("1");
                return result;
        } return result;
    }

    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
        if (value==null) return null;
        else {
            buffer.append(negative ? "-" : "");
            for (int i : value) {
                buffer.append(i);
            }
        }
        return buffer.toString();
    }

    private int[] mirror(int[] source){
        int[] result = new int[source.length];
        int index = 0;
        for (int i=source.length-1;i>=0;i--){
            result[index++] = source[i];
        }
        return result;
    }

    private int compare(int[] a, int[] b){
        if (a.length!=b.length){
            return a.length>b.length ? 1 : 2;
        } else {
            for (int i=0;i<a.length;i++){
                if (a[i]!=b[i]){
                    return a[i]>b[i] ? 1 : 2;
                }
            }
        }
        return 3;
    }

    private int[] sum(int[] a, int[] b){
        a = mirror(a);
        b = mirror(b);
        int[] result = new int[a.length>b.length ? a.length : b.length];
        for (int i=0;i<result.length;i++){
            try {
                result[i] = a[i] + b[i];
            } catch (IndexOutOfBoundsException e){
                if (a.length>b.length){
                    result[i]=a[i];
                } else {
                    result[i]=b[i];
                }
            }
        }
        return mirror(result);
    }

    private int[] subtraction(int[] a, int[] b){
        a = mirror(a);
        b = mirror(b);
        int[] result = new int[a.length>b.length ? a.length : b.length];
        for (int i=0;i<result.length;i++){
            try {
                int temp = a[i] - b[i];
                if (temp<0){
                    temp = (a[i]+10) - b[i];
                    result[i] = temp;
                    a[i+1] -= 1;
                } else result[i] = temp;
            } catch (IndexOutOfBoundsException e){
                if (a.length>b.length){
                    result[i]=a[i];
                } else {
                    result[i]=b[i];
                }
            }
        }
        return mirror(result);
    }

    private int[] normalize(int[] source){
        ArrayList<Integer> resultList = new ArrayList<Integer>();
        source = mirror(source);
            for (int i = 0; i < source.length; i++) {
                resultList.add(source[i]);
            }
            resultList.add(0);
            for (int i = 0; i < source.length; i++) {
                if (resultList.get(i) > 9) {
                    resultList.set(i, resultList.get(i) % 10);
                    resultList.set(i + 1, resultList.get(i + 1) + 1);
                }
            }
            if (resultList.get(resultList.size() - 1) == 0) resultList.remove(resultList.size() - 1);
            int[] result = new int[resultList.size()];
            for (int i = 0; i < resultList.size(); i++) {
                result[i] = resultList.get(i);
            }
            return mirror(result);
    }

    private int[] getValue() {
        return value;
    }

    private boolean isNegative() {
        return negative;
    }

    private void setValue(int[] value) {
        this.value = value;
    }

    private void setNegative(boolean negative) {
        this.negative = negative;
    }
}
