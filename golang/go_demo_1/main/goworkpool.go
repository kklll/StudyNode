package main

import (
	"fmt"
	"time"
)

//go的工作池
func main() {
	const workerNum = 5
	jobs := make(chan int, workerNum)
	result := make(chan int, workerNum)
	for i := 1; i <= 3; i++ {
		go worker1(i, jobs, result)
	}
	for i := 1; i <= workerNum; i++ {
		//发布任务
		jobs <- i
	}
	//关闭任务通道
	close(jobs)
	for i := 1; i <= workerNum; i++ {
		<-result
	}
}

func worker1(id int, jobs <-chan int, result chan<- int) {
	for j := range jobs {
		fmt.Println("worker", id, "start jobs", j)
		time.Sleep(time.Second)
		fmt.Println("worker ", id, "finish jobs", j)
		result <- j * 2
	}
}
