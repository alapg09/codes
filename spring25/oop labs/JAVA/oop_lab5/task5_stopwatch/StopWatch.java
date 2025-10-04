public class StopWatch {
    private long startTime;
    private long endTime;

    // No-arg constructor that initializes startTime
    public StopWatch() {
        startTime = System.currentTimeMillis();
    }

    // Resets startTime to current time
    public void start() {
        startTime = System.currentTimeMillis();
    }

    // Sets endTime to current time
    public void stop() {
        endTime = System.currentTimeMillis();
    }

    // Returns elapsed time in milliseconds
    public long getElapsedTime() {
        return endTime - startTime;
    }

    // Getter methods
    public long getStartTime() {
        return startTime;
    }

    public long getEndTime() {
        return endTime;
    }
}
