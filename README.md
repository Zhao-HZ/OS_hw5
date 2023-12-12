# Homework 5

## Page Replacement Algorithm

```sh
cd YOUR_DIR/os_hw5/page-replacement
make all
./page-replacement
```

The random array generated does not look so random
even if I involve the `srand` function.
For sake of convenience, I just pick one example.

<img src="./page-replacement/img/check.jpg">

The result is as follow:<br>
FIFO and OPT:<br>
<img src="./page-replacement/img/result_fifo_opt.png"><br>
LRU<br>
<img src="./page-replacement/img/result_lru.png">


## Banker's Algorithm


## Scheduling Algorithm

```sh
cd YOUR_DIR/os_hw5/scheduling_algorithm/posix
make rr
make sjf
make fcfs
make priority
make priority_rr
```

Result:

<img src="./scheduling_algorithm/img/fcfs.png"><br>
<img src="./scheduling_algorithm/img/rr.png"><br>
<img src="./scheduling_algorithm/img/sjf.png"><br>
<img src="./scheduling_algorithm/img/priority.png"><br>
<img src="./scheduling_algorithm/img/priority_rr.png"><br>