# philosophers

### description
The dining philosophers sitting next to each other on a round table. They either think, eat or sleep. If they don't eat or sleep they think. If a philosopher does not eat enough they die. Philosophers try to avoid dying. In the middle of that tables is spaghetti (or whatever food you desire) and between each philosopher is one fork (spoon w.e.).
There are as many forks as philosophers available. Each philosopher can only use forks right next to him (left and right fork) and has to use two forks to eat. 
Every philosopher is treated as a single thread (pthread). Philosophers don't know if any other philosopher is about to die or eat or sleep.
### rules
• One or more philosophers sit at a round table. </br>
  </t>There is a large bowl of spaghetti in the middle of the table.</br>
• The philosophers alternatively eat, think, or sleep. </br>
  </t>While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping;</br>
  </t>and, of course, while sleeping, they are not eating nor thinking.</br>
• There are also forks on the table. There are as many forks as philosophers.</br>
• Because serving and eating spaghetti with only one fork is very inconvenient, a </br>
  </t>philosopher takes their right and their left forks to eat, one in each hand. </br>
• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.</br>
• Every philosopher needs to eat and should never starve.</br>
• Philosophers don’t speak with each other.</br>
• Philosophers don’t know if another philosopher is about to die.</br>
• No need to say that philosophers should avoid dying!
### usage
• Your(s) program(s) should take the following arguments: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] </br>
◦ number_of_philosophers: The number of philosophers and also the number of forks.</br>
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the sim- ulation, they die.</br>
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.</br>
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.</br>
◦ number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.</br>
• Each philosopher has a number ranging from 1 to number_of_philosophers.</br>
• Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philoso- pher number N + 1.
##### example:
Copy repo and run bash cmd 'make' inside the repository. </br>
Valid 'make' attributes are: {clean, fclean, re}.</br>
```
make
./philo 5 5000 1000 1000 7 
```
(argument 5 is optional).
### learned
-> ...about mutex.</br>
-> ...about threading and sync threads in a single process (POSIX Threads).</br>
-> ...about parallel computing. </br>
-> ...about semaphores in c</br>
