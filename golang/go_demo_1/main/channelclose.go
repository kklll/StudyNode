package main

import "fmt"

func main() {
	jobs := make(chan int, 5)
	done := make(chan bool)
	go func() {
		for {
			j, ok := <-jobs
			if ok {
				fmt.Println("接收到消息", j)
			} else {
				fmt.Println("所有工作已经完成！下班了！")
				done <- true
			}
		}
	}()
	for i := 0; i < 3; i++ {
		jobs <- i
		fmt.Println("send job", i)
	}
	close(jobs)
	fmt.Println("send all jobs")
	<-done
}
