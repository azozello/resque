package core.engine;

import com.googlecode.fannj.*;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * @author azozello
 */
class JediBrain {

    int getDecision(float[] in){
        Fann fann = new Fann("ann");
        return getAction(fann.run(in));
    }

    void train(){
        List<Layer> layerList = new ArrayList<>();

        layerList.add(Layer.create(3, ActivationFunction.FANN_SIGMOID_SYMMETRIC, 0.01f));
        layerList.add(Layer.create(16, ActivationFunction.FANN_SIGMOID_SYMMETRIC, 0.01f));
        layerList.add(Layer.create(4, ActivationFunction.FANN_SIGMOID_SYMMETRIC, 0.01f));

        Fann fann = new Fann(layerList);

        Trainer trainer = new Trainer(fann);
        trainer.setTrainingAlgorithm(TrainingAlgorithm.FANN_TRAIN_RPROP);

        trainer.train(new File("train.data").getAbsolutePath(), 100000, 100, 0.0001f);
        fann.save("ann");
    }

    void test(){
        Fann fann = new Fann("ann");
        float[][] tests = {
                {1.0f, 0, 1},
                {0.9f, 1, 3},
                {0.3f, 0, 8},
                {1.0f, 1, 8},
                {0.1f, 0, 0},
        };
        System.out.println("Health    Gun      Enemy");
        for (float[] test : tests){
            System.out.print(" ");
            for (float f : test){
                System.out.print(f+"      ");
            }
            System.out.println(getAction(fann.run(test)));
        }
    }

    private int getAction(float[] out){
        int i = 0;
        for (int j = 1; j < 4; j++) {
            if(out[i]<out[j]){
                i = j;
            }
        }
        return i;
    }
}
