package core.context;

import core.constants.Alphabet;
import core.constants.SentenceType;
import core.units.Sentence;
import core.units.Word;

import java.util.ArrayList;

/**
 * @author azozello
 */
public class Context {

    private ArrayList<Alphabet> alphabets = new ArrayList<>();
    private ArrayList<String> stringSentences = new ArrayList<>();


    private ArrayList<Sentence> sentences = new ArrayList<>();
    private ArrayList<Word> words = new ArrayList<>();

    public Context() {

    }

    private void loadAlphabet(){
        try {
            ArrayList<String> stringAlphabets = AlphabetReader.read();
            stringAlphabets.forEach(v -> {
                String[] allSounds = v.split("\\|");

                Alphabet temp = new Alphabet();
                temp.setVowels(allSounds[0].toCharArray());
                temp.setConsonants(allSounds[1].toCharArray());

                alphabets.add(temp);
            });
        } catch (Exception e){
            e.printStackTrace();
        }
    }

    public void init(){
        loadAlphabet();
        splitSentences();
    }

    private void splitSentences(){
        String[] separatedByDotSentences = FileReader.readPDF().split("\\.");
        ArrayList<String> notEmptySentences = new ArrayList<>();
        ArrayList<String> separatedByExclamation = new ArrayList<>();
        ArrayList<String> separatedByQuestion = new ArrayList<>();

        for (String tempString : separatedByDotSentences){
            if (!tempString.equals("")){
                tempString = tempString.trim();
                notEmptySentences.add(tempString);
            }
        }

        notEmptySentences.forEach(v -> {
            if (v.contains("!")) {
                String[] tempSentences = v.split("!");
                for (int i = 0; i < tempSentences.length; i++) {
                    if (i < tempSentences.length-1) {
                        separatedByExclamation.add(tempSentences[i] + "_1");
                    } else {
                        separatedByExclamation.add(tempSentences[i]);
                    }
                }
            } else {
                separatedByExclamation.add(v);
            }
        });

        separatedByExclamation.forEach(v -> {
            if (v.contains("?")) {
                String[] tempSentences = v.split("\\?");
                for (int i = 0; i < tempSentences.length; i++) {
                    if (i < tempSentences.length-1) {
                        separatedByQuestion.add(tempSentences[i] + "_2");
                    } else {
                        separatedByQuestion.add(tempSentences[i]);
                    }
                }
            } else {
                separatedByQuestion.add(v);
            }
        });

        for (int i=0; i<separatedByQuestion.size(); i++){
            String tempSentence = separatedByQuestion.get(i).trim();
            if (tempSentence.substring(0,1).equals("—")){
                tempSentence = tempSentence.substring(1).trim();
                separatedByQuestion.set(i,tempSentence);
            }
        }

        for (int i=0; i<separatedByQuestion.size(); i++){
            separatedByQuestion.set(i,separatedByQuestion.get(i).trim());
        }

        stringSentences.add(separatedByQuestion.get(0));

        int increment = 1;
        for (int i = 1; i < separatedByQuestion.size(); i++){
            String predictedUpper = separatedByQuestion.get(i).substring(0,1);
            if (predictedUpper.equals(predictedUpper.toLowerCase())){
                stringSentences.set(stringSentences.size()-1, separatedByQuestion.get(i - increment)+" "+separatedByQuestion.get(i));
                increment++;
            } else {
                increment = 1;
                stringSentences.add(separatedByQuestion.get(i));
            }
        }

        stringSentences.forEach(v -> {
            Sentence temp = new Sentence();
            if (v.endsWith("_1")) {
                String substring = v.substring(0,v.length()-2);
                substring = substring.replaceAll("_1","!");
                substring = substring.replaceAll("_2","?");
                temp.setContent(substring);
                temp.setType(SentenceType.EXCLAMATORY);
            } else if (v.endsWith("_2")) {
                String substring = v.substring(0,v.length()-2);
                substring = substring.replaceAll("_1","!");
                substring = substring.replaceAll("_2","?");
                temp.setContent(substring);
                temp.setType(SentenceType.INTERROGATIVE);
            } else {
                String s = v;
                s = v.replace("_1","!");
                s = s.replace("_2","?");
                temp.setContent(s);
                temp.setType(SentenceType.DECLARATIVE);
            }
            sentences.add(temp);
        });
    }

    public void splitWords(){
        ArrayList<String> vowels = new ArrayList<>();
        ArrayList<String> consonants = new ArrayList<>();

        alphabets.forEach(v -> {
            for (char c : v.getVowels()){
                vowels.add(String.valueOf(c).toLowerCase());
            }
            for (char c : v.getConsonants()){
                consonants.add(String.valueOf(c).toLowerCase());
            }
        });

        sentences.forEach(v -> {
            String[] allWords = v.getContent().split(" ");
            for (String stringWord : allWords){
                Word word = new Word();

            }
        });
    }

    public ArrayList<String> getStringSentences() {
        return stringSentences;
    }

    public ArrayList<Sentence> getSentences() {
        return sentences;
    }
}
