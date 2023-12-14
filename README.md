# Homework 5

```sh
.
├── README.md
├── bankers_algorithm (Chapter 8)
│   ├── Makefile
│   ├── banker.c
│   ├── banker.h
│   ├── img
│   │   ├── draft.jpg
│   │   ├── img1.png
│   │   ├── img2.png
│   │   └── img3.png
│   ├── main.c
│   └── max_requests.txt
├── page-replacement (Implementation 10.44)
│   ├── Makefile
│   ├── img
│   │   ├── check.jpg
│   │   ├── result_fifo_opt.png
│   │   └── result_lru.png
│   ├── include
│   │   ├── fifo.h
│   │   ├── lru.h
│   │   ├── opt.h
│   │   └── replacement_alg.h
│   ├── page-replacement.c
│   └── replacement_alg.c
└── scheduling_algorithm (Chapter 5)
    ├── img
    │   ├── fcfs.png
    │   ├── priority.png
    │   ├── priority_rr.png
    │   ├── rr.png
    │   └── sjf.png
    └── posix
        ├── CPU.c
        ├── Makefile
        ├── book.txt
        ├── cpu.h
        ├── driver.c
        ├── list.c
        ├── list.h
        ├── pri-schedule.txt
        ├── rr-schedule.txt
        ├── schedule.txt
        ├── schedule_fcfs.c
        ├── schedule_priority.c
        ├── schedule_priority_rr.c
        ├── schedule_rr.c
        ├── schedule_sjf.c
        ├── schedulers.h
        └── task.h

8 directories, 42 files
```

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

```sh
cd YOUR_DIR/os_hw5/bankers_algorithm
make all
make run
```
<img src="./bankers_algorithm/img/img1.png">

(cont.)
<img src="./bankers_algorithm/img/img2.png">

(cont.)
<img src="./bankers_algorithm/img/img3.png">

Here is my draft:
<img src="./bankers_algorithm/img/draft.jpg">

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