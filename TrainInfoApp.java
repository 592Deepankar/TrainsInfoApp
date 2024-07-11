import java.util.ArrayList;
import java.util.Scanner;

public class TrainInfoApp {

    // Class to represent a train
    public static class Train {
        private String name;
        private String number;
        private String timetable;
        private int seatAvailability;

        public Train(String name, String number, String timetable, int seatAvailability) {
            this.name = name;
            this.number = number;
            this.timetable = timetable;
            this.seatAvailability = seatAvailability;
        }

        // Getters
        public String getName() {
            return name;
        }

        public String getNumber() {
            return number;
        }

        public String getTimetable() {
            return timetable;
        }

        public int getSeatAvailability() {
            return seatAvailability;
        }

        // toString method to display the train details
        @Override
        public String toString() {
            return "Train Name: " + name + "\nTrain Number: " + number + "\nTimetable: " + timetable + "\nSeat Availability: " + seatAvailability;
        }
    }

    // Method to create and add a new train to the list
    public static void addTrain(ArrayList<Train> trainList, Scanner scanner) {
        System.out.print("Enter train name: ");
        String name = scanner.nextLine();

        System.out.print("Enter train number: ");
        String number = scanner.nextLine();

        System.out.print("Enter train timetable: ");
        String timetable = scanner.nextLine();

        System.out.print("Enter seat availability: ");
        int seatAvailability = Integer.parseInt(scanner.nextLine());

        Train train = new Train(name, number, timetable, seatAvailability);
        trainList.add(train);

        System.out.println("Train added successfully!");
    }

    // Method to display all trains in the list
    public static void displayTrains(ArrayList<Train> trainList) {
        System.out.println("Train Information:");
        for (Train train : trainList) {
            System.out.println(train);
            System.out.println("--------------");
        }
    }

    // Main application logic
    public static void main(String[] args) {
        ArrayList<Train> trainList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Select a choice:");
            System.out.println("1. Add Train");
            System.out.println("2. View Train Information");
            System.out.println("3. Exit");

            String choice = scanner.nextLine();

            if (choice.equals("1")) {
                // Add a new train
                addTrain(trainList, scanner);
            } else if (choice.equals("2")) {
                // View all trains in the list
                displayTrains(trainList);
            } else if (choice.equals("3")) {
                // Exit the application
                System.out.println("Exiting...");
                break;
            } else {
                System.out.println("Invalid choice. Please try again.");
            }
        }

        scanner.close();
    }
}
 