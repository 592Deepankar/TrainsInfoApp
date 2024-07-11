import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Train class to represent a train
class Train {
    private int trainNumber;
    private String trainName;
    private String trainTiming;

    public Train(int trainNumber, String trainName, String trainTiming) {
        this.trainNumber = trainNumber;
        this.trainName = trainName;
        this.trainTiming = trainTiming;
    }

    public int getTrainNumber() {
        return trainNumber;
    }

    public String getTrainName() {
        return trainName;
    }

    public String getTrainTiming() {
        return trainTiming;
    }

    @Override
    public String toString() {
        return "Train{" +
                "trainNumber=" + trainNumber +
                ", trainName='" + trainName + '\'' +
                ", trainTiming='" + trainTiming + '\'' +
                '}';
    }
}

// TrainSchedule class to manage a list of trains and display the schedule
class TrainSchedule {
    private List<Train> trains;

    public TrainSchedule() {
        trains = new ArrayList<>();
    }

    public void addTrain(Train train) {
        trains.add(train);
    }

    public void displaySchedule() {
        if (trains.isEmpty()) {
            System.out.println("No trains in the schedule.");
        } else {
            for (Train train : trains) {
                System.out.println("Train Number: " + train.getTrainNumber());
                System.out.println("Train Name: " + train.getTrainName());
                System.out.println("Train Timing: " + train.getTrainTiming());
                System.out.println();
            }
        }
    }
}

// Main class to interact with the user and manage the train schedule
public class Main {
    public static void main(String[] args) {
        TrainSchedule trainSchedule = new TrainSchedule();
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("\nMenu:");
            System.out.println("1. Add a train");
            System.out.println("2. Display train schedule");
            System.out.println("3. Exit");
            System.out.print("Choose an option: ");

            int choice = scanner.nextInt();
            scanner.nextLine();  // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter train number: ");
                    int trainNumber = scanner.nextInt();
                    scanner.nextLine();  // Consume newline
                    System.out.print("Enter train name: ");
                    String trainName = scanner.nextLine();
                    System.out.print("Enter train timing: ");
                    String trainTiming = scanner.nextLine();
                    Train train = new Train(trainNumber, trainName, trainTiming);
                    trainSchedule.addTrain(train);
                    System.out.println("Train added.");
                    break;
                case 2:
                    System.out.println("Train Schedule:");
                    trainSchedule.displaySchedule();
                    break;
                case 3:
                    running = false;
                    break;
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }

        scanner.close();
        System.out.println("Goodbye!");
    }
}
