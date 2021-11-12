# MultiTreading

## Description

In this project I realized basic threads. I create and destroy threads and turn on/off mutex in a playful way.



Compilation was with flags: `gcc -Wall -Wextra -Werror`.

Project has written in accordance with the Norminette.

No memory leaks.

## Requirements

There are N philosophers who sit at the table and have three states: sleep, think and eat. The program should take the following arguments: `number_of_philosophers` `time_to_die`
`time_to_eat` `time_to_sleep` `number_of_times_each_philosopher_must_eat`.

◦ `number_of_philosophers`: is the number of philosophers and also the number
of forks.

◦ `time_to_die`: is in milliseconds, if a philosopher doesn’t start eating `time_to_die`
milliseconds after starting their last meal or the beginning of the simulation,
it dies.

◦ `time_to_eat`: is in milliseconds and is the time it takes for a philosopher to
eat. During that time they will need to keep the two forks.

◦ `time_to_sleep`: is in milliseconds and is the time the philosopher will spend
sleeping.

◦ `number_of_times_each_philosopher_must_eat`: argument is optional, if all
philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death
of a philosopher.

• Each philosopher should be given a number from 1 to `number_of_philosophers`.

• Philosopher number 1 is next to philosopher number `number_of_philosophers`.
Any other philosopher with the number `N` is seated between philosopher `N - 1` and
philosopher `N + 1`.

The program has logs. In logs there will print states of philosophers.

Philosophers should avoid dying.

##Specific rules

• Each philosopher is a thread.

• One fork between each philosopher, therefore if they are multiple philosophers, there
will be a fork at the right and the left of each philosopher.

## Usage

Use `make` to compile the executable file.

Use `./multithreading` to launch program.

Use `make re` to recompile.

Use `make clean` to delete `.o`files.

Use `make fclean` to delete `multithreading` and `.o`files.