package main

import (
	"fmt"
	"sync"
	"time"
)

//等待池
func main() {
	var wg sync.WaitGroup
	for i := 1; i <= 5; i++ {
		wg.Add(1)
		go worker2(i, &wg)
	}
	wg.Wait()
}

func worker2(id int, wg *sync.WaitGroup) {
	defer wg.Done()
	fmt.Printf("work %d is start\n", id)
	time.Sleep(time.Second)
	fmt.Printf("work %d is done %v \n ", id, time.Now())

}
