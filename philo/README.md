# 🍽️ Philosophers
🛸[42 São Paulo](https://www.42sp.org.br/)<br>
🗓️*Sunday, 25 January 2025* - 📍*São Paulo, Brazil*<br>

This project addresses the classic problem of the Philosophers' Dinner. It uses 
the following fundamental concepts: concurrency, threads, processes, and 
synchronization.

## 🛠️ Technologies Used
- **Language:** C
- **Main libraries:** pthread

## 🍝 The Philosophers' Problem
The problem consists of a round table with a plate of pasta in the center, 
where **N philosophers** sit around the table, with the same number of 
**forks as philosophers** distributed around the table.

There are three stages that every philosopher must go through:
- Eating (**requires two forks**)
- Sleeping
- Thinking

The goal is to create a system where:
- No philosopher dies (when the time of death does not conflict with the others)
- Deadlocks do not occur
- Race conditions do not occur

## ⚙️ Compilation
To compile the project, run in the `/philo/` directory:
```bash
make
```

To run the project, go to `/bin/` and execute the `philo` executable:
```bash
./bin/philo <1> <2> <3> <4> [5]
```

Expected inputs, all integers:
- 1. Number of philosophers in the simulation [required]
- 2. Death time limit [required]
- 3. Meal time [required]
- 4. Sleep time [required]
- 5. Meal limit per philosopher [optional]

To clean up the object files:
```bash
make clean
```

To clean everything:
```bash
make fclean
```

## 🔒 Synchronization
- Each fork is protected by a mutex
- Screen prints are protected to prevent mixed messages
- A monitor constantly checks whether any philosopher has died or reached the 
  number of meals
- Careful use of usleep to maintain timing accuracy

## ⚠️ Precautions Taken
- Prevention of **deadlocks**
- Protection against **race conditions**
- Accuracy in **timestamps**
- Correct **memory release**
- **Threads** terminated correctly

## 🏁 Conclusion
The Philosophers project is an excellent exercise for understanding real-world 
concurrency and synchronization problems, requiring attention to detail and 
good solution design.
